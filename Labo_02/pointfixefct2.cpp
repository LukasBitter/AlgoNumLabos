#include <cmath>

#include "pointfixefct2.h"
#include "pointfixe.h"

PointFixeFct2::PointFixeFct2(double ptDepart, double ptFin, double lam, double nbIterMax) : PointFixe(ptDepart, ptFin, lam, nbIterationsMax)
{
    //ctor
}

PointFixeFct2::~PointFixeFct2()
{
    //dtor
}

double PointFixeFct2::calculFDeX(double x)
{
    return x/(1-pow(x,2));
}
