/******************************************************************
// 
//  NAME: Adam Graham
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        March 1, 2024
//
//  FILE:        driver.c
//
//  DESCRIPTION: 
//   Driver code to test the writefile and readfile functions
//   to show that they work.
//
****************************************************************/

#include <string.h>
#include <stdio.h>
#include "pokemon.h"
#include "iofunctions.h"

/******************************************************************
// 
//  Function name: main 
//
//  DESCRIPTION:   Tests the writefile and readfile functions from
//                 iofunctions.c to show that they work.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                 to the program.
//
//  Return values:  0 : End of program reached. Success.
//
****************************************************************/

int main(int argc, char *argv[])
{
    struct pokemon pokemonbank[6];
    struct pokemon largerPokemonBank[7];
    int numpokemons;
    int i;
    int result;
    char filename[25] = "PokemonList.txt";

    printf("\nWelcome, Trainer! This is Professor Oak's Pokemon bank.\n");
    printf("The bank stores Pokemon and their level.\n");
    printf("****************NOTE: The following data is hardcoded.****************\n\n");

    printf("****************TEST 1 (Part 1): writefile FUNCTION****************\n");
    printf("<<<Tests if the writefile function will write the data stored in the array"
    " into a text file>>>\n");
    numpokemons = 3;

    strcpy(pokemonbank[0].name, "Pikachu");
    pokemonbank[0].level = 15;

    strcpy(pokemonbank[1].name, "Charizard");
    pokemonbank[1].level = 36;

    strcpy(pokemonbank[2].name, "Bulbasaur");
    pokemonbank[2].level = 16;

    printf("<<<Pokemon array data containing 3 Pokemon>>>: \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("%s lvl. %d\n", pokemonbank[i].name, pokemonbank[i].level);
    }
    printf("\n");

    printf("FUNCTION CALLED: writefile. Writing to \"%s\"\n", filename);
    result = writefile(pokemonbank, numpokemons, filename);
    printf("writefile returned %d\n", result);
    if (result == 0)
    {
        printf("SUCCESS! Wrote to the file \"%s\"\n", filename);
    }
    else
    {
        printf("ERROR: Occurred when writing to file \"%s\"\n", filename);
    }
    printf("****************END OF TEST 1 (Part 1)****************\n");

    printf("\n****************TEST 1 (Part 2): readfile FUNCTION****************\n");
    printf("<<<Testing whether the readfile will read the data from a text file and store"
    " it in the array called by pokearray.>>>\n");
    for (i = 0; i < numpokemons; i++)
    {
        strncpy(pokemonbank[i].name, "", 30);
        pokemonbank[i].level = 0;
    }
    printf("<<<Pokemon array data before reading from the file>>>: \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("%d\n%s\n", pokemonbank[i].level, pokemonbank[i].name);
    }
    printf("\n");

    printf("FUNCTION CALLED: readfile\n");
    result = readfile(pokemonbank, &numpokemons, filename);
    printf("readfile returned %d\n", result);
    if (result == 0)
    {
        printf("SUCCESS! Read from file \"%s\"\n", filename);
        printf("\nPokemon array data after reading from file: \n");
        for (i = 0; i < numpokemons; i++)
        {
            printf("%d\n%s\n", pokemonbank[i].level, pokemonbank[i].name);
        }
    }
    else
    {
        printf("ERROR: Occurred when reading from file \"%s\"\n\n", filename);
    }
    printf("****************END OF TEST 1 (Part 2)****************\n");

    printf("\n****************TEST 2 (Part 1): writefile WITH 7 POKEMON****************\n");
    printf("<<<Testing if writefile function will overwrite the previous file\n");
    printf("with a different set of Pokemon (from largerPokemonBank[7])>>>\n");
    numpokemons = 7;

    strcpy(largerPokemonBank[0].name, "Rampardos");
    largerPokemonBank[0].level = 15;

    strcpy(largerPokemonBank[1].name, "Bronzong");
    largerPokemonBank[1].level = 36;

    strcpy(largerPokemonBank[2].name, "Garchomp");
    largerPokemonBank[2].level = 16;

    strcpy(largerPokemonBank[3].name, "Lucario");
    largerPokemonBank[3].level = 12;

    strcpy(largerPokemonBank[4].name, "Greninja");
    largerPokemonBank[4].level = 14;

    strcpy(largerPokemonBank[5].name, "Talonflame");
    largerPokemonBank[5].level = 38;

    strcpy(largerPokemonBank[6].name, "Psyduck");
    largerPokemonBank[6].level = 70;

    printf("<<<Pokemon array data containing 7 Pokemon>>>: \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("%s lvl. %d\n", largerPokemonBank[i].name, largerPokemonBank[i].level);
    }
    printf("\n");

    printf("FUNCTION CALLED: writefile. Writing to \"%s\"\n", filename);

    result = writefile(largerPokemonBank, numpokemons, filename);

    printf("writefile returned %d\n", result);

    if (result == 0)
    {
        printf("SUCCESS! Wrote to the file \"%s\"\n", filename);
    }
    else
    {
        printf("ERROR: Occurred when writing to file \"%s\"\n", filename);
    }
    printf("****************END OF TEST 2 (Part 1)****************\n");

    printf("\n****************TEST 2 (Part 2): readfile****************\n");
    printf("<<<Testing readfile will store all the Pokemon the array can hold "
    "(largerPokemonBank[7])>>>\n");
    for (i = 0; i < 7; i++)
    {
        strncpy(largerPokemonBank[i].name, "", 30);
        largerPokemonBank[i].level = 0;
    }
    printf("<<<Pokemon array data before reading from file>>>: \n");
    for (i = 0; i < 7; i++)
    {
        printf("%d\n%s\n", largerPokemonBank[i].level, largerPokemonBank[i].name);
    }
    printf("\n");

    printf("FUNCTION CALLED: readfile \n");
    result = readfile(largerPokemonBank, &numpokemons, filename);
    printf("readfile returned %d\n", result);
    if (result == 0)
    {
        printf("SUCCESS! Read from the file \"%s\"\n", filename);
        printf("\nPokemon array data after reading from the file: \n");
        for (i = 0; i < numpokemons; i++)
        {
            printf("%d\n%s\n", largerPokemonBank[i].level, largerPokemonBank[i].name);
        }
    }
    else
    {
        printf("ERROR: Occurred when reading from the file \"%s\"\n\n", filename);
    }

    printf("****************END OF TEST 2 (Part 2)****************\n");

    printf("\n****************TEST 3 (Part 1): writefile WITH 6 POKEMON****************\n");
    printf("<<<Testing whether the writefile function will overwrite the previous file "
    "with another set of Pokemon (from pokemonbank[6])>>>\n");

    numpokemons = 6;

    strcpy(pokemonbank[0].name, "Clefable");
    pokemonbank[0].level = 15;

    strcpy(pokemonbank[1].name, "Doduo");
    pokemonbank[1].level = 36;

    strcpy(pokemonbank[2].name, "Raichu");
    pokemonbank[2].level = 16;

    strcpy(pokemonbank[3].name, "Beedrill");
    pokemonbank[3].level = 12;

    strcpy(pokemonbank[4].name, "Sandslash");
    pokemonbank[4].level = 14;

    strcpy(pokemonbank[5].name, "Skarmory");
    pokemonbank[5].level = 38;

    printf("<<<Pokemon array data containing 6 Pokemon>>>: \n");
    for (i = 0; i < numpokemons; i++)
    {
        printf("%s lvl. %d\n", pokemonbank[i].name, pokemonbank[i].level);
    }
    printf("\n");

    printf("FUNCTION CALLED: writefile. Writing to \"%s\"\n", filename);
    result = writefile(pokemonbank, numpokemons, filename);
    printf("writefile returned %d\n", result);
    if (result == 0)
    {
        printf("SUCCESS! Wrote to the file \"%s\"\n", filename);
    }
    else
    {
        printf("ERROR: Occurred when writing to file \"%s\"\n", filename);
    }
    printf("****************END OF TEST 3 (Part 1)****************\n");

    printf("\n****************TEST 3 (Part 2): readfile****************\n");
    printf("<<<Testing that readfile will store all the Pokemon the array can hold "
    "(pokemonbank[6] max)>>>\n");
    for (i = 0; i < 6; i++)
    {
        strncpy(pokemonbank[i].name, "", 30);
        pokemonbank[i].level = 0;
    }
    printf("<<<Pokemon array data before reading from file>>>: \n");
    for (i = 0; i < 6; i++)
    {
        printf("%d\n%s\n", pokemonbank[i].level, pokemonbank[i].name);
    }
    printf("\n");

    printf("FUNCTION CALLED: readfile \n");
    result = readfile(pokemonbank, &numpokemons, filename);
    printf("readfile returned %d\n", result);
    if (result == 0)
    {
        printf("SUCCESS! Read from file \"%s\"\n", filename);
        printf("\nPokemon array data after reading from the file: \n");
        for (i = 0; i < numpokemons; i++)
        {
            printf("%d\n%s\n", pokemonbank[i].level, pokemonbank[i].name);
        }
    }
    else
    {
        printf("ERROR: Occurred when reading from the file \"%s\"\n\n", filename);
    }

    printf("****************END OF TEST 3 (Part 2)****************\n");

    return 0;
}
