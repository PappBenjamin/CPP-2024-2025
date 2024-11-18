#include "Employee.h"

int Employee::count = 0;

void Employee::print(ostream &os)
{
    Person::print(os);
    os << "Role : " << this->role << " ID : " << this->id <<  endl;
}
