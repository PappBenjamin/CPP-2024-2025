
#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols)
{
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double*[mRows];

    for(int i = 0; i < mRows; i++)
    {
        this->mElements[i] = new double[mCols];
    }

}

Matrix::Matrix(const Matrix &what)
{
   this->mRows = what.mRows;
   this->mCols = what.mCols;

   this->mElements = new double*[what.mRows];

   for(int i = 0; i < what.mRows; i++)
   {
       this->mElements[i] = new double[what.mCols];

       for(int j = 0; j < what.mCols; j++)
       {
           this->mElements[i][j] = what.mElements[i][j];
       }
   }
}

Matrix::Matrix(Matrix &&what)
{
    this->mRows = what.mRows;
    this->mCols = what.mCols;

    this->mElements = what.mElements;
    what.mElements = nullptr;
    what.mRows = 0;
}

Matrix::~Matrix()
{
    if(mElements != nullptr){return;}

    for(int i = 0; i < this->mRows; i++)
    {
        delete[] this->mElements[i];
    }

    delete[] this->mElements;

}

void Matrix::fillMatrix(double value)
{

    for(int i = 0; i < this->mRows; i++)
    {
        for(int j = 0; j < this->mCols; j++)
        {
            this->mElements[i][j] = value;
        }
    }

}

void Matrix::randomMatrix(int a, int b)
{
    srand(time(nullptr));

    for(int i = 0; i < this->mRows; i++)
    {
        for(int j = 0; j < this->mCols; j++)
        {
            this->mElements[i][j] = rand() % (b - a) + 1 + a;
        }
    }

}

void Matrix::printMatrix(ostream &os) const
{

    for(int i = 0; i < this->mRows; i++)
    {
        for (int j = 0; j < this->mCols; j++)
        {
            os << this->mElements[i][j] << " ";
        }
        os << endl;
    }

}

bool Matrix::isSquare() const {
    return this->mRows == this->mCols;
}

Matrix operator+(const Matrix &x, const Matrix &y)
{

    if(x.mRows != y.mRows || x.mCols != y.mCols)
    {
       throw out_of_range("Matrices have different sizes");
    }

    Matrix sum(x.mRows, x.mCols);

    for(int i = 0; i < x.mRows; i++)
    {
        for(int j = 0; j < x.mCols; j++)
        {
            sum.mElements[i][j] = x.mElements[i][j] + y.mElements[i][j];
        }
    }

    return sum;
}



istream &operator>>(istream &is, Matrix &mat)
{

    for(int i = 0; i < mat.mRows; i++)
    {
        for(int j = 0; j < mat.mCols; j++)
        {
            is >> mat.mElements[i][j];
        }
    }

    return is;
}

ostream &operator<<(ostream &os, const Matrix &mat) {

    for (int i = 0; i < mat.mRows; i++)
    {
        for (int j = 0; j < mat.mCols; j++)
        {
            os << mat.mElements[i][j] << " ";
        }
        os << endl;
    }
    return os;
}

Matrix operator*(const Matrix &x, const Matrix &y)
{
    Matrix sum(x.mRows,y.mCols);

    for(int i = 0; i < sum.mRows; ++i)
    {
        for(int j = 0; j < sum.mCols; ++j)
        {
            sum.mElements[i][j] = 0;

            for(int k = 0; k < x.mCols; ++k)
            {
                sum.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
            }
        }

    }

    return sum;
}

double *Matrix::operator[](int index)
{
    return this->mElements[index];
}





