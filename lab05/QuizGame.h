#ifndef LAB5_QUIZGAME_H
#define LAB5_QUIZGAME_H

#include <iostream>
#include <vector>

#include "quiz.h"

using namespace std;


class QuizGame{

private:
    quiz q;

public:
    QuizGame(quiz q);

    void printResults();
    void printQuestions();

    Question getQuestion(int number);
    void printQuestion(int number);
    void printResult(int number);

    bool checkAnswer(int currentQuestion, int inputAnswer);

    void startGame();



};


#endif //LAB5_QUIZGAME_H
