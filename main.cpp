//
//  main.cpp
//  BST
//
//  Created by Anup Sankarraman on 4/8/17.
//  Copyright © 2017 Anup Sankarraman. All rights reserved.
//


#include "database.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    //create a database handle to perform database operations: insert, delete, update,
    //find records (in this example from students and faculty records/tables)
    
    database *databaseHandle = new database();
    
    //read records from faculty table/file (faculty.txt) and student table (student.txt)
    databaseHandle->readFacultyFromFile();
    databaseHandle->readStudentsFromFile();
    
    int option = 0;
    string input;
    
    //based on the input option perform the desired operation
    while (option != 14)
    {
        databaseHandle->printMenu();
        getline(cin>>ws, input);
        option = stoi(input);
        
        
        switch(option)
        {
            case 1:
                databaseHandle->printAllStudentInfo();
                break;
            case 2:
                databaseHandle->printAllFacultyInfo();
                break;
            case 3:
                databaseHandle->findStudent();
                break;
            case 4:
                databaseHandle->findFaculty();
                break;
            case 5:
                databaseHandle->printFacultyInfoOfStudent();
                break;
            case 6:
                databaseHandle->printAllStudentsInfoOfFaculty();
                break;
            case 7:
                databaseHandle->addStudent();
                break;
            case 8:
                databaseHandle->deleteStudent();
                break;
            case 9:
                databaseHandle->addFaculty();
                break;
            case 10:
                databaseHandle->deleteFaculty();
                break;
            case 11:
                databaseHandle->changeStudentAdivsor();
                break;
            case 12:
                databaseHandle->removeAdviseeFromFaculty();
                break;
            case 13:
                databaseHandle->rollback();
                break;
            default:
                break;
        }
    }
    
    //write the records back to the file
    databaseHandle->writeFacultyToFile();
    databaseHandle->writeStudentToFile();
    
    return 0;
}
