#include "Book.h"

Book::Book(const string &author, const string &title, int year, int pages) : author(author), title(title), year(year),
                                                                             pages(pages) {}
const string &Book::getAuthor() const {
    return author;
}

const string &Book::getTitle() const {
    return title;
}
int Book::getYear() const {
    return year;
}

int Book::getPages() const {
    return pages;
}

void Book::print(ostream &os) const
{
    os << "Book: " << this->title << " by " << this->author << "(published in " << this->year << "), " << this->pages << " pages";
}

ostream &operator <<(ostream &os, const Book &book)
{
    book.print(os);
    return os;
}

istream &operator>>(istream &is, Book &book)
{
    is >> book.author >> book.title >> book.year >> book.pages;
    return is;
}
