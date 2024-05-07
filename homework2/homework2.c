/*****************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        January 21, 2024
//
//  FILE:        homework2.c
//
//  DESCRIPTION:
//   Generates a table of numbers from 0 to a maximum number specified
//   by the user. The table includes a column denoting whether each number 
//   is a multiple of 3 or not. 
//
****************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int user_interface();
int is_multiple3(int);
void print_table(int);

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Calls the 'user_interface' function to get the maximum
//                 number from the user and calls the 'print_table' function
//                 to generate and print a table of numbers from 0 to the
//                 specified maximum.
//                 
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : Success
//
****************************************************************/

int main(int argc, char* argv[])
{
    int maximum = user_interface();
    print_table(maximum);

    return 0;
}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION: Prints introductory message explaining the program,
//               the 'Enter maximum number to show: ' prompt, and the 
//               error messages. It also gets and validates user input
//               to ensure it is a positive integer, and returns the 
//               validated maximum number.          
//
//  Parameters:    None : None
//
//  Return values:  max_num : Integer representing the validated maximum
//                            number entered by the user.               
//
****************************************************************/

int user_interface()
{
    int max_num;
    char input[50];
    int i;
    int valid_input = 0;  /* Flag to check if input is valid */

    printf("This program generates a table of numbers from 0 to the user-specified maximum.");
    printf(" The table includes a column indicating the numbers that are multiples of 3.\n");

    do
    {
        i = 0;

        valid_input = 1;  /* Assume valid input */

        printf("Enter maximum number to show: ");
        fgets(input, sizeof(input), stdin);

        /* Check if all characters are digits */
        while (input[i] != '\n' && input[i] != '\0' && valid_input)
        {
            if (!isdigit(input[i]) && !(i == 0 && input[i] == '-'))
            {
                printf("ERROR: Input is not a number. Please enter a positive integer.\n");
                valid_input = 0;  /* Set flag to invalid */
            }
            i++;
        }

        /* If the loop finishes without breaking, the input is valid */
        if (valid_input && (input[i] == '\n' || input[i] == '\0'))
        {
            max_num = atoi(input);

            if (max_num <= 0)
            {
                printf("ERROR: Negative integer or is 0. Enter a non-zero positive integer.\n");
                valid_input = 0;
            }
        }
    }
    while (!valid_input);

    return max_num;
}

/*****************************************************************
//
//  Function name: is_multiple3
//  
//  DESCRIPTION:   Checks whether a given integer is a multiple of 3.
//                 It returns 1 if the integer is a multiple of 3 and
//                 not equal to 0, and returns 0 if the integer is not
//                 a multiple of 3.                 
//
//  Parameters:    num (int) : The integer to check for being a 
//                             multiple of 3.                            
//
//  Return values:  1 : Integer is a multiple of 3 and not equal to 0.
//                  0 : Integer is not a multiple of 3.
//
****************************************************************/

int is_multiple3(int num)
{
    int return_val;

    if (num % 3 == 0 && num != 0)
    {
        return_val = 1;
    }
    else if (num == 0 || !num % 3 == 0)
    {
        return_val = 0;
    }
    return return_val;
}

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION: Generates and prints a table of numbers from 0 to 
//               the specified maximum number by the user. It also 
//               prints a column denoting whether each number is a 
//               multiple of 3 or not. The function uses the 'is_multiple3'
//               function to determine if each number is indeed a multiple
//               of 3.
//              
//  Parameters:    max_num (int) : The maximum number specified by
//                                 the user for generating the table.
//
//  Return values:  None : None               
//
****************************************************************/

void print_table(int max_num)
{
    int i;

    printf("%8s %16s\n", "Number", "Multiple of 3 ?");

    for (i = 0; i <= max_num; i++)
    {
        if (is_multiple3(i) == 1)
        {
            printf("%8d %4s\n", i, "Yes");
        }
        else
        {
            printf("%8d %4s\n", i, "No");
        }
    }
}
