/**
 * Attribute.cpp
 *
 * Pratik Joshi
 * Mackenzie Francisco
 *
 * prjoshi
 * mackfran
 *
 * EECS 183: Project 4
 *
 * This class represents personality attributes that can be
 *      applied to the Personality class. Each attribute consists
 *      of an index, which uniquely identifies an Attribute, and
 *      a point value, which determines how much a Personality is
 *      affected when this Attribute is applied.
 */

#include "Attribute.h"


Attribute::Attribute() {
    // initializes index and points to 0
    index = 0;
    points = 0;
}


int Attribute::getValueWithinRange(int value) {
    // if value is in range, returns value
    if (0 <= value && value < MAX_NUM_ATTRIBUTES){
        return value;
    }
    // if value is greater than (MAX_NUM_ATTRIBUTES - 1), returns
    //      (MAX_NUM_ATTRIBUTES - 1)
    else if (value > (MAX_NUM_ATTRIBUTES - 1)){
        value = MAX_NUM_ATTRIBUTES - 1;
        return value;
    }
    // else returns 0 when value is less than 0
    return 0;
}


Attribute::Attribute(int inIndex, int inPoints) {
    // sets index and points to the correspoding parameters after
    //      checking inIndex for validity
    index = getValueWithinRange(inIndex);
    points = inPoints;
}

int Attribute::getIndex()  {
    // returns the unique identifier index of this Attribute
    return index;
}


int Attribute::getPoints()  {
    // returns the number of points for this Attribute
    return points;
}


void Attribute::setIndex(int inIndex) {
    // sets index to the corresponding parameter after checking
    //      for validity
    index = getValueWithinRange(inIndex);
}

void Attribute::setPoints(int inPoints) {
    // sets points to the corresponding parameter
    points = inPoints;
}


void Attribute::read(istream &ins) {
    // if ins is in the good state, reads in values from ins to
    //      index and points after checking the index read in
    //      for validity
    if (ins.good()){
        ins >> index;
        index = getValueWithinRange(index);
        ins >> points;
    }
    // if ins is in the fail state, clears the input stream and
    //      prints error message
    if (ins.fail() ) {
        index = 0;
        points = 0;
        ins.clear();
        string restOfLine;
        getline(ins,restOfLine);
        cout << "Attribute: read failed on following data: " << restOfLine << endl;
    }

}


void Attribute::write(ostream &outs)  {
    // prints index and points to the output stream
    cout << index << " " << points;
}
