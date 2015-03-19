#include <vector>
#include <cmath>
#include <iostream>

#include "pointfixe.h"
#include "constantes.h"

using namespace std;

PointFixe::PointFixe(double ptDepart, double ptFin, double lam, double nbIterMax)
{
    pointDepart=ptDepart;
    pointFin=ptFin;
    lambda= lam;
    nbIterationsMax= nbIterMax;
    listZeros= vector<double>();
}

PointFixe::~PointFixe()
{
    //dtor
}

double PointFixe::getPointDepart()
{
    return pointDepart;
}

void PointFixe::demarrerRecherche(double ptDepart)
{
    double gDeX = calculGDeX(ptDepart);
    double i=1;
    while(!estUnZero(gDeX,calculGDeX(gDeX)) || i<=nbIterationsMax)
    {
        gDeX= calculGDeX(gDeX);
        cout<<"Iteration  "<<i<<"\t\tg(x)= "<<gDeX<<endl;
        i++;
    }
    listZeros.push_back(gDeX);
    cout << "ZERO TROUVE" << endl;
}

double PointFixe::calculGDeX(double x)
{

    return x+lambda*calculFDeX(x);
}

bool PointFixe::estUnZero(double a, double b)
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
