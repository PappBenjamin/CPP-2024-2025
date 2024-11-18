#include "Manager.h"
#include <algorithm>
using namespace std;


void Manager::removeEmployee(Employee *&employee) {
    if(std::find(employees.begin(), employees.end(), employee) != employees.end())
    {
        employees.erase(std::find(employees.begin(), employees.end(), employee));
    }
    else
    {
        throw logic_error("Employee not found");
    }

}

void Manager::print(ostream &os)
{
    os << "Manager: " << this->Fname << " " << this->Lname << endl;
    os << "Employees: " << endl;
    for(Employee* employee : employees)
    {
        cout << "\t";
        employee->print(os);
    }
}

void Manager::printManager(ostream & os)
{
    os << "Manager: " << this->Fname << " " << this->Lname << ", bYear: " << this->birthYear << ", ID: " << this->id << endl;
}
