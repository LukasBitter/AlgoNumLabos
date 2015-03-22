#ifndef AFFICHAGE_H
#define AFFICHAGE_H


#include <windows.h>
#include <iostream>
#include <limits>
#include <conio.h>

using namespace std;


class Affichage
{
    public:
        Affichage();
        virtual ~Affichage();
        static int menuBegin();
        static int menuNotValid();

        static double saisieValeur(const double &valeurMin, const double &valeurMax);

        static void readme();

        static void pressKey();
    protected:
    private:
        static void header();
        static void menu();

        static void viderBuffer();
};

#endif // AFFICHAGE_H
