/**
 * harmony.cpp
 *
 * Pratik Joshi
 * Mackenzie Francisco
 *
 * prjoshi
 * mackfran
 *
 * EECS 183: Project 4
 *
 * This file makes use of the implemented classes for this
 *      project.
 */

#include "harmony.h"

int main() {
    printOpeningMessage();

    // declares a variable of datatype Personality
    Personality personalityProfile;
    
    // declares variables to keep track of:
    //     all the filenames of the quizzes that have been taken
    //     and the number of quizzes that have been taken
    string fileNamesOfQuizzesTaken[MAX_QUIZZES] = {};
    int numQuizzesTaken = 0;
    
    bool done = false;

    while (!done) {
        printMenu();
            
        int userInput = 5;
            
        // reads which menu choice the user wants from the keyboard
        //       makes sure it's within range
        userInput = getNumberInRange(1, 5);
            
            
        if (userInput == 1) {
            // if user has taken all the quizzes, prints message
            if (numQuizzesTaken == MAX_QUIZZES) {
                cout << "You have already taken the maximum number of quizzes!"
                    << endl;
            }
            // else, creates an input stream instance, asks user for
            //       name of file to open and
            //       then opens the file for reading
            else {
                ifstream fileName;
                string quizName = openFile(fileName);
                
                // checks if quiz has been taken, prints message
                //      if it has
                if (quizHasBeenTaken(quizName,fileNamesOfQuizzesTaken, numQuizzesTaken)) {
                    cout << "You've already taken that quiz!" << endl;
                }
                else {
                    // saves the new file name to keep track of quizzes taken
                    fileNamesOfQuizzesTaken[numQuizzesTaken] = quizName;
                    // takes the quiz
                    takeQuiz(fileName, personalityProfile);
                    // updates how many quizzes have been taken
                    numQuizzesTaken++;
                }
            }
                
        } else if (userInput == 2) {
            // prints personality profile
            personalityProfile.write(cout);
                
        } else if (userInput == 3) {
            // saves personality profile to file
            saveProfile(personalityProfile);
                
        } else if (userInput == 4) {
            // resets personality profile
            personalityProfile.reset();
                
        } else if (userInput == 5) {
            // ends the loop
            done = true;
        }
    }
        
    printClosingMessage();
    return 0;
}

/**
 * You must implement the following functions.
 */

int getNumberInRange(int min, int max) {
    // reads a number from cin
    int menuChoice = 0;
    cin >> menuChoice;
    
    // if the number is not valid, or if cin is not in a good
    //      state, prints an arror message, clears the stream
    //      state, and reads all remaining on the line into a
    //      temp variable
    while (!(min <= menuChoice && menuChoice <= max) || !cin.good()) {
        cout << "Invalid response! Please enter a number between ";
        cout << min << " and " << max << ": " << endl;
        cin.clear();
        string restOfLine;
        getline(cin,restOfLine);
        cin >> menuChoice;
    }
    // returns the number from cin
    return menuChoice;
}

bool quizHasBeenTaken(string fileName, string takenQuizFileNames[MAX_QUIZZES], int numberOfQuizzesTaken) {
    // if fileName is one of the strings in takenQuizFileNames[],
    //      returns true
    for (int i = 0; i < numberOfQuizzesTaken; ++i) {
        if (takenQuizFileNames[i] == fileName) {
            return true;
        }
    }
    return false;
}


void takeQuiz(ifstream &quizFile, Personality &personality) {
    // gets quiz title from the file
    string quizName;
    getline(quizFile, quizName);
    
    // prints out a blank line, the name of the quiz, and a
    //      newline
    cout << endl << quizName << endl;
    
    // reads the number of questions from the file
    int numQuestions;
    quizFile >> numQuestions;
    
    // loops through all the questions
    for (int i = 1; i <= numQuestions; ++i) {
        cout << endl << "Question ";
        cout << i;
        cout << " out of ";
        cout << numQuestions;
        cout << endl;
        // declares a variable of datatype Question
        // uses this instance to read the next question from the
        //      file
        Question question1;
        question1.read(quizFile);
        // prints the question to cout
        question1.write(cout);
        
        cout << endl << "Enter your answer: ";
        
        // reads the answer from the keyboard, making sure that
        //      it is within range
        int answerInput;
        cin >> answerInput;
        question1.getAnswer(answerInput - 1);
        
        // gets the attribute of the answer chosen by user
        Attribute attribute1 = question1.getAttributeOfAnswer(answerInput);
        
        // applies that attribute to the personality instance
        personality.adjustPersonality(attribute1);
        
    }
    
    cout << endl << "Congratulations, you've finished the quiz!" << endl
    << "Be sure to take a look at your updated"
    << " EECS Harmony Personality Profile!"
    << endl;
    
    // closes the file
    quizFile.close();
}


/**
 * Do NOT change implementations of the following functions.
 */

string openFile(ifstream &inFile) {

    // get file name from user
    cout << endl << "Enter the quiz input file name: ";
    string quizFileName;
    cin >> quizFileName;

    // attempt to open file
    inFile.open(quizFileName.c_str());

    // keep asking until file is open
    while(!inFile) {
        inFile.clear();
        cout << "Couldn't open quiz input file!" << endl;
        cout << "Enter the quiz input file name: ";
        cin >> quizFileName;
        inFile.open(quizFileName.c_str());
    }

    return quizFileName;
}

void printOpeningMessage() {
    cout << "*************************************************" << endl
         << "*****             Welcome to the            *****" << endl
         << "*****    EECS Harmony Friendship Machine    *****" << endl
         << "*************************************************" << endl;
}

void printMenu() {
    cout << endl
         << "1) Take the Quiz" << endl
         << "2) Print Your Personality Profile" << endl
         << "3) Save Personality Profile to File" << endl
         << "4) Reset Personality Profile" << endl
         << "5) Quit" << endl << endl
         << "Enter command: ";
}

void printClosingMessage() {
    cout << "*************************************************" << endl
         << "*****        Thank you for using the        *****" << endl
         << "*****    EECS Harmony Friendship Machine    *****" << endl
         << "*************************************************" << endl;
}

void saveProfile(Personality &p) {
     stringstream whatIsThis;p.write(whatIsThis);int $;string soComplex;
     whatIsThis>>soComplex;int onbegrijpelijkharibo = 0;int $$$ = 2;int ___ =
     static_cast<int>(soComplex.length())+whatIsThis.good();
     ofstream xyz(OUTPUT_FILE_NAME);for(unsigned int x=xyz.good();x<___;x++)
     {whatIsThis>>soComplex;$$$ += 1;}for (unsigned int __=0;
     $$$*=8,$=71, __<___; onbegrijpelijkharibo+=1){for(;___>__;--___)
     {whatIsThis>>soComplex;onbegrijpelijkharibo = 10*isdigit(soComplex[
     soComplex.length() - 2*whatIsThis.good()]);onbegrijpelijkharibo +=
     soComplex[soComplex.length() - whatIsThis.good()] - $$$;
     xyz<<static_cast<char>(onbegrijpelijkharibo*___+$)<<'|';}}xyz.close();
}
