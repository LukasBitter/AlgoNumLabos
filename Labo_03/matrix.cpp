//
//  matrix.cpp
//  Matrix
//
//  Created by Team 6 on 10.03.15.
//  Copyright (c) 2015 Team 6. All rights reserved.
//

#include "matrix.h"

using namespace std;

Matrix::Matrix(int N, int M)
{
    n= N;
    m= M;
    matrix = new double*[n];
    result = new double[n];
    for(int i = 0; i < n; ++i)
    {
        matrix[i] = new double[m];
    }
//
//    //construction temporaire
//    for(int i = 0; i<cote; i++)
//    {
//        for(int j = 0; j<cote; j++)
//        {
//            matrix[i][j] = 1;
//        }
//    }
}
Matrix::Matrix(int N, int M, double** mat): Matrix(N,M)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            matrix[i][j]=mat[i][j];
        }
    }
}

//
//Matrix::Matrix(int N,int M, double table[][200], double* result) : Matrix(N,M)
//{
//    for(int i = 0; i<n; i++)
//    {
//        for(int j = 0; j<n; j++)
//        {
//            matrix[i][j] = table[i][j];
//        }
//        result[i] = new_result[i];
//    }
//}
//
//Matrix::Matrix(int N, int M, double table[][3], double* new_result) : Matrix(N,M)
//{
//    for(int i = 0; i<n; i++)
//    {
//        for(int j = 0; j<n; j++)
//        {
////            matrix[i][j] = 1;
//            matrix[i][j] = table[i][j];
//        }
//
//        result[i] = new_result[i];
//    }
//}

Matrix::~Matrix()
{
    //dtor
}

void Matrix::add()
{
}

void Matrix::sub()
{

}

void Matrix::showMatrix()
{
    for(int i = 0; i<n; i++)
    {
        cout << "|";
        for(int j=0; j<n; j++)
        {
//            cout << matrix[i][j];
            cout << matrix[i][j] << " ";
        }
        cout << "|\n";
    }
}


void Matrix::diagonaliser()
{
    for(int i=1; i<n; i++)
    {
        double m1 = matrix[i-1][i-1];
        for(int j=i; j<n; j++)
        {
            double m2 = matrix[j][i-1];

            multLine(j, m1); //multiplier toute la ligne
            sustractLines(j, i-1, m2); //line(j) = line(j) - m*line(i-1)
        }
    }
}
void Matrix::multLine(int line, double n)
{
    for (int i=0; i<n; i++) {
        matrix[line][i] = matrix[line][i] * n;
    }
    result[line] = result[line] * n;
}

//line1 = line1 - m*line2
void Matrix::sustractLines(int line1, int line2, double m)
{
    for(int i=0; i<n; i++)
    {
        matrix[line1][i] = matrix[line1][i]-m*matrix[line2][i];
    }
    result[line1] = result[line1] - m * result[line2];
}

double Matrix::determinant()
{
    double det = 0;
    for(int i = 0; i < n; i++)
    {
        det += matrix[i][i];
    }
    return det;
}

double* Matrix::solve()
{
    double solvedResult[n];

    for(int i = 0; i < n; i++)
    {
        double value = result[n - i-1];
        int m = 1;
        for(int k = n - i; k < n ; k++)
        {
            value -= solvedResult[k] * matrix[k-m][k];
            m++;
        }
        solvedResult[n-1-i] = value / matrix[n-1-i][n-1-i];

        cout << "x" << n-i << " = " << solvedResult[n-1-i] << endl;
    }

    return solvedResult;
}

double** Matrix::getMatrix()
{
    return matrix;
}
double Matrix::getN()
{
    return n;
}

double Matrix::getM()
{
    return m;
}
