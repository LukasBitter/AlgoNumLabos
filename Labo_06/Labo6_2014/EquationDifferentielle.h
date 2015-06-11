/*
 * Labo 6
 *
 * Auteurs:
 *	Fábio Marques
 *	Cyriaque Skrapits
 *	Eddy Strambini
 */

#ifndef EQUATIONDIFFERENTIELLE_H
#define EQUATIONDIFFERENTIELLE_H

#include <sstream>
#include <string>
#include <iostream>
#include <stdio.h>

#include "GeomGlut.h"

class EquationDifferentielle
{
public:
    EquationDifferentielle();
    virtual ~EquationDifferentielle();

    static double fonction(const double, const double);
    static void dessinerCourbe(GeomGlut*, const double, const double);
    static void dessinerGrille(GeomGlut*);
    static void dessinerVecteurs(GeomGlut*);
		static void texte(GeomGlut*, const double, const double);

protected:
private:
};

#endif // EQUATIONDIFFERENTIELLE_H
