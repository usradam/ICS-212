/******************************************************************
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
//  FILE:        database.c
//
//  DESCRIPTION:
//   Stubs for the database functions.
//
***************************************************************/

#include <stdio.h>
#include "record.h"
#include "database.h"

extern int debug_mode;

/******************************************************************
//  
//  Function name: addRecord
//
//  DESCRIPTION:   Adds new record to the list.
//               
//  Parameters:    start (struct record **) : Pointer to the pointer
//                                            of the first record.
//                 accountno (int) : Account number to be added.
//                 name (char []) : Name to be added.
//                 address (char []) : Address to be added.
//
//  Return values:  0 : success
//
****************************************************************/

int addRecord(struct record **start, int accountno, char name[], char address[])
{
    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: addRecord called.\n");
        printf("Debug: accountno = %d\n", accountno);
        printf("Debug: name = %s\n", name);
        printf("Debug: address = %s\n", address);
        printf("********************************\n\n");
    }
    return 0;
}

/*******************************************************************
//  
//  Function name: printAllRecrods
//
//  DESCRIPTION:   Prints all records.
//
//  Parameters:    start (struct record *) : Pointer to the first record.
//
//  Return values:  none
//
****************************************************************/

void printAllRecords(struct record *start)
{
    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: printAllRecords called.\n");
        printf("********************************\n\n");
    }
}

/******************************************************************
//  
//  Function name: findRecord
//
//  DESCRIPTION:   Finds record with account number.
//
//  Parameters:    start (struct record *) : pointer to the first record.
//                 accountno (int) : Account number to find.
//
//  Return values:  0 : success
//
****************************************************************/

int findRecord(struct record *start, int accountno)
{
    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: findRecord called.\n");
        printf("Debug: Record = %d\n", accountno);
        printf("********************************\n\n");
    }
    return 0;
}

/*******************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Deletes record with specified account number.
//
//  Parameters:    start (record **) : Pointer to the pointer of the
//                                     first record.
//                 accountno (int) : Account number to delete.
//
//  Return values:  0 : success
//
****************************************************************/

int deleteRecord(struct record **start, int accountno)
{
    if (debug_mode == 1)
    {
        printf("\n********** DEBUG MODE **********\n");
        printf("Debug: deleteRecord called.\n");
        printf("Debug: Deleted record = %d\n", accountno);
        printf("********************************\n\n");
    }
    return 0;
}
