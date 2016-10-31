#ifndef ANSWER_H
#define ANSWER_H

/**
 * Answer.h
 *
 * EECS 183: Project 4
 *
 * Header file for the Answer class.
 * Do NOT modify this file.
 */

#include <iostream>
#include <string>

using namespace std;

#include "Attribute.h"

class Answer {

public:
    /**
     * Requires: Nothing.
     * Modifies: private data members.
     * Effects:  Default constructor.
     *           Initializes attribute to the default attribute and
     *           text to an empty string
     * Note:     Don't over complicate this one.  Work on understanding
     *           what happens with constructors for the different datatypes
     *           what happens when you have
     *           Attribute attribute // what goes on behind the scenes
     *           string text // or track with your debugger
     */
    Answer();


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the attribute that this answer impacts.
     */
    Attribute getAttribute();


    /**
     * Requires: inAttribute is a valid Attribute.
     * Modifies:  attribute.
     * Effects:  Sets this answer's attribute to the inAttribute.
     */
    void setAttribute(Attribute &inAttribute);


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the text of this answer.
     */
    string getText();


    /**
     * Requires: Nothing.
     * Modifies: text.
     * Effects:  Set the answer text to the inText.
     */
    void setText(string inText);


    /**
     * Requires: ins to be in the good state.
     * Modifies: ins, attribute, text.
     * Effects:  Initializes private data members from the input stream.
     * Effects:  Sets the value of this answer's attribute and the answer
     *           text by reading values from the ins.
     * Format:   attribute text (space between attribute and text is optional)
     * Example:  2 2calm
     * Note:     you have a 'read' member function for type 'Attribute'
     *           this will work great to read 'attribute'
     *           also note that 'text' can be more than just one word, so you
     *           will want to use 'getline' for 'text'
     */
    void read(istream &ins);


    /**
     * Requires: outs to be in the good state.
     * Modifies: outs.
     * Effects:  Writes the answer text to the output stream outs.
     *           Note: it is only the 'text' portion that is written
     * Format:   text (no newline)
     * Example:  calm
     */
    void write(ostream &outs);


private:
    // The personality attribute associated with this answer.
    Attribute attribute;

    // The text for this answer.
    string text;

};

#endif
