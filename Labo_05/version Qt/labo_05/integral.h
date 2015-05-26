/**
    Integral Class - Declaration File
    Purpose: Calculate the Integral result from a Function according to start, stop et n parameters

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 17.05.2015
*/

#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "fonction.h"
#include "fonctiona.h"

class Integral
{
    public:
        /** Constructor
            @param f : Pointer on a Fonction Object
            @param start : Starting of the Integral
            @param stop : Stop of the Integral
        */
        Integral(Fonction* f, long double start, long double stop);

        /** Destructor */
        virtual ~Integral();

        /** Calculate the approximation using Middle Point method
            @param n : Number of iterations
        */
        long double approximateMiddlePoint(long double n);

        /** Calculate the approximation using Simpson method
            @param n : Number of iterations
        */
        long double approimateSimpson(long double n);

    protected:
    private:
        long double start;
        long double stop;
        Fonction* f;

};

#endif // INTEGRAL_H
