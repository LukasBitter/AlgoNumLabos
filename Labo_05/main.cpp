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
    Integral approximationPI(new FonctionA(), 0, 1, 10000000);
    long double PI = 3.14159265358979323846264338327950288419716;
    static int rep = Affichage::menuBegin();

    do{
        switch(rep)
        {
        case 1:
            cout << setprecision(18) << 4 * approximationPI.approximateMiddlePoint();
            cout << endl;
            cout << PI;
            cout << endl;
            system("pause");
            rep = Affichage::menuBegin();
            break;

        case 2:
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
