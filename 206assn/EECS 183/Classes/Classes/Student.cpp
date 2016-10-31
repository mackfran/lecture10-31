/**
 * Student.cpp
 *
 * EECS 183, Fall 2015
 * Assignment 4: File I/O and classes
 *
 * Mackenzie Francisco
 * mackfran
 *
 */

#include "Student.h"
#include <string>

using namespace std;

Student::Student(string studentName) {
    name = studentName;
}
    
Student::Student() {
    name = "";
}
    
string Student::getName() {
    return name;
}

int Student::getNumGrades() {
    return numGrades;
}

void Student::addGrade(int score) {
    grades[numGrades] = score;
    numGrades++;
}

int Student::getLowestGrade() {
    if (numGrades == 0) {
        return -1;
    }
    int lowestGrade = grades[0];
    for (int grade = 0; grade < numGrades; ++grade) {
        if (grades[grade] < lowestGrade) {
            lowestGrade = grades[grade];
        }
    }
    return lowestGrade;
}

int Student::getHighestGrade() {
    if (numGrades == 0) {
        return -1;
    }
    int highestGrade = grades[0];
    for (int grade = 0; grade < numGrades; ++grade) {
        if (grades[grade] > highestGrade) {
            highestGrade = grades[grade];
        }
    }
    return highestGrade;
}

double Student::getAverageGrade() {
    int total = 0;
        
    for (int grade = 0; grade < numGrades; ++grade) {
        total += grades[grade];
    }
    
    // Handle special case of no grades
    if (numGrades == 0) {
        return 0;
    }
    
    return ((double) total) / numGrades;
}

string Student::printableSummary() {
    return getName() + "\n" + to_string((int)getAverageGrade()) + " average, given " + to_string(numGrades) + " grades";
}
