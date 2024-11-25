#ifndef LAB10_GRADUATIONDAO_H
#define LAB10_GRADUATIONDAO_H

#include "Student.h"
#include <fstream>


class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}
    void enrollStudents(const string &filename);
    void saveGradesForSubject(const string &subject, const string &filename);
    void computeAverage();
    [[nodiscard]] int numEnrolled() const;
    [[nodiscard]] int numPassed() const;
// throws out_of_range exception for nonexistent id
    Student findById(int id) const;
    double getAverageBySubject(const string &subject) const;

};


#endif //LAB10_GRADUATIONDAO_H
