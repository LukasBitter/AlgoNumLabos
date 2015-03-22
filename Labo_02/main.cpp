/**
    Main - Implementation File
    Purpose: The main program is here.

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#include <iostream>
#include <limits>

#include "constantes.h"
#include "pointfixe.h"
#include "fonction.h"
#include "fonctiona.h"
#include "fonctionb.h"

#include <math.h>
#include "affichage.h"

using namespace std;

int main()
{
    double lambda;
    double nbIterationsMax;
    int rep = Affichage::menuBegin();

    PointFixe* fonction;

    do{
        switch(rep)
        {

        case 1:
            cout << endl << "Saisissez lambda :" << endl;
            lambda = Affichage::saisieValeur(LAMBDA_MIN, LAMBDA_MAX);
            cout << endl << "Saisissez le nombre d'iteration maximum :" << endl;
            nbIterationsMax = Affichage::saisieValeur(ITERATIONS_MIN, ITERATIONS_MAX);

            //double pointDepart1 = saisieValeur(&POINT_MIN,&POINT_MAX);
            fonction = new PointFixe(new FonctionA(), POINT_MIN, POINT_MAX, lambda, nbIterationsMax);
            fonction->demarrerRecherche();

            Affichage::pressKey();

            rep = Affichage::menuBegin();
            delete fonction;
            break;

        case 2:
            cout << endl << "Saisissez lambda :" << endl;
            lambda = Affichage::saisieValeur(LAMBDA_MIN, LAMBDA_MAX);
            cout << endl << "Saisissez le nombre d'iteration maximum :" << endl;
            nbIterationsMax = Affichage::saisieValeur(ITERATIONS_MIN,ITERATIONS_MAX);

            //double pointDepart2 = saisieValeur(&POINT_MIN, &POINT_MAX);
            fonction = new PointFixe(new FonctionB(), POINT_MIN, POINT_MAX, lambda, nbIterationsMax);
            fonction->demarrerRecherche();

            Affichage::pressKey();

            rep = Affichage::menuBegin();
            delete fonction;
            break;

        case 3:
            Affichage::readme();
            rep = Affichage::menuBegin();
            break;
        case 4:
            break;
        default:
            rep = Affichage::menuNotValid();
            break;
        }

    }
    while(rep != 4);


    cin.seekg(0, ios::end);
    return 0;
}

