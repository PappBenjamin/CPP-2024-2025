
#include "QuizGame.h"

QuizGame::QuizGame(quiz quiz)
{
    this->q = quiz;

}

void QuizGame::printResults()
{
   cout << "All results: " << endl;

   for(int i = 0; i < q.getQuestions().size(); i++)
   {
       cout << q.getQuestions()[i].getText() << ": " << q.getQuestions()[i].getCorrectAnswer() << endl;
   }
}
void QuizGame::printResult(int number)
{
    vector<Answer> answers = q.getQuestions()[number].getAnswers();

    for(int i = 0; i < answers.size(); i++)
    {
        cout << "\t\t" << answers[i].getText() << endl;
    }
}

Question QuizGame:: getQuestion(int number)
{
    return q.getQuestions()[number].getText();
}

void QuizGame:: printQuestion(int number)
{
    cout << q.getQuestions()[number].getText() << endl;
}
void QuizGame::printQuestions()
{
    for(int i = 0; i < q.getQuestions().size(); i++)
    {
        q.getQuestions()[i].printQuestion();
    }

}

bool QuizGame:: checkAnswer(int currentQuestion, int inputAnswer)
{
    if(inputAnswer == q.getQuestions()[currentQuestion].getCorrectAnswer())
    {
        return true;
    }

    return false;

}

void QuizGame:: startGame()
{

    cout << "Please enter the correct number: " << endl;

    for(int i = 0; i < q.getQuestions().size(); i++)
    {
        cout << "\t";
        printQuestion(i);

        printResult(i);

        int answer;
        cin >> answer;

        if(checkAnswer(i, answer))
        {
            cout << "Correct!" << endl;
        }
        else
        {
            cout << "Wrong!" << endl;
        }
    }

    cout << endl;
    this->printResults();
}

