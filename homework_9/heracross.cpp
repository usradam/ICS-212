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
//  FILE:        heracross.cpp
//
//  DESCRIPTION:
//   Heracross implementation.
//
****************************************************************/

#include <iostream>
#include "heracross.h"

using namespace std;

/*****************************************************************
//
//  Function name: Heracross
//
//  DESCRIPTION:   The Heracross constructor.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

Heracross::Heracross()
{
    cout << "Heracross Constructor" << endl;
    this->type = "Bug & Fighting";
    this->weight = 119.0;
}

/*****************************************************************
//
//  Function name: ~Heracross
//
//  DESCRIPTION:   The Heracross destructor.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

Heracross::~Heracross()
{
    cout << "Heracross Destructor" << endl;
}

/*****************************************************************
//
//  Function name: Heracross
//
//  DESCRIPTION:   Prints the data of Heracross.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

void Heracross::printData()
{
    cout << "****Heracross (Actual Name) Data****" << endl;
    cout << "Type: " << type << endl;
    cout << "Weight: " << weight << " lbs" << endl;
}
