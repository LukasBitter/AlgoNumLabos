/**
    Fonction2 - Implementation File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 03.05.2015
*/

#include "fonction2.h"
#include <cmath>

Fonction2::Fonction2() : Fonction()
{
}
double Fonction2::f(double x)
{
     return x/(1-pow(x,2));
}
