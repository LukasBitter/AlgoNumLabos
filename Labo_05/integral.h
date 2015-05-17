#ifndef INTEGRAL_H
#define INTEGRAL_H

#include "fonction.h"
#include "fonctiona.h"

class Integral
{
    public:
        Integral(Fonction* f, long double start, long double stop);
        virtual ~Integral();

        long double approximateMiddlePoint(long double n);
        long double approimateSimpson(long double n);

    protected:
    private:
        long double start;
        long double stop;
        Fonction* f;

};

#endif // INTEGRAL_H
