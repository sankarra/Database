//
//  database.cpp
//  BST
//
//  Created by Anup Sankarraman on 4/21/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include "database.hpp"

using namespace std;

//constructor creates an empty BST tree
database::database()
{
    masterStudent = new BST<Student>();
    masterFaculty = new BST<Faculty>();
    
};

//read records from faculty.txt file. The file is expected in exist in the directory
//where the program is run (or the program current working directory).
//This file is supplied with the program
//Each record is read from file and stored as a Faculty record in the Faculty BST
void database::readFacultyFromFile()
{
    //Read Faculty Records from file faculty.txt
    cout << "Loading Faculty Records from file facultyTable" << endl << endl;
    
    try
    {
        
        Faculty f;
        string line;
        
        ifstream infile( "facultyTable" );
        
        if (infile.is_open())
        {
            while (getline(infile, line))
            {
                f.readInput(line);
                masterFaculty->insert(f);
            }
            infile.close();
        }
        
    }
    catch(exception e)
    {
        cout << "Error: cannot open file facultyTable." << endl;
    }
    
}

//read records from student.txt file. The file is expected in exist in the directory
//where the program is run (or the program current working directory).
//This file is supplied with the program
//Each record is read from file and stored as a Student record in the Student BST
void database::readStudentsFromFile()
{
    //Read Student Records from file student.txt
    cout << "Loading Student Records from file studentTable" << endl << endl;
    
    try
    {
        
        Student s;
        string line;
        
        ifstream infile( "studentTable" );
        
        if (infile.is_open())
        {
            while (getline(infile, line))
            {
                s.readInput(line);
                masterStudent->insert(s);
            }
            infile.close();
        }
        
    }
    catch(exception e)
    {
        cout << "Error: cannot open file studentTable" << endl;
    }
    
}

//Print the database menu options for users to perform operations
//on the database
void database::printMenu()
{
    cout << "Main Menu " << endl;
    cout << "__________" << endl;
    cout << "Here are the options: " << endl;
    cout << "1. Print all students and their information (sorted by ascending id#) " << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id#) " << endl;
    cout << "3. Find and display student information given the student id " << endl;
    cout << "4. Find and display the faculty information given the faculty id " << endl;
    cout << "5. Given a student id, print the name and info of their faculty advisor " << endl;
    cout << "6. Given a faculty id, print all the names and info of his/her advisees " << endl;
    cout << "7. Add a new student " << endl;
    cout << "8. Delete a student given the id " << endl;
    cout << "9. Add a new Faculty member " << endl;
    cout << "10. Delete a faculty memmber given the id " << endl;
    cout << "11. Change the student's advisor given the student id and the new faculty id" << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl << endl;
    cout << "Enter the option: " ;
}

//Print all the students in the student table
//we will do an inorder traversal of BST
//so the student records are printed in student id (natural) order
void database::printAllStudentInfo()
{
    masterStudent->inOrder();
}

//Print all the faculties in the faculty table
//we will do an inorder traversal of BST
//so the faculty records are printed in faculty id (natural) order
void database::printAllFacultyInfo()
{
    masterFaculty->inOrder();
}

//find a student in the student table given the id
void database::findStudent()
{
    string input;
    int id;
    
    cout << endl << "Find a student" << endl;
    cout << "______________" << endl;
    cout << "Enter the student id to get student information ";
    getline(cin>>ws, input);
    id = stoi(input);
    
    Student temp(id);
    
    if (masterStudent->contains(temp) == true)
    {
        Student temp2;
        temp2 = masterStudent->search(temp);
        temp2.printData();
    }
    else
        cout << "Error: Student with id " << id << " not found " << endl;
}

//find a faculty in the faculty table given the id
void database::findFaculty()
{
    string input;
    int id;
    
    cout << endl << "Find a faculty" << endl;
    cout << "______________" << endl;
    cout << "Enter the faculty id to get faculty information ";
    getline(cin>>ws, input);
    id = stoi(input);
    
    Faculty temp(id);
    
    if (masterFaculty->contains(temp) == true)
    {
        Faculty temp2;
        temp2 = masterFaculty->search(temp);
        temp2.printData();
    }
    else
        cout << "Error: Faculty with id " << id << " not found " << endl;
}

