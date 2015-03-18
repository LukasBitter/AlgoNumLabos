#ifndef POINTFIXEFCT1_H
#define POINTFIXEFCT1_H

#include "pointfixe.h"


class PointFixeFct1 : public PointFixe
{
    public:
        /** Default constructor */
        PointFixeFct1(double ptDepart, double ptFin, double lam);
        /** Default destructor */
        virtual ~PointFixeFct1();
    protected:
    private:
};

#endif // POINTFIXEFCT1_H
