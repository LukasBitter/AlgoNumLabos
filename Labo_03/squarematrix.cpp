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
<<<<<<< .merge_file_a04304
    
    matrix = new int*[cote];
    for(int i = 0; i < cote; ++i)
    {
        matrix[i] = new int[cote];
    }
    
    //construction temporaire
=======

    matrix = new double*[cote];
    for(int i = 0; i < cote; ++i)
    {
        matrix[i] = new double[cote];
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

SquareMatrix::SquareMatrix(int n, double table[][200]) : SquareMatrix(n)
{
    for(int i = 0; i<cote; i++)
    {
        for(int j = 0; j<cote; j++)
        {
            matrix[i][j] = table[i][j];
        }
    }
}

SquareMatrix::SquareMatrix(int n, double table[][3]) : SquareMatrix(n)
{
>>>>>>> .merge_file_a02812
    for(int i = 0; i<cote; i++)
    {
        for(int j = 0; j<cote; j++)
        {
<<<<<<< .merge_file_a04304
            matrix[i][j] = 1;
=======
            matrix[i][j] = table[i][j];
>>>>>>> .merge_file_a02812
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
<<<<<<< .merge_file_a04304
            std::cout << matrix[i][j];
=======
            std::cout << matrix[i][j] << " ";
>>>>>>> .merge_file_a02812
        }
        std::cout << "|\n";
    }
}


void SquareMatrix::diagonaliser()
{
    for(int i=1; i<cote; i++)
    {
        double m1 = matrix[i-1][i-1];
        for(int j=i; j<cote; j++)
        {
            double m2 = matrix[j][i-1];
            
            multLine(j, m1); //multiplier toute la ligne
            sustractLines(j, i-1, m2); //line(j) = line(j) - m*line(i-1)
        }
    }
}
void SquareMatrix::multLine(int line, double n)
{
    for (int i=0; i<cote; i++) {
        matrix[line][i] = matrix[line][i] * n;
    }
}

//line1 = line1 - m*line2
void SquareMatrix::sustractLines(int line1, int line2, double m)
{
    for(int i=0; i<cote; i++)
    {
        matrix[line1][i] = matrix[line1][i]-m*matrix[line2][i];
    }
}

