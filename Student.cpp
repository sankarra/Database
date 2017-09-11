//
//  Student.cpp
//  BST
//
//  Created by Anup Sankarraman on 4/15/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Student.hpp"

using namespace std;

//Operations related to student record
//constructors and methods (setter, getter, display etc)
Student::Student()
{
    id = 0;
    name = "";
    level = "";
    major = "";
    gpa = 0.0;
    advisor = 0;
}

Student::Student(int i)
{
    id = i;
}

Student::Student(int i, string n, string l, string m, double g, int a)
{
    id = i;
    name = n;
    level = l;
    major = m;
    gpa = g;
    advisor = a;
}

void Student::readInput(string line)
{
    
    istringstream ss( line );
    int j = 0;
    
    while (ss)
    {
        string s;
        if (!getline( ss, s, ',' )) break;
        switch(j) {
            case 0:
                id = stoi(s);
                break;
            case 1:
                name = s;
                break;
            case 2:
                level = s;
                break;
            case 3:
                major = s;
                break;
            case 4:
                gpa = stod(s);
                break;
            case 5:
                advisor = stoi(s);
            default:
                break;
        }
        j++;
    }
    
}

bool Student::operator==(Student &s1)
{
    return s1.id == this->id;
}

bool Student::operator<(Student &s1)
{
    return this->id < s1.id;
}

bool Student::operator>(Student &s1)
{
    return this->id > s1.id;
}

bool Student::operator!=(Student &s1)
{
    return s1.id != this->id;
}

int Student::getId()
{
    return id;
}

void Student::setId(int i)
{
    id = i;
}

int Student::getFacultyId()
{
    return advisor;
}

void Student::setFacultyId(int id)
{
    advisor = id;
}

string Student::getName()
{
    return name;
}

string Student::getLevel()
{
    return level;
}

string Student::getMajor()
{
    return major;
}

double Student::getGPA()
{
    return gpa;
}

int Student::getAdvisor()
{
    return advisor;
}

void Student::printData()
{
    cout << "Student: " << endl;
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Major: " << major << endl;
    cout << "GPA: " << gpa << endl;
    cout << "Advisor Id: " << advisor << endl;
    cout << endl << endl;
}
