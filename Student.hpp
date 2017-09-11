//
//  Student.hpp
//  BST
//
//  Created by Anup Sankarraman on 4/15/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Student {
public:
    Student();
    Student(int id);
    Student(int i, string n, string l, string m, double g, int a);
    void readInput(string s);
    bool operator == (Student &s1);
    bool operator < (Student &s1);
    bool operator > (Student &s1);
    bool operator != (Student &s1);
    void printData();
    int getId();
    void setId(int id);
    int getFacultyId();
    void setFacultyId(int id);
    string getName();
    string getLevel();
    string getMajor();
    double getGPA();
    int getAdvisor();
    
protected:
    int id;
    string name;
    string level;
    string major;
    double gpa;
    int advisor;
};
#endif /* Student_hpp */
