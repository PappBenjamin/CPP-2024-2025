#ifndef LAB5_QUESTION_H
#define LAB5_QUESTION_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>

#include "Answer.h"


class Question {

private:
    string text;
    int correctAnswer;
    vector<Answer> answers;

public:

    /////////////////////CONSTRUCTORS/////////////////////////

    Question(string text);
    Question(){this->text = "";};


    /////////////////////GETTERS AND SETTERS/////////////////////

    string getText();
    vector<Answer> getAnswers();
    int getCorrectAnswer();

    void setText(string text);
    void addAnswer(Answer answer);
    void setCorrectAnswer(int correctAnswer);


    /////////////////////METHODS///////////////////////////////


    void clearAnswers();
};


#endif //LAB5_QUESTION_H
