#include <cmath>

#include "pointfixefct1.h"
#include "pointfixe.h"

PointFixeFct1::PointFixeFct1(double ptDepart, double ptFin, double lam, double nbIterMax) : PointFixe(ptDepart, ptFin, lam, nbIterationsMax)
{
    //ctor
}

PointFixeFct1::~PointFixeFct1()
{
    //dtor
}

double PointFixeFct1::calculFDeX(double x)
{
    return sin(x)-x/13;
}
