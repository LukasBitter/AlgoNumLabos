/**
    Main - Implementation File
    Purpose: The main program is here.

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
    @date 2015-04-28
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
            cout << endl << "   Enter a value for Lambda (WORKS BEST WITH 1) :" << endl;
            lambda = Affichage::saisieValeur(LAMBDA_MIN, LAMBDA_MAX);
            cout << endl << "   Enter the maximum number of iteration (WORKS BEST WITH 1000) :" << endl;
            nbIterationsMax = Affichage::saisieValeur(ITERATIONS_MIN, ITERATIONS_MAX);

            //double pointDepart1 = saisieValeur(&POINT_MIN,&POINT_MAX);
            fonction = new PointFixe(new FonctionA(), POINT_MIN, POINT_MAX, lambda, nbIterationsMax);
            fonction->startAlgo();

            Affichage::pressKey();

            rep = Affichage::menuBegin();
            delete fonction;
            break;

        case 2:
            cout << endl << "   NOTE: For this function we should  check"<<endl;
            cout << "   if the absolute value of the derivates is between 0 and 1"<<endl;
            cout << "   else we should stop iterating."<<endl;
            cout << "   As we don't do this control, making useless iterations"<<endl;
            cout << "   takes too much time to find the roots, i.e if you put a lot of iterations"<<endl;
            cout << "   the program should in the end find the roots, but will take a long long time."<<endl;
            cout << "   The same happens if we increase precision to compare the two values" << endl;
            cout << "   in order to find a root" << endl << endl;

            cout << endl << "   Enter a value for Lambda :" << endl;
            lambda = Affichage::saisieValeur(LAMBDA_MIN, LAMBDA_MAX);
            cout << endl << "   Enter the maximum number of iteration :" << endl;
            nbIterationsMax = Affichage::saisieValeur(ITERATIONS_MIN,ITERATIONS_MAX);

            //double pointDepart2 = saisieValeur(&POINT_MIN, &POINT_MAX);
            fonction = new PointFixe(new FonctionB(), POINT_MIN, POINT_MAX, lambda, nbIterationsMax);
            fonction->startAlgo();

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

