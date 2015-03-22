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

PointFixe::PointFixe(Fonction* fonction, double ptDepart, double ptFin, double lam, double nbIterMax)
//PointFixe::PointFixe(double ptDepart, double ptFin, double lam, double nbIterMax)
{
    currentFonction = fonction;

    pointDepart = ptDepart;
    pointFin = ptFin;
    lambda = lam;
    nbIterationsMax = nbIterMax;
    valeurMaxTemporaireTrouve = ptDepart;

    zeroTrouve = false;
    listZeros = set<double>();
}

double PointFixe::g(double x)
{
    return x+lambda*f(x);
}

double PointFixe::f(double x)
{
    //return sin(x)-x/13;
    return currentFonction->f(x);
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
    while(valeurMaxTemporaireTrouve < 100)
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
    double gDeX = g(ptDepart);
    if(gDeX > valeurMaxTemporaireTrouve)
    {
        valeurMaxTemporaireTrouve = gDeX;
    }

    double i=1;
    while(!estUnZero(gDeX,g(gDeX)) && i<=nbIterationsMax)
    {
        gDeX = g(gDeX);
        if(gDeX > valeurMaxTemporaireTrouve)
        {
            valeurMaxTemporaireTrouve = gDeX;
        }

        //cout<<"Iteration  "<<i<<"\t\tg(x)= "<<gDeX<<endl;
        i++;

        if(estUnZero(gDeX,g(gDeX)))
        {
            zeroTrouve= true;
            listZeros.insert(round(gDeX * pow(10, 5)) / pow(10, 5)); //arrondi a 5 chiffres apres la virgule (test temporaire)

            //if(valeurMaxTemporaireTrouve>-6.87)
               // cout << "\tZERO TROUVE" <<"\tg(x)= "<<gDeX<<" / "<<valeurMaxTemporaireTrouve<< endl;
            // cout << "\tVALEUR MAX" <<"\t = "<<valeurMaxTemporaireTrouve<< endl;
        }
    }

    return zeroTrouve;
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
