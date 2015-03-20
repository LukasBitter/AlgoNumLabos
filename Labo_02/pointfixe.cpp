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
    valeurMaxTemporaireTrouve=0;
    zeroTrouve= false;
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

void PointFixe::demarrerRecherche()
{
    bool nouveauZeroTrouve = rechercheZeros(pointDepart);
    while(valeurMaxTemporaireTrouve<100)
    {
        valeurMaxTemporaireTrouve+=pow(10,16)*EPSILON_MACHINE;
        rechercheZeros(valeurMaxTemporaireTrouve);
    }
    cout<<"\n\tFINI"<<endl;

    for(unsigned int i=0;i<listZeros.size();i++)
    {
        cout<<"\n\t\t Zero: "<<listZeros[i]<<endl;
    }
}

bool PointFixe::rechercheZeros(double ptDepart)
{
    double gDeX = calculGDeX(ptDepart);
    valeurMaxTemporaireTrouve= gDeX;
    double i=1;
    while(!estUnZero(gDeX,calculGDeX(gDeX)) && i<=nbIterationsMax)
    {
        gDeX= calculGDeX(gDeX);
        if(gDeX>valeurMaxTemporaireTrouve)
        {
            valeurMaxTemporaireTrouve= gDeX;
        }
        cout<<"Iteration  "<<i<<"\t\tg(x)= "<<gDeX<<endl;
        i++;
        if(estUnZero(gDeX,calculGDeX(gDeX)))
        {
            zeroTrouve= true;
            listZeros.push_back(gDeX);
            cout << "\tZERO TROUVE" <<"\tg(x)= "<<gDeX<< endl;
        }
    }
    return zeroTrouve;
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
