#ifndef LAB10_STUDENT_H
#define LAB10_STUDENT_H

#include <iostream>
#include <string>
#include <map>

using namespace std;


class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(int id, const string &firstName, const string &lastName);
    int getId() const;
    void setId(int id);
    [[nodiscard]] const string &getFirstName()const;
    [[nodiscard]] const string &getLastName() const;
    void addGrade(const string& subject, double grade);
// throws out_of_range exception for nonexistent subject
    double getGrade(const string& subject);
    const map<string, double> &getGrades() const;
    void computeAverage();
    double getAverage() const;
    friend ostream& operator<<(ostream& os, const Student& student);

};


#endif //LAB10_STUDENT_H
