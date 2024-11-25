#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName)
{
    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
}

int Student::getId() const {
    return this->id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return this->firstName;
}
const string &Student::getLastName() const {
    return this->lastName;
}

void Student::addGrade(const string &subject, double grade) {
    this->grades[subject] = grade;

}
double Student::getGrade(const string &subject) {
    if(this->grades.empty()){return 0;}
    return this->grades[subject];
}
const map<string, double> &Student::getGrades() const {
    return this->grades;
}

void Student::computeAverage()
{
    if(this->grades["math"] < 5 || this->grades["romanian"] < 5 || this->grades["hungarian"] < 5){return;}

    double sum = 0;
    for (const auto &grade : this->grades) {
        sum += grade.second;
    }

    if(sum / this->grades.size() >= 6)
    {
        this->average = sum / this->grades.size();
    }

}
double Student::getAverage() const {
    return this->average;
}

ostream &operator<<(ostream &os, const Student &student) {
    for(const auto &grade : student.grades){
       os << grade.first << ": " << grade.second << endl;
    }
}

