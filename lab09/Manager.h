#ifndef LAB9_MANAGER_H
#define LAB9_MANAGER_H

#include "Employee.h"
#include "vector"



class Manager : public Employee {

private:
    vector<Employee*> employees;

public:
    const string MANAGER_MUNKAKOR = "manager";
    Manager(string Fname, string Lname, int bYear, string role) : Employee(Fname, Lname, bYear, role){};
    void addEmployee(Employee *employee)
    {
        employees.push_back(employee);
    }
    void removeEmployee(Employee *&employee);
    void removeEmployee(int index){employees.erase(employees.begin() + index);};
    int empSize(){return employees.size();};
    void print(ostream & os);
    void printManager(ostream & os);


};


#endif //LAB9_MANAGER_H
