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
//  FILE:        gyarados.h
//
//  DESCRIPTION:
//   Class definition of Gyarados.
//
****************************************************************/

#ifndef GYARADOS_H
#define GYARADOS_H

#include "pokemon.h"

class Gyarados:public Pokemon
{
public:
    Gyarados();
    virtual ~Gyarados();
    void printData();
};

#endif
