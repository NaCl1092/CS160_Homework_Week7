//Course.cpp

#include<iostream>
#include<iomanip>
#include<fstream>
#include<chrono> //To find the current date in the computer
#include<string>

#include "Course.h"
using namespace std;

Date Datenow()
{
    time_t Time = time(0); //Get the amount of seconds distancing from 00:00:00 1/1/1970
    tm *Now = localtime(&Time); //Convert the seconds to the local time structure
    return {Now -> tm_mday, Now -> tm_mon + 1, Now -> tm_year + 1900};
    // The Now structure stores the year (distance from 1900 to now), month (from 0 to 11), day in the month;
    // hours, minutes and seconds.
}

void SwapStudent(Student &a, Student &b)
{
    Student temp = a;
    a = b;
    b = temp;
}

void InitCourse(Course &c, int capacity)
{
    if (c.studentList != nullptr) delete[] c.studentList;
    c.maxStudent = capacity;
    c.studentList = new Student[capacity];
    c.status = false;
    c.curStudent = 0;
    c.minStudent = 0;
}

void DeleteCourse(Course &c)
{
    if (c.studentList != nullptr)
    {
        delete[] c.studentList;
        c.studentList = nullptr;
    }
}

void Input(std::ifstream &inp, Course &c)
{
    inp >> c.id;
    inp.ignore();
    getline(inp, c.name);
    inp >> c.maxStudent >> c.minStudent;
    if (c.studentList != nullptr) delete[] c.studentList;
    c.studentList = new Student[c.maxStudent];
}

void Output(std::ofstream &out, Course c)
{
    out << "Course: " << c.id << " - " << c.name << '\n';
    out << "Status: " << (c.status ? "Open" : "Close");
    out << "\nStudents list:\n";
    for (int i = 0; i < c.curStudent; ++i) SOutputfile(out, c.studentList[i]);
}

void AddStudent(Course &c, Student s)
{
    if (c.curStudent == c.maxStudent)
    {
        cout << "The course is full!\n";
        return;
    }
    c.studentList[c.curStudent++] = s;
    if (c.curStudent >= c.minStudent && !c.status) c.status = true;
}

void RemoveStudent(Course &c, string ID)
{
    int idx = -1;
    for (int i = 0; i < c.curStudent; ++i)
    {
        if (c.studentList[i].id == ID)
        {
            idx = i;
            break;
        }
    }
    if (idx == -1)
    {
        cout << "Student not found.\n";
        return;
    }
    for (int i = idx; i < c.curStudent - 1; ++i)
    {
        c.studentList[i] = c.studentList[i + 1];
    }
    c.curStudent--;
    if (c.status && c.curStudent < c.minStudent) c.status = false;
}

void FindBornMonth(Course c)
{
    Date Today = Datenow();
    bool exist = false;
    for (int i = 0; i < c.curStudent; ++i)
    {
        Student cur = c.studentList[i];
        if (cur.dob.month == Today.month)
        {
            exist = true;
            cout << cur.name << " (" << cur.id << ")\n";
        }
    }
    if (!exist) cout << "No students found for this condition.\n";
}

void FindBornDay(Course c)
{
    Date Today = Datenow();
    bool exist = false;
    for (int i = 0; i < c.curStudent; ++i)
    {
        Student cur = c.studentList[i];
        if (cur.dob.day == Today.day)
        {
            exist = true;
            cout << cur.name << " (" << cur.id << ")\n";
        }
    }
    if (!exist) cout << "No students found for this condition.\n";
}

void FindAbove18(Course c)
{
    Date Today = Datenow();
    bool exist = false;
    for (int i = 0; i < c.curStudent; ++i)
    {
        Student cur = c.studentList[i];
        int age = Today.year - cur.dob.year;
        if (Today.month < cur.dob.month || (Today.month == cur.dob.month && Today.day < cur.dob.day)) age--;
        if (age >= 18)
        {
            exist = true;
            cout << cur.name << " (" << cur.id << ")\n";
        }
    }
    if (!exist) cout << "No students found for this condition.\n";
}

void FindK19Class(std::ofstream &out, Course c)
{
    bool exist = false;
    for (int i = 0; i < c.curStudent; ++i)
    {
        Student cur = c.studentList[i];
        string Class;
        FindClass(cur, Class);
        if (Class == "K19")
        {
            exist = true;
            out << cur.name << " (" << cur.id << ")\n";
        }
    }
    if (!exist) out << "No students found for this condition.\n";
}

void FindStudentbyID(std::ofstream &out, Course c, string ID)
{
    for (int i = 0; i < c.curStudent; ++i)
    {
        Student cur = c.studentList[i];
        if (cur.id == ID)
        {
            out << cur.name << " (" << cur.id << ")\n";
            return;
        }
    }
    out << "No students found with the given id.\n";
}

void FindStudentbyName(std::ofstream &out, Course c, string Name)
{
    bool exist = false;
    for (int i = 0; i < c.curStudent; ++i)
    {
        Student cur = c.studentList[i];
        if (cur.name.find(Name) != string::npos)
        {
            exist = true;
            out << cur.name << " (" << cur.id << ")\n";
        }
    }
    if (!exist) out << "No students found with the given name.\n";
}

void SortStudentbyID(std::ofstream &out, Course &c)
{
    int &n = c.curStudent;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (c.studentList[i].id > c.studentList[j].id)
            {
                SwapStudent(c.studentList[i], c.studentList[j]);
            }
        }
    }
    Output(out, c);
}

void SortStudentbyFirstname(std::ofstream &out, Course &c)
{
    int &n = c.curStudent;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            string FName1, FName2;
            firstName(c.studentList[i], FName1);
            firstName(c.studentList[j], FName2);
            if (FName1 > FName2)
            {
                SwapStudent(c.studentList[i], c.studentList[j]);
            }
        }
    }
    Output(out, c);
}

void SortStudentbyGPA(std::ofstream &out, Course &c)
{
    int &n = c.curStudent;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (cmpDouble(c.studentList[i].gpa, c.studentList[j].gpa) > 0)
            {
                SwapStudent(c.studentList[i], c.studentList[j]);
            }
        }
    }
    Output(out, c);
}

void SortStudentbyDoB(std::ofstream &out, Course &c)
{
    int &n = c.curStudent;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (compareDates(c.studentList[i].dob, c.studentList[j].dob) > 0)
            {
                SwapStudent(c.studentList[i], c.studentList[j]);
            }
        }
    }
    Output(out, c);
}

