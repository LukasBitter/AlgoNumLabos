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
PointFixe::PointFixe(Fonction* fonction, double ptDepart, double ptFin, double lam, double nbIterMax)
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

// Destructor
PointFixe::~PointFixe()
{
    //dtor
}

// Return the solved result of g(x) where g(x) = x + lambda * f(x)
double PointFixe::g(double x)
{
    return x+lambda*currentFonction->f(x);
}

// Return the pointDepart attribute value
double PointFixe::getPointDepart()
{
    return pointDepart;
}

// Start to search the Zero values
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

// Search the Zero values
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

// Check if the found value is a Zero
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
