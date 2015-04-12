//
//  main.cpp
//  SquareMatrix
//
//  Created by Team 6 on 10.03.15.
//  Copyright (c) 2015 Team 6. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <windows.h>
#include "squarematrix.h"
#include "affichage.h"

#include "matriceDeTest.h"



using namespace std;

int main()
{
    int rep = Affichage::menuBegin();
    SquareMatrix sm(5);
    SquareMatrix* test;

    int stop_s;
    int start_s;
    do{
        switch(rep)
        {
        case 1:
            start_s = clock();

            test = new SquareMatrix(sizeof(matriceDeTestProf)/sizeof(*matriceDeTestProf),matriceDeTestProf,resultDeTestProf);
            cout << endl;
            test->diagonaliser();
            cout << endl;
            cout << test->determinant() << endl << endl;

            test->solve();

            stop_s = clock();
            cout << "Processing time : " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << "ms" << endl;

            system("pause");
            rep = Affichage::menuBegin();
            break;

        case 2:
            start_s = clock();

            test = new SquareMatrix(sizeof(matriceDeTestEasy)/sizeof(*matriceDeTestEasy),matriceDeTestEasy,resultDeTestEasy);
            test->showMatrix();
            cout << endl;
            test->diagonaliser();
            cout << endl;
            cout << test->determinant() << endl << endl;

            test->solve();

            stop_s = clock();
            cout << "Processing time : " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << "ms" <<  endl;

            system("pause");
            rep = Affichage::menuBegin();
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


    return 0;
}
