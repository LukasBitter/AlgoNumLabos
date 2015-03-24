//
//  main.cpp
//  SquareMatrix
//
//  Created by Team 6 on 10.03.15.
//  Copyright (c) 2015 Team 6. All rights reserved.
//

#include <iostream>
#include "squarematrix.h"

using namespace std;

int main()
{
    int rep = Affichage::menuBegin();

    do{
        switch(rep)
        {

        case 1:
            rep = Affichage::menuBegin();
            SquareMatrix sm(5);
            sm.showMatrix();

            break;

        case 2:

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
