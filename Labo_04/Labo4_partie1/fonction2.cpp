#include "fonction2.h"
#include <cmath>

Fonction2::Fonction2() : Fonction()
{
}
double Fonction2::f(double x)
{
     return x/(1-pow(x,2));
}
