/**
 * Answer.cpp
 *
 * Pratik Joshi
 * Mackenzie Francisco
 *
 * prjoshi
 * mackfran
 *
 * EECS 183: Project 4
 *
 * This class represents the selectable answers to EECS Harmony
 *      questions. Each answer contains the text of the answer
 *      and the personality attribute associated with the answer.
 */

#include "Answer.h"

Answer::Answer() {
    // initializes attrribute to the default attribute and
    //      text to an empty string
    Attribute attribute;
    text = "";
}

Attribute Answer::getAttribute(){
    // returns the attribute that this answer impacts
    return attribute;
}

void Answer::setAttribute(Attribute &inAttribute){
    // sets this answer's attribute to the inAttribute
    attribute = inAttribute;
}

string Answer::getText(){
    // returns the text of this answer
    return text;
}

void Answer::setText(string inText){
    // sets the answer text to the inText
    text = inText;
}

void Answer::read(istream &ins) {
    // initializes private data members from the input stream
    //      sets the value of this answer's attribute and the
    //      answer text by reading values from the ins
    attribute.read(ins);
    getline(ins, text);
}


void Answer::write(ostream &outs) {
    // writes the answer text to the output stream outs
    outs << text;
}
