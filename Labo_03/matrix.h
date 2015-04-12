//
//  matrix.h
//  Matrix
//
//  Created by Team 6 on 10.03.15.
//  Copyright (c) 2015 Team 6. All rights reserved.
//

#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <iostream>

class Matrix
{
    public:
        Matrix(int N,int M);
        Matrix(int N, int M, double** mat);
        Matrix(int N,int M, double table[][200], double* result);
        Matrix(int N,int M, double table[][3], double* result);
        virtual ~Matrix();

        void add();
        void sub();
        void showMatrix();

        void diagonaliser();
        void multLine(int line, double n);
        void sustractLines(int line1, int line2, double m);
        double determinant();
        double* solve();

        double** getMatrix();
        double getN();
        double getM();

    protected:
    private:
        double** matrix;
        double* result;
        int n;
        int m;

};

#endif // SQUAREMATRIX_H
