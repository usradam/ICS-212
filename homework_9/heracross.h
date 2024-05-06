/*****************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    9
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 24, 2024
//
//  FILE:        heracross.h
//
//  DESCRIPTION:
//   Class definition of Heracross.
//
****************************************************************/

#ifndef HERACROSS_H
#define HERACROSS_H

#include "pokemon.h"

class Heracross:public Pokemon
{
public:
    Heracross();
    virtual ~Heracross();
    void printData();
};

#endif
