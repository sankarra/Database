//
//  database.hpp
//  BST
//
//  Created by Anup Sankarraman on 4/21/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#ifndef database_hpp
#define database_hpp
#include <stack>
#include "TreeNode.cpp"
#include "BST.cpp"


using namespace std;

class database {
    
public:
    database();
    void readFacultyFromFile();
    void readStudentsFromFile();
    void printMenu();
    void printAllStudentInfo();
    void printAllFacultyInfo();
    void findStudent();
    void findFaculty();
    void printFacultyInfoOfStudent();
    void printAllStudentsInfoOfFaculty();
    void addStudent();
    void deleteStudent();
    void addFaculty();
    void deleteFaculty();
    void changeStudentAdivsor();
    void removeAdviseeFromFaculty();
    void rollback();
    void writeFacultyToFile();
    void writeStudentToFile();
    void insertStudentHelper(Student s, bool pushStack);
    void insertFacultyHelper(Faculty f, bool pushStack);
    void deleteStudentHelper(Student s, bool pushStack);
    void deleteFacultyHelper(Faculty f, bool pushStack);
    void changeStudentAdvisorHelper(Student s, bool pushStack);
    void removeAdviseeFromFacultyHelper(Faculty f, bool pushStack);
    ~database();
    
private:
    BST<Student>* masterStudent; //BST tree consisting of all students
    BST<Faculty>* masterFaculty; //BST tree consisting of all faculty
    stack<Student> studentStack; //This student stack is used to undo (rollback) some actions related to student table
    stack<Faculty> facultyStack; //This faculty stack is used to undo (rollup) some actions related to faculty table
    stack<int> operationStack;
    
};
#endif /* database_hpp */
