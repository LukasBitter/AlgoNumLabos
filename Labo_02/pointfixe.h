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

        void demarrerRecherche();
        double getPointDepart();
    protected:

    private:
        virtual double calculFDeX(double x)=0;
        bool rechercheZeros(double ptDepar);
        double calculGDeX(double x);
        bool estUnZero(double a, double b);

        double pointDepart;
        double pointFin;
        double lambda;
        double nbIterationsMax;
        double valeurMaxTemporaireTrouve;
        bool zeroTrouve;
        vector<double> listZeros;

};

#endif // POINTFIXE_H
