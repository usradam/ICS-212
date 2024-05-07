/*****************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    10
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 28, 2024
//
//  FILE:        homework10.c
//
//  DESCRIPTION:
//   The library for C. Checks whether a user-given integer is a
//   multiple of 3.
//
****************************************************************/

#include <stdio.h>
#include "homework10.h"

/*****************************************************************
//
//  Function name: Java_homework10_is_1multiple3
//
//  DESCRIPTION:   Checks whether a given integer is a multiple of 3.
//                 It returns 1 if the integer is a multiple of 3 and
//                 not equal to 0, and returns 0 if the integer is not
//                 a multiple of 3.
//
//  Parameters:    env (JNIEnv*) : The Java environment
//                 homework10 (jclass) : The class using the method
//                 num (jint) : A Java integer to check if it is a
//                              multiple of 3.
//
//  Return values:  1 : Integer is a multiple of 3 and not equal to 0.
//                  0 : Integer is not a multiple of 3.
//
****************************************************************/

JNIEXPORT jint JNICALL Java_homework10_is_1multiple3(JNIEnv *env, jclass homework10, jint num)
{
    int return_val;

    if (num % 3 == 0 && num != 0)
    {
        return_val = 1;
    }
    else
    {
        return_val = 0;
    }
    return return_val;
}
