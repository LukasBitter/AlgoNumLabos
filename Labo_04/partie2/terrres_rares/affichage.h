/**
    Affichage - Declaration File
    Purpose: Add printing methods for a better user interaction

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
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


        /** Read and print the Readme file */
        static void readme();

        /** Ask the user to press a key to continue */
        static void pressKey();

    private:
        /** Print the header */
        static void header();
        /** Print the menu */
        static void menu();

};

#endif // AFFICHAGE_H
