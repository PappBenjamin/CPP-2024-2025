#ifndef LAB7_LIST_H
#define LAB7_LIST_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class List {
public:
    List() = default;
    List(const string& filename);
    ~List();

    bool exists(int d) const;
    int size() const;
    bool empty() const;
    void insertFirst(int d);
    void insertLast(int d);
    int removeFirst();
    void print(ostream& os = cout) const;

    /* Copy constructor */
    List(const List&what);
    /* Copy Assignment operator */
    List& operator=(const List&);
    /* Move constructor */
    List(List&&what);
    /* Move Assignment operator */
    List& operator=(List&&);


    friend List operator+(const List& list1, const List& list2);
    friend ostream& operator<<(ostream& os, const List& list);

private:
    struct Node {
        int value;
        Node* next;

        Node(int v = 0, Node* n = nullptr) : value(v), next(n) {}
    };

    Node* first = nullptr; // pointer to the first node
    int nodeCounter = 0;
};

#endif // LAB7_LIST_H
