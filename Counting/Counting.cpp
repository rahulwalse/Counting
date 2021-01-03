// Counting.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Program for performing different counting operations.

#include <iostream>
using namespace std;
const int FirstChoice = 1, LastChoice = 3;

void PassedStudentsCount();
void NegativeNonNegativeNumbersCount();
void FailedStudentsCount();

int main()
{
    //Declaring the variables to determine choice and to check if the user wants to continue.
    int choice; char conti;

    do
    {
        //Provide the selection of different counting operations to the user.
        cout << "\nSelect the count operations from the following\n1. Count the number of passed students\n2. Count negative and non-negative numbers";
        cout << "\n3. Count the number of passed students (by initializing passed count to total number of students)\nEnter your choice:" << endl;
        cin >> choice;

        //Check whether the choice is valid. If it is not valid, exit the program.
        if (choice < FirstChoice or choice > LastChoice)
        {
            cout << "\nYour choice is invalid... exiting the program." << endl;
            return 0;
        }

        //The choice is valid then continue executing the program.
        else
        {
            switch (choice) //Switch and call the function according to the choice.
            {
            case 1: PassedStudentsCount();
                break;
            case 2: NegativeNonNegativeNumbersCount();
                break;
            case 3: FailedStudentsCount();
                break;
            }
        }

        //Check if the user wants to exit or select another operation.
        cout << "\nDo you want to perform different counting operation? (Y/N)" << endl;
        cin >> conti;
    } while (conti == 'Y' or conti == 'y');
}

//Implementation for counting the number of students passed.
void PassedStudentsCount()
{
    //Declaring the required variables.
    int total_num_of_students, count, marks_obtained, pass_count;   char conti;

    do
    {
        pass_count = 0; //Initializing the variable to 0.
        //Read the number of students.
        cout << "\nEnter the total number of students appeared for examination" << endl;
        cin >> total_num_of_students;

        //Checking if the number of students is not 0.
        if (total_num_of_students < 1)
        {
            cout << "\nIt seems no student appeared for the examination!" << endl;
        }

        else
        {
            //Continue to read marks of students until it equals to the total number of students.
            for (count = 1; count <= total_num_of_students; count++)
            {
                cout << "\nEnter the marks obtained by " << count << " student out of 100" << endl;
                cin >> marks_obtained;

                //Check if the marks entered are valid.
                if (marks_obtained < 0 or marks_obtained > 100)
                {
                    cout << "\nMarks entered are not valid. Please re-enter the marks correctly (minimum marks = 0 and maximum marks = 100)." << endl;
                    count = count - 1;
                }

                //Check whether the current student has passed for the marks entered.
                else if (marks_obtained >= 50 and marks_obtained <= 100)
                {
                    pass_count = pass_count + 1;
                }
            }

            //Display the total number of students passed in examination.
            if (pass_count == 0)
            {
                cout << "\nUnfortunately, no student has passed the examination!" << endl;
            }
            else if (pass_count == total_num_of_students)
            {
                cout << "\nCongratulations! Every student who appeared for examination has passed." << endl;
            }
            else
            {
                cout << "\nThe number student(s) who passed the examination is: " << pass_count << endl;
            }
        }

        cout << "\nWant to count another set of students who passed? (Y/N)" << endl;
        cin >> conti;

    } while (conti == 'Y' or conti == 'y');
}

//Implementation for counting negative numbers and non-negative numbers from a set of given numbers.
void NegativeNonNegativeNumbersCount()
{
    //Declaring the required variables.
    int total_number, count, number, negative_num, non_negative_num;    char conti;

    do
    {
        negative_num = 0, non_negative_num = 0; //Initializing the negative_num and non_negative_num to 0.

        //Read the total number in the set.
        cout << "\nEnter the total numbers in a set" << endl;
        cin >> total_number;

        //While the count is not more than total number, read the next number.
        for (count = 1; count <= total_number; count++)
        {
            cout << "\nEnter the value (negative or non-negative) for " << count << " number" << endl;
            cin >> number;

            //Check if the entered number is negative. If it is, increase the negative number count by 1.
            if (number < 0)
            {
                negative_num = negative_num + 1;
            }

            else
            {
                non_negative_num = non_negative_num + 1;    //Increase the non-negative count by 1.
            }
        }

        //Displaying the count for both -- negative and non-negative numbers.
        cout << "\nThe count of negative numbers is: " << negative_num << ", and count of non-negative numbers is: " << non_negative_num << endl;

        cout << "\nWant to count of negative and non-negative numbers for new set of numbers? (Y/N)" << endl;
        cin >> conti;
    } while (conti == 'Y' or conti == 'y');

}

//Implementation for counting the number of passed students by initializing passed count to the total number of students.
void FailedStudentsCount()
{
    /*
        This method is efficient when the number of students who passed the examination is greater than those failed, as we only subtract
        those who fail, reducing the pass_count deduction operations.
    */
    //Declaring the required variables.
    int total_num_of_students, count, pass_count, marks_obtained;   char conti;

    do
    {
        //Reading the total number of students from the user.
        cout << "\nEnter the number of students who appeared for examination" << endl;
        cin >> total_num_of_students;

        pass_count = total_num_of_students; //Initialized the pass_count to total number of students.

        //Checking if the number of students is zero. If it is, it means no student has appeared for the examination.
        if (total_num_of_students < 1)
        {
            cout << "\nIt seems no student appeared for the examination!" << endl;
        }
        //When the number of students in not zero.
        else
        {
            for (count = 1; count <= total_num_of_students; count++)    //The for loop will execute until the count becomes equal to the total number of students.
            {
                cout << "\nEnter the marks obtained by " << count << " student out of 100." << endl;
                cin >> marks_obtained;

                if (marks_obtained < 0 or marks_obtained>100)   //Checking if the marks entered are valid: not less than 0 and not more than 100.
                {
                    cout << "\nMarks entered are not valid. Please re-enter the marks correctly (minimum marks = 0 and maximum marks = 100)." << endl;
                    count = count - 1;
                }

                else if (marks_obtained < 50)   //As the pass_count is initialized to total number of students, we need to check the students who have failed.
                {
                    pass_count = pass_count - 1;
                }
            }

            //Display the total number of students passed in examination.
            if (pass_count == 0)
            {
                cout << "\nUnfortunately, no student has passed the examination!" << endl;
            }
            else if (pass_count == total_num_of_students)
            {
                cout << "\nCongratulations! Every student who appeared for examination has passed." << endl;
            }
            else
            {
                cout << "\nThe number student(s) who passed the examination is: " << pass_count << endl;
            }
        }

        cout << "\nDo you want to count another set of students who passed using this method? (Y/N)" << endl;
        cin >> conti;
    } while (conti == 'Y' or conti == 'y');
}