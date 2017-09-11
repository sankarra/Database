//
//  Faculty.hpp
//  BST
//
//  Created by Anup Sankarraman on 4/15/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef Faculty_hpp
#define Faculty_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Faculty {
public:
    Faculty();
    Faculty(int id);
    Faculty(int i, string n, string l, string d, vector<int> al);
    void readInput(string s);
    int getId();
    string getName();
    string getLevel();
    string getDept();
    vector<int> getAdvisees();
    void setId(int id);
    void printData();
    bool operator == (Faculty &f1);
    bool operator < (Faculty &f1);
    bool operator > (Faculty &f1);
    bool operator != (Faculty &f1);
    bool operator < (Faculty f1);
    
protected:
    int id;
    string name;
    string level;
    string dept;
    vector<int> advisees;
};

#endif /* Faculty_hpp */
