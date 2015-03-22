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
    //rootFound = false;
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
    // A ENLEVER AVANT D'ENVOYER
    /*
    string filename = "log.txt";
    myfile.open (filename);
    */

    // First algo iteration with lanbda positive
    findRoots(startPoint);
    while(maxTempValue < endPoint)
    {
        maxTempValue+=pow(10,15)*EPSILON_MACHINE;
        findRoots(maxTempValue);
    }

    // Second algo iteration with lanbda positive
    lambda = -1*lambda;
    findRoots(startPoint);
    while(maxTempValue < endPoint)
    {
        maxTempValue+=pow(10,16)*EPSILON_MACHINE;
        findRoots(maxTempValue);
    }

    // A ENLEVER AVANT D'ENVOYER
    //myfile.close();
    cout<<"\n\tFINISHED"<<endl;

    set<double>::iterator it;
    for(it=rootsSet.begin(); it!=rootsSet.end(); ++it)
    {
        cout<<"\n\t\t Zero: "<<*it<<endl;
    }
}

// Search the Zero values
void PointFixe::findRoots(double ptDepart)
{
    double gDeX = g(ptDepart);
    if(gDeX > maxTempValue)
    {
        maxTempValue = gDeX;
    }

    double i=1;
    while(!isRoot(gDeX,g(gDeX)) && i<=nbIterationsMax)
    {
        gDeX = g(gDeX);
        if(gDeX > maxTempValue)
        {
            maxTempValue = gDeX;
        }


    // A ENLEVER AVANT D'ENVOYER
        //myfile <<"Iteration  "<<i<<"\t\tg(x)= "<<gDeX<<"\n";
        //if(-8<valeurMaxTemporaireTrouve && valeurMaxTemporaireTrouve<-3)
          //  cout<<"Iteration  "<<i<<"\t\tg(x)= "<<gDeX<<endl;
        i++;

        if(isRoot(gDeX,g(gDeX)))
        {
            rootsSet.insert(round(gDeX * pow(10, 5)) / pow(10, 5)); //arrondi a 5 chiffres apres la virgule (test temporaire)

    // A ENLEVER AVANT D'ENVOYER
            //if(-8<valeurMaxTemporaireTrouve && valeurMaxTemporaireTrouve<-3)
                //myfile << "\tZERO TROUVE" <<"\tg(x)= "<<gDeX<<" / "<<valeurMaxTemporaireTrouve<<"\n";
             //cout << "\tVALEUR MAX" <<"\t = "<<valeurMaxTemporaireTrouve<< endl;
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
