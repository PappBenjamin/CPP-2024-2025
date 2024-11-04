#include "Library.h"

using namespace std;

//comperator function
bool cmp(Book &b1, Book &b2)
{
    if(b1.getAuthor() == b2.getAuthor())
    {
        return b1.getTitle() < b2.getTitle();
    }

    return b1.getAuthor() < b2.getAuthor();
}


Library::Library(const vector<Book> &library) : library(library) {}

void Library::addBook(const Book &book)
{
    library.push_back(book);
}

void Library::print() const
{
    for(auto i: library)
    {
        cout << i << endl;
    }

}

void Library::searchByAuthor(const string &author) const
{

    for(auto i: library)
    {
        if(i.getAuthor() == author)
        {
            cout << i;
            return;
        }
    }

    throw logic_error("Author not found");

}

int Library::countByAuthor(const string &author) const
{
    int c = 0;

    for(auto i: library)
    {
        if(i.getAuthor() == author){c++;}
    }

    return c;
}

Book Library::searchByTerm(const string &term)
{
   for(auto i: library)
   {
       if(i.getAuthor() == term || i.getTitle() == term)
       {
           return i;
       }
   }

   throw logic_error("Book not found");
}

void Library::sortLibrary()
{
    sort(library.begin(), library.end(), cmp);
}

void Library::removeBook(const string &title)
{
    int index = -1;

    for(int i = 0; i < library.size(); ++i)
    {
        if(title == library[i].getTitle())
        {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        throw logic_error("Book not found");
    }

    this->library.erase(library.begin() + index);
    cout << "Book removed" << endl;
}


