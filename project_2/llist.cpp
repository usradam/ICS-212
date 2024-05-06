/******************************************************************
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
//  FILE:        llist.cpp
//
//  DESCRIPTION:
//   Database functions for llist implemented.
//
***************************************************************/

#include <iostream>
#include <fstream>
#include <cstring>
#include "llist.h"

using namespace std;

/******************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   Constructor of the llist.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

llist::llist()
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: llist constructor reached" << endl;
    cout << "********************************" << endl << endl;
#endif

    start = NULL;
    strncpy(filename, "filename", sizeof(filename) - 1);
    readfile();
}

/******************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   Constructor of the llist.
//
//  Parameters:    filename (char[]) : File to write to
//
//  Return values: none
//
****************************************************************/

llist::llist(char filename[])
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: llist constructor reached" << endl;
    cout << "Debug: Filename = " << filename << endl;
    cout << "********************************" << endl << endl;
#endif

    start = NULL;
    strncpy(this->filename, filename, sizeof(this->filename) - 1);
    readfile();
}

/******************************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION:   Destructor of the llist.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

llist::~llist()
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: Destructor called" << endl;
    cout << "********************************" << endl << endl;
#endif

    writefile();
    cleanup();
}

/******************************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   Copy constructor of the llist.
//
//  Parameters:    other (const llist&) : The llist to copy data from
//
//  Return values: none
//
****************************************************************/

llist::llist(const llist& other)
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: Copy constructor called" << endl;
    cout << "********************************" << endl << endl;
#endif

    strncpy(this->filename, other.filename, sizeof(this->filename) - 1);
    this->filename[sizeof(this->filename) - 1] = '\0';

    record* otherNode = other.start;

    while (otherNode != NULL)
    {
        int accountno = otherNode->accountno;
        char name[sizeof(otherNode->name)];
        char address[sizeof(otherNode->address)];

        // Copy data from otherNode
        strncpy(name, otherNode->name, sizeof(name));
        strncpy(address, otherNode->address, sizeof(address));

        // Ensure null termination
        name[sizeof(name) - 1] = '\0';
        address[sizeof(address) - 1] = '\0';

        // Add a new record to this list with the copied data
        this->addRecord(accountno, name, address);

        otherNode = otherNode->next;
    }
}

/******************************************************************
//
//  Function name: operator=
//
//  DESCRIPTION:   Overloads the assignment operator for the llist class.
//
//  Parameters:    other (const llist&) : Other llist to copy the data from
//
//  Return values: Reference to a llist.
//
****************************************************************/

llist& llist::operator=(const llist& other)
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: Assignment operator called" << endl;
    cout << "********************************" << endl << endl;
#endif

    if (this != &other)
    {
        this->cleanup();

        strncpy(this->filename, other.filename, sizeof(this->filename) - 1);
        this->filename[sizeof(this->filename) - 1] = '\0';  // Ensure null termination

        // Pointer to iterate over the other list
        record* copyCurrent = other.start;

        while (copyCurrent != NULL)
        {
            // Add a new record to this list with the copied data
            this->addRecord(copyCurrent->accountno, copyCurrent->name, copyCurrent->address);

            // Move to the next node in the other list
            copyCurrent = copyCurrent->next;
        }
    }
    // Return a reference to this object
    return *this;
}

/******************************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all available records.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

void llist::printAllRecords()
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: printAllRecords called" << endl;
    cout << "********************************" << endl << endl;
#endif

    if (start == NULL)
    {
        cout << "\n***No records are in the database***" << endl;
    }
    else
    {
        for (struct record* current = start; current != NULL; current = current->next)
        {
            cout << "Accountno: " << current->accountno << "\nName: " << current->name
            << "\nAddress: " << current->address << "\n" << endl;
        }
    }
}

/******************************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   Overload the << operator to print the contents
//                 of the entire database so that it replaces the
//                 function call of printAllRecords in the user-interface.
//
//  Parameters:    output (ostream&) : The ostream to write data of llist to.
//                 linkedList (const llist&) : Other llist to copy data from.
//
//  Return values: Reference to ostream.
//
****************************************************************/

ostream& operator<<(ostream& output, const llist& linkedList)
{
    if (linkedList.start == NULL)
    {
        output << "\n***No records are in the database***" << endl;
    }
    else
    {
        for (struct record *current = linkedList.start; current != NULL; current = current->next)
        {
            output << "Accountno: " << current->accountno << "\nName: " << current->name
            << "\nAddress: " << current->address << "\n" << endl;
        }
    }
    return output;
}

/******************************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds new record to the list.
//
//  Parameters:    accountno (int) : Account number to be added
//                 name (char[]) : Name to be added
//                 address (char[]) : Address to be added
//
//  Return values: 0 : Success
//                -1 : Could not add record
//
****************************************************************/

int llist::addRecord(int accountno, char name[], char address[])
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: addRecord called" << endl;
    cout << "Debug: accountno = " << accountno << endl;
    cout << "Debug: name = " << name << endl;
    cout << "Debug: address = " << address << endl;
    cout << "********************************" << endl << endl;
#endif

    struct record* current = start;
    struct record* previous = NULL;
    struct record* newRecord;
    int returnVal = 0;

    while (current != NULL && current->accountno < accountno)
    {
        previous = current;
        current = current->next;
    }
    if (current != NULL && current->accountno == accountno)
    {
        returnVal = -1;
    }
    else
    {
        newRecord = new record;
        newRecord->accountno = accountno;
        strncpy(newRecord->name, name, 25);
        strncpy(newRecord->address, address, 45);

        if (previous == NULL)
        {
            newRecord->next = start;
            start = newRecord;
        }
        else
        {
            newRecord->next = previous->next;
            previous->next = newRecord;
        }
    }
    return returnVal;
}

