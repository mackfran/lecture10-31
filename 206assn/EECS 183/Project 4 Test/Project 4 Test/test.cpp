/**
 * test.cpp
 *
 * EECS 183, Fall 2015
 * Project 4: EECS Harmony Test Suite
 *
 * Pratik Joshi
 * Mackenzie Francisco
 *
 * prjoshi
 * mackfran
 *
 * This tests all of the possible bugs in our code and outputs a message if one 
 * is found
 */

#include <iostream>
#include "Personality.h"
#include "Question.h"
#include "Answer.h"
#include "Attribute.h"

void test_Attribute_construct_default();

void test_Attribute_construct_2param();

void test_Attribute_setIndex();

void test_Attribute_setPoints();

void test_Attribute_readwrite();

void test_Answer_construct();

void test_Answer_setAttribute();

void test_Answer_setText();

void test_Answer_readwrite();

void test_Personality();

void test_Question_addAnswer();

void test_Question_getNumAnswers();

void test_Question_getAttributeOfAnswer();

void test_Question_setQuestionPrompt();

/**
 * Declare more test functions here
 * It is a good idea to test all constructors
 * It is a good idea to test all member functions that modify member variables
 * It is a good idea to test read() and write()
 */

int main() {
    test_Attribute_construct_default();
    test_Attribute_construct_2param();
    test_Attribute_setIndex();
    test_Attribute_setPoints();
    test_Attribute_readwrite();
    test_Answer_construct();
    test_Answer_setAttribute();
    test_Answer_setText();
    test_Answer_readwrite();
    test_Personality();
    test_Question_addAnswer();
    test_Question_getAttributeOfAnswer();
    test_Question_setQuestionPrompt();

    return 0;
}


void test_Attribute_construct_default() {
    // checks if the construct works
    Attribute att;

    if (att.getIndex() != 0) {
        cout << "bug in Attribute default constructor" << endl;
    }

    if (att.getPoints() != 0) {
        cout << "bug in Attribute default constructor" << endl;
    }
}


void test_Attribute_construct_2param() {
    // tests values that should work
    Attribute att1(4, 5);
    if (att1.getIndex() != 4) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    if (att1.getPoints() != 5) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    // tests an index that is too low
    Attribute att2(-1, 5);
    if (att2.getIndex() != 0) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    if (att2.getPoints() != 5) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    // tests an index that is too high
    Attribute att3(MAX_NUM_ATTRIBUTES, 5);
    if (att3.getIndex() != (MAX_NUM_ATTRIBUTES - 1)) {
        cout << "bug in Attribute non-default constructor" << endl;
    }

    if (att3.getPoints() != 5) {
        cout << "bug in Attribute non-default constructor" << endl;
    }
}

void test_Attribute_setIndex() {
    // checks if setIndex works properly
    Attribute att(4, 5);

    att.setIndex(0);
    if (att.getIndex() != 0) {
        cout << "bug in Attribute::setIndex()" << endl;
    }

    if (att.getPoints() != 5) {
        cout << "bug in Attribute::setIndex()" << endl;
    }

    // tests an index that is too low
    att.setIndex(-1);
    if (att.getIndex() != 0) {
        cout << "bug in Attribute::setIndex()" << endl;
    }

    if (att.getPoints() != 5) {
        cout << "bug in Attribute::setIndex()" << endl;
    }

    // tests an index that is too high
    att.setIndex(MAX_NUM_ATTRIBUTES);
    if (att.getIndex() != (MAX_NUM_ATTRIBUTES - 1)) {
        cout << "bug in Attribute::setIndex()" << endl;
    }

    if (att.getPoints() != 5) {
        cout << "bug in Attribute::setIndex()" << endl;
    }
}


void test_Attribute_setPoints() {
    Attribute attribute1(4, 5);
    Attribute att1(1, 2);
    
    // checks if points is valid
    attribute1.setPoints(-1);
        if (attribute1.getPoints() != -1) {
            cout << "bug in Attribute::setPoints()" << endl;
        }
    
        if (attribute1.getIndex() != 4) {
            cout << "bug in Attribute::setPoints()" << endl;
    }
    attribute1.setPoints(0);
        if (attribute1.getPoints() != 0) {
            cout << "bug in Attribute::setPoints()" << endl;
        }
    
        if (attribute1.getIndex() != 4) {
            cout << "bug in Attribute::setPoints()" << endl;
        }
    
    att1.setPoints(-1);
        if (att1.getPoints() != -1) {
            cout << "bug in Attribute::setPoints()" << endl;
        }
        if (att1.getIndex() != 1) {
            cout << "bug in Attribute::setPoints()" << endl;
        }
    att1.setPoints(0);
        if (att1.getPoints() != 0) {
            cout << "bug in Attribute::setPoints()" << endl;
        }
        if (att1.getIndex() != 1) {
            cout << "bug in Attribute::setPoints()" << endl;
        }
    
}

void test_Attribute_readwrite(){
    // tests read and write for attribute
    Attribute attribute1;
    attribute1.write(cout);
    cout << endl;
}


