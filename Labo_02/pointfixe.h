/**
    PointFixe - Declaration File
    Purpose: This class is used to solve an equation using Point Fixed method.

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#ifndef POINTFIXE_H
#define POINTFIXE_H

#include <set>
#include "fonction.h"

using namespace std;

class PointFixe
{
    public:
        /** Default constructor */
        PointFixe(Fonction* fonction, double ptDepart, double ptFin, double lam, double nbIterMax);
        //PointFixe(double ptDepart, double ptFin, double lam, double nbIterMax);
        /** Default destructor */
        virtual ~PointFixe();

        void demarrerRecherche();
        double getPointDepart();

    protected:

    private:
        //virtual double f(double x)=0;
        bool rechercheZeros(double ptDepar);
        bool estUnZero(double a, double b);

        double pointDepart;
        double pointFin;
        double lambda;
        double nbIterationsMax;
        double valeurMaxTemporaireTrouve;
        bool zeroTrouve;
        set<double> listZeros;

        //TEST
        Fonction* currentFonction;
        double f(double x);
        double g(double x);

};

#endif // POINTFIXE_H
