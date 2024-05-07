/*****************************************************************
//
//  NAME:        Adam Graham
//
//  HOMEWORK:    Project 2
//
//  CLASS:       ICS 212
//
//  INSTRUCTOR:  Ravi Narayan
//
//  DATE:        April 20, 2024
//
//  FILE:        user_interface.cpp
//
//  DESCRIPTION:
//   User interface for the database. Allows the user the following
//   options when accessing the database: add, printall, find,
//   delete, quit.
//
****************************************************************/

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include "llist.h"

void getaddress(char[], int);
int isPositiveInt();

using namespace std;

/*****************************************************************
//
//  Function name: main
//
//  DESCRIPTION:   Gives the user the following options for accessing
//                 the database: add, printall, find, delete, quit.
//
//  Parameters:    argc (int) : The number of elements in argv
//                 argv (char*[]) : An array of arguments passed
//                                  to the program.
//
//  Return values:  0 : success
//
****************************************************************/

int main()
{
    char userInput[100];
    char name[25];
    char address[45];
    int accountno;
    bool valid = true;
    char filename[] = "SaveFileData.txt";
    llist myList(filename);

#ifdef DEBUG
    cout << "\n*******************" << endl;
    cout << "DEBUG MODE ENABLED." << endl;
    cout << "*******************\n" << endl;
#endif

    while (valid)
    {
        cout << "\nThis program accesses a database to add, print, find, and delete items." << endl;
        cout << "\nType and enter one of the following menu options below:" << endl;
        cout << "add: Adds record to database." << endl;
        cout << "printall: Prints all available records." << endl;
        cout << "find: Finds a specific record." << endl;
        cout << "delete: Deletes specific record." << endl;
        cout << "quit: Exits the program." << endl;

        cin.getline(userInput, sizeof(userInput));

        if (strncmp(userInput, "add", strlen(userInput))  == 0)
        {
            cout << "Please enter an account number:" << endl;
            accountno = isPositiveInt();

            cout << "Enter a name:" << endl;
            cin.getline(name, sizeof(name));

            cout << "Enter address. When done, type a backslash (\\) and press 'Enter'." << endl;
            getaddress(address, sizeof(address));

            myList.addRecord(accountno, name, address);
            cout << "\n***Success! Added to database***" << endl;
        }
        else if (strncmp(userInput, "printall", strlen(userInput)) == 0)
        {
            cout << "\n***Printing all records***" << endl;
            cout << myList;
        }
        else if (strncmp(userInput, "find", strlen(userInput)) == 0)
        {
            cout << "Please enter an account number to find:" << endl;
            accountno = isPositiveInt();

            myList.findRecord(accountno);
        }
        else if (strncmp(userInput, "delete", strlen(userInput)) == 0)
        {
            cout << "Enter a positive integer:" << endl;
            accountno = isPositiveInt();

            myList.deleteRecord(accountno);
        }
        else if (strncmp(userInput, "quit", strlen(userInput)) == 0)
        {
            cout << "\n********** EXITING PROGRAM **********" << endl;
            cout << "Thank you for your business." << endl;
            cout << "*************************************\n" << endl;
            valid = false;
        }
        else
        {
            cout << "***Invalid option. Please try again.***" << endl;
        }
    }
    return 0;
}

/*****************************************************************
//
//  Function name: getaddress
//
//  DESCRIPTION:   Accepts user input for their address until
//                 until a backslash (\) is encountered.
//
//  Parameters:    address (char[]) : String stored as character array
//                 size (int) : Size of the string
//
//  Return values:  none
//
****************************************************************/

void getaddress(char address[], int size)
{
    cin.getline(address, size, '\\');
    cin.ignore(100, '\n');
}

/*****************************************************************
//
//  Function name: isPositiveInt
//
//  DESCRIPTION:   Checks for a positive integer greater than 0 when
//                 the user enters an account number. Invalid option
//                 asks user to enter a valid number.
//
//  Parameters:    none
//
//  Return values: Positive integer greater than 0 the user gives.
//
****************************************************************/

int isPositiveInt()
{
    int max_num;
    bool valid_input = false;
    string input;

    while (!valid_input)
    {
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
