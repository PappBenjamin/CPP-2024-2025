#include <iostream>
#include "List.h"

int main()
{
    List list1("input.txt");
    cout << "list1: " << list1 << endl;

    List list2;
    for(int i = 10; i < 15; ++i)
    {
        list2.insertLast(i);
    }
    cout << "list2: " << list2 << endl;


    List list3 = list1 + list2;
    cout << "list3 = list1 + list2: "<<list3 << endl;

    List list4;
    list4 = list1;
    cout << "list4 = list1; list4: " << list4 << endl;

    List list5 = std::move(list2 + list1);
    cout << "list5 = std::move(list2 + list1); list5: " << list5 << endl;

    List list6;
    list6 = (list1 + list1);
    cout << "list6 = list1 + list1; list6: " << list6 << endl;
    return 0;


}