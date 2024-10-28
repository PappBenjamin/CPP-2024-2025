#ifndef LAB6_MATRIX_H
#define LAB6_MATRIX_H

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

using namespace std;

class Matrix {

public:

    // Default constructor
    Matrix( int mRows = 10, int mCols =10);
    // Copy constructor
    Matrix(const Matrix& what);
    // Move constructor
    Matrix( Matrix&& what );
    // Destructor
    ~Matrix();
    //fills the matrix with identical elements
    void fillMatrix(double value);
    //fills the matrix with random real numbers in the range [a, b)
    void randomMatrix(int a, int b); //fills
    //prints the matrix
    void printMatrix(ostream& os = cout) const;

    bool isSquare() const;

    int getRows() const { return this->mRows;}

    int getCols() const { return this->mCols;}

    friend Matrix operator+(const Matrix& x, const Matrix& y);

    friend Matrix operator*(const Matrix& x, const Matrix& y);

    // extractor operator
    friend istream & operator>>(istream& is, Matrix& mat);

    // inserter operator
    friend ostream & operator<<(ostream& os, const Matrix& mat);

    // index operator
    double* operator[] (int index);
    // index operator that works on constant matrices!
    double* operator[] (int index) const;

private:
//Data
    double ** mElements;
    int mRows; //number of rows
    int mCols; //number of columns
};

#endif //LAB6_MATRIX_H
