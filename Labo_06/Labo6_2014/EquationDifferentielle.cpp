/*
 * Labo 6
 *
 * Auteurs:
 *	Fábio Marques
 *	Cyriaque Skrapits
 *	Eddy Strambini
 */

#include "EquationDifferentielle.h"

EquationDifferentielle::EquationDifferentielle()
{
    //ctor
}

EquationDifferentielle::~EquationDifferentielle()
{
    //dtor
}

/**
 * Équation différentielle.
 * @param t Temps
 * @param y Valeur Y
 */
double EquationDifferentielle::fonction(const double t, const double y)
{
    return t * t + y * y;
}

/**
 * Dessine les vecteur.
 * @param graphWin Graphique GLUT
 */
void EquationDifferentielle::dessinerVecteurs(GeomGlut* graphWin)
{
    const float STEP = 0.1f;
    const float WIDTH = 0.02f;
    const double XMIN = graphWin->xMin();
    const double XMAX = graphWin->xMax();
    const double YMIN = graphWin->yMin();
    const double YMAX = graphWin->yMax();

    double pente = 0;

    for(float t = XMIN; t < XMAX; t += STEP)
    {
        for(float y = YMIN; y < YMAX; y += STEP)
        {
            pente = fonction(t, y);
            graphWin->setColorForPlotWithoutColor(0.6f, 0.8f, 1.0f);
            graphWin->segment(t - WIDTH, y - pente / 4 * STEP, t + WIDTH, y + pente / 4 * STEP);
        }
    }
}

/**
 * Dessine la courbe de l'équation depuis un certain point.
 * @param graphWin Graphique GLUT
 * @param t Temps initial
 * @param y Hauteur initiale
 */
void EquationDifferentielle::dessinerCourbe(GeomGlut* graphWin, const double t, const double y)
{
    const double XMAX = graphWin->xMax();
    const int N = 100;
    const float H = (XMAX - t) / N;

    float yDebut = y; // Extrémité de gauche.
    float yFin; // Extrémité de droite.
    float x;

    // Méthode d'Euler
    for(float it = 0; it < N; it++)
    {
        x = t + it * H;
        yFin = yDebut + H * fonction(x, yDebut);
        graphWin->setColorForPlotWithoutColor(0.f, 0.f, 0.f);
        graphWin->segment(x, yDebut, x + H, yFin);
        yDebut = yFin;
    }
}

/**
 * Dessine une grille sur le graphique.
 * @param graphWin Graphique GLUT
 */
void EquationDifferentielle::dessinerGrille(GeomGlut* graphWin)
{
    char nombre[2];
    const double XMIN = graphWin->xMin();
    const double XMAX = graphWin->xMax();
    const double YMIN = graphWin->yMin();
    const double YMAX = graphWin->yMax();



    // Lignes verticales
    for(int x = XMIN; x < XMAX; x++)
    {
        graphWin->setColorForPlotWithoutColor(0.8f, 0.8f, 0.8f);
        graphWin->segment(x, YMIN, x, YMAX);

        // Texte
        sprintf(nombre, "%d", x);
        graphWin->setColorForPlotWithoutColor(0.5f, 0.5f, 0.5f);
        graphWin->texte(x + 0.02, -0.05f, nombre);
    }

    // Lignes horizontales
    for(int y = YMIN; y < YMAX; y++)
    {
        graphWin->setColorForPlotWithoutColor(0.8f, 0.8f, 0.8f);
        graphWin->segment(XMIN, y, XMAX, y);

        // Texte
        if (y == 0) continue; // Évite d'avoir deux nombres au centre.
        sprintf(nombre, "%d", y);
        graphWin->setColorForPlotWithoutColor(0.5f, 0.5f, 0.5f);
        graphWin->texte(0.02f, y, nombre);
    }

    // Lignes centrales
    graphWin->setColorForPlotWithoutColor(0.5f, 0.5f, 0.5f);
    graphWin->segment(0, YMIN, 0, YMAX);
    graphWin->segment(XMIN, 0, XMAX, 0);
}

/**
 * Ecrit les informations de l'application.
 * @param graphWin Graphique GLUT
 * @param x Point de départ en X de la courbe
 * @param y Point de départ en Y de la courbe
 */
void EquationDifferentielle::texte(GeomGlut* graphWin, const double x, const double y)
{
    const float MARGEX = 0.1f;
    const float MARGEY = 0.05f;
    const double XMIN = graphWin->xMin();
    const double YMAX = graphWin->yMax();

    std::ostringstream p;
    p << "P0 : (" << x << ", " << y << ")";

    graphWin->setColorForPlotWithoutColor(0.5f, 0.5f, 0.5f);
    graphWin->texte(XMIN + MARGEX, YMAX - MARGEY * 2, "ALGORITHMES NUMERIQUES : LABO #6");
    graphWin->texte(XMIN + MARGEX, YMAX - MARGEY * 3, "Groupe 7");
    graphWin->texte(XMIN + MARGEX, YMAX - MARGEY * 4, "Fabio Marques, Cyriaque Skrapits, Eddy Strambini");

    graphWin->texte(XMIN + MARGEX, YMAX - MARGEY * 6, "Fonction :  f(y, t) = t * t + y * y");
    graphWin->texte(XMIN + MARGEX, YMAX - MARGEY * 8, p.str().c_str());
}