//Given a student id, find and display all information about the student advisor (faculty)
void database::printFacultyInfoOfStudent()
{
    string input;
    int id;
    int advisor;
    
    cout << endl << "Given a student, Find all info about the student faculty" << endl;
    cout << "________________________________________________________" << endl;
    cout << "Enter the student id to get the student faculty information ";
    getline(cin >>ws, input);
    id = stoi(input);
    Student s(id);
    
    cout << endl;
    
    if (masterStudent->contains(s) == true)
    {
        cout << "Student information is: " << endl;
        Student s2;
        s2 = masterStudent->search(s);
        s2.printData();
        advisor = s2.getFacultyId();
        
        
        Faculty f(advisor);
        
        if (masterFaculty->contains(f) == true)
        {
            cout << "Faculty information is: " << endl;
            Faculty f2;
            f2 = masterFaculty->search(f);
            f2.printData();
        }
        else
            cout << "Error: Faculty " << advisor << " not found " << endl;
    }
    else
        cout << "Error: Student " << id << " not found " << endl;
}

//Given a faculty id, find and proint all information of all the students the faculty advises
void database::printAllStudentsInfoOfFaculty()
{
    string input;
    int id;
    vector<int> advisees;
    vector <int>::iterator It;
    
    cout << endl << "Given a Faculty, find info of all students the faculty advises" << endl;
    cout << "______________________________________________________________" << endl;
    cout << "Enter the faculty id to get information about his or her students ";
    getline(cin >>ws, input);
    id = stoi(input);
    
    Faculty f(id);
    
    if (masterFaculty->contains(f) == true)
    {
        cout << "Faculty information is: " << endl;
        Faculty f2;
        f2 = masterFaculty->search(f);
        f2.printData();
        advisees = f2.getAdvisees();
    }
    cout << "Student informations are: " << endl;
    for (It = advisees.begin(); It != advisees.end(); ++It)
    {
        Student s(*It);
        Student st2;
        
        st2 = masterStudent->search(s);
        st2.printData();
    }
    cout << endl;
    
}

//Add a new student to the student table
void database::addStudent()
{
    string input;
    int id;
    string name = "";
    string level = "";
    string major = "";
    double gpa = 0.0;
    int advisor = 0;
    
    
    cout << endl << "Add a new Student: " << endl;
    cout << "__________________ " << endl;
    cout << "Enter student information: " << endl;
    cout << "id: ";
    getline(cin >>ws, input);
    id = stoi(input);
    
    cout << "name: ";
    getline(cin,name);
    
    cout << "level: " ;
    getline(cin, level);
    
    cout << "major: ";
    getline(cin, major);
    
    cout << "gpa: ";
    getline(cin, input);
    gpa = stod(input);
    
    cout << "advisor: ";
    getline(cin, input);
    advisor = stoi(input);
    cout << endl;
    Student s(id, name, level, major, gpa, advisor);
    insertStudentHelper(s, true);
    
}

//student insert helper function
void database::insertStudentHelper(Student s, bool pushStack)
{
    int id = s.getId();
    vector<int> advisees;
    Faculty f(s.getAdvisor());
    
    if (masterFaculty->contains(f) == true)
    {
        
        if (masterStudent->insert(s) == true)
        {
            
            cout << "Student successfully inserted " << endl;
            if (pushStack == true)
            {
                operationStack.push(1);
                studentStack.push(s);
            }
        }
        else
        {
            cout << "Insert Student failed: Student with same id already exists " << endl;
        }
        Faculty f2 = masterFaculty->search(f);
        advisees = f2.getAdvisees();
        advisees.push_back(id);
        Faculty f3(f2.getId(), f2.getName(), f2.getLevel(), f2.getDept(), advisees);
        masterFaculty->deleteV(f2);
        masterFaculty->insert(f3);
    }
    else
    {
        cout << "Insert Student failed: Student's Faculty does not exist " << endl;
    }
    cout << endl;
}

