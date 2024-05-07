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
//  FILE:        gyarados.cpp
//
//  DESCRIPTION:
//   Gyarados implementation.
//
****************************************************************/

#include <iostream>
#include "gyarados.h"

using namespace std;

/*****************************************************************
//
//  Function name: Gyarados
//
//  DESCRIPTION:   The Gyarados constructor.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

Gyarados::Gyarados()
{
    cout << "Gyarados Constructor" << endl;
    this->type = "Water & Flying";
    this->weight = 518.1;
}

/*****************************************************************
//
//  Function name: ~Gyarados
//
//  DESCRIPTION:   The Gyarados destructor.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

Gyarados::~Gyarados()
{
    cout << "Gyarados Destructor" << endl;
}

/*****************************************************************
//
//  Function name: printData
//
//  DESCRIPTION:   Prints the data of Gyarados.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

void Gyarados::printData()
{
    cout << "****Gyarados (Actual Name) Data****" << endl;
    cout << "Type: " << type << endl;
    cout << "Weight: " << weight << " lbs" << endl;
}
