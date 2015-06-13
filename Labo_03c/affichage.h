/**
    Affichage - Declaration File
    Purpose: Add printing methods for a better user interaction

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 29.04.2015
*/

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
        /** Default constructor */
        Affichage();
        /** Default destructor */
        virtual ~Affichage();

        /** First call of the interaction with the user */
        static int menuBegin();
        /** Ask user for another menu number because the previous was not valid */
        static int menuNotValid();

        /**
            Get an insertion from the user with control of minimum and maximum value.

            @param valeurMin, valeurMax : Minimum and Maximum value accepted
            @return double numerical value entered by the user
        */
        static double saisieValeur(const double &valeurMin, const double &valeurMax);

        /** Read and print the Readme file */
        static void readme();

        /** Ask the user to press a key to continue */
        static void pressKey();

    private:
        /** Print the header */
        static void header();
        /** Print the menu */
        static void menu();

        /** Empty the Buffer */
        static void viderBuffer();
};

#endif // AFFICHAGE_H
