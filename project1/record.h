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
