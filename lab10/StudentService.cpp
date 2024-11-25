#include "StudentService.h"

bool StudentServiceImpl::isEnrolled(int id) const
{
    try
    {
        Student temp = this->dao->findById(id);
    }
    catch(const std::exception& e)
    {
        return false;
    }

    return true;

}

vector<string> StudentServiceImpl::getSubjects(int id) const {

    try
    {
        Student temp = this->dao->findById(id);

        map<string,double> m =  temp.getGrades();

        vector<string> subjects;

        for(auto const &i:m)
        {
            subjects.push_back(i.first);
        }

        return subjects;
    }
    catch(const std::exception& e)
    {
        cout << "No student with this id" << endl;
        exit(-1);
    }


}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {

    try
    {
        Student temp = this->dao->findById(id);
        map<string,double> m =  temp.getGrades();

        return m[subject];
    }
    catch(const std::exception& e)
    {
        cout << "No student with this id" << endl;
        return 0;
    }


}

double StudentServiceImpl::getAverage(int id) const {
    try
    {
        Student temp = this->dao->findById(id);

        return temp.getAverage();
    }
    catch(const std::exception& e)
    {
        cout << "No student with this id" << endl;
        return 0;
    }
}

bool StudentServiceImpl::isPassed(int id) const {
    try
    {
        Student temp = this->dao->findById(id);
        temp.computeAverage();
        return temp.getAverage() > 0;
    }
    catch (const std::exception& e)
    {
        cout << "No student with this id" << endl;
        return false;
    }
}
