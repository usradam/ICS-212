/******************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    Project
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 20, 2024
//
//  FILE:        database.c
//
//  DESCRIPTION:
//   Database functions implemented.
//
***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "database.h"

extern int debug_mode;

/******************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds new record to the list.
//
//  Parameters:    start (struct record**) : Pointer to the pointer
//                                            of the first record.
//                 accountno (int) : Account number to be added.
//                 name (char []) : Name to be added.
//                 address (char []) : Address to be added.
//
//  Return values:  0 : Success
//                 -1 : Could not add record
//
****************************************************************/

int addRecord(struct record **start, int accountno, char name[], char address[])
{
    struct record* current;
    struct record* previous;
    struct record* new_record;
    int return_val;

    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: addRecord called.\n");
        printf("Debug: accountno = %d\n", accountno);
        printf("Debug: name = %s\n", name);
        printf("Debug: address = %s\n", address);
        printf("********************************\n\n");
    }

    return_val = 0;
    current = *start;
    previous = NULL;

    while (current != NULL && current->accountno < accountno)
    {
        previous = current;
        current = current->next;
    }
    if (current != NULL && current->accountno == accountno)
    {
        return_val = -1;
    }
    else
    {
        new_record = (struct record*)malloc(sizeof(struct record));
        new_record->accountno = accountno;
        strncpy(new_record->name, name, 25);
        strncpy(new_record->address, address, 45);

        if (previous == NULL)
        {
            new_record->next = *start;
            *start = new_record;
        }
        else
        {
            new_record->next = previous->next;
            previous->next = new_record;
        }
    }
    return return_val;
}

/*******************************************************************
//
//  Function name: printAllRecrods
//
//  DESCRIPTION:   Prints all records.
//
//  Parameters:    start (struct record*) : Pointer to the first record.
//
//  Return values:  none
//
****************************************************************/

void printAllRecords(struct record *start)
{
    struct record* current;

    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: printAllRecords called.\n");
        printf("********************************\n\n");
    }

    if (start == NULL)
    {
        printf("***No records are in the database***\n");
    }
    else
    {
        for (current = start; current != NULL; current = current->next)
        {
            printf("Accountno: %d\nName: %s\nAddress: %s\n\n",
            current->accountno, current->name, current->address);
        }
    }
}

/******************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds record of specified account number.
//
//  Parameters:    start (struct record*) : Pointer to the first record.
//                 accountno (int) : Account number to find.
//
//  Return values:  0 : Record not found
//                  1 : Record found
//
****************************************************************/

int findRecord(struct record *start, int accountno)
{
    struct record* temp;
    int found = 0;

    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: findRecord called.\n");
        printf("Debug: Record = %d\n", accountno);
        printf("********************************\n\n");
    }

    if (start != NULL && found == 0)
    {
        temp = start;
        while (temp != NULL && !found)
        {
            if (temp->accountno == accountno)
            {
                printf("\n***Found record with accountno: %d***\n", accountno);
                printf("Accountno: %d\n", temp->accountno);
                printf("Name: %s\n", temp->name);
                printf("Address: %s\n", temp->address);
                printf("*************************************\n");
                found = 1;
            }
            temp = temp->next;
        }
    }
    if (!found)
    {
        printf("\n***Record does not exist***\n");
    }
    return found;
}

/*******************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Deletes record with specified account number.
//
//  Parameters:    start (struct record**) : Pointer to the pointer of the
//                                           first record.
//                 accountno (int) : Account number to delete.
//
//  Return values:  0 : Success. Record deleted
//                 -1 : Failure to delete
//
****************************************************************/

int deleteRecord(struct record **start, int accountno)
{
    struct record* temp_prev;
    struct record* temp;
    int return_val = -1;
    int found = 0;

    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: deleteRecord called.\n");
        printf("Debug: Deleted record = %d\n", accountno);
        printf("********************************\n\n");
    }

    if (*start != NULL)
    {
        temp = *start;
        if (temp->accountno == accountno && found == 0)
        {
            *start = temp->next;
            free(temp);
            printf("\n***Success! Deleted accountno %d***\n", accountno);
            return_val = 0;
            found = 1;
        }
        else
        {
            while (temp->next != NULL && found == 0)
            {
                temp_prev = temp;
                temp = temp->next;
                if (temp->accountno == accountno && found == 0)
                {
                    temp_prev->next = temp->next;
                    free(temp);
                    printf("\n***Success! Deleted accountno %d***\n", accountno);
                    return_val = 0;
                    found = 1;
                }
            }
        }
    }
    if (found == 0)
    {
        printf("Record with account number %d does not exist.\n", accountno);
    }
    return return_val;
}

