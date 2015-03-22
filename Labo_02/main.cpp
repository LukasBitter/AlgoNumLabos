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

using namespace std;

int main()
{
    cout << "Bienvenue a la methode du point fixe\t:)\n"<<
            "Pour touver les f(x) = 0 compris de [-100, 100] nouos nous aidons d'une autre fonction:\n"<<
            "\tg(x) = x + lambda * f(x)\n"<<
            "\tf(x) = 0 => g(x) = x\n\n"
            "Nous allons commencer par la fonction sin(x)-x/13"<<
            endl;

//    double pointDepart1 = saisieValeur(&POINT_MIN,&POINT_MAX, &STRING_POINT_DEPART);
    double lambda1 = saisieValeur(LAMBDA_MIN, LAMBDA_MAX, STRING_LAMBDA);
    double nbIterationsMax1 = saisieValeur(ITERATIONS_MIN,ITERATIONS_MAX,STRING_ITERATIONS);

    PointFixe function1(new FonctionA(), POINT_MIN, POINT_MAX, lambda1, nbIterationsMax1);
    function1.demarrerRecherche();

    cout << "\n\nMaintenant place a la fonction 1/(1-x^2)"<<endl;

//    double pointDepart2 = saisieValeur(&POINT_MIN, &POINT_MAX, &STRING_POINT_DEPART);
    double lambda2 = saisieValeur(LAMBDA_MIN, LAMBDA_MAX, STRING_LAMBDA);
    double nbIterationsMax2 = saisieValeur(ITERATIONS_MIN,ITERATIONS_MAX,STRING_ITERATIONS);

    PointFixe function2(new FonctionB(), POINT_MIN, POINT_MAX, lambda2, nbIterationsMax2);
    function2.demarrerRecherche();

    return 0;
}

double saisieValeur(const double &valeurMin, const double &valeurMax, const string &str)
{
    double valeurDeRetour= valeurMin-1;
    while(true)
    {
        cout << str << endl;
        cin >> valeurDeRetour;

        if(cin.eof() || cin.bad())
        {
            cerr << "Une erreur interne est survenue." << endl;
            if(cin.eof() || valeurDeRetour <= valeurMin || valeurDeRetour >=valeurMax)
            {
                break;
            }
            viderBuffer();
            continue;
        }
        else if(cin.fail() || valeurDeRetour <= valeurMin ||valeurDeRetour >=valeurMax)
        {
            cerr << "Erreur, saisie incorrecte." << endl;
            viderBuffer();
            continue;
        }
        break;
    }
    return valeurDeRetour;
}

void viderBuffer()
{
    cin.clear();
    cin.seekg(0, ios::end);

    if(!cin.fail())
    {
        cin.ignore(numeric_limits<streamsize>::max());
    }
    else
    {
        cin.clear();
    }
}
