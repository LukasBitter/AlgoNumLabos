/**
    SquareMatrix Class - Declaration File
    Purpose: This class is used to implement different methods on matrix including:
            creating a matrix, it's destructor, printing a matrix, diagonalizing,
            determinant and solving of a matrix

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 29.04.2015
*/

#ifndef SQUAREMATRIX_H
#define SQUAREMATRIX_H

#include <stdio.h>
#include <iostream>
#include <windows.h>
using namespace std;

class SquareMatrix
{
    public:

        /** Public Constructors and Destructors*/
        SquareMatrix(int n);
        //SquareMatrix(int n, double** table, double* result);
        SquareMatrix(int n, double** table, double* result);
        SquareMatrix(int n, double table[][3], double* result);
        virtual ~SquareMatrix();

        /** Public methods */
        void showMatrix();
        void diagonaliser();
        void findDeterminant();
        void solve();
        void printSolutions();

    protected:
    private:

        /** Private Methods */
        void multLine(int line, double n);
        void substractLines(int line1, int line2, double m);

        /** Private attributes */
        double** matrix;
        double* vectB;
        double* solvedResult;
        double determinant;
        int cote;
};

#endif // SQUAREMATRIX_H
