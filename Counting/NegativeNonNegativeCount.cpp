/*
    Implementation for counting negative numbers and non-negative numbers from a set of given numbers.
*/

#include <iostream>
using namespace std;

void NegativeNonNegativeCount()
{
    /*Required variables.*/
    int total_number, count, number, negative_num, non_negative_num;    char conti;

    do
    {
        /*Initializing the negative_num and non_negative_num to 0.*/
        negative_num = 0, non_negative_num = 0;

        /*Read the total numbers in the set.*/
        cout << "\nEnter the total numbers in a set" << endl;
        cin >> total_number;

        /*While the count is not more than total number, read the next number.*/
        for (count = 1; count <= total_number; count++)
        {
            cout << "\nEnter the value (negative or non-negative) for " << count << " number" << endl;
            cin >> number;

            /*Check if the entered number is negative. If it is, increase the negative numbers count by 1.*/
            if (number < 0)
            {
                negative_num = negative_num + 1;
            }
            else
            {
                /*Increase the non-negative numbers count by 1.*/
                non_negative_num = non_negative_num + 1;
            }
        }

        /*Displaying the count for both -- negative and non-negative numbers.*/
        cout << "\nThe count of negative numbers is: " << negative_num << ", and count of non-negative numbers is: " << non_negative_num << endl;

        cout << "\nWant to count of negative and non-negative numbers for new set of numbers? (Y/N)" << endl;
        cin >> conti;
    } while (conti == 'Y' || conti == 'y');
}