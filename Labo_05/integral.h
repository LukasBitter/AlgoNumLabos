#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "fonction.h"
#include "fonctiona.h"

class Integral
{
    public:
        Integral(Fonction* f, double start, double stop);
        virtual ~Integral();
    protected:
    private:
        double start;
        double stop;
        Fonction* f;

};

#endif // INTEGRAL_H
