#ifndef LAB9_EMPLOYEE_H
#define LAB9_EMPLOYEE_H

#include "Person.h"


class Employee : public Person {

protected:
    string role;
    int id;
    static int count;

public:
    Employee(string Fsname, string Lname, int bYear, string role) : Person(Fsname, Lname, bYear)
    {
        this->role = role;
        this->id = count++;

    }

    virtual void print(ostream & os);
};




#endif //LAB9_EMPLOYEE_H
