#include "fonction.h"
#include <cmath>

Fonction::Fonction()
{
    this->h = 0.0001; //Default value
}
Fonction::~Fonction(){

}

/* calculate the f'(x)
 * use the "différence centrée"
 * */
double  Fonction::f_derivate(double x)
{
    double x1 = x - h;
    double y1 = f(x1);

    double x2 = x + h;
    double y2 = f(x2);

    double variationL = x2-x1;
    double variationH = y2-y1;

    return variationH/variationL;
}

/* calculate the f''(x)
 * use the "différence centrée"
 * */
double Fonction::f_derivateSecond(double x)
{
    return (f(x+h)+f(x-h)-2*f(x))/pow(h, 2);
}

void Fonction::seth(double h)
{
    this->h = h;
}
