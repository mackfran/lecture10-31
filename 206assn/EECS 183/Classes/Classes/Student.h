/**
 * Student.h
 *
 * EECS 183, Fall 2015
 * Assignment 4: File I/O and classes
 *
 * Header file for the Student class.
 * This file is used to tell other code (e.g., main.cpp) what functionality the
 * Student class exposes, but does not share how that functionality is implemented.
 *
 * Do NOT modify this file.
 *
 */

#ifndef Student_h
#define Student_h

#include <string>

using namespace std;

const int MAX_NUM_GRADES = 20;

class Student {
private:
    /**
     * Instance variables that represent a student
     * Marked as private so that they are not able to be changed outside of this
     * class
     */
    
    // The full name of this student
    string name;
    
    // An array of grades recorded for this student
    int grades[MAX_NUM_GRADES] = { };
    
    // The number of valid grades for this student, used to know the upper bound
    // of the grades[] array
    int numGrades = 0;
    
public:
    /**
     * Requires: name of the student
     * Modifies: name
     * Effects : Student constructor for when only a student name is given.
     *           Note that numGrades is 0 and grades[] is all 0's, given by
     *           their declarations.
     */
    Student(string name);
    
    /**
     * Requires: nothing
     * Modifies: name
     * Effects : Default Student constructor.  name is set to be an empty string.
     *           Note that numGrades is 0 and grades[] is all 0's, given by
     *           their declarations.
     */
    Student();
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns the name of this Student instance.
     */
    string getName();
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns the number of grades contained by this Student instance.
     */
    int getNumGrades();
    
    /**
     * Requires: An integer (score) representing the grade to add, 0 to 100 inclusive
     * Modifies: grades[] and numGrades
     * Effects : Adds the passed score to the list of grades for this Student
     *           instance and increments the number of grades that this Student
     *           instance contains.
     */
    void addGrade(int score);
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns the lowest grade in the list of grades for this
     *           Student instance.  Returns -1 if there are no grades.
     */
    int getLowestGrade();
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns the highest grade in the list of grades for this
     *           Student instance.  Returns -1 if there are no grades.
     */
    int getHighestGrade();
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Calculates and returns the average grade given all of this
     *           Student instance's grades.  Returns 0 if there are no grades.
     */
    double getAverageGrade();
    
    /**
     * Requires: nothing
     * Modifies: nothing
     * Effects : Returns a string, suitable for printing, that contains this
     *           Student instance's name, average grade, and the number of
     *           grades stored.
     */
    string printableSummary();
};

#endif /* Student_h */
