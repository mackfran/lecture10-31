#ifndef PERSONALITY_H
#define PERSONALITY_H

/**
 * Personality.h
 *
 * EECS 183: Project 4
 *
 * Header file for the Personality class.
 * Do NOT modify this file.
 */

#include<string>

using namespace std;

#include "Attribute.h"


// a default Personality has this number of points for all attributes
const int DEFAULT_POINTS = 5;

const int MIN_POINTS = 0;
const int MAX_POINTS = 10;

// List of all the attributes that make up a personality
const string ATTRIBUTE_NAMES[MAX_NUM_ATTRIBUTES] = {
    "Openness to Experience",
    "Conscientiousness",
    "Extraversion",
    "Agreeableness",
    "Neuroticism"
};


class Personality {

public:
    /**
     * Requires: Nothing.
     * Modifies: points
     * Effects:  Resets the points array to its default state, where each
     *           attribute has DEFAULT_POINTS.
     * Note:     DEFAULT_POINTS is declared above as a const
     */
    void reset();


    /**
     * Requires: Nothing.
     * Modifies: points
     * Effects:  Default constructor.
     *           Initializes the points array to its default state, where each
     *           attribute has DEFAULT_POINTS.
     */
    Personality();


    /**
     * Requires: Nothing.
     * Modifies: points
     * Effects:  Adjust the current value of this Personality by the given
     *           Attribute. Adds the points of inAttribute to the
     *           current value of that attribute in this Personality.
     *           The Attribute index corresponds to the index in the points
     *           array. If addition of a negative points value results in a
     *           value that is below MIN_POINTS, the value
     *           stored in the points array will be MIN_POINTS.
     *           If an addition surpasses MAX_POINTS, then the value stored
     *           into the points array will be MAX_POINTS.
     */
    void adjustPersonality(Attribute &inAttribute);


    /**
     * Requires: outs is in a good state.
     * Modifies:   outs.
     * Effects:  Prints out the personality profile (see example in the spec).
     * Format:   1st prints out
     *           "Your EECS Harmony Personality Profile"
     *           followed by
     *               text_from_ATTRIBUTE_NAMES[i]: current_corresponding_Attribute_Value
     *                as found in points[i]
     *               ...( repeats for all attributes )
     * Note:     Refer to the spec for a full example of the output format.
     * Note:     the array ATTRIBUTE_NAMES -- declared at the top of this
     *           file -- will be helpful in printing this information
     */
    void write(ostream &outs);


private:
    /**
     * Array of the personality points. For example, points[0] refers to
     * how many "Openness to Experience" points this Personality has.
     */
    int points[MAX_NUM_ATTRIBUTES];

};

#endif
