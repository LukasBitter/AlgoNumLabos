#include "integral.h"

Integral::Integral(Fonction* f, double start, double stop, double n)
{
    this->f = f;
    this->start = start;
    this->stop = stop;
    this->n = n;
}

Integral::~Integral()
{
    delete f;
}

double Integral::approximateMiddlePoint()
{
    double x = start;
    double aire = 0;
    double h = (stop - start) / n;

    do{
        aire += h * (f->f(x+h) + f->f(x))/2;
        x = x + h;
    }
    while(x < stop);

    return aire;
}
