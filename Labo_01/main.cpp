#include <iostream>
#include <math.h>
#include <bitset>
#include "affichage.h"

using namespace std;

int main()
{
    double num;
    int rep;

    rep = Affichage::menuBegin();

    do
    {
        switch(rep)
        {
        case 1:
            Affichage::encode();
            rep = Affichage::menuBegin();
            break;
        case 2:
            Affichage::decode();
            rep = Affichage::menuBegin();
            break;
        case 3:
            Affichage::addition();
            rep = Affichage::menuBegin();
            break;
        case 4:
            Affichage::readme();
            rep = Affichage::menuBegin();
            break;
        case 5:
            break;
        default:
            rep = Affichage::menuNotValid();
            break;
        }
    }while(rep != 5);

    return 0;
}
