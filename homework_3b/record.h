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
//  FILE:        record.h
//
//  DESCRIPTION:
//   Header file for record(s).
//
****************************************************************/

struct record
{
    int                accountno;
    char               name[25];
    char               address[45];
    struct record*     next;
};
