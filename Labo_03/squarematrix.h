//
//  squarematrix.h
//  SquareMatrix
//
//  Created by Team 6 on 10.03.15.
//  Copyright (c) 2015 Team 6. All rights reserved.
//

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <stdio.h>
#include <iostream>

class SquareMatrix
{
    public:
        SquareMatrix(int n);
        SquareMatrix(int n, double table[][200], double* result);
        SquareMatrix(int n, double table[][3], double* result);
        virtual ~SquareMatrix();

        void add();
        void sub();
        void showMatrix();

        void diagonaliser();
        void multLine(int line, double n);
        void sustractLines(int line1, int line2, double m);
        double determinant();
        double* solve();

    protected:
    private:
        double** matrix;
        double* result;
        int cote;

};

#endif // SQUAREMATRIX_H
