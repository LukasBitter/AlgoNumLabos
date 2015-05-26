/**
    Integral Class - Implementation File
    Purpose: Calculate the Integral result from a Function according to start, stop et n parameters

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 17.05.2015
*/

#include "integral.h"

// Constructor
Integral::Integral(Fonction* f, long double start, long double stop)
{
    this->f = f;
    this->start = start;
    this->stop = stop;
}

// Destructor
Integral::~Integral()
{
    delete f;
}

// Approxiamtion using Middle Point Method
long double Integral::approximateMiddlePoint(long double n)
{
    long double x = start;
    long double aire = 0;
    long double h = (stop - start) / n;

    do{
        aire += h * (f->f(x+h) + f->f(x))/2;
        x = x + h;
    }
    while(x < stop);

    return aire;
}

// Approximation using Simpson Method
long double Integral::approimateSimpson(long double n)
{
    long double h = (stop - start)/n;
    long double sommePaire = 0;
    long double sommeImpaire = 0;

    for(unsigned int i = 1; i < n; i+=2)
    {
        sommeImpaire += f->f(start+h*i);
    }

    for(unsigned int i = 2; i < n; i+=2)
    {
        long double xi = start + h * i;
        sommePaire += f->f(start+h*i);
    }

    return h/3*(f->f(start) + f->f(stop)+ 2*sommePaire + 4*sommeImpaire);
}
