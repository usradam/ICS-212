/******************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 20, 2024
//
//  FILE:        record.h
//
//  DESCRIPTION:
//   Header file for record(s).
//
****************************************************************/

#ifndef RECORD_H
#define RECORD_H

struct record
{
    int                accountno;
    char               name[25];
    char               address[45];
    struct record*     next;
};

#endif
