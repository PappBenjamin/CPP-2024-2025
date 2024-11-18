#ifndef LAB9_PERSON_H
#define LAB9_PERSON_H

#include "iostream"
#include "string"
using namespace std;


class Person {

protected:
    string Lname;
    string Fname;
    int birthYear;

public:
    Person(string Lname, string Fname, int birthYear) : Lname(Lname), Fname(Fname), birthYear(birthYear) {}

    virtual void print(ostream &os);
    const string &getLname() const;
    const string &getFname() const;
    int getBirthYear() const;

};


#endif //LAB9_PERSON_H
