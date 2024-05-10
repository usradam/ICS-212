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
//  FILE:        homework10.java
//
//  DESCRIPTION:
//   The user interface in Java.
//
****************************************************************/

import java.util.Scanner;

public class homework10
{
    static
    {
        System.loadLibrary("homework10");
    }

    /*****************************************************************
    //
    //  Function name: main
    //
    //  DESCRIPTION:   Calls the 'user_interface' function to get the maximum
    //                 number from the user and calls the 'print_table' function
    //                 to generate and print a table of numbers from 0 to the
    //                 specified maximum.
    //
    //  Parameters:    args (String[]) : command line argument array
    //
    //  Return values: none
    //
    ****************************************************************/

    public static void main(String[] args)
    {
        int max = user_interface();
        print_table(max);
    }

    private static native int is_multiple3(int num);

    /*****************************************************************
    //
    //  Function name: user_interface
    //
    //  DESCRIPTION:   Prints introductory message explaining the program,
    //                 the 'Enter maximum number to show:' prompt, and the
    //                 error messages. It also gets and validates user input
    //                 to ensure it is a positive integer and returns the
    //                 validated maximum number.
    //
    //  Parameters:    none
    //
    //  Return values: maxNum : Integer which represents the validated maximum
    //                          number entered by the user.
    //
    ****************************************************************/

    private static int user_interface()
    {
        int maxNum = 0;
        boolean validInput = false;
        Scanner scanner = new Scanner(System.in);

        System.out.println("This program generates a table of numbers from 0 to the user-specified maximum.");
        System.out.println("The table includes a column indicating the numbers that are multiples of 3.");

        while (!validInput)
        {
            System.out.println("Enter a maximum number to show:");
            String input = scanner.nextLine();

            try
            {
                maxNum = Integer.parseInt(input);
                if (maxNum > 0)
                {
                    validInput = true;
                }
                else
                {
                    System.out.println("***ERROR: Invalid Input. Please enter a non-zero positive integer***");
                }
            }
            catch (NumberFormatException e)
            {
                System.out.println("***ERROR: Invalid Input. Please enter a non-zero positive integer***");
	    }
        }
        return maxNum;
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
    //  Parameters:    maxNum (int) : The maximum number specified by
    //                                 the user for generating the table.
    //
    //  Return values: none
    //
    ****************************************************************/

    private static void print_table(int maxNum)
    {
        int i;

        System.out.printf("%8s %16s%n", "Number", "Multiple of 3?");

        for (i = 0; i <= maxNum; i++)
        {
            if(is_multiple3(i) == 1)
            {
                System.out.printf("%8d %4s%n", i, "Yes");
            }
            else
            {
                System.out.printf("%8d %4s%n", i, "No");
            }
        }
    }
}
