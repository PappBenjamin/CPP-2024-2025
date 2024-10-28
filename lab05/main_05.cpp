#include <iostream>
#include "QuizGame.h"
using namespace std;



int main()
{
    string name = "Quiz1";
    string filename = "in.txt";

    quiz q(name, filename);
//    q.printQuiz();


    //////////TESTS///////////

    QuizGame qg(q);
    qg.startGame();
}