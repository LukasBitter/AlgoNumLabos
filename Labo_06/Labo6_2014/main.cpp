/*
 * Labo 6
 *
 * Auteurs:
 *	Fábio Marques
 *	Cyriaque Skrapits
 *	Eddy Strambini
 */

#include <math.h>

#include "main.h"
#include "GeomGlut.h"
#include "EquationDifferentielle.h"

extern GeomGlut graphWin;

float courbeX = -1.5f; // Point de départ en X de la courbe.
float courbeY = -1.4f; // Point de départ en Y de la courbe.

int main(int argc, char **argv)
{
		intro();
    graphWin.initGraphicsWin(1000, -2, 2, -2, 2);

    return(0);
}

/**
 * Fonction appelée par GLUT lors d'un clique sur la fenêtre.
 * @param x Position X du curseur
 * @param y Position Y du curseur
 */
void dessinerCourbe(const double x, const double y)
{
    courbeX = x;
    courbeY = y;

    EquationDifferentielle::dessinerCourbe(&graphWin, courbeX, courbeY);

    Display(); // Rafraîchi.
}

void intro()
{
    cout << "================================================================================" << endl;
    cout << "Algorithmes numeriques" << endl;
    cout << "Laboratoire 6" << endl;
    cout << endl;
    cout << "Equipe : 7" << endl;
    cout << "Eleves : Febio Marques, Cyriaque Skrapits, Eddy Strambini" << endl;
    cout << "Professeur : Dr. Stephane Gobron" << endl;
    cout << "================================================================================" << endl;
    cout << endl;
}

void mainFunction( void )
{
    EquationDifferentielle::dessinerVecteurs(&graphWin);
    EquationDifferentielle::dessinerGrille(&graphWin);
    EquationDifferentielle::dessinerCourbe(&graphWin, courbeX, courbeY);
    EquationDifferentielle::texte(&graphWin, courbeX, courbeY);
}

