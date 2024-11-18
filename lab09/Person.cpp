#include "Person.h"

void Person::print(ostream &os)
{
    os << "Name: " << this->Fname << " " << this->Lname << "Birthday: " << this->birthYear << " ";
}
const string &Person::getLname() const {
    return Lname;
}
const string &Person::getFname() const {
    return Fname;
}
int Person::getBirthYear() const {
    return birthYear;
}
