/*****************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    1
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        January 20, 2024
//
//  FILE:        homework1.c
//
//  DESCRIPTION:
//   A simple loop program, making use of for, while, and do-while to print out a series of messages
//
//
****************************************************************/

#include <stdio.h>

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Starts execution of code and allows expected return of an integer value
//
//  Parameters:    argc (int) : number of arguments
//                 argv (char*[]): array of arguments
//
//  Return values:  0 : success
//
****************************************************************/

int main(int argc, char* argv[])
{
    int num;
    int i;

    for (i = 0; i < 3; i = i + 1)
    {
        if (i < 1)
            printf("Hello\n");
        else if (i < 2)
            printf("World\n");
        else
            printf("!!!\n");
    }

    num = 0;
    while (num < 4)
    {
        printf("While loop!\n");
        num = num + 1;
    }

    num = 0;
    do
    {
        printf("Do-while loop!\n");
        num = num + 1;
    }
    while (num < 3);
    return 0;
}
