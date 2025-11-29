//25125040
//Le Hong Dang
//25A02

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

/* Test case 1:
Input:
    20
    ABCDCBABCD
    CBABCDCBAB
(This is the correct answer's file)
    20
    AAAAAAAAAA
    AAAAAAAAAA

Output:
    Missed questions:
    Question 2:
    Student: A
    Correct: B
    Question 3:
    Student: A
    Correct: C
    Question 4:
    Student: A
    Correct: D
    Question 5:
    Student: A
    Correct: C
    Question 6:
    Student: A
    Correct: B
    Question 8:
    Student: A
    Correct: B
    Question 9:
    Student: A
    Correct: C
    Question 10:
    Student: A
    Correct: D
    Question 11:
    Student: A
    Correct: C
    Question 12:
    Student: A
    Correct: B
    Question 14:
    Student: A
    Correct: B
    Question 15:
    Student: A
    Correct: C
    Question 16:
    Student: A
    Correct: D
    Question 17:
    Student: A
    Correct: C
    Question 18:
    Student: A
    Correct: B
    Question 20:
    Student: A
    Correct: B
    The total number of questions missed: 16
    The percentage of questions answered correctly: 20.00%
    The student failed the exam.
*/

/* Test case 2:
Input:
    20
    ABCDCBABCD
    CBABCDCBAB
(This is the correct answer's file)
    20
    ABCDCBABCD
    CBABCDCBAB

Output:
    The total number of questions missed: 0
    The percentage of questions answered correctly: 100.00%
    The student passed the exam.
*/

/* Test case 3:
Input:
    20
    ABCDCBABCD
    CBABCDCBAB
    0

Output:
    Missed questions:
    Question 1:
    The student didn't answer this question.
    Correct: A
    Question 2:
    The student didn't answer this question.
    Correct: B
    Question 3:
    The student didn't answer this question.
    Correct: C
    Question 4:
    The student didn't answer this question.
    Correct: D
    Question 5:
    The student didn't answer this question.
    Correct: C
    Question 6:
    The student didn't answer this question.
    Correct: B
    Question 7:
    The student didn't answer this question.
    Correct: A
    Question 8:
    The student didn't answer this question.
    Correct: B
    Question 9:
    The student didn't answer this question.
    Correct: C
    Question 10:
    The student didn't answer this question.
    Correct: D
    Question 11:
    The student didn't answer this question.
    Correct: C
    Question 12:
    The student didn't answer this question.
    Correct: B
    Question 13:
    The student didn't answer this question.
    Correct: A
    Question 14:
    The student didn't answer this question.
    Correct: B
    Question 15:
    The student didn't answer this question.
    Correct: C
    Question 16:
    The student didn't answer this question.
    Correct: D
    Question 17:
    The student didn't answer this question.
    Correct: C
    Question 18:
    The student didn't answer this question.
    Correct: B
    Question 19:
    The student didn't answer this question.
    Correct: A
    Question 20:
    The student didn't answer this question.
    Correct: B
    The total number of questions missed: 20
    The percentage of questions answered correctly: 0.00%
    The student failed the exam.
*/

void readFile(ifstream &inp, int &n, char *&arr);
void compare(char *arrCorrectAns, char *arrStudentAns, int numsCorrectAns, int numsStudentAns);

int main()
{
    int numsCorrectAns = 0, numsStudentAns = 0;
    char *arrCorrectAns = nullptr;
    char *arrStudentAns = nullptr;
    ifstream inp;
    inp.open("CorrectAnswers.txt");
    readFile(inp, numsCorrectAns, arrCorrectAns);
    inp.close();
    inp.open("StudentAnswers.txt");
    readFile(inp, numsStudentAns, arrStudentAns);
    compare(arrCorrectAns, arrStudentAns, numsCorrectAns, numsStudentAns);
    delete[] arrCorrectAns;
    delete[] arrStudentAns;
    return 0;
}

void readFile(ifstream &inp, int &n, char *&arr)
{
    inp >> n; //Assume that the size of the array and the array are well-defined
    char *newArr = new char[n];
    for (int i = 0; i < n; ++i) inp >> newArr[i];
    delete[] arr;
    arr = newArr;
}

void compare(char *arrCorrectAns, char *arrStudentAns, int numsCorrectAns, int numsStudentAns)
{
    int missAns = 0;
    for (int i = 0; i < numsStudentAns; ++i)
    {
        if (arrStudentAns[i] != arrCorrectAns[i])
        {
            missAns++;
            if (missAns == 1) cout << "Missed questions:\n";
            cout << "Question " << i + 1 << ":\n";
            cout << "Student: " << arrStudentAns[i] << "\nCorrect: " << arrCorrectAns[i] << "\n";
        }
    }
    for (int i = numsStudentAns; i < numsCorrectAns; ++i)
    {
        missAns++;
        if (missAns == 1) cout << "Missed questions:\n";
        cout << "Question " << i + 1 << ":\n";
        cout << "The student didn't answer this question.\n";
        cout << "Correct: " << arrCorrectAns[i] << '\n';
    }
    cout << "The total number of questions missed: " << missAns << '\n';
    cout << "The percentage of questions answered correctly: ";
    double percentage = 100.0 * (numsCorrectAns - missAns) / numsCorrectAns;
    cout << setprecision(2) << fixed << percentage << "\%\n";
    if (percentage >= 70.0) cout << "The student passed the exam.\n";
    else cout << "The student failed the exam.\n";
}
