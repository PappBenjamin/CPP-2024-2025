#ifndef LAB5_QUIZ_H
#define LAB5_QUIZ_H

using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

#include "Question.h"
#include "Answer.h"


class quiz {

private:
    string name;
    vector<Question> questions;

public:

    ///////////////CONSTRUCTORS///////////////
    quiz(string &name);
    quiz(string & name, const string &fname);
    quiz();

    ///////////////GETTERS///////////////
    string getName();
    vector<Question> getQuestions();

    ///////////////FUNCTIONS///////////////

    void printQuiz();

};


#endif //LAB5_QUIZ_H
