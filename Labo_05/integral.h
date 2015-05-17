#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "fonction.h"
#include "fonctiona.h"

class Integral
{
    public:
        Integral(Fonction* f, double start, double stop, double n);
        virtual ~Integral();

        double somme(int i, int maximum);
        double approximateMiddlePoint();

    protected:
    private:
        double start;
        double stop;
        double n;
        Fonction* f;

};

#endif // INTEGRAL_H
