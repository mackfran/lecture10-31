/**
 * birthdays.cpp
 *
 * Mackenzie Francisco
 * mackfran
 *
 * EECS 183: Project 2
 *
 * This program determines what day of the week a person was born given their 
   birthdate.
 */

#include <iostream>
#include <string>
#include <cmath>

using namespace std;


/**
 * Requires: nothing
 * Modifies: cout
 * Effects: prints out the initial heading for the program
 */
void printHeading();


/**
 * Requires: nothing
 * Modifies: cout
 * Effects:  prints out the final greeting for the program
 */
void printCloser();


/**
 * Requires: nothing
 * Modifies: cout 
 * Effects: prints the menu
 */
void printMenu();


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  prints the menu
 *           reads the input from the user
 *           checks to make sure the input is within range for the menu
 *           If not prints "Invalid menu choice"
 *           continues to print the menu and read an input until a valid one is entered
 *           returns the users choice of menu options

 */
int getMenuChoice();


/**
 * Requires: year is a Gregorian year
 * Modifies: nothing
 * Effects: Returns 'true' if the year is a leap year
 *          otherwise returns 'false'
 */
bool isLeapYear(int year);


/**
 * Requires: month, day, year may represent a date
 * Modifies: nothing
 * Effects:  Returns 'true' if the date is valid
 *           otherwise returns 'false'
 *           see the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);


/**
 * Requires: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed isValidDate()
 * Modifies: nothing
 * Effects:  Returns the value that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);


/**
 * Requires: day (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * Modifies: cout
 * Effects:  prints the day you were born on
 *           Sunday, Monday, ..., Saturday
 */
void printDayOfBirth(int day);


/**
 * Requires: nothing
 * Modifies: cout, cin
 * Effects:  Asks for the Month/day/year of their birth
 *           If the date is valid, it will print the day
 *              of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt
 */
void determineDayOfBirth();


/**
 * Base Project
 * Requires: nothing
 * Modifies: cout
 * Effects: prints "Under Construction"
 *
 * S'more version of this function
 * Requires: nothing
 * Modifies: cout, cin 
 * Effects:  reads the month and day of birthday
 *           loops through 10 years printing the day of the week
 *              the birthday falls on
 *            if the month/day is not valid, it prints nothing
 */
void print10Years();


int main() {
    int menuChoice = 0;
    
    printHeading();
    menuChoice = getMenuChoice();
    while (menuChoice != 3) {
        if (menuChoice == 1) {
            determineDayOfBirth();
        }
        else if (menuChoice == 2) {
            print10Years();
        }
        menuChoice = getMenuChoice();
    }
    if (menuChoice == 3) {
        printCloser();
    }
    
    return 0;
}


void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
}


void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl << endl;
}


void printMenu() {
    cout << endl << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Determine birthdays for the next 10 years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
}


int getMenuChoice() {
    int menuChoice = 0;
    
    printMenu();
    cin >> menuChoice;
    
    while (menuChoice != 3) {
        if (menuChoice == 1 || menuChoice == 2) {
            return menuChoice;
        }
        else {
            cout << "Invalid menu choice" << endl;
            if (cin.fail()) {
                cin.clear();
                string trash;
                getline(cin, trash);
            }
        }
        printMenu();
        cin >> menuChoice;
    }

    return menuChoice;
}


bool isLeapYear(int year) {
    
    if (year % 400 == 0) {
        return true;
    }
    else if (year % 100 == 0) {
        return false;
    }
    else if (year % 4 == 0) {
        return true;
    }
    
    return false;
}


bool isValidDate(int month, int day, int year) {
    
    if (year < 1752) {
        return false;
    }
    else if (year == 1752) {
        if (month < 9) {
            return false;
        }
        else if (month == 9 && day <= 13) {
            return false;
        }
        else {

        }
    }
    
    if (month == 1 && day >= 1 && day <= 31) {
        return true;
    }
    else if (month == 2) {
        if (isLeapYear(year)) {
            if (day >= 1 && day <= 29) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            if (day >= 1 && day <= 28) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    else if (month == 3 && day >= 1 && day <= 31) {
        return true;
    }
    else if (month == 4 && day >= 1 && day <= 30) {
        return true;
    }
    else if (month == 5 && day >= 1 && day <= 31) {
        return true;
    }
    else if (month == 6 && day >= 1 && day <= 30) {
        return true;
    }
    else if (month == 7 && day >= 1 && day <= 31) {
        return true;
    }
    else if (month == 8 && day >= 1 && day <= 31) {
        return true;
    }
    else if (month == 9 && day >= 1 && day <= 30) {
        return true;
    }
    else if (month == 10 && day >= 1 && day <= 31) {
        return true;
    }
    else if (month == 11 && day >= 1 && day <= 30) {
        return true;
    }
    else if (month == 12 && day >= 1 && day <= 31) {
        return true;
    }

    return false;
}


int determineDay(int month, int day, int year) {
    int century = 0;
    century = year / 100;
    year %= 100;
    
    if (month == 1) {
        if (year == 0) {
            --century;
            year = 99;
        }
        else {
            --year;
        }
        month = 13;
    }
    if (month == 2) {
        if (year == 0) {
            --century;
            year = 99;
        }
        else {
            --year;
        }
        month = 14;
    }
    
    int f = 0;
    f = int(day + floor((13 * (month + 1)) / 5) + year + floor(year / 4) +
            floor(century / 4) + 5 * century) % 7;

    return f;
}


void printDayOfBirth(int day) {
    
    if (day == 0) {
        cout << "Saturday";
    }
    else if (day == 1) {
        cout << "Sunday";
    }
    else if (day == 2) {
        cout << "Monday";
    }
    else if (day == 3) {
        cout << "Tuesday";
    }
    else if (day == 4) {
        cout << "Wednesday";
    }
    else if (day == 5) {
        cout << "Thursday";
    }
    else if (day == 6) {
        cout << "Friday";
    }
    
    return;
}


void determineDayOfBirth() {
    int month = 0;
    int day = 0;
    int year = 0;
    char slash;
    
    cout << "Enter your date of birth" << endl;
    cout << "format: month / day / year  -->" << endl;
    
    cin >> month;
    cin >> slash;
    cin >> day;
    cin >> slash;
    cin >> year;
    cin.clear();
    string trash;
    getline(cin, trash);
    
    if (isValidDate(month, day, year)) {
        day = determineDay(month, day, year);
        cout << "You were born on a: ";
        printDayOfBirth(day);
        cout << endl;
        cout << "Have a great birthday!!!" << endl;
    }
    else {
        cout << "Invalid date" << endl;
    }
    
    return;
}


void print10Years() {
    
    cout << "Under Construction";
    
    return;
}
