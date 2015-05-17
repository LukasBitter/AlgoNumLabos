/**
    Main Class - Implementation File
    Purpose: this is the Main of the program

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 17.05.2015
*/

#include <iostream>
#include <time.h>
#include <windows.h>
#include "affichage.h"
#include <iomanip>

#include "integral.h"
#include "fonction.h"
#include "fonctiona.h"

using namespace std;

/**  Main program */
int main()
{
    //Variables
    Integral approximationPI(new FonctionA(), 0, 1);
    long double PI = 3.14159265358979323L;
    static int rep = Affichage::menuBegin();

    do{
        switch(rep)
        {
        case 1:
            // Conseil: Entrez un chiffre pair pour le nombre d'itérations.
            cout << "  Approximation : \t" << setprecision(18) << 4 * approximationPI.approimateSimpson(400) << endl;
            cout << "  PI : \t\t\t" << PI << endl << endl << "  ";
            system("pause");
            rep = Affichage::menuBegin();
            break;

        case 2:
            cout << "  Approximation : \t" << setprecision(18) << 4 * approximationPI.approximateMiddlePoint(10000000) << endl;
            cout << "  PI : \t\t\t" << PI << endl << endl << "  ";
            system("pause");
            rep = Affichage::menuBegin();
            break;

        case 3:
            // Print readme
            Affichage::readme();
            rep = Affichage::menuBegin();
            break;

            // Exit
        case 4:
            break;

            // Invalid entry
        default:
            rep = Affichage::menuNotValid();
            break;
        }

    }
    while(rep != 4);

    return 0;
}
