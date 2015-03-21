#ifndef POINTFIXEFCT2_H
#define POINTFIXEFCT2_H

#include "pointfixe.h"

class PointFixeFct2 : public PointFixe
{
    public:
        /** Default constructor */
        PointFixeFct2(double ptDepart, double ptFin, double lam, double nbIterMax);
        /** Default destructor */
        virtual ~PointFixeFct2();
    protected:
    private:
        double calculFDeX(double x);
};

#endif // POINTFIXEFCT2_H
