#ifndef LAB10_STUDENTSERVICE_H
#define LAB10_STUDENTSERVICE_H

#include "GraduationDao.h"




class StudentService {
public:
    [[nodiscard]] virtual bool isEnrolled(int id) const= 0;
    [[nodiscard]] virtual double getResultBySubject(int id, const string& subject) const= 0;
    [[nodiscard]] virtual vector<string> getSubjects(int id) const= 0;
    [[nodiscard]] virtual double getAverage(int id) const= 0;
    [[nodiscard]] virtual bool isPassed(int id) const= 0;
};

class StudentServiceImpl : public StudentService{
    GraduationDao *dao;
public:
    explicit StudentServiceImpl(GraduationDao *dao) : dao(dao) {}
    [[nodiscard]] bool isEnrolled(int id) const override;
    [[nodiscard]] vector<string> getSubjects(int id) const override;
    [[nodiscard]] double getResultBySubject(int id, const string& subject) const override;
    [[nodiscard]] double getAverage(int id) const override;
    [[nodiscard]] bool isPassed(int id) const override;
};


#endif //LAB10_STUDENTSERVICE_H
