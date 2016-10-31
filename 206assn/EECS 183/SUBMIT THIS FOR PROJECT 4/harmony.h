#ifndef HARMONY_H
#define HARMONY_H

/**
 * harmony.h
 *
 *
 * EECS 183: Project 4
 *
 */

#include <iostream>
#include <fstream>
#include <string>

// used only for saveProfile()
#include <sstream>

using namespace std;

#include "Answer.h"
#include "Attribute.h"
#include "Personality.h"
#include "Question.h"


// number of options on the menu
const int NUM_MENU_OPTIONS = 5;

// maximum number of quizzes you can take
const int MAX_QUIZZES = 5;
const char * OUTPUT_FILE_NAME = "MyProfile.efc";


/**
 * The following functions are implemented for you.
 */

/**
 * Requires: inFile is in the good state.
 * Modifies: cout, inFile.
 * Effects:  Prompts user for a file name and opens inFile, reprompting
 *           if there are errors opening the file. Returns the file name.
 */
string openFile(ifstream &inFile);


/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints the welcome message.
 */
void printOpeningMessage();


/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints the main menu and prompts for a command.
 */
void printMenu();


/**
 * Requires: Nothing.
 * Modifies: cout.
 * Effects:  Prints the closing message.
 */
void printClosingMessage();


/**
 * Requires: Nothing.
 * Modifies: p.
 * Effects:  Writes the personality profile to an encoded file.
 * Note:     This function is intentionally obfusctated; you are not required
 *           to understand why or how it does what it does.
 */
void saveProfile(Personality &p);


/**
 * You must implement the following functions.
 */

/**
 * Requires: cin is in the good state, min <= max
 * Modifies: cin.
 * Effects:  Reads and returns a number from cin. Continually repeats until
 *           the number is in range [min, max] (see the spec for an example).
 * Note:     If the number is not valid, or if cin is not in a good state,
 *           print the error message already within this function
 *           clear the stream state
 *           and read all remaining on the line into a temp variable
 *           (this will have the effect of "dumping" all left on the line)
 */
int getNumberInRange(int min, int max);


/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects:  Returns true if and only if fileName is one of the
 *           strings in takenQuizFileNames[].
 *           Returns false otherwise.
 */
bool quizHasBeenTaken(string fileName, string takenQuizFileNames[MAX_QUIZZES],
                      int numberOfQuizzesTaken);


/**
 * Requires: cin is in the good state,
 *           quizFile has been opened and is in the good state.
 * Modifies: personality.
 * Effects:  Reads a quiz from quizFile and presents questions,
 *           one at a time to the user. Based on the user's response to each
 *           question, personality is updated.
 */
void takeQuiz(ifstream &quizFile, Personality &personality);

#endif
