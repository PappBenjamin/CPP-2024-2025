
#ifndef LAB6_LIBRARY_H
#define LAB6_LIBRARY_H

#include "Book.h"
#include <vector>
#include <stdexcept>


class Library {

    private:
    vector<Book> library;

    public:
    Library(){};
    explicit Library(const vector<Book> &library);


    void addBook(const Book &book);

    void print() const;

    Book searchByTerm(const string &term);

    int countByAuthor(const string &author) const;

    void sortLibrary();

    void searchByAuthor(const string &author) const;

    void removeBook(const string &title);





};


#endif //LAB6_LIBRARY_H
