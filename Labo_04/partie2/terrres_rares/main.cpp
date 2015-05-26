//  main.cpp
//
//  Created by Team 6 on 03.05.15.
//  Copyright (c) 2015 Team 6. All rights reserved.


#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>

#include "affichage.h"
#include "bourse.h"

using namespace std;

int main()
{
    Bourse* bourse;

    int rep = Affichage::menuBegin();
    do{
        switch(rep)
        {
        case 1:
            bourse = new Bourse("../terre_rare/cours_terres_rares.csv","../terre_rare/inflation.csv");
            bourse->displayMapCours();
            bourse->findCheapestMoment();
            bourse->findBestPeriodToBuyAndSale();

            delete bourse;
            system("pause");
            rep = Affichage::menuBegin();
            break;

        case 2:
            bourse = new Bourse("../or/cours_or.csv","../or/inflation.csv");
            bourse->displayMapCours();
            bourse->findCheapestMoment();
            bourse->findBestPeriodToBuyAndSale();

            delete bourse;

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
