/**
    FonctionB - Full Fonction Declaration File
    FunctionB is derived from Fonction.
    Purpose: Contain the fonction  "1 / (1-pow(x,2))"

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#ifndef FONCTIONB_H
#define FONCTIONB_H

#include "fonction.h"
#include <math.h>

class FonctionB : public Fonction
{
    public:
        FonctionB() {}
        virtual ~FonctionB() {}

        double f(double x) { return 1 / (1-pow(x,2)); }

    protected:
    private:
};

#endif // FONCTIONB_H
