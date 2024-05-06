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
//  FILE:        pokemon.cpp
//
//  DESCRIPTION:
//   Prints out the Pokemon constructor and destructor.
//
****************************************************************/

#include <iostream>
#include "pokemon.h"

using namespace std;

/*****************************************************************
//
//  Function name: Pokemon
//
//  DESCRIPTION:   The Pokemon constructor.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

Pokemon::Pokemon()
{
    cout << "Pokemon Constructor" << endl;
}

/*****************************************************************
//
//  Function name: ~Pokemon
//
//  DESCRIPTION:   The Pokemon destructor.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

Pokemon::~Pokemon()
{
    cout << "Pokemon Destructor" << endl;
}

/*****************************************************************
//
//  Function name: printData
//
//  DESCRIPTION:   The printData function.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

void Pokemon::printData()
{
}
