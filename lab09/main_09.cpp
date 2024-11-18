#include <iostream>
#include "Manager.h"

int main()
{
    Employee p1("Kiss", "Gergo", 2000, "developer");
    Employee p2("Nagy", "Anna", 1995, "designer");
    Employee p3("Tóth", "Béla", 1988, "tester");
    Employee p4("Szabó", "Katalin", 1990, "project manager");
    Employee p5("Horváth", "István", 1975, "developer");
    Employee p6("Varga", "Mária", 1980, "team lead");
    Employee p7("Kovács", "Péter", 2002, "intern");

    Manager m1("Molnár", "Zsuzsa", 1999, "manager");
    Manager m2("Lukács", "János", 1985, "manager");
    Manager m3("Balogh", "Réka", 1993, "manager");

    m1.addEmployee(&p1);
    m1.addEmployee(&p2);
    m1.addEmployee(&p3);

    m2.addEmployee(&p4);
    m2.addEmployee(&p5);

    m3.addEmployee(&p6);
    m3.addEmployee(&p7);

    ////////////////

    m1.printManager(cout);
    m2.printManager(cout);
    m3.printManager(cout);
    cout << endl;

    ////////////////

    m1.print(cout);
    cout << endl;
    m2.print(cout);
    cout << endl;
    m3.print(cout);

    return 0;
}