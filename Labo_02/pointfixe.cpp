#include <set>
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
    valeurMaxTemporaireTrouve=ptDepart;
    zeroTrouve= false;
    listZeros= set<double>();
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
    valeurMaxTemporaireTrouve+=pow(10,13)*EPSILON_MACHINE;
        rechercheZeros(valeurMaxTemporaireTrouve);
    }
    cout<<"\n\tFINI"<<endl;

    set<double>::iterator it;
    for(it=listZeros.begin(); it!=listZeros.end(); ++it)
    {
        cout<<"\n\t\t Zero: "<<*it<<endl;
    }
}

bool PointFixe::rechercheZeros(double ptDepart)
{
    double gDeX = calculGDeX(ptDepart);
    if(gDeX>valeurMaxTemporaireTrouve)
    {
        valeurMaxTemporaireTrouve= gDeX;
    }
    double i=1;
    while(!estUnZero(gDeX,calculGDeX(gDeX)) && i<=nbIterationsMax)
    {
        gDeX= calculGDeX(gDeX);
        if(gDeX>valeurMaxTemporaireTrouve)
        {
            valeurMaxTemporaireTrouve= gDeX;
        }
        //cout<<"Iteration  "<<i<<"\t\tg(x)= "<<gDeX<<endl;
        i++;
        if(estUnZero(gDeX,calculGDeX(gDeX)))
        {
            zeroTrouve= true;
            listZeros.insert(gDeX);
            //if(valeurMaxTemporaireTrouve>-6.87)
               // cout << "\tZERO TROUVE" <<"\tg(x)= "<<gDeX<<" / "<<valeurMaxTemporaireTrouve<< endl;
           // cout << "\tVALEUR MAX" <<"\t = "<<valeurMaxTemporaireTrouve<< endl;
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
