/**
    Main - Implementation File
    Purpose: The main program is here.

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#include <iostream>
#include <limits>

#include "main.h"
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

//    double pointDepart1 = saisieValeur(&POINT_MIN,&POINT_MAX, &STRING_POINT_DEPART);
    double lambda1 = saisieValeur(LAMBDA_MIN, LAMBDA_MAX, STRING_LAMBDA);
    double nbIterationsMax1 = saisieValeur(ITERATIONS_MIN,ITERATIONS_MAX,STRING_ITERATIONS);

            cout << "saisiez lambda :" << endl;
            lambda = Affichage::saisieValeur(LAMBDA_MIN, LAMBDA_MAX);

            cout << "saisiez le nombre d'iteration maximum :" << endl;
            nbIterationsMax = Affichage::saisieValeur(ITERATIONS_MIN, ITERATIONS_MAX);


            //    double pointDepart1 = saisieValeur(&POINT_MIN,&POINT_MAX, &STRING_POINT_DEPART);

            fct1 = new PointFixeFct1(POINT_MIN,POINT_MAX, lambda, nbIterationsMax);
            fct1->demarrerRecherche();

            Affichage::pressKey();

            rep = Affichage::menuBegin();
            delete fct1;
            break;

        case 2:
            cout << "saisiez lambda :" << endl;
            lambda = Affichage::saisieValeur(LAMBDA_MIN, LAMBDA_MAX);
            cout << "saisiez le nombre d'iteration maximum :" << endl;
            nbIterationsMax = Affichage::saisieValeur(ITERATIONS_MIN,ITERATIONS_MAX);
            //    double pointDepart2 = saisieValeur(&POINT_MIN, &POINT_MAX, &STRING_POINT_DEPART);
        cin >> valeurDeRetour;
            //    fct2 = new PointFixeFct2(POINT_MIN, POINT_MAX, lambda, nbIterationsMax);
            //    fct2->demarrerRecherche(fct2.getPointDepart());
}
            Affichage::pressKey();

            rep = Affichage::menuBegin();
            delete fct2;
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
    }while(rep != 4);
    cin.seekg(0, ios::end);
    return 0;
    }
}
