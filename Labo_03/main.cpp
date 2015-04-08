//
//  main.cpp
//  Matrix
//
//  Created by Team 6 on 10.03.15.
//  Copyright (c) 2015 Team 6. All rights reserved.
//

#include <iostream>
#include <windows.h>
#include "matrix.h"
#include "affichage.h"

#include "matriceDeTest.h"

using namespace std;

int main()
{
    int rep = Affichage::menuBegin();

    int n=4;
    int m=6;
    double *line1= new double[1,2,2,-3,2,3];
    double *line2= new double[2,4,1,0,-5,-6];
    double *line3= new double[4,8,5,-6,-1,0];
    double *line4= new double[-1,-2,-1,1,1,1];
    double** mat= new double*[n];

    mat[0]= line1;
    mat[1]= line2;
    mat[2]= line3;
    mat[3]= line4;
//    Matrix sm(5);
    Matrix* test;

    do{
        switch(rep)
        {
        case 1:
//            test = new Matrix(sizeof(matriceDeTestProf)/sizeof(*matriceDeTestProf),matriceDeTestProf,resultDeTestProf);
//            cout << endl;
//            test->diagonaliser();
//            cout << endl;
//            cout << test->determinant() << endl;
//
//            test->solve();
//
//            system("pause");
//            rep = Affichage::menuBegin();
            break;

        case 2:

            test= new Matrix(n,m,mat);

//            test = new Matrix(sizeof(matriceDeTestEasy)/sizeof(*matriceDeTestEasy),matriceDeTestEasy,resultDeTestEasy);
//            test->showMatrix();
//            cout << endl;
//            test->diagonaliser();
//            test->showMatrix();
//            cout << endl;
//            cout << test->determinant() << endl;
//
//            test->solve();

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
