/**
 * Course.h
 *
 * EECS 183, Fall 2015
 * Assignment 4: File I/O and classes
 *
 * Header file for the Course class.
 * This file is used to tell other code (e.g., main.cpp) what functionality the
 * Course class exposes, but does not share how that functionality is implemented.
 *
 * Do NOT modify this file.
 *
 */

#ifndef Course_h
#define Course_h

#include <iostream>
#include "Student.h"

using namespace std;

const int MAX_NUM_STUDENTS = 100;

class Course {
private:
    /**
     * Instance variables that represent a course
     * Marked as private so that they are not able to be changed outside of this
     * class
     */
    
    // The name of this course (e.g., EECS 183)
    string name;
    
    // An array that holds all of the students that have been added to this course
    Student students[MAX_NUM_STUDENTS];
    
    // The number of students in this course, used to know the upper bound of
    // the students[] array
    int numStudents = 0;
    
public:
    /**
     * Requires: name of the course
     * Modifies: nothing
     * Effects : Constructor for when only a course name is given.
     *           Note that numStudents is 0 and students[] is uninitialized,
     *           given by their declarations.
     */
    Course(string courseName);
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns the name of this Course instance.
     */
    // Function (getName) that returns the name (string) of this Course
    string getName();
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns the number of students contained by this Course instance.
     */
    // Function (getNumStudents) that returns the number of students (int) in
    // this course
    int getNumStudents();
    
    /**
     * Requires: A Student instance
     * Modifies: students[] and numStudents
     * Effects : Adds the passed student to the list of students for this Course
     *           instance and increments the number of students that this Course
     *           instance contains.
     */
    void addStudent(Student newStudent);
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns the lowest grade given all grades by all students in this
     *           Course instance.  Returns -1 if there are no students.
     */
    int getLowestGrade();
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns the highest grade given all grades by all students in this
     *           Course instance.  Returns -1 if there are no students.
     */
    int getHighestGrade();
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Calculates and returns the average grade given all of this
     *           Course instance's student's average grade.  Returns 0 if there
     *           are no grades.
     */
    double getAverageGrade();
    
    /**
     * Requires: nothing
     * Modifies: cout
     * Effects : Prints out the student summary for every student contained in
     *           this Course instance.
     */
    void printStudents();
};

#endif /* Course_h */
