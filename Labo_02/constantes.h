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
const double LAMBDA_MIN = 0;
const double LAMBDA_MAX = 10000;
const double ITERATIONS_MIN = 100;
const double ITERATIONS_MAX = 1000000000;
const double EPSILON_MACHINE = numeric_limits<double>::epsilon();

//const string STRING_POINT_DEPART = "\tEntrez le point de depart entre ["/*+std::to_string(POINT_MIN)+", "+std::to_string(POINT_MAX)+"]"*/;
const string STRING_LAMBDA = "\tEntrez un lambda entre ["/*+LAMBDA_MIN+", "+LAMBDA_MAX+*/"]";
const string STRING_ITERATIONS = "\tEntrez un nombre d'iterations maximal pour l'arret de l'algo en cs de divergence";
#endif // CONSTANTES_H_INCLUDED