//Delete a student from students table, given the id
void database::deleteStudent()
{
    string input;
    int id;
    
    cout << endl << "Delete an existing student " << endl;
    cout << "___________________________" << endl;
    cout << "Enter student id of the student to delete ";
    getline(cin >>ws, input);
    id = stoi(input);
    
    Student s(id);
    deleteStudentHelper(s, true);
}

//delete helper function
void database::deleteStudentHelper(Student s, bool pushStack)
{
    vector<int> advisees;
    vector<int>::iterator It;
    int id = s.getId();
    
    if (masterStudent->contains(s) == true)
    {
        Student s2;
        
        int j = 0;
        
        s2 = masterStudent->search(s);
        Faculty f = Faculty(s2.getFacultyId());
        Faculty f2 = masterFaculty->search(f);
        
        
        advisees = f2.getAdvisees();
        for (It = advisees.begin(); It != advisees.end(); ++It,++j)
        {
            if (*It == id)
                break;
        }
        if (j < advisees.size())
            advisees.erase(advisees.begin() + j);
        Faculty f3(f2.getId(), f2.getName(), f2.getLevel(), f2.getDept(), advisees);
        masterStudent->deleteV(s);
        masterFaculty->deleteV(f);
        masterFaculty->insert(f3);
        cout << "Student with id " << id << " successfully deleted " << endl;
        if (pushStack == true)
        {
            operationStack.push(2);
            studentStack.push(s2);
        }
    }
    else
        cout << "Error: Student with id " << id << " not found " << endl;
    
}

//Add a faculty to faculty table
void database::addFaculty()
{
    string input;
    int id;
    string name = "";
    string level = "";
    string dept = "";
    vector<int> advisees;
    bool exit = false;
    
    cout << endl << "Add a new Faculty: " << endl;
    cout << "__________________ " << endl;
    cout << "Enter faculty information: " << endl;
    cout << "id: ";
    getline(cin >>ws, input);
    id = stoi(input);
    
    cout << "name: ";
    getline(cin,name);
    
    cout << "level: " ;
    getline(cin, level);
    
    cout << "dept: ";
    getline(cin, dept);
    
    cout << "student ids (seperated by space) ";
    getline(cin, input);
    
    istringstream ss(input);
    while (ss)
    {
        int sid;
        
        string s;
        if (!getline( ss, s, ' ' )) break;
        sid = stoi(s);
        Student st(sid);
        if (masterStudent->contains(st) == true)
            advisees.push_back(sid);
        else
        {
            cout << "Error: Student with id " << id << " does not exist " << endl;
            exit = true;
        }
    }
    
    if (exit == false)
    {
        Faculty f(id, name, level, dept, advisees);
        insertFacultyHelper(f, true);
    }
    cout << endl;
}

//faculty insert helper function
void database::insertFacultyHelper(Faculty f, bool pushStack)
{
    if (masterFaculty->contains(f) == false)
    {
        if (masterFaculty->insert(f) == true)
        {
            cout << "Faculty successfully inserted " << endl;
            if (pushStack == true)
            {
                operationStack.push(3);
                facultyStack.push(f);
            }
        }
    }
    else
    {
        cout << "Error: Insert Faculty failed: Faculty with same id already exists " << endl;
    }
    
}

//delete a faculty from faculty table given the faculty id
void database::deleteFaculty()
{
    string input;
    int id;
    
    
    cout << endl << "Delete an existing faculty " << endl;
    cout << "___________________________" << endl;
    cout << "Enter faculty id of the faculty to delete ";
    getline(cin >>ws, input);
    id = stoi(input);
    Faculty f(id);
    deleteFacultyHelper(f, true);
}

//delete faculty helper function
void database::deleteFacultyHelper(Faculty f, bool pushStack)
{
    int id = f.getId();
    vector<int> advisees;
    vector <int>::iterator It;
    
    if (masterFaculty->contains(f) == true)
    {
        Student s;
        Faculty f2;
        
        f2 = masterFaculty->search(f);
        advisees = f2.getAdvisees();
        if (advisees.size() == 0)
        {
            if (masterFaculty->deleteV(f) == true)
            {
                cout << "Faculty with id " << id << " successfully deleted " << endl;
                if (pushStack == true)
                {
                    operationStack.push(4);
                    facultyStack.push(f2);
                }
            }
        }
        else
            cout << "Faculty with id " << id << " has students as advisees. Reassign students before deleting faculty" << endl;
    }
    else
        cout << "Faculty with id " << id << " not found " << endl;
    
    cout << endl;
    
}

