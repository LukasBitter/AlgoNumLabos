#include "squarematrix.h"

SquareMatrix::SquareMatrix(int n)
{
    matrix = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        matrix[i] = new int[n];
    }
}

SquareMatrix::~SquareMatrix()
{
    //dtor
}

void SquareMatrix::add()
{

}

void SquareMatrix::sub()
{

}
