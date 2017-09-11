//
//  Faculty.cpp
//  BST
//
//  Created by Anup Sankarraman on 4/15/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#include <iostream>
#include <sstream>
#include "Faculty.hpp"

using namespace std;

//Operations related to a faculty record
//constructors and methods (setter, getter, display etc)
Faculty::Faculty()
{
    id = 0;
    name = "";
    level = "";
    dept = "";
}

Faculty::Faculty(int i)
{
    id = i;
    name = level = dept = "";
    
}
Faculty::Faculty(int i, string n, string l, string d, vector<int> al)
{
    id = i;
    name = n;
    level = l;
    dept = d;
    advisees = al;
}

void Faculty::readInput(string line)
{
    
    istringstream ss( line );
    int j = 0;
    advisees.clear();
    
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
                dept = s;
                break;
            default:
                advisees.push_back(stoi(s));
                break;
        }
        j++;
    }
    
}


bool Faculty::operator==(Faculty &f1)
{
    return f1.id == this->id;
}


bool Faculty::operator>(Faculty &f1)
{
    return this->id > f1.id;
}


bool Faculty::operator<(Faculty &f1)
{
    return this->id < f1.id;
}


bool Faculty::operator!=(Faculty &f1)
{
    return f1.id != this->id;
}

int Faculty::getId()
{
    return id;
}


string Faculty::getName()
{
    return name;
}

string Faculty::getLevel()
{
    return level;
}

string Faculty::getDept()
{
    return dept;
}

vector<int> Faculty::getAdvisees()
{
    return advisees;
}

void Faculty::setId(int i)
{
    id = i;
}

void Faculty::printData()
{
    cout << "Faculty: " << endl;
    cout << "Id: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Level: " << level << endl;
    cout << "Department: " << dept << endl;
    cout << "Advisees: ";
    for (vector<int>::iterator i = advisees.begin(); i != advisees.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl << endl;
}
