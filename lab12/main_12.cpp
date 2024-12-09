#include "SimpleTextGenerator.h"
#include <cstdlib>
#include <ctime>

#include "EmailService.h"


int main()
{

    /*

     srand(time(nullptr));

    SimpleTextGenerator generator;
    //generator.trainFromText("My! name is ,asd name is my");
    generator.trainFromFile("in.txt");
    //generator.printData();

    for(int i = 0; i < 10; ++i)
    {
        cout << generator.generate("and god",10) << endl;
    }

    */




    EmailService service("email.txt");
    cout << "-------------- -ALL---------------------" << endl;
    service.showAll();
    cout << "---------------REMOVED--------------------" << endl;
    service.removeUsername("third1");
    service.removeUsername("third");
    //service.removeUsername("first");
    service.showAll();
    cout << "---------------READD--------------------" << endl;
    service.addUsername("first");
    service.showAll();




    return 0;
}