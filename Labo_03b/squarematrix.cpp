/**
    SquareMatrix Class - Implementation File
    Purpose: This class is used to implement different methods on matrix including:
            creating a matrix, it's destructor, printing a matrix, diagonalizing,
            determinant and solving of a matrix

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#include "squarematrix.h"

/**    Matrix constructor   */
SquareMatrix::SquareMatrix(int n)
{
    this->cote = n;
    matrix = new double*[cote];
    vectB = new double[cote];
    solvedResult = new double[cote];
    for(int i = 0; i < cote; ++i)
    {
        matrix[i] = new double[cote];
    }
}

/**    Big Matrix constructor   */
SquareMatrix::SquareMatrix(int n, double** table, double* new_vect) : SquareMatrix(n)
{
    for(int i = 0; i<cote; i++)
    {
        for(int j = 0; j<cote; j++)
        {
            matrix[i][j] = table[i][j];
        }
        vectB[i] = new_vect[i];
    }
}

/**    Small Matrix constructor   */
SquareMatrix::SquareMatrix(int n, double table[][3], double* new_vect) : SquareMatrix(n)
{
    for(int i = 0; i<cote; i++)
    {
        for(int j = 0; j<cote; j++)
        {
            matrix[i][j] = table[i][j];
        }
        vectB[i] = new_vect[i];
    }
}

/**    Matrix destructor   */
SquareMatrix::~SquareMatrix()
{
    //dtor
}

/**    Print Matrix     */
void SquareMatrix::showMatrix()
{
        cout<<endl<<"  Matrix and vector:"<<endl;
    for(int i = 0; i<cote; i++)
    {
        cout << "  |";
        for(int j=0; j<cote; j++)
        {
            cout << "  "<< matrix[i][j] << " ";
        }
        cout << " | . X = " << vectB[i] << "\n";
    }
    cout<<endl;
}

/**    Matrix diagonalisation   */
void SquareMatrix::diagonaliser()
{
    for(int i=1; i<cote; i++)
    {
        double m1 = matrix[i-1][i-1];
        for(int j=i; j<cote; j++)
        {
            double m2 = matrix[j][i-1];

            multLine(j, m1); //multiplier toute la ligne
            substractLines(j, i-1, m2); //line(j) = line(j) - m*line(i-1)
        }
    }
}

/**    Matrix lines multiplicator   */
void SquareMatrix::multLine(int line, double n)
{
    for (int i=0; i<cote; i++) {
        matrix[line][i] = matrix[line][i] * n;
    }
    vectB[line] = vectB[line] * n;
}

/**    Matrix lines substracor   */
void SquareMatrix::substractLines(int line1, int line2, double m)
{
    for(int i=0; i<cote; i++)
    {
        matrix[line1][i] = matrix[line1][i]-m*matrix[line2][i];
    }
    vectB[line1] = vectB[line1] - m * vectB[line2];
}

/**    Matrix determinant finder   */
void SquareMatrix::findDeterminant()
{
    double det = 1;
    for(int i = 0; i < cote; i++)
    {
        det *= matrix[i][i];
    }
    this->determinant = det;
}

/**    Print Matrix solutions   */
void SquareMatrix::printSolutions()
{
    if(this->determinant==0)
    {
        cout << "  --> The matrix has Infinite solutions!!!" << endl << endl;
    }

    else
    {
        cout<<"  Solutions:"<<endl;
        for(int i = 0; i < cote; i++)
        {
            cout << "  x" << cote-i << " = " << solvedResult[cote-1-i] << endl;
        }
    }

}

/**    Find Matrix solutions   */
void SquareMatrix::solve()
{
    for(int i = 0; i < cote; i++)
    {
        double value = vectB[cote - i-1];
        int m = 1;
        for(int k = cote - i; k < cote ; k++)
        {
            value -= solvedResult[k] * matrix[k-m][k];
            m++;
        }

        /** Information: matrix[cote-1-i][cote-1-i] n'est jamais égal à 0 car le déterminant n'est pas null **/
        solvedResult[cote-1-i] = value / matrix[cote-1-i][cote-1-i];
    }
}

