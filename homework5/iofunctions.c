/******************************************************************
//  
//  NAME:        Adam Graham
//
//  HOMEWORK:    5
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        Februrary 20, 2024
//
//  FILE:        iofunctions.c
//
//  DESCRIPTION:
//   File for the writefile and readfile functions.
//
****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pokemon.h"

/******************************************************************
//  
//  Function name: writefile
//
//  DESCRIPTION:   Will write the data stored in the array into a text file.
//
//  Parameters:    pokearray (struct pokemon[]) : Pokemon array to write to file.
//                 num (int) : Size of pokemon array.
//                 filename (char[]) : Filename to write to.
//
//  Return values:  0 : Success. File opened.
//                 -1 : Failure.
//
****************************************************************/

int writefile(struct pokemon pokearray[], int num, char filename[])
{
    FILE *outfile;
    int i = 0;
    int contents = 0;
    int result = 0;

    outfile = fopen(filename, "w");
    if (outfile == NULL)
    {
        result = -1;
    }

    for (i = 0; i < num && result == 0; i++)
    {
        contents = fprintf(outfile, "%d\n%s\n", pokearray[i].level, pokearray[i].name);

        if (contents < 0)
        {
            result = -1;
        }
    }

    if (fclose(outfile) == EOF)
    {
        result = -1;
    }
    return result;
}

/******************************************************************
//  
//  Function name: readfile
//
//  DESCRIPTION:   Will read the data from a text file and store it in the
//                 array called by pokearray.
//
//  Parameters:    pokearray (struct pokemon[]) : The array used to write Pokemon
//                                                to the file.
//                 num (int*) : Max number of pokemon. Stores successfully read Pokemon
//                              into num.
//                 filename (char[]) : Filename to write to.
//
//  Return values:  0 : Success. File opened
//                 -1 : Failure
//
****************************************************************/

int readfile(struct pokemon pokearray[], int* num, char filename[])
{
    FILE *infile;
    int i = 0;
    int result = 0;
    int maxPokemon = *num;
    char level[26];
    char name[26];
    char* endptr;

    infile = fopen(filename, "r");
    if (infile == NULL)
    {
        result = -1;
    }
    else
    {
        while (i < maxPokemon && !feof(infile) && result == 0)
        {
            if (fgets(level, sizeof(level), infile) != NULL &&
                fgets(name, sizeof(name), infile) != NULL)
            {
                pokearray[i].level = (int)strtol(level, &endptr, 10);
                if (endptr == level) /* Check if conversion was successful */
                {
                    result = -1;
                }
                else
                {
                    name[strcspn(name, "\n")] = 0;
                    strncpy(pokearray[i].name, name, sizeof(pokearray[i].name) - 1);
                    pokearray[i].name[sizeof(pokearray[i].name) - 1] = '\0';

                    i++;
                }
            }
            else
            {
                result = -1;
            }
        }
        *num = i;

        if (fclose(infile) == EOF)
        {
            result = -1;
        }
    }
    return result;
}
