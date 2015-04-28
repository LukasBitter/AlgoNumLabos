/**
    PointFixe - Declaration File
    Purpose: This class is used to solve an equation using Point Fixed method.

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
    @date 2015-04-28
*/

#ifndef POINTFIXE_H
#define POINTFIXE_H

#include <set>
#include "fonction.h"
#include <fstream>

using namespace std;

class PointFixe
{
    public:
        /** Default constructor

            @param _currentFunction : Function that will be solved
            @param _startPoint : Starting point
            @param _endPoint : Ending point
            @param _lambda : Lambda
            @param _nbIterationMax : Number of iterations max to do
        */
        PointFixe(Fonction* _currentFunction, double _startPoint, double _endPoint, double _lambda, double _nbIterationsMax);
        /** Default destructor */
        virtual ~PointFixe();

        /** Start to solve the equation */
        void startAlgo();

        // USED TO DEBUG
        double getStartPoint();

    private:

        /**
            Returns the solved result of : x + lambda * f(x) where f(x) is the equation stored in currentFonction.

            @param x Value of the unknown value in the equation
            @return The result of the solved equation
        */
        double g(double x);

        /**
            Search for roots

            @param ptDepart Value where the search if started
        */
        void findRoots(double ptDepart);

        /**
            Check if value a is equal with value b (Counting an error machine)

            @param a, b : Two numbers to compare
            @return Boolean : True if equal, false if not equal
        */
        bool isRoot(double a, double b);

        /** Attribute */
        //Input
        Fonction* currentFunction;
        double startPoint;
        double endPoint;
        double lambda;
        double nbIterationsMax;

        //Tools
        double maxTempValue;
        //bool rootFound;
        set<double> rootsSet;
        ofstream myfile;
};

#endif // POINTFIXE_H
