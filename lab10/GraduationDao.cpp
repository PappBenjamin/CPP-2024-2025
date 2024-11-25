#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename)
{
    ifstream names(filename);
    int id;
    string Fname,Lname;

    while(names >> id >> Fname >> Lname)
    {
        Student temp(id,Fname,Lname);
        this->students.insert({id,temp});
    }

}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename)
{
    ifstream file(filename);
    int id;
    double grade;

    while(file >> id >> grade)
    {
        this->students.find(id)->second.addGrade(subject,grade);
    }

}

void GraduationDao::computeAverage()
{
    for(auto &student : this->students)
    {
        student.second.computeAverage();
    }

}

int GraduationDao::numEnrolled() const {
    return this->students.size();
}

int GraduationDao::numPassed() const {
    int count = 0;

    for(auto &student : this->students)
    {
        if(student.second.getAverage() > 0) {count++;}
    }

    return count;
}

Student GraduationDao::findById(int id) const
{
    if(this->students.find(id) == this->students.end())
    {
        throw domain_error("Student not found");
    }
    return this->students.find(id)->second;
}

double GraduationDao::getAverageBySubject(const string &subject) const
{
    double sum = 0;
    int count = 0;

    for(auto student : this->students)
    {
        sum += student.second.getGrade(subject);
        count++;
    }

    return sum / count;
}
