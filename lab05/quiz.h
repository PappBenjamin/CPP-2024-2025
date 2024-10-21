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
    quiz(string &name);
    quiz(string & name, const string &fname);
    void printQuiz();
};


#endif //LAB5_QUIZ_H
