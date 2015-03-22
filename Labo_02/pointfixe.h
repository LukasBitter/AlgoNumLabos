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
        /** Default destructor */
        virtual ~PointFixe();

        /** Start to solve the equation */
        void demarrerRecherche();

        // USED TO DEBUG
        double getPointDepart();

    private:

        /**
            Returns the solved result of : x + lambda * f(x) where f(x) is the equation stored in currentFonction.

            @param x Value of the unknown value in the equation
            @return The result of the solved equation
        */
        double g(double x);

        /**
            Search for zeros and returns a boolean informing if zeros where found or not.

            @param ptDepart Value where the search if started
            @return Boolean : True if zero where found, false if not
        */
        void rechercheZeros(double ptDepart);

        /**
            Check if value a is equal with value b (Counting an error machine)

            @param a, b : Two numbers to compare
            @return Boolean : True if equal, false if not equal
        */
        bool estUnZero(double a, double b);

        /** Attribute */
        //Input
        Fonction* currentFonction;
        double pointDepart;
        double pointFin;
        double lambda;
        double nbIterationsMax;

        //Tools
        double valeurMaxTemporaireTrouve;
        bool zeroTrouve;
        set<double> listZeros;
};

#endif // POINTFIXE_H