//Change a student advisor
void database::changeStudentAdivsor()
{
    string input;
    int id;
    int advisor;
    vector<int> advisees;
    vector<int>::iterator It;
    int j = 0;
    
    cout << endl << "Change Student advisor " << endl;
    cout << "_______________________" << endl;
    cout << "Enter student id of student whose advisor you want to change ";
    getline(cin >>ws, input);
    id = stoi(input);
    cout << "Enter the advisor id ";
    getline(cin >>ws, input);
    advisor = stoi(input);
    cout << endl;
    
    Faculty f(advisor);
    if (masterFaculty->contains(f) == true)
    {
        Student s(id);
        if (masterStudent->contains(s) == true)
        {
            int previousAdvisor;
            
            Student st2;
            st2 = masterStudent->search(s);
            previousAdvisor = st2.getFacultyId();
            
            Faculty f2(previousAdvisor);
            Faculty f3 = masterFaculty->search(f2);
            advisees = f3.getAdvisees();
            for (It = advisees.begin(); It != advisees.end(); ++It,++j)
            {
                if (*It == id)
                    break;
            }
            advisees.erase(advisees.begin() + j);
            Faculty f4(f3.getId(), f3.getName(), f3.getLevel(), f3.getDept(), advisees);
            masterFaculty->deleteV(f3);
            masterFaculty->insert(f4);
            
            if (masterStudent->deleteV(s) == true)
            {
                operationStack.push(5);
                studentStack.push(st2);
                st2.setFacultyId(advisor);
                if (masterStudent->insert(st2) == true)
                {
                    cout << "Successfully changed advisor for student with id " << id << endl;
                    studentStack.push(st2);
                }
            }
        }
        else
        {
            cout << "Error: Change failed: student does not exist" << endl;
        }
    }
    else
    {
        cout << "Error: Change failed: advisor does not exist" << endl;
    }
    
}



//remove an advisee from faculty
void database::removeAdviseeFromFaculty()
{
    int id;
    string input;
    int advisee;
    
    cout << endl << "Remove advisee from faculty " << endl;
    cout << "___________________________" << endl;
    cout << "Enter the facilty id ";
    getline(cin >>ws, input);
    id = stoi(input);
    cout << endl;
    cout << "Enter the student id of the student to remove from faculty as advisee ";
    getline (cin >> ws, input);
    advisee = stoi(input);
    
    Faculty f(id);
    if (masterFaculty->contains(f) == true)
    {
        int j = 0;
        vector<int>::iterator It;
        Faculty f2 = masterFaculty->search((f));
        
        vector<int> advisees = f2.getAdvisees();
        for (It = advisees.begin(); It != advisees.end(); ++It,++j)
        {
            if (*It == advisee)
                break;
        }
        if (j < advisees.size())
        {
            advisees.erase(advisees.begin() + j);
            Faculty f3(f2.getId(), f2.getName(), f2.getLevel(), f2.getDept(), advisees);
            masterFaculty->deleteV(f2);
            masterFaculty->insert(f3);
            
            
            Student s(advisee);
            Student s2 = masterStudent->search(s);
            operationStack.push(6);
            studentStack.push(s2);
            s2.setFacultyId(0);
            masterStudent->deleteV(s);
            masterStudent->insert(s2);
            cout << "Sucessfully removed student from Faculty " << endl;
        }
        else
        {
            cout << "Error: Student " << id << " is not an advisee of Faculty " << endl;
        }
    }
    else
        cout << "Error: Faculty " << id << " does not exist " << endl;
}

