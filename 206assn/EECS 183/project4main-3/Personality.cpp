/**
 * Personality.cpp
 *
 * Pratik Joshi
 * Mackenzie Francisco
 *
 * prjoshi
 * mackfran
 *
 * EECS 183: Project 4
 *
 * This class consists of an array of integers that represent the
 *      number of points in each personality characteristic.
 */


#include <iostream>

#include "Personality.h"


void Personality::reset(){
    // resets each attribute in the points array to its default
    //      state with DEFAULT_POINTS
    for (int i = 0; i < MAX_NUM_ATTRIBUTES; i++){
        points[i] = DEFAULT_POINTS;
    }
}

Personality::Personality(){
    // initializes the points array to its default state where
    //      each attribute has DEFAULT_POINTS
    for (int i = 0; i < MAX_NUM_ATTRIBUTES; i++){
        points[i] = DEFAULT_POINTS;
    }
}

void Personality::adjustPersonality(Attribute &inAttribute){
    // adds the points of inAttribute to the current value of
    //      that attribute in this Personality
    points[inAttribute.getIndex()] += inAttribute.getPoints();
    
    // if addition results in a value below MIN_POINTS, value
    //      stored is MIN_POINTS
    if (points[inAttribute.getIndex()] < MIN_POINTS){
        points[inAttribute.getIndex()] = MIN_POINTS;
    }
    // if addition results in a value above MAX_POINTS, value
    //      stored is MAX_POINTS
    if (points[inAttribute.getIndex()] > MAX_POINTS){
        points[inAttribute.getIndex()] = MAX_POINTS;
    }
}

void Personality::write(ostream &outs) {
    // prints out personality profile starting with header,
    //      followed by attribute names with corresponding values
    cout << "Your EECS Harmony Personality Profile";
    for (int i = 0; i < MAX_NUM_ATTRIBUTES; i++){
        cout << ATTRIBUTE_NAMES[i] << ": " << points[i] << endl;
    }
}
