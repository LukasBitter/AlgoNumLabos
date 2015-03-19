#ifndef POINTFIXEFCT1_H
#define POINTFIXEFCT1_H

#include "pointfixe.h"

class PointFixeFct1 : public PointFixe
{
    public:
        /** Default constructor */
        PointFixeFct1(double ptDepart, double ptFin, double lam, double nbIterMax);
        /** Default destructor */
        virtual ~PointFixeFct1();
    protected:
        double calculFDeX(double x);
    private:
};

#endif // POINTFIXEFCT1_H
