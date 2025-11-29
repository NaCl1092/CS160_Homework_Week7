//25125040
//Le Hong Dang
//25A02

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

//The tests for the same contents as Assignment 2.53 are located in the program Assignment2_53.cpp.

/* Test case 1:
Input:
    5
    1 2 3 4 5

Output:
    1 2 3 4 5 0 0 0 0 0
*/

/* Test case 2:
Input:
    3
    6 6 6

Output:
    6 6 6 0 0 0
*/

/* Test case 3:
Input:
    2
    99 99

Output:
    99 99 0 0
*/

void readFile(ifstream &inp, int &n, char *&arr);
void compare(char *arrCorrectAns, char *arrStudentAns, int numsCorrectAns, int numsStudentAns);
void InputArray(int *&arr, int &arraySize);
void DoubleSizeArray(int *&arr, int &arraySize);

int main()
{
    int numsCorrectAns = 0, numsStudentAns = 0;
    char *arrCorrectAns = nullptr;
    char *arrStudentAns = nullptr;
    ifstream inp;
    inp.open("CorrectAnswers.txt");
//    readFile(inp, numsCorrectAns, arrCorrectAns);
    inp.close();
    inp.open("StudentAnswers.txt");
//    readFile(inp, numsStudentAns, arrStudentAns);
    inp.close();
//    compare(arrCorrectAns, arrStudentAns, numsCorrectAns, numsStudentAns);
    delete[] arrCorrectAns;
    delete[] arrStudentAns;
    int arraySize = 0;
    int *arr = nullptr;
    InputArray(arr, arraySize);
    DoubleSizeArray(arr, arraySize);
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

void InputArray(int *&arr, int &arraySize)
{
    ifstream inp("Array.txt");
    inp >> arraySize;
    arr = new int[arraySize];
    for (int i = 0; i < arraySize; ++i) inp >> arr[i];
    inp.close();
}

void DoubleSizeArray(int *&arr, int &arraySize)
{
    int *newArr = new int[arraySize * 2];
    for (int i = 0; i < arraySize; ++i) newArr[i] = arr[i];
    for (int i = arraySize; i < 2 * arraySize; ++i) newArr[i] = 0;
    ofstream out("ArrayRes.txt");
    arraySize *= 2;
    delete[] arr;
    arr = newArr;
    for (int i = 0; i < arraySize; ++i) out << arr[i] << ' ';
    out.close();
}
