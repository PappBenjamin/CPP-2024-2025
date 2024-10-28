#include "Question.h"

///////////////////////CONSTRUCTORS/////////////////////////

Question::Question(string text)
{
    this->text = text;
}


///////////////////GETTERS AND SETTERS/////////////////////


string Question::getText()
{
    return this->text;
}

vector<Answer> Question::getAnswers()
{
    return this->answers;
}

int Question::getCorrectAnswer()
{
    for(int i = 0; i < this->answers.size(); i++)
    {
        if(this->answers[i].getIsCorrect())
        {
            return i;
        }
    }

    return -1;
}

void Question::setText(string text)
{
    this->text = text;

}

void Question::setCorrectAnswer(int correctAnswer)
{
    this->answers[correctAnswer].setIsCorrect(true);
}

///////////////////METHODS///////////////////////////////

void Question::addAnswer(Answer answer)
{
    this->answers.push_back(answer);

}
void Question::clearAnswers()
{
    this->answers.clear();
}
void Question:: printQuestion()
{
   cout << this->text << endl;
}
void Question:: printAnswers()
{
    for(int i = 0; i < this->answers.size(); i++)
    {
        cout << "\t" << this->answers[i].getText() << endl;
    }
}


