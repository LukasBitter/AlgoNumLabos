#include "integral.h"

Integral::Integral(Fonction* f, long double start, long double stop)
{
    this->f = f;
    this->start = start;
    this->stop = stop;
}

Integral::~Integral()
{
    delete f;
}

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

long double Integral::approimateSimpson(long double n)
{
    long double h = (stop - start)/n;
    long double sommePaire = 0;
    long double sommeImpaire = 0;

    for(unsigned int i = 1; i < n; i = i+2)
    {
        sommeImpaire += f->f(start+h*i);
    }

    for(unsigned int i = 2; i < n; i = i+2)
    {
        long double xi = start + h * i;
        sommePaire += f->f(start+h*i);
    }

    return h/3*(f->f(start) + f->f(stop)+ 2*sommePaire + 4*sommeImpaire);
}
