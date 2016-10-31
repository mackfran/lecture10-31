/**
 * Question.cpp
 *
 * Pratik Joshi
 * Mackenzie Francisco
 *
 * prjoshi
 * mackfran
 *
 * EECS 183: Project 4
 *
 * This class represents a quiz quesiton that will be presented
 *      to the user. A Question instance consists of a text
 *      prompt for the question, a nubmer of answers, and an
 *      array of answers corresponding to the question.
 */

#include "Question.h"

Question::Question(){
    // initializes this question to one with an empty prompt
    //      and 0 answers
    numAnswers = 0;
    questionPrompt = "";
}

int Question::getNumAnswers(){
    // returns the number of answers for this question
    return numAnswers;
}

string Question::getQuestionPrompt(){
    // returns the prompt of this question
    return questionPrompt;
}

void Question::setQuestionPrompt(string inQuestionPrompt){
    // sets the value of this question's prompt to
    //      inQuestionPrompt
    questionPrompt = inQuestionPrompt;
}

Answer Question::getAnswer(int index){
    // if index is valid, returns the answer at index
    if (index >= 0 && index < MAX_NUMBER_OF_ANSWERS){
        return answers[index];
    }
    // if index is invalid, returns a default constructed Answer
    else{
        return Answer();
    }
}

int Question::getValueWithinRange(int value, int minValue, int maxValue){
    if (value >= minValue && value <= maxValue){
        return value;
    }
    else if (value < minValue){
        return minValue;
    }
    else if (value > maxValue){
        return maxValue;
    }
    return value;
}

void Question::addAnswer(Answer &inAnswer){
    // adds the inAnswer to the end of the answers array
    if (numAnswers < MAX_NUMBER_OF_ANSWERS){
        answers[numAnswers] = inAnswer;
        numAnswers++;
    }
}

Attribute Question::getAttributeOfAnswer(int answerNumber){
    // if answerNumber is valid, returns the attribute portion
    //      of the answers array
    if (answerNumber <= numAnswers && answerNumber > 0){
        return answers[answerNumber - 1].getAttribute();
    }
    // if answerNumber is invalid, returns a default constructed
    //      Attribute
    return Attribute();
}

void Question::read(istream &ins) {
    if (ins.good()) {
        // initializes numAnswers and questionPrmpt by reading
        //      from ins
        int numOfAnswers;
        ins >> numOfAnswers;
        numOfAnswers = getValueWithinRange(numOfAnswers, 0, MAX_NUMBER_OF_ANSWERS);
        
        getline(ins, questionPrompt);
        
        // initializes answers by reading from ins
        Answer answer1;
        for (int i = 0; i < numOfAnswers; i++) {
            answer1.read(ins);
            addAnswer(answer1);
        }
    }
}


void Question::write(ostream &outs) {
    if (outs.good()) {
        // prints the question to the output stream
        outs << questionPrompt << endl;
        // prints numbered answers to the output stream
        for (int i = 0; i < numAnswers; i++) {
            outs << i + 1 << ")" << " ";
            answers[i].write(outs);
            cout << endl;
        }
    }
}
