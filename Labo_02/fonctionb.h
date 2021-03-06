/**
    FonctionB - Full Fonction Declaration File
    FunctionB is derived from Fonction.
    Purpose: Contains the fonction  "1 / (1-pow(x,2))"

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
    @date 2015-04-28
*/

#ifndef FONCTIONB_H
#define FONCTIONB_H

#include "fonction.h"
#include <math.h>

class FonctionB : public Fonction
{
    public:
        /** Default constructor */
        FonctionB() {}
        /** Default destructor */
        virtual ~FonctionB() {}

        /**
            Returns the result of the equation with a specified x

            @param x The value of the "unknown" value of the equation
            @return The result of the solved equation
        */
        double f(double x) { return 1 / (1-pow(x,2)); }

    protected:
    private:
};

#endif // FONCTIONB_H
