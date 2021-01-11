/*
    Implementation for counting the number of students who passed the examination.
*/

#include <iostream>
using namespace std;

void PassedStudentsCount()
{
    /*Declaring the required variables.*/
    int total_students, count, marks_obtained, pass_count;   char conti;

    do
    {
        /*Initializing the pass count to 0.*/
        pass_count = 0;
        /*Read the number of students.*/
        cout << "\nEnter the total number of students appeared for examination" << endl;
        cin >> total_students;

        /*Check that the number of students is not 0.*/
        if (total_students < 1)
        {
            cout << "\nIt seems no student appeared for the examination!" << endl;
        }

        else
        {
            /*Read marks of students until it equals to the total number of students.*/
            for (count = 1; count <= total_students; count++)
            {
                cout << "\nEnter the marks obtained by " << count << " student out of 100" << endl;
                cin >> marks_obtained;

                /*Check if the marks entered are valid.*/
                if (marks_obtained < 0 || marks_obtained > 100)
                {
                    cout << "\nMarks entered are not valid. Please re-enter the marks correctly (minimum marks = 0 and maximum marks = 100)." << endl;
                    count = count - 1;
                }

                /*Check whether the current student has passed for the marks entered.*/
                else if (marks_obtained >= 50 && marks_obtained <= 100)
                {
                    pass_count = pass_count + 1;
                }
            }

            //Display the total number of students passed in examination.
            if (pass_count == 0)
            {
                cout << "\nUnfortunately, no student has passed the examination!" << endl;
            }
            else if (pass_count == total_students)
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
    }while (conti == 'Y' || conti == 'y');
}