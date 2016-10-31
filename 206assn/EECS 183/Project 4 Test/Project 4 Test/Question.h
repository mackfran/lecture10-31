#ifndef QUESTION_H
#define QUESTION_H

/**
 * Question.h
 *
 * EECS 183: Project 4
 *
 * Header file for the Question class.
 * Do NOT modify this file.
 */

#include <iostream>
#include <string>

using namespace std;

#include "Answer.h"
#include "Attribute.h"
#include "Personality.h"


// total possible number of choosable answers a Question can have
const int MAX_NUMBER_OF_ANSWERS = 10;


class Question {

public:
    /**
     * Requires: Nothing.
     * Modifies: numAnswers, questionPrompt.
     * Effects:  Initializes this question to one with an empty prompt
     *           and 0 answers.
     */
    Question();


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the number of answers for this question.
     */
    int getNumAnswers();


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the prompt of this question.
     */
    string getQuestionPrompt();


    /**
     * Requires: Nothing.
     * Modifies: questionPrompt.
     * Effects:  Sets the value of prompt of this question to inQuestionPrompt.
     */
    void setQuestionPrompt(string inQuestionPrompt);


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Returns the answer at index after checking its validity.
     *           If index is invalid, returns a default constructed Answer.
     */
    Answer getAnswer(int index);


    /**
     * Requires: Nothing.
     * Modifies: answers and numAnswers.
     * Effects:  Adds the inAnswer to the end of the answers array.
     *           If numAnswers >= MAX_NUMBER_OF_ANSWERS, no state is changed.
     */
    void addAnswer(Answer &inAnswer);


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Every question has a list of answers (Answer instances in
     *           answers). When a question gets answered, we need to get the
     *           attribute impacted by that choice.
     *
     *           Within harmony.cpp, this function allows a
     *           Personality instance to update the appropriate attribute
     *           when a question gets answered using the adjustPersonality
     *           member function.
     *
     *           To support this, this function returns the attribute associated
     *           with the selected answer (provided it is valid) so that it can
     *           be passed to the adjustPersonality member function of a
     *           Personality instance within harmony.cpp
     *
     *           answerNumber is valid of it is >= 1 and <= numAnswers
     *
     *           If answerNumber is not valid,
     *              this function returns a default constructed Attribute, i.e.,
     *                   Attribute().
     *
     *           Otherwise, it returns the attribute portion of the answers array
     *                  at index of answerNumber
     *           Remember, answers is an array (therefore zero based) and
     *           answerNumber is NOT zero-based. Make sure you adjust BEFORE
     *           you use this on the array answers.
     */
    Attribute getAttributeOfAnswer(int answerNumber);


    /**
     * Requires: ins is in the good state.
     * Modifies: ins, numAnswers, questionPrompt, and answers.
     * Effects:  Initialize numAnswers, questionPrompt, and answers by reading
     *           from ins.
     * Format:   #of answers followed by the question prompt
     *           the next lines are the answers
     *           (remember these are in the format of an Answer)
     * Example:  2What is your favorite color?
     *           1 2blue
     *           2 1red
     * Note:     You will need to assume that the number of answers and
     *           the number of actual answers match.
     * Note:     You will want to use addAnswer() in this one to make sure
     *           you don't overload the array.
     */
    void read(istream &ins);


    /**
     * Requires: outs is in the good state.
     * Modifies: outs.
     * Effects:  Prints the question and numbered answers to the output stream.
     * Format:   Do you enjoy EECS183?    <--this is the question prompt
     *           1) Yes                   <--these are the numbered answers
     *           2) No
     * Note: You should call write() on an Answer instance to print it out.
     */
    void write(ostream &outs);


private:
    /**
     * The number of chooseable answers for this question.
     * It must be between 0 and MAX_NUMBER_OF_ANSWERS inclusive.
     */
    int numAnswers;


    /**
     * The prompt, i.e. "What's your favorite color?"
     */
    string questionPrompt;


    /**
     * The array of chooseable Answers to the question.
     */
    Answer answers[MAX_NUMBER_OF_ANSWERS];


    /**
     * Requires: Nothing.
     * Modifies: Nothing.
     * Effects:  Puts value within range of minValue <= value <= maxValue.
     *           Returns value when value is in the range
     *           Returns minValue when value is < minValue
     *           Returns maxValue when value is > maxValue
     */
    int getValueWithinRange(int value, int minValue, int maxValue);

};

#endif
