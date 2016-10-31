#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

/**
 * Attribute.h
 *
 * EECS 183: Project 4
 *
 * Header file for the Attribute class.
 * Do NOT modify this file.
 */

#include <iostream>

using namespace std;

// maximum number of Personality attributes
const int MAX_NUM_ATTRIBUTES = 5;

class Attribute {

public:

    // constructors

    /**
     * Requires: Nothing
     * Modifies: index, points
     * Effects: initializes index and points to 0
     */
    Attribute();


    /**
     * Requires: nothing
     * Modifies: index, points
     * Effects:  sets index and points to the corresponding parameters
     *           after checking inIndex for validity.  If the index
     *           parameter is invalid, it will be set to 0 or
     *           (MAX_NUM_ATTRIBUTES - 1), whichever is closer.  points is
     *           allowed to be any value.
     */
    Attribute(int inIndex, int inPoints);


    // accessors

    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the unique identifier index of this Attribute.
     */
    int getIndex();


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the number of points for this Attribute.
     */
    int getPoints();


    /**
     * Requires: Nothing.
     * Modifies: index.
     * Effects:  Sets index to the corresponding parameter
     *           after checking for validity.
     *           sets index to 0 if inIndex < 0
     *           sets index to MAX_NUM_ATTRIBUTES -1
     *                if inIndex is >= MAX_NUM_ATTRIBUTES
     *           set index to inIndex if inIndex is within range
     */
    void setIndex(int inIndex);


    /**
     * Requires: Nothing.
     * Modifies: points.
     * Effects:  Sets points to the corresponding parameter.
     */
    void setPoints(int inPoints);


    /**
     * Requires: ins is in the good state
     * Modifies: ins, index, points
     * Effects:  Reads in values from ins into index
     *           and points after checking the index read in for validity.
     *
     *           Although not needed for this project -- assumption is the
     *           datafile is perfect -- we have found that the following code
     *           gives me information if things go wrong and it won't cause
     *           issues within the autograder.
     *           if (ins.fail() ) {
     *              index = 0;
     *              points = 0;
     *              ins.clear();
     *              string restOfLine;
     *              getline(ins,restOfLine);
     *              cout << "Attribute: read failed on following data: "
     *                   << restOfLine << endl;
     *           }
     * Format:   index points
     * Note:     The data read in may be out of range.  So check what you
     *           you have read in before you update the member variables
     */
    void read(istream &ins);


    /**
     * Requires: outs is in the good state.
     * Modifies: outs.
     * Effects:  Prints index and points to the output stream.
     * Format:   index points (no newline printed)
     */
    void write(ostream &outs);


private:
    // every personality attribute has a unique index,
    // from must always be between 0 and MAX_NUM_ATTRIBUTES - 1, inclusive
    int index;


    // points associated with this attribute
    int points;


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns value when value is in the range
     *           0 <= value < MAX_NUM_ATTRIBUTES,
     *           returns 0 when value is less than 0, and
     *           returns (MAX_NUM_ATTRIBUTES - 1) when value is
     *           greater than (MAX_NUM_ATTRIBUTES - 1).
     */
    int getValueWithinRange(int value);

};

#endif
