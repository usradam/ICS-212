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
//  FILE:        typhlosion.h
//
//  DESCRIPTION:
//   Class definition of Typhlosion.
//
****************************************************************/

#ifndef TYPHLOSION_H
#define TYPHLOSION_H

#include "pokemon.h"

class Typhlosion:public Pokemon
{
public:
    Typhlosion();
    virtual ~Typhlosion();
    void printData();
};

#endif
