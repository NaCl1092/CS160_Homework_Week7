//Student.cpp
#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

#include "Student.h"

int cmpDouble(double a, double b)
{
    double diff = a - b;
    if (-eps < diff && diff < eps) return 0;
    if (diff > eps) return 1;
    return -1;
}

void SInput(Student &s)
{
    cin >> s.id;
    cin.ignore();
    getline(cin, s.name);
    cin >> s.gpa;
    cin.ignore();
    getline(cin, s.address);
    cin >> s.dob.day >> s.dob.month >> s.dob.year;
    cin.ignore();
}

void SOutput(Student s)
{
    cout << "The student's information:\n";
    cout << "Id: " << s.id << '\n';
    cout << "Full name: " << s.name << '\n';
    cout << "GPA: " << fixed << setprecision(2) << s.gpa << '\n';
    cout << "Address: " << s.address << '\n';
    cout << "DOB: " << s.dob.day << "/" << s.dob.month << "/" << s.dob.year << '\n';
}

void SInputfile(std::ifstream &inp, Student &s)
{
    inp >> s.id;
    inp.ignore();
    getline(inp, s.name);
    inp >> s.gpa;
    inp.ignore();
    getline(inp, s.address);
    inp >> s.dob.day >> s.dob.month >> s.dob.year;
    inp.ignore();
}

void SOutputfile(std::ofstream &out, Student s)
{
    out << "Id: " << s.id << '\n';
    out << "Full name: " << s.name << '\n';
    out << "GPA: " << fixed << setprecision(2) << s.gpa << '\n';
    out << "Address: " << s.address << '\n';
    out << "DOB: " << s.dob.day << "/" << s.dob.month << "/" << s.dob.year << '\n';
}

void firstName(Student s, string &ans)
{
    for (int i = 0; s.name[i] != '\0'; ++i)
    {
        if (s.name[i] == ' ') return;
        ans.push_back(s.name[i]);
    }
}

void FindClass(Student s, string &C)
{
    C.push_back('K');
    C.push_back(s.id[0]);
    C.push_back(s.id[1]);
}

int ComparebyID(Student s1, Student s2)
{
    if (s1.id > s2.id) return 1;
    if (s1.id < s2.id) return -1;
    return 0;
}

int ComparebyFirstname(Student s1, Student s2)
{
    string s_1, s_2;
    firstName(s1, s_1);
    firstName(s2, s_2);
    if (s_1 > s_2) return 1;
    if (s_1 < s_2) return -1;
    return 0;
}

int ComparebyGPA(Student s1, Student s2)
{
    return cmpDouble(s1.gpa, s2.gpa);
}

int ComparebyDoB(Student s1, Student s2)
{
    int d_1 = toDays(s1.dob);
    int d_2 = toDays(s2.dob);
    if (d_1 > d_2) return 1;
    else if (d_1 < d_2) return -1;
    else return 0;
}

