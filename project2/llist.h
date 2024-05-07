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
//  FILE:        llist.h
//
//  DESCRIPTION:
//   Header file for the llist.
//
****************************************************************/

#ifndef LLIST_H
#define LLIST_H

#include "record.h"

class llist
{
private:
    record *    start;
    char        filename[20];
    int         readfile();
    int         writefile();
    void        cleanup();

public:
    llist();
    llist(char[]);
    llist(const llist&);
    ~llist();
    int addRecord(int, char[], char[]);
    int findRecord(int);
    void printAllRecords();
    int deleteRecord(int);
    llist& operator=(const llist&);
    friend std::ostream& operator<<(std::ostream&, const llist&);
};

#endif
