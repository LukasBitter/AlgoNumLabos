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



/** Start the counter and return it */
LARGE_INTEGER StartCounter()
{
    LARGE_INTEGER li;
    if(!QueryPerformanceFrequency(&li))
    {
         cout << "QueryPerformanceFrequency failed!\n";
    }

    QueryPerformanceCounter(&li);

    return li;
}

/** Calcultate the time elapsed since "CounterStart" in params  */
double GetTime(__int64 CounterStart, double PCFreq)
{
    LARGE_INTEGER li;
    QueryPerformanceCounter(&li);
    return double(li.QuadPart-CounterStart)/PCFreq;
}

/**  Main program */
int main()
{
    //Variables
    Integral approximationPI(new FonctionA(), 0, 1);
    long double PI = 3.14159265358979323L;
    static int rep = Affichage::menuBegin();


    double pi;
    LARGE_INTEGER CounterStart;

    do{
        switch(rep)
        {
        case 1:
            // Conseil: Entrez un chiffre pair pour le nombre d'itérations.

            CounterStart = StartCounter();
            pi =  4 * approximationPI.approimateSimpson(400);
            cout << "  Temps de calcul en ms : \t" << GetTime(CounterStart.QuadPart, double(CounterStart.QuadPart)/1000.0) <<"\n";

            cout << "  Approximation : \t" << setprecision(18) << pi << endl;
            cout << "  PI : \t\t\t" << PI << endl << endl << "  ";
            system("pause");
            rep = Affichage::menuBegin();
            break;

        case 2:

            CounterStart = StartCounter();
            pi =  4 * approximationPI.approximateMiddlePoint(10000000);
            cout << "  Temps de calcul en ms : \t" << GetTime(CounterStart.QuadPart, double(CounterStart.QuadPart)/1000.0) <<"\n";

            cout << "  Approximation : \t" << setprecision(18) << pi << endl;
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
