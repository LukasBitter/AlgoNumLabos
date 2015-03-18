#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

#include <string>
#include <limits>

using namespace std;

const string STRING_POINT_DEPART = "\tEntrez le point de depart entre -100 et 100";
const string STRING_LAMBDA = "\tEntrez un lambda >0";
const double POINT_MIN = -100;
const double POINT_MAX = 100;
const double LAMBDA_MIN = 0;
const double LAMBDA_MAX = 10000;
const double EPSILON_MACHINE = numeric_limits<double>::epsilon();
#endif // CONSTANTES_H_INCLUDED