void test_Answer_construct(){
    Answer answer;
    Attribute attribute2 = answer.getAttribute();
    if (answer.getText() != ""){
        cout << "bug in Answer::Answer()" << endl;
    }
    
    if (attribute2.getPoints() != 0) {
        cout << "bug in Answer::Answer()" << endl;
    }
    if (attribute2.getIndex() != 0) {
        cout << "bug in Answer::Answer()" << endl;
    }
    
}


void test_Answer_setAttribute(){
    Attribute att1(0,1);
    Attribute attribute1(1,2);
    Attribute attribute3;
    Answer answer;
    
    // checks if setAttribute works
    answer.setAttribute(att1);
        if ((answer.getAttribute()).getPoints() != 1) {
            cout << "bug in Answer::setAttribute()" << endl;
        }
    answer.setAttribute(attribute1);
        if ((answer.getAttribute()).getPoints() != 2) {
            cout << "bug in Answer::setAttribute()" << endl;
        }
    
    answer.setAttribute(attribute3);
        if (answer.getAttribute().getPoints() != 0) {
            cout << "bug in Answer::setAttribute()" << endl;
        }
    
        if (answer.getAttribute().getIndex() != 0) {
            cout << "bug in Answer::setAttribute()" << endl;
        }

    if ((answer.getAttribute()).getIndex() != 1) {
        cout << "bug in Answer::setAttribute()" << endl;
    }
    
}


void test_Answer_setText(){
    
    // checks if setText works
    Answer answer;
    string a = "aaaaa";
    string b = "i like cats";
    string c = "a b c";
    
    answer.setText(a);
        if (answer.getText() != "aaaaa"){
            cout << "bug in Answer::setText()" << endl;
        }
    
    answer.setText(b);
        if (answer.getText() != "i like cats"){
            cout << "bug in Answer::setText()" << endl;
        }
    
    answer.setText(c);
        if (answer.getText() != "a b c"){
            cout << "bug in Answer::setText()" << endl;
        }
}

void test_Answer_readwrite(){
    
    // checks if read and write for Answer work
    Answer answer;
    answer.write(cout);
}

void test_Personality(){
    
    // checks if Personality works correctly
    Personality personality;
    Attribute attribute1(5,5);
    
    personality.write(cout);
    personality.adjustPersonality(attribute1);
    
    personality.write(cout);
    personality.reset();
    
    personality.write(cout);
    
    Attribute att1(1,1);
    
    personality.write(cout);
    personality.adjustPersonality(att1);
    
    personality.write(cout);
    personality.reset();
    
    personality.write(cout);
}

void test_Question_addAnswer(){
    
    // checks if addAnswer works correctly
    Question ques1;
    
    Attribute attribute5(1, 5);
    string text1 = "aaaaa";
    Answer answer1;
    answer1.setAttribute(attribute5);
    answer1.setText(text1);
    
    Attribute attribute6(2, 4);
    string text2 = "xyz";
    Answer answer2;
    answer2.setAttribute(attribute6);
    answer2.setText(text2);
    
    ques1.addAnswer(answer1);
    ques1.addAnswer(answer2);
    ques1.write(cout);
}

void test_Question_getNumAnswers(){
    
    // checks if getNumAnswers in Question works correctly
    Question quest;
    if (quest.getNumAnswers() != 0){
        cout << "bug in Question::getNumAnswers()" << endl;
    }
    Attribute attribute7(1, 5);
    string text1 = "aaaaa";
    Answer answer;
    answer.setAttribute(attribute7);
    answer.setText(text1);
    
    quest.addAnswer(answer);
    if (quest.getNumAnswers() != 1){
        cout << "bug in Question::getNumAnswers()" << endl;
    }
}

void test_Question_getAttributeOfAnswer(){
    
    // chekcs if getAttributeOfAnswer works
    Question ques;
    
    Attribute attribute8(1, 5);
    string text1 = "aaaaa";
    Answer answer;
    answer.setAttribute(attribute8);
    answer.setText(text1);
    ques.addAnswer(answer);
    
    if(ques.getAttributeOfAnswer(1).getIndex() != 1){
        cout << "bug in Question::getAttributeOfAnswer()" << endl;
    }
    if(ques.getAttributeOfAnswer(1).getPoints() != 5){
        cout << "bug in Question::getAttributeOfAnswer()" << endl;
    }
    
    Attribute attribute9(0, 4);
    string text2 = "aaaaa";
    Answer answer1;
    answer1.setAttribute(attribute9);
    answer1.setText(text2);
    ques.addAnswer(answer1);
    
    if(ques.getAttributeOfAnswer(1).getIndex() != 0){
        cout << "bug in Question::getAttributeOfAnswer()" << endl;
    }
    if(ques.getAttributeOfAnswer(1).getPoints() != 4){
        cout << "bug in Question::getAttributeOfAnswer()" << endl;
    }
}



void test_Question_setQuestionPrompt(){
    
    // checks if setQuestionPrompt works
    Question ques;
    string text = "abc";
    ques.setQuestionPrompt(text);
    cout << ques.getQuestionPrompt() << endl;
    
    Question ques1;
    string text1 = "aaaaa";
    ques1.setQuestionPrompt(text1);
    cout << ques1.getQuestionPrompt() << endl;
}
