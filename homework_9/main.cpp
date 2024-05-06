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
//  FILE:        main.cpp
//
//  DESCRIPTION:
//   Create and stores each Pokemon and its associated nickname.
//   Prints the data from the Pokedex.
//
****************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "pokemon.h"
#include "gyarados.h"
#include "heracross.h"
#include "typhlosion.h"

void checkPokedex(Pokemon *pokemon);

using namespace std;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Create and stores each Pokemon and its associated
//                 nickname. Prints the data from the Pokedex.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    // Instances of all the child classes in the heap memory
    // Addresses stored in pointers of Pokemon, i.e., Pokemon*
    Pokemon* gyarados = new Gyarados();
    Pokemon* heracross = new Heracross();
    Pokemon* typhlosion = new Typhlosion();

    // Vector container to store the Pokémon nicknames
    cout << endl << "Creating a vector container that stores the Pokemon nicknames" << endl;
    cout << endl << "===========================================" << endl;
    vector<string> nickname;
    nickname.push_back("Swamp");
    nickname.push_back("Freddy");
    nickname.push_back("Pyro");

    // Map container that stores a Pokémon pointer by its corresponding nickname as a key
    map<string, Pokemon*> pair;
    pair.insert(make_pair(nickname[0], gyarados));
    pair.insert(make_pair(nickname[1], heracross));
    pair.insert(make_pair(nickname[2], typhlosion));

    vector<string>::iterator it;
    for (it = nickname.begin(); it != nickname.end(); it++)
    {
        cout << "Accessing value \"" << *it << "\" in nickname vector." << endl;
        cout << "Accessing key \"" << *it << "\" in pair map." << endl;
        cout << endl << "Nickname: " << *it << endl;
        checkPokedex(pair[*it]);
        cout << endl << "===========================================" << endl;
    }

    // Clean up the heap memory
    cout << endl << "***Cleaning up the heap memory***" << endl;
    delete gyarados;
    delete heracross;
    delete typhlosion;

    return 0;
}

/*****************************************************************
//
//  Function name: checkPokedex
//
//  DESCRIPTION:   Prints the data of each Pokemon.
//
//  Parameters:    pokemon (Pokemon*) : The Pokemon data to print
//
//  Return values: none
//
****************************************************************/

void checkPokedex(Pokemon *pokemon)
{
    pokemon->printData();
}
