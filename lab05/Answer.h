#ifndef LAB5_ANSWER_H
#define LAB5_ANSWER_H


using namespace std;
#include <iostream>
#include <string>
#include <vector>


class Answer {

private:
    string text;
    bool isCorrect;

public:
    Answer(string text, bool isCorrect = false);

    string getText();
    bool getIsCorrect();

    void setText(string text);
    void setIsCorrect(bool isCorrect);

};


#endif //LAB5_ANSWER_H
