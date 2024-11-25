#include "StudentService.h"

int main()
{

    Student test1(1,"Willoughby","Rogers");
    test1.addGrade("math", 10);
    test1.addGrade("romanian", 5);
    test1.addGrade("hungarian", 8);

    test1.computeAverage();
    cout << "Willoughby's average: " << test1.getAverage() << endl;


    GraduationDao dao(2023);
    dao.enrollStudents("names.txt");
    cout << "Number of enrolled students: " << dao.numEnrolled() << endl;

    string subjects[] = {"math", "romanian", "hungarian"};
    int numSubjects = 3;

    for (int i = 0; i < numSubjects; ++i)
    {
        dao.saveGradesForSubject(subjects[i], subjects[i] + ".txt");
    }

    dao.computeAverage();
    cout <<"Number of passed students: " << dao.numPassed() << endl;

    StudentService* service = new StudentServiceImpl(&dao);
    cout << "Individual results: " << endl;
    int id = 0;
    while (id != -1)
    {
        cout << "Enter ID (-1 for EXIT): ";
        cin >> id;

        if (id == -1)
        {
            break;
        }

        if (!service->isEnrolled(id))
        {
            cout << "Student id = " << id << " not found" << endl;
            continue;
        }

        cout << "Student id = " << id << " results: " << endl;

        bool passed = service->isPassed(id);

        cout << "\tpassed: " << (passed ? "yes" : "no") << endl;

        if (!passed)
        {
            continue;
        }

    }

}