/*****************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    8
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 2, 2024
//
//  FILE:        homework8.c
//
//  DESCRIPTION:
//   C++ version of Homework 2. Generates a table of numbers from 0 to a maximum
//   number specified by the user. The table includes a column denoting whether
//   each number is a multiple of 3 or not.
//
****************************************************************/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;
int user_interface();
void is_multiple3(int, int&);
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
    int max = user_interface();
    print_table(max);

    return 0;
}

/*****************************************************************
//
//  Function name: user_interface
//
//  DESCRIPTION:   Prints introductory message explaining the program,
//                 the 'Enter maximum number to show: ' prompt, and the
//                 error messages. It also gets and validates user input
//                 to ensure it is a positive integer, and returns the
//                 validated maximum number.
//
//  Parameters:    None
//
//  Return values:  max_num : Integer representing the validated maximum
//                            number entered by the user.
//
****************************************************************/

int user_interface()
{
    int max_num;
    bool valid_input = false;
    string input;

    cout << "This program generates a number table from 0 to the user-specified maximum." << endl;
    cout << "The table includes a column indicating the numbers that are multiples of 3." << endl;

    while (!valid_input)
    {
        cout << "Enter a maximum number to show:";
        getline(cin, input);

        istringstream ss(input);
        if (ss >> max_num && max_num > 0 && ss.eof())
        {
            valid_input = true;
        }
        else
        {
            cout << "***ERROR: Invalid Input. Please enter a non-zero positive integer***" << endl;
        }
    }
    return max_num;
}

/*****************************************************************
//
//  Function name: is_multiple3
//
//  DESCRIPTION:   Checks whether a given integer is a multiple of 3.
//                 It sets 'isMultiple' to 0 if the integer is a multiple of 3 and
//                 not equal to 0, and sets it to -1 if the integer is not
//                 a multiple of 3 or is 0.
//
//  Parameters:    num (int) : The integer to check for being a
//                             multiple of 3.
//                 isMultiple (int&): A reference to an integer that will be
//                                    set to 0 if 'num' is a non-zero multiple of 3,
//                                    and -1 otherwise.
//
//  Return values:  None
//
****************************************************************/

void is_multiple3(int num, int& isMultiple)
{
    if (num % 3 == 0 && num != 0)
    {
        isMultiple = 0;
    }
    else
    {
        isMultiple = -1;
    }
}

/*****************************************************************
//
//  Function name: print_table
//
//  DESCRIPTION:   Generates and prints a table of numbers from 0 to
//                 the specified maximum number by the user. It also
//                 prints a column denoting whether each number is a
//                 multiple of 3 or not. The function uses the 'is_multiple3'
//                 function to determine if each number is indeed a multiple
//                 of 3.
//
//  Parameters:    max_num (int) : The maximum number specified by
//                                 the user for generating the table.
//
//  Return values:  None
//
****************************************************************/

void print_table(int max_num)
{
    int i;
    int isMultipleOfThree;

    cout << setw(8) << "Number" << setw(18) << "Multiple of 3?" << endl;

    for (i = 0; i <= max_num; i++)
    {
        is_multiple3(i, isMultipleOfThree);
        {
            if (isMultipleOfThree == 0)
            {
                cout << setw(8) << i << setw(7) << "Yes" << endl;
            }
            else if (isMultipleOfThree == -1)
            {
                cout << setw(8) << i << setw(7)  << "No" << endl;
            }
        }
    }
}
