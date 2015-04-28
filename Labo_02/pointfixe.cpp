/**
    PointFixe Class - Implementation File
    Purpose: This class is used to solve an equation using Point Fixed method.

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#include <set>
#include <cmath>
#include <iostream>

#include "pointfixe.h"
#include "constantes.h"

using namespace std;

// Constructor
PointFixe::PointFixe(Fonction* _currentFunction, double _startPoint, double _endPoint, double _lambda, double _nbIterationsMax):
    currentFunction(_currentFunction), startPoint(_startPoint), endPoint(_endPoint), lambda(_lambda), nbIterationsMax(_nbIterationsMax),
    maxTempValue(_startPoint)
{
    rootsSet = set<double>();
}

// Destructor
PointFixe::~PointFixe()
{
    //dtor
}

// Return the solved result of g(x) where g(x) = x + lambda * f(x)
double PointFixe::g(double x)
{
    return x+lambda*currentFunction->f(x);
}

// Return the pointDepart attribute value
double PointFixe::getStartPoint()
{
    return startPoint;
}

// Start to search the Zero values
void PointFixe::startAlgo()
{
    // First algo iteration with lanbda positive
    findRoots(startPoint);
    while(maxTempValue < endPoint)
    {
        maxTempValue+=STEP;
        findRoots(maxTempValue);
    }

    myfile <<"*************SECOND ALGO*************\n";

    // Second algo iteration with lanbda positive
    lambda = -1*lambda;
    maxTempValue = startPoint;
    findRoots(startPoint);
    while(maxTempValue < endPoint)
    {
        maxTempValue+=STEP;
        findRoots(maxTempValue);
    }

    cout<<"\n\tFINISHED"<<endl;

    set<double>::iterator it;
    for(it=rootsSet.begin(); it!=rootsSet.end(); ++it)
    {
        cout<<"\n\t\t Zero #"<<distance(rootsSet.begin(),it)<<": "<<*it<<endl;
    }
}

// Search the Zero values
void PointFixe::findRoots(double ptDepart)
{
    double gDeX = g(ptDepart);
    bool isARoot = false;
    if(gDeX > maxTempValue)
    {
        maxTempValue = gDeX;
    }

    double i=1;

    // Here we should also check if the absolute value of th derivates is between 0 and 1
    // else we should stop iterating
    // as we don't do this control, making useless iterations takes too much time to find the roots
    while(!isARoot && i<=nbIterationsMax)
    {
        gDeX = g(gDeX);
        if(gDeX > maxTempValue)
        {
            maxTempValue = gDeX;
        }

        i++;

        if(isRoot(gDeX,g(gDeX)))
        {
            isARoot = true;
            rootsSet.insert(round(gDeX * pow(10, 5)) / pow(10, 5));
        }
    }
}

// Check if the found value is a Zero
bool PointFixe::isRoot(double a, double b)
{
    if (a == 0 || b == 0)
    {
        return abs(a - b) <= EPSILON_MACHINE;
    }
    else
    {
        return abs((a - b) / a) <= EPSILON_MACHINE;
    }
}
