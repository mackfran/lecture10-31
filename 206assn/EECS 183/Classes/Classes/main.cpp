#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
#include "Course.h"

using namespace std;


/**
 * Requires: a reference to an existing Course instance and the name of a file
 *           with student data
 * Modifies: myCourse
 * Effects : Attempts to open the passed filename for reading, then creates a new
 *           Student instance for each student in the file and adds the grades
 *           following each student's name to that Student instance.  Each
 *           student is added to the passed Course instance.  Returns the number
 *           of students added to the passed Course instance or 0 if, for whatever
 *           reason, no students were added.
 */
int addStudentsToCourseFromFile(Course &myCourse, const string fileName);

// Read in information about a course's students from a file and print out summary information
// DO NOT MODIFY
int main(int argc, const char * argv[]) {
    Course myCourse ("EECS 183");
    
    if (addStudentsToCourseFromFile(myCourse, "data.txt") == 0) {
        cout << "ERROR: No students added" << endl;
        return 1;
    }
    
    cout << myCourse.getName() << endl;
    cout << "Course average: " << myCourse.getAverageGrade() << endl;
    cout << "Lowest grade in the course: " << myCourse.getLowestGrade() << endl;
    cout << "Highest grade in the course: " << myCourse.getHighestGrade() << endl;
    cout << "Student summary: " << endl;
    myCourse.printStudents();
    
    return 0;
}


int addStudentsToCourseFromFile(Course &myCourse, const string fileName) {
    
    // Declare a variable for the input file called infile
    ifstream infile;
    
    // Open the passed file name
    infile.open("data.txt");
    
    // Print error message and return if error opening file
    if (!infile) {
        cout << "ERROR: File not found: " << fileName << endl;
        return 0;
    }
    
    // Read student names and grades from the input file
    string name = "";
    while (getline(infile, name)) {
        // Create a new Student instance with the name read from the file
        Student current_student = Student(name);
        
        // Read all of the grades for the current student
        int score;
        while (infile >> score) {
            // Add the grade we just read in to the current student
            current_student.addGrade(score);
            
        }
        // Clear the fail state that results from trying to covert a student
        // name into a grade
        infile.clear();
        
        // Add the current student to the course
        myCourse.addStudent(current_student);
    }
    
    // Close the input file
    infile.close();
    
    // Return the number of students added to the course
    return myCourse.getNumStudents();

}

