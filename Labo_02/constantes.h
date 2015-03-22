#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include <string>
/**
    Constant used in the program

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#include <limits>

using namespace std;

const double POINT_MIN = -100;
const double POINT_MAX = 100;
const double LAMBDA_MIN = -101;
const double LAMBDA_MAX = 101;
const double ITERATIONS_MIN = 99;
const double ITERATIONS_MAX = 1000000000;
const double EPSILON_MACHINE = numeric_limits<double>::epsilon();

#endif // CONSTANTES_H_INCLUDED
