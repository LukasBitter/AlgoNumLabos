#include "main.h"
#include "constantes.h"
#include <iostream>
#include <limits>

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

    cout << "\n\nMaintenant place a la fonction 1/(1-x^2)"<<
            endl;
//    double pointDepart2 = saisieValeur(&POINT_MIN, &POINT_MAX, &STRING_POINT_DEPART);
    double lambda2 = saisieValeur(LAMBDA_MIN, LAMBDA_MAX, STRING_LAMBDA);

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
