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
//  FILE:        typhlosion.cpp
//
//  DESCRIPTION:
//   Typhlosion implementation.
//
****************************************************************/

#include <iostream>
#include "typhlosion.h"

using namespace std;

/*****************************************************************
//
//  Function name: Typhlosion
//
//  DESCRIPTION:   The Typhlosion constructor.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

Typhlosion::Typhlosion()
{
    cout << "Typhlosion Constructor" << endl;
    this->type = "Fire";
    this->weight = 175.3;
}

/*****************************************************************
//
//  Function name: ~Typhlosion
//
//  DESCRIPTION:   The Typhlosion destructor.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

Typhlosion::~Typhlosion()
{
    cout << "Typhlosion Destructor" << endl;
}

/*****************************************************************
//
//  Function name: Typhlosion
//
//  DESCRIPTION:   Prints the data of Typhlosion.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

void Typhlosion::printData()
{
    cout << "****Typhlosion (Actual Name) Data****" << endl;
    cout << "Type: " << type << endl;
    cout << "Weight: " << weight << " lbs" << endl;
}
