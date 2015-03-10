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
        virtual ~SquareMatrix();

        void add();
        void sub();
        void showMatrix();

    protected:
    private:
        int** matrix;
        int cote;
    
};

#endif // SQUAREMATRIX_H
