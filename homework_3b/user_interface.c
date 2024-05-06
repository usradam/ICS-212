/*****************************************************************
//  
//  NAME:        Adam Graham
//
//  HOMEWORK:    3b
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        February 7, 2024
//
//  FILE:        user_interface.c
//
//  DESCRIPTION:
//   User interface for the database. Allows the user the following 
//   options when accessing the database: add, printall, find,
//   delete, quit.
//
****************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "record.h"
#include "database.h"

int debug_mode = 0;
void getaddress(char[], int);
int is_positive_int();

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Gives the user the following options for accessing
//                 the database: add, printall, find, delete, quit.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//                  1 : value not found
//
****************************************************************/

int main(int argc, char* argv[])
{
    struct record * start = NULL;
    char user_input[100];
    char name[25];
    char address[45];
    int accountno;
    int valid_debug = 1;

    if (argc > 2)
    {
        printf("Invalid option. Only \"debug\" is allowed.");
        valid_debug = 0;
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "debug") == 0)
        {
            printf("\n*******************\n");
            printf("DEBUG MODE ENABLED.\n");
            printf("*******************\n\n");
            debug_mode = 1;
        }
        else
        {
            printf("Invalid option. Only \"debug\" is allowed.");
            valid_debug = 0;
        }
    }
    else if (argc == 1)
    {
        printf("\n*******************\n");
        printf("DEBUG MODE ENABLED.\n");
        printf("*******************\n\n");
        debug_mode = 1;
    }

    while (valid_debug)
    {
        printf("\nThis program accesses a database to add, print, find, and delete items.\n");
        printf("\nType and enter one of the following menu options below:\n");
        printf("add: Adds record to database.\n");
        printf("printall: Prints all available records.\n");
        printf("find: Finds a specific record.\n");
        printf("delete: Deletes specific record.\n");
        printf("quit: Exits the program.\n");

        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = 0;

        if (strncmp(user_input, "add", strlen(user_input)) == 0 &&
            strlen(user_input) <= strlen("add"))
        {
            printf("Please enter an account number:\n");
            accountno = is_positive_int();

            printf("Enter a name:\n");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = '\0';

            printf("Enter address. When done, type a backslash (\\) and then press 'Enter'.\n");
            getaddress(address, sizeof(address));

            addRecord(&start, accountno, name, address);
        }
        else if (strncmp(user_input, "printall", strlen(user_input)) == 0 &&
            strlen(user_input) <= strlen("printall"))
        {
            printAllRecords(start);
        }
        else if (strncmp(user_input, "find", strlen(user_input)) == 0 &&
            strlen(user_input) <= strlen("find"))
        {
            printf("Please enter an account number to find:\n");
            accountno = is_positive_int();

            findRecord(start, accountno);
        }
        else if (strncmp(user_input, "delete", strlen(user_input)) == 0 &&
            strlen(user_input) <= strlen("delete"))
        {
            printf("Enter a positive integer:\n");
            accountno = is_positive_int();

            deleteRecord(&start, accountno);
        }
        else if (strncmp(user_input, "quit", strlen(user_input)) == 0 &&
            strlen(user_input) <= strlen("quit"))
        {
            printf("\n********** EXITING PROGRAM **********\n");
            printf("Thank you for your business.\n");
            printf("*************************************\n\n");
            valid_debug = 0;
        }
        else
        {
            printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

/*****************************************************************
//  
//  Function name: getaddress
//
//  DESCRIPTION:   Accepts user input for their address until
//                 until a backslash (\) is encountered.
//
//  Parameters:    address (char []) : String stored as character array
//                 size (int) : Size of the array
//
//  Return values:  none
//
****************************************************************/

void getaddress(char address[], int size)
{
    int i = 0;
    char c;

    while (i < size - 1 && (c = getchar()) != '\\')
    {
        address[i] = c;
        i++;
    }
    address[i] = '\0';

    /* Clear the input buffer */
    while ((c = getchar()) != '\n' && c != EOF);
}

/*****************************************************************
//  
//  Function name: is_positive_int
//
//  DESCRIPTION:   Checks for a positive integer greather than 0 when
//                 the user enters an account number. Invalid option
//                 asks user to enter a valid number.
//
//  Parameters:    none
//                 
//  Return values:  Input that user gives and returns as an integer value.
//
****************************************************************/

int is_positive_int()
{
    int num;
    char input[50];
    int i;
    int valid_input = 0;  /* Flag to check if input is valid */

    do
    {
        i = 0;
        valid_input = 1;  /* Assume valid input */

        fgets(input, sizeof(input), stdin);

        /* Check if all characters are digits */
        while (input[i] != '\n' && input[i] != '\0' && valid_input)
        {
            if (!isdigit(input[i]) && !(i == 0 && input[i] == '-'))
            {
                printf("ERROR: Invalid input. Only positive integers greater than 0 allowed.\n");
                valid_input = 0;  /* Set flag to invalid */
            }
            i++;
        }

        /* If the loop finishes without breaking, the input is valid */
        if (valid_input && (input[i] == '\n' || input[i] == '\0'))
        {
            num = atoi(input);

            if (num <= 0)
            {
                printf("ERROR: Integer is negative or 0. Enter a non-zero positive integer.\n");
                valid_input = 0;
            }
        }
    }
    while (!valid_input);

    return num;
}
