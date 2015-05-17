/**
    FonctionGraphique - Header File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 03.05.2015
*/

#ifndef FONCTIONSGRAPHIQUE_H
#define FONCTIONSGRAPHIQUE_H
#include "graph.h"

#include <QWidget>

class QPushButton;
class QLabel;

class FonctionsGraphique : public QWidget
{
    Q_OBJECT
public:
    explicit FonctionsGraphique(QWidget *parent = 0);

private:
    Graph* graphique;
    QPushButton *btnFonction1, *btnFonction2;
    QLabel *labelF, *labelFDerivate, *labelFSecondDerivate;

signals:

public slots:
    void slot_fonction1();
    void slot_fonction2();

    void print();

};

#endif // FONCTIONSGRAPHIQUE_H