//write all faculty records to file. The file name is faculty.txt
void database::writeFacultyToFile()
{
    //Write Faculty Records to file faculty.txt
    cout << "Writing Faculty Records to file facultyTable" << endl << endl;
    
    Faculty *allFaculties = masterFaculty->levelOrder();
    
    try
    {
        
        Faculty f;
        
        ofstream outfile( "facultyTable" );
        
        if (outfile.is_open())
        {
            for (int i = 0; i < masterFaculty->getElements(); i++)
            {
                vector<int> advisees = allFaculties[i].getAdvisees();
                vector<int>::iterator It;
                
                outfile << allFaculties[i].getId() << "," << allFaculties[i].getName() << "," << allFaculties[i].getLevel() << "," << allFaculties[i].getDept();
                for (It = advisees.begin(); It != advisees.end(); ++It)
                {
                    outfile << "," << *It;
                }
                outfile << endl;
            }
            outfile.close();
        }
        
    }
    catch(exception e)
    {
        cout << "Error: cannot open file facultyTable." << endl;
    }
    
}

//write all students record to file. The file name is students.txt
void database::writeStudentToFile()
{
    
    //Write Student Records to file student.txt
    cout << "Writing Student Records to file studentTable" << endl << endl;
    
    Student *allStudents = masterStudent->levelOrder();
    
    try
    {
        
        Student s;
        
        ofstream outfile( "studentTable" );
        
        if (outfile.is_open())
        {
            for (int i = 0; i < masterStudent->getElements(); i++)
            {
                outfile << allStudents[i].getId() << "," << allStudents[i].getName() << "," << allStudents[i].getLevel() << "," << allStudents[i].getMajor() << "," << allStudents[i].getGPA() << "," << allStudents[i].getAdvisor();
                outfile << endl;
            }
            outfile.close();
        }
        
    }
    catch(exception e)
    {
        cout << "Error: cannot open file studentTable" << endl;
    }
    
}

//Rollback. This rollback operation performs up to 5 rollback operation. Not sure
//why it was limited to 5 but think of 5 update operations (insert, delete, update)
//of any database records as a transaction. So, if insert a record and rollback,
//this option will undo the insert (that is, it will delete the record) from the
//database. Similary, if you delete a record and rollback, it will reinsert the
//record and so on.
void database::rollback()
{
    int count = 0;
    int operation = 0;
    Student s;
    Faculty f, *f2;
    int Id = 0;
    vector<int> advisees;
    
    while (operationStack.size() != 0 && count < 5)
    {
        operation = operationStack.top();
        operationStack.pop();
        
        switch(operation) {
            case 1:
                cout << "Undo student Add" << endl;
                s = studentStack.top();
                studentStack.pop();
                deleteStudentHelper(s, false);
                break;
            case 2:
                cout << "Undo student Delete" << endl;
                s = studentStack.top();
                studentStack.pop();
                insertStudentHelper(s, false);
                break;
            case 3:
                cout << "Undo faculty Add" << endl;
                f = facultyStack.top();
                facultyStack.pop();
                deleteFacultyHelper(f, false);
                break;
            case 4:
                cout << "Undo faculty Delete" << endl;
                f = facultyStack.top();
                facultyStack.pop();
                insertFacultyHelper(f, false);
                break;
            case 5:
                cout << "Undo student advisor change " << endl;
                s = studentStack.top();
                studentStack.pop();
                deleteStudentHelper(s, false);
                s = studentStack.top();
                studentStack.pop();
                insertStudentHelper(s, false);
                break;
            case 6:
                cout << "Undo Faculty advisee change " << endl;
                s = studentStack.top();
                studentStack.pop();
                Id = s.getId();
                f = masterFaculty->search(s.getAdvisor());
                masterFaculty->deleteV(f);
                advisees = f.getAdvisees();
                advisees.push_back(Id);
                f2 = new Faculty(f.getId(), f.getName(), f.getLevel(), f.getDept(), advisees);
                masterFaculty->insert(*f2);
                masterStudent->deleteV(s);
                s.setFacultyId(f.getId());
                masterStudent->insert(s);
            default:
                break;
        }
        count++;
    }
}

database::~database()
{
    delete masterFaculty;
    delete masterStudent;
    
}
