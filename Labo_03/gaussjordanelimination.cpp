#include "gaussjordanelimination.h"
#include "matrix.h"
#include "cmath"

using namespace std;

GaussJordanElimination::GaussJordanElimination(Matrix mat)
{
    //ctor
    n=mat.getN();                     //number of lines
    m=mat.getM();                     //number of columns
    solutions= new double[n-1];        //number of unknowns

    *matrix= new double[n];
    for(int i=0; i<n; i++)
    {
        matrix[i]= new double[m];
    }

    double **startMatrix= mat.getMatrix();
    for(int i=0;i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            matrix[i][j]= startMatrix[i][j];
        }
    }
}

GaussJordanElimination::~GaussJordanElimination()
{
    //dtor
}


void GaussJordanElimination::solve()
{
    r=0;        //increment index
    k=-1;       //line number of pivot
    pivot=0;    //value of pivot
    for(int j=0; j<m; j++)
    {
        k=findPivot(j,r);

        if(pivot!=0)
        {
            divideLine(k,pivot);
            exchangeLines(k,r);
            for(int i=0; i<n; i++)
            {
                if(i!=r)
                {
                    subtractLine(i,k,r);
                }
            }
            r++;
        }
        pivot=0;
    }
}

int GaussJordanElimination::findPivot(int j, int r)
{
    int posMaxValue=-1;
    for(int i=r; i<n; i++)
    {
        if(abs(matrix[i][j]) > abs(pivot))
        {
            pivot = matrix[i][j];
            posMaxValue=i;
        }
    }
    return posMaxValue;
}

void GaussJordanElimination::divideLine(int k, double v)
{
    for(int j=0; j<m; j++)
    {
        matrix[k][j]=matrix[k][j]/v;
    }
}

void GaussJordanElimination::exchangeLines(int k, int r)
{
    double *temp= new double[m];
    //k line in temp
    for(int j=0; j<m; j++)
    {
        temp[j]= matrix[k][j];
    }
    //r line in k line
    for(int j=0; j<m; j++)
    {
        matrix[k][j]= matrix[r][j];
    }
    //temp line(k) in r line
    for(int j=0; j<m; j++)
    {
        matrix[r][j]= temp[j];
    }
}

void GaussJordanElimination::subtractLine(int i, int k, int r)
{
    double valueToMultiplyLine= matrix[i][r];
    for(int j=0; j<m; j++)
    {
        matrix[i][j]=matrix[i][j]-valueToMultiplyLine*matrix[k][j];
    }
}
