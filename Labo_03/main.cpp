//
//  main.cpp
//  SquareMatrix
//
//  Created by Team 6 on 10.03.15.
//  Copyright (c) 2015 Team 6. All rights reserved.
//

#include <iostream>
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

    do{
        switch(rep)
        {
        case 1:
            test = new SquareMatrix(sizeof(matriceDeTestProf)/sizeof(*matriceDeTestProf),matriceDeTestProf,resultDeTestProf);
            cout << endl;
            test->diagonaliser();
            cout << endl;
            cout << test->determinant() << endl;

            test->solve();

            system("pause");
            rep = Affichage::menuBegin();
            break;

        case 2:
            test = new SquareMatrix(sizeof(matriceDeTestEasy)/sizeof(*matriceDeTestEasy),matriceDeTestEasy,resultDeTestEasy);
            test->showMatrix();
            cout << endl;
            test->diagonaliser();
            test->showMatrix();
            cout << endl;
            cout << test->determinant() << endl;

            test->solve();

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
