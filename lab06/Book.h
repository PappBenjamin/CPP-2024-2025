#ifndef LAB6_BOOK_H
#define LAB6_BOOK_H

#include <iostream>
#include <string>

using namespace std;


class Book{

    private:

    string author;
    string title;
    int year;
    int pages;

public:

    Book(){};
    Book(const string &author, const string &title, int year, int pages);

    const string &getAuthor() const;

    const string &getTitle() const;

    int getYear() const;

    int getPages() const;

    void print(ostream &os) const;

    friend ostream &operator<<(ostream &os, const Book &book);
    friend istream &operator>>(istream &is, Book &book);




};




#endif //LAB6_BOOK_H
