//
//  squarematrix.cpp
//  SquareMatrix
//
//  Created by Team 6 on 10.03.15.
//  Copyright (c) 2015 Team 6. All rights reserved.
//

#include "squarematrix.h"

SquareMatrix::SquareMatrix(int n)
{
    this->cote = n;
    
    matrix = new int*[cote];
    for(int i = 0; i < cote; ++i)
    {
        matrix[i] = new int[cote];
    }
    
    //construction temporaire
    for(int i = 0; i<cote; i++)
    {
        for(int j = 0; j<cote; j++)
        {
            matrix[i][j] = 1;
        }
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

void SquareMatrix::showMatrix()
{
    for(int i = 0; i<cote; i++)
    {
        std::cout << "|";
        for(int j=0; j<cote; j++)
        {
            std::cout << matrix[i][j];
        }
        std::cout << "|\n";
    }
}
