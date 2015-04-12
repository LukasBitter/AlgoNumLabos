#ifndef GAUSSJORDANELIMINATION_H
#define GAUSSJORDANELIMINATION_H

#include "matrix.h"

class GaussJordanElimination
{
    public:
        /** Default constructor */
        GaussJordanElimination(Matrix mat);
        /** Default destructor */
        virtual ~GaussJordanElimination();
    protected:
    private:
        void solve();
        int findPivot(int j, int r);
        void divideLine(int line, double v);
        void exchangeLines(int k, int r);
        void subtractLine(int i, int k, int r);
        double **matrix;
        double *solutions;
        int n;
        int m;
        double pivot;
        int r;
        int k;
};

#endif // GAUSSJORDANELIMINATION_H
