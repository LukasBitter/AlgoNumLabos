#include "integral.h"

Integral::Integral(Fonction* f, double start, double stop)
{
    this->f = f;
    this->start = start;
    this->stop = stop;
}

Integral::~Integral()
{
    delete f;
}
