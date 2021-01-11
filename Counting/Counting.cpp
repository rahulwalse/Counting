/*Counting.cpp : This file contains the 'main' function. Program execution begins and ends there.*/
/*
    Program for counting, like counting passed students, negative and non-negative numbers using methods. This 
    program is an implementation in C++ of algorithm for interchanging the values from the book "How to Solve 
    it by Computer" by R.G. Dromey.
*/

#include <iostream>
#include "countingf.h"
using namespace std;
const int FIRSTOPTION = 1, LASTOPTION = 3;

int main()
{
    /*Declaring the variables to determine choice and to check if the user wants to continue.*/
    int choice; char conti;

    do
    {
        /*Provide the selection of different counting operations to the user.*/
        cout << "\nSelect the count operations from the following\n1. Count the number of passed students\n2. Count negative and non-negative numbers";
        cout << "\n3. Count the number of passed students (by initializing passed count to total number of students)\nEnter your choice:" << endl;
        cin >> choice;

        /*Check whether the choice is valid. If it is not valid, exit the program.*/
        if (choice < FIRSTOPTION || choice > LASTOPTION)
        {
            cout << "\nYour choice is invalid... exiting the program." << endl;
            return 0;
        }

        /*The choice is valid then continue executing the program.*/
        else
        {
            /*Switch and call the function according to the choice.*/
            switch (choice)
            {
            case 1: PassedStudentsCount();
                    break;
            case 2: NegativeNonNegativeCount();
                    break;
            case 3: FailedStudentsCount();
                    break;
            }
        }
        /*Check if the user wants to exit or select another operation.*/
        cout << "\nDo you want to perform different counting operation? (Y/N)" << endl;
        cin >> conti;
    } while (conti == 'Y' || conti == 'y');
}