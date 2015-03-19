#ifndef POINTFIXE_H
#define POINTFIXE_H

#include <vector>

using namespace std;

class PointFixe
{
    public:
        /** Default constructor */
        PointFixe(double ptDepart, double ptFin, double lam, double nbIterMax);
        /** Default destructor */
        virtual ~PointFixe();

        void demarrerRecherche(double ptDepart);
        double getPointDepart();
    protected:
        virtual double calculFDeX(double x)=0;
        double calculGDeX(double x);
        bool estUnZero(double a, double b);

        double pointDepart;
        double pointFin;
        double lambda;
        double nbIterationsMax;
        vector<double> listZeros;

    private:
};

#endif // POINTFIXE_H
