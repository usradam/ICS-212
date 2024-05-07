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
//  FILE:        database.h
//
//  DESCRIPTION:
//   Header file for the database.
//
****************************************************************/

int addRecord(struct record **, int, char[], char[]);
void printAllRecords(struct record *);
int findRecord(struct record *, int);
int deleteRecord(struct record **, int);
