#include "quiz.h"


//////////////CONSTRUCTORS///////////////

quiz::quiz(string &name)
{
    this->name = name;
}
quiz::quiz(string &  name, const string &fname)
{
    this->name = name;

    ifstream file(fname);
    if(!file.is_open())
    {
    cout << "File not found" << endl;
    return;
    }

    Question questTemp;// create new question

    string temp; // temporary string
    while(getline(file, temp))
    {

        ; // read line
        istringstream firstChar(temp); // get first character
        string temp2;
        firstChar >> temp2;

        if(temp2 == "Q")
        {
            questTemp.clearAnswers();
            questTemp.setText(temp.substr(2));
            continue;
        }

        if(temp2 == "A")
        {

            Answer answTemp(temp.substr(2));
            questTemp.addAnswer(answTemp);
            continue;
        }

        istringstream iss(temp2);
        int correct;
        iss >> correct;

        questTemp.getAnswers()[correct - 1].setIsCorrect(true);
        questTemp.setCorrectAnswer(correct - 1);

        this->questions.push_back(questTemp);
    }
}
quiz::quiz() {}



/////////////GETTERS///////////////
string quiz::getName()
{
    return this->name;
}

vector<Question> quiz::getQuestions()
{
    return this->questions;
}

/////////////FUNCTIONS///////////////

void quiz:: printQuiz()
{

    for(int i = 0; i < this->questions.size(); i++)
    {

        cout << questions[i].getText() << endl;

        for(int j = 0; j < questions[i].getAnswers().size(); j++)
        {
            cout << "\t" << questions[i].getAnswers()[j].getText() << endl;
        }

        cout << "Correct answer : " << questions[i].getCorrectAnswer() << endl;
        cout << endl;
    }
}
