#ifndef POINTFIXEFCT2_H
#define POINTFIXEFCT2_H

#include "pointfixe.h"


class PointFixeFct2 : public PointFixe
{
    public:
        /** Default constructor */
        PointFixeFct2(double ptDepart, double ptFin, double lam);
        /** Default destructor */
        virtual ~PointFixeFct2();
    protected:
    private:
};

#endif // POINTFIXEFCT2_H
