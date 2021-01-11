/*
    Implementation for counting the number of passed students by initializing passed count to the total number of
    students. This method is efficient when the number of students who passed the examination is greater than 
    those failed, as we only subtract those who fail, reducing the pass_count deduction operations.
*/

#include <iostream>
using namespace std;

void FailedStudentsCount()
{
    /*Declaring the required variables.*/
    int total_students, count, pass_count, marks_obtained;   char conti;

    do
    {
        /*Read the total number of students from the user.*/
        cout << "\nEnter the number of students who appeared for examination" << endl;
        cin >> total_students;
        /*Initialize the pass_count to total number of students.*/
        pass_count = total_students;

        /*Check if the number of students is zero. If it is, it means no student has appeared for the examination.*/
        if (total_students < 1)
        {
            cout << "\nIt seems no student appeared for the examination!" << endl;
        }
        /*When the number of students who appeared for the examination in not zero.*/
        else
        {
            /*The for loop will execute until the count becomes equal to the total number of students.*/
            for (count = 1; count <= total_students; count++)
            {
                cout << "\nEnter the marks obtained by " << count << " student out of 100." << endl;
                cin >> marks_obtained;
                /*Checking if the marks entered are valid -- not less than 0 and not more than 100.*/
                if (marks_obtained < 0 || marks_obtained>100)
                {
                    cout << "\nMarks entered are not valid. Please re-enter the marks correctly (minimum marks = 0 and maximum marks = 100)." << endl;
                    count = count - 1;
                }
                /*As the pass_count is initialized to total number of students, we need to check the students who have failed.*/
                else if (marks_obtained < 50)
                {
                    pass_count = pass_count - 1;
                }
            }

            /*Display the total number of students passed in examination.*/
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
        cout << "\nDo you want to count another set of students who passed using this method? (Y/N)" << endl;
        cin >> conti;
    } while (conti == 'Y' || conti == 'y');
}