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
//  FILE:        pokemon.h
//
//  DESCRIPTION:
//   Header file of Pokemon.
//
****************************************************************/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon
{
public:
    Pokemon();
    virtual ~Pokemon();
    virtual void printData() = 0;

protected:
    std::string type;  // e.g., electric, poison, etc
    float weight;
};

#endif
