/**
 * Course.cpp
 *
 * EECS 183, Fall 2015
 * Assignment 4: File I/O and classes
 *
 * Mackenzie Francisco
 * mackfran
 *
 */

#include "Course.h"

Course::Course(string courseName) {
    name = courseName;
}

// Function (getName) that returns the name (string) of this Course
string Course::getName() {
    return name;
}

// Function (getNumStudents) that returns the number of students (int) in the course
int Course::getNumStudents() {
    return numStudents;
}

void Course::addStudent(Student newStudent) {
    students[numStudents] = newStudent;
    numStudents++;
}

int Course::getLowestGrade() {
    int currentMin = -1;
        
    for (int student = 0; student < numStudents; ++student) {
        if (students[student].getLowestGrade() < currentMin || currentMin == -1) {
            currentMin = students[student].getLowestGrade();
        }
    }
        
    return currentMin;
}

int Course::getHighestGrade() {
    int currentMax = -1;
        
    for (int student = 0; student < numStudents; ++student) {
        if (students[student].getHighestGrade() > currentMax || currentMax == -1) {
            currentMax = students[student].getHighestGrade();
        }
    }
        
    return currentMax;
}

double Course::getAverageGrade() {
    double total = 0.0;
        
    for (int student = 0; student < numStudents; ++student) {
        total += students[student].getAverageGrade();
    }
    
    // Handle special case of 0 students
    if (numStudents == 0) {
        return 0;
    }
    
    return total / numStudents;
}

void Course::printStudents() {
    for (int student = 0; student < numStudents; ++student) {
        cout << students[student].printableSummary() << endl;
    }
}
