#include <cstdlib>
#include <fstream>
using namespace std;

#include "Library.h"

int main(int argc, char** argv)
{
    Book book("Hobbit", "Kis Gyula",2001,200);
    cout << book << endl;


    ///////////////////////////////////////////////////////////////////

    cout << endl;

    ifstream fileIn("inBooks.txt");
    if(!fileIn.is_open())
    {
        cerr << "Cannot open file" << endl;
        exit(EXIT_FAILURE);
    }

    int n = 6;
    Library library;

    for(int i = 0; i < n; i++)
    {
       Book book1;
       fileIn >> book1;
       library.addBook(book1);
    }


    //sort
    cout << "sorted:" << endl;
    library.sortLibrary();

    //print
    library.print();

    //count
    cout << endl;
    cout << "Number of books by Murakami: " << library.countByAuthor("Murakami") << "\n\n";

    //search
    cout << "Searching for: Jokai" << "\n";
    library.searchByAuthor("Jokai");
    cout << endl;

    // remove
    cout << endl;
    library.removeBook("A_koszivu_ember_fiai");

    //print
    library.print();










}