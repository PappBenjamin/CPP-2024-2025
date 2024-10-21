#include "Answer.h"

///////////////////////CONSTRUCTORS/////////////////////////

Answer::Answer(string text, bool isCorrect)
{
    this->text = text;
    this->isCorrect = isCorrect;

}

///////////////////GETTERS AND SETTERS/////////////////////

string Answer::getText()
{
    return this->text;
}
bool Answer::getIsCorrect()
{
   return this->isCorrect;
}

void Answer::setText(string text)
{
    this->text = text;
}
void Answer::setIsCorrect(bool isCorrect)
{
    this->isCorrect = isCorrect;
}

