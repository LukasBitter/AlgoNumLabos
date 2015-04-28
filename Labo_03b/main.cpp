/**
    Main Class - Implementation File
    Purpose: this is the Main of the program

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#include <iostream>
#include <time.h>
#include <windows.h>
#include "squarematrix.h"
#include "affichage.h"
#include "matriceDeTest.h"

using namespace std;

/**  Main program */
int main()
{
    static int rep = Affichage::menuBegin();
    SquareMatrix* m;

    int stop_s;
    int start_s;
    int N;
    double** mArray;
    do{
        cout<<rep<<endl;
        switch(rep)
        {
        case 1:
            start_s = clock();
            N=200;

            // Convert 2d array to table of pointers
            mArray = new double* [N];
            for (int i=0; i<N; ++i) {
                mArray[i] = matriceDeTestProf[i];
            }

            // Compute matrix
            m = new SquareMatrix(N,mArray,vecteurDeTestProf);
            m->diagonaliser();
            m->findDeterminant();
            m->solve();
            stop_s = clock();

            // print solutions
            cout << "Processing time : " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << "ms" << endl;
            m->printSolutions();

            system("pause");
            delete m;
            delete mArray;
            rep = Affichage::menuBegin();
            break;

        case 2:
            start_s = clock();
            N=3;

            // Convert 2d array to table of pointers
            mArray = new double* [N];

            for (int i=0; i<N; ++i) {
                mArray[i] = matriceDeTestEasy[i];
            }

            // Compute matrix
            m = new SquareMatrix(N,mArray,vecteurDeTestEasy);
            m->showMatrix();
            m->diagonaliser();
            m->findDeterminant();
            m->solve();
            stop_s = clock();

            // print solutions
            cout << "Processing time : " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << "ms" <<  endl;
            m->printSolutions();

            system("pause");
            delete m;
            delete mArray;
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
