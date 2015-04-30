#include "fonction1.h"
#include <cmath>

Fonction1::Fonction1() : Fonction()
{
}
double Fonction1::f(double x)
{
     return pow(x,5) + 5*pow(x,3) + 2*x;
}