/******************************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds the record of a specified account number.
//
//  Parameters:    accountno (int) : Account number to find
//
//  Return values: 0 : Record not found
//                 1 : Record found
//
****************************************************************/

int llist::findRecord(int accountno)
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: findRecord called." << endl;
    cout << "Debug: Record = " << accountno << endl;
    cout << "********************************\n" << endl;
#endif

    struct record* temp = start;
    int found = 0;

    if (start != NULL && found == 0)
    {
        while (temp != NULL && !found)
        {
            if (temp->accountno == accountno)
            {
                cout << "\n***Found record with accountno: " << accountno << "***" << endl;
                cout << "Accountno: " << temp->accountno << "\nName: " << temp->name
                << "\nAddress: " << temp->address << "\n" << endl;
                found = 1;
            }
            temp = temp->next;
        }
    }
    if (!found)
    {
        cout << "\n***Record does not exist***" << endl;
    }
    return found;
}

/*******************************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Deletes record of a specified account number.
//
//  Parameters:    accountno (int) : Account number to delete.
//
//  Return values:  0 : Success. Record deleted
//                 -1 : Failure to delete record
//
****************************************************************/

int llist::deleteRecord(int accountno)
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: deleteRecord called" << endl;
    cout << "Debug: Deleted record = " << accountno << endl;
    cout << "********************************" << endl << endl;
#endif

    struct record* temp = start;
    struct record* temp_prev = NULL;
    int return_val = -1;
    int found = 0;

    if (start != NULL)
    {
        if (temp->accountno == accountno && found == 0)
        {
            start = temp->next;
            delete temp;
            cout << "\n***Success! Deleted accountno " << accountno << "***\n";
            return_val = 0;
            found = 1;
        }
        else
        {
            while (temp->next != NULL && found == 0)
            {
                temp_prev = temp;
                temp = temp->next;
                if (temp->accountno == accountno && found == 0)
                {
                    temp_prev->next = temp->next;
                    delete temp;
                    cout << "\n***Success! Deleted accountno " << accountno << "***" << endl;
                    return_val = 0;
                    found = 1;
                }
            }
        }
    }
    if (found == 0)
    {
        cout << "***Record with account number " << accountno << " does not exist.***" << endl;
    }
    return return_val;
}

/*******************************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes linked list data of account numbers to a file.
//
//  Parameters:    none
//
//  Return values:  0 : Success
//                 -1 : Unsuccessful write to the file
//
****************************************************************/

int llist::writefile()
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: writefile called. Saving records to file." << endl;
    cout << "Debug: Filename = " << filename << endl;
    cout << "********************************" << endl << endl;
#endif

    int result = 0;

    ofstream outfile(filename);
    if (!outfile)
    {
        cout << "Could not write to file" << endl;
        result = -1;
    }

    for (record* current = start; current != NULL; current = current->next)
    {
        outfile << current->accountno << "\n" << current->name << "\n"
        << current->address<< "\\\n";
        if (!outfile)
        {
            result = -1;
        }
    }
    outfile.close();
    if (!outfile)
    {
        result = -1;
    }
    return result;
}

/*******************************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Retrieves records from saved file and transfers to database.
//
//  Parameters:    none
//
//  Return values:  0 : Success
//                 -1 : Unsuccessful read from file
//
****************************************************************/

int llist::readfile()
{
#ifdef DEBUG
    cout << "\n********** DEBUG MODE **********" << endl;
    cout << "Debug: readfile called. Reading from the database." << endl;
    cout << "Debug: Filename = " << filename << endl;
    cout << "********************************" << endl << endl;
#endif

    ifstream infile(filename);
    unsigned int i;
    int accountno;
    char name[26];
    char address[46];
    int result = 0;  // Initialize result to 0

    if (!infile)
    {
        cout << "No existing file found. A new file will be created when data is saved.\n";
        result = -1;
    }
    else
    {
        bool done = false;

        while (!done)
        {
            infile >> accountno;
            infile.ignore();
            infile.getline(name, sizeof(name));
            bool done_address = false;

            for (i = 0; i < sizeof(address) && !done_address; i++)
            {
                char address_buffer = infile.get();

                if (address_buffer == '\\')
                {
                    address[i] = '\0';
                    infile.get();
                    done_address = true;
                }
                else if (infile.eof())
                {
                    address[i] = '\0';
                    done = true;
                }
                else
                {
                    address[i] = address_buffer;
                }
            }
            if (!done)
            {
                addRecord(accountno, name, address);
            }
        }
    }
    return result;
}

/*******************************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Cleans up memory from the database.
//
//  Parameters:    none
//
//  Return values: none
//
****************************************************************/

void llist::cleanup()
{
#ifdef DEBUG
    cout << "********** DEBUG MODE **********" << endl;
    cout << "Debug: cleanup called. Cleaning memory from the database." << endl;
    cout << "********************************\n" << endl;
#endif

    struct record* current;
    struct record* toDelete;

    if (start == NULL)
    {
        cout << "***No records are in the database***" << endl;
    }
    else
    {
        for (current = start; current != NULL;)
        {
            toDelete = current;
            current = current->next;
            delete toDelete;
        }
        start = NULL;
    }
}