/*******************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes database of account numbers to a file.
//
//  Parameters:    start (struct record*) : Pointer to the first record
//                                           in the database.
//                 filename (char[]) : File to write to.
//
//  Return values:  0 : Success
//                 -1 : Unsuccessful write to the file
//
****************************************************************/

int writefile(struct record *start, char filename[])
{
    FILE *outfile;
    struct record *current;
    int contents = 0;
    int result = 0;

    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: writefile called. Saving records to file.\n");
        printf("Debug: Filename = %s\n", filename);
        printf("********************************\n\n");
    }

    outfile = fopen(filename, "w");
    if (outfile == NULL)
    {
        printf("Could not write to file\n");
        result = -1;
    }

    for (current = start; current != NULL; current = current->next)
    {
        contents = fprintf(outfile, "%d\n%s\n%s\\\n",
        current->accountno, current->name, current->address);
        if (contents < 0)
        {
            result = -1;
        }
    }

    if (fclose(outfile) == EOF)
    {
        result = -1;
    }
    return result;
}

/*******************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Retrieves records from saved file and transfers to database.
//
//  Parameters:    start (struct record**) : Pointer to the pointer of first record
//                                           in the database
//                 filename (char[]) : File to read from.
//
//  Return values:  0 : success
//                 -1 : unsuccessful read from file
//
****************************************************************/

int readfile(struct record **start, char filename[])
{
    FILE *infile;
    int accountno;
    int result = 0;
    char text_of_accountno[26];
    char name[26];
    char address[46];
    char* endptr;
    char address_buffer;
    int i = 0;
    int done = 0;
    int done_address = 0;

    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: readfile called. Reading from the database.\n");
        printf("Debug: Filename = %s\n", filename);
        printf("********************************\n\n");
    }

    infile = fopen(filename, "r");
    if (infile == NULL)
    {
        printf("No existing file found. A new file will be created when data is saved.\n");
        result = 0;
    }
    else
    {
        while (!done)
        {
            if (fgets(text_of_accountno, sizeof(text_of_accountno), infile) == NULL ||
                fgets(name, sizeof(name), infile) == NULL)
            {
                done = 1;
            }
            else
            {
                accountno = (int)strtol(text_of_accountno, &endptr, 10);
                if (endptr == text_of_accountno) /* Check if conversion was successful */
                {
                    result = -1;
                    done = 1;
                }
                else
                {
                    name[strcspn(name, "\n")] = 0;

                    done_address = 0;
                    for (i = 0; i < sizeof(address) && !done_address; i++)
                    {
                        address_buffer = fgetc(infile);

                        if (address_buffer == '\\')
                        {
                            address[i] = '\0';
                            fgetc(infile);
                            done_address = 1;
                        }
                        else if (address_buffer == EOF)
                        {
                            address[i] = '\0';
                            done = 1;
                        }
                        else
                        {
                            address[i] = address_buffer;
                        }
                    }
                    addRecord(start, accountno, name, address);
                }
            }
        }

        if (fclose(infile) == EOF)
        {
            result = -1;
        }
    }
    return result;
}

/*******************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Cleans up memory from the database.
//
//  Parameters:    start (struct record**) : Pointer to the pointer of first record
//                                           in the database.
//
//  Return values:  none
//
****************************************************************/

void cleanup(struct record **start)
{
    struct record* current;
    struct record* delete;

    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: cleanup called. Cleaning memory from the database.\n");
        printf("********************************\n\n");
    }

    if (start == NULL)
    {
        printf("***No records are in the database***\n");
    }
    else
    {
        for (current = *start; current != NULL;)
        {
            delete = current;
            current = current->next;
            free(delete);
        }
        *start = NULL;
    }
}
