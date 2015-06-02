/**
    FonctionA - Full Fonction Declaration File
    FunctionA is derived from Fonction.
    Purpose: Contains the fonction  "sin(x) - x/13"

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
    @date 26.05.2015
*/

#ifndef FONCTIONA_H
#define FONCTIONA_H

#include "fonction.h"
#include "math.h"

class FonctionA : public Fonction
{
    public:
        /** Default constructor */
        FonctionA() {}
        /** Default destructor */
        virtual ~FonctionA() {}

        /**
            Returns the result of the equation with a specified x

            @param x The value of the "unknown" value of the equation
            @return The result of the solved equation
        */
        long double f(long double x) { return 1 / (1 + pow(x,2)); }

    protected:
    private:
};

#endif // FONCTIONA_H
