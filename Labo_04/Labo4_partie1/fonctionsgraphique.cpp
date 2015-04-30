#include <QtWidgets>
#include "fonctionsgraphique.h"
#include "fonction.h"
#include "fonction1.h"
#include "fonction2.h"

FonctionsGraphique::FonctionsGraphique(QWidget *parent) :
    QWidget(parent)
{
    //With "this" they will be destroy ! love Qt forever
    btnFonction1 = new QPushButton(tr("&Fonction 1"), this);
    btnFonction2 = new QPushButton(tr("&Fonction 2"), this);

    labelF = new QLabel(tr("f : fonction"), this);
    labelFDerivate = new QLabel(tr("f' : dérivée première"), this);
    labelFSecondDerivate = new QLabel(tr("f'' : dérivée seconde"), this);

    labelF->setFixedHeight(20);
    labelF->setStyleSheet("font-family:'arial'; font-size:18pt; color: blue;");
    labelFDerivate->setFixedHeight(20);
    labelFDerivate->setStyleSheet("font-family:'arial'; font-size:18pt; color: red;");
    labelFSecondDerivate->setFixedHeight(20);
    labelFSecondDerivate->setStyleSheet("font-family:'arial'; font-size:18pt; color: green;");

    Fonction1* f = new Fonction1();
    graphique = new Graph(f);

    QHBoxLayout *btns = new QHBoxLayout();
    btns->addStretch(1);
    btns->addWidget(btnFonction1);
    btns->addWidget(btnFonction2);
    btns->addStretch(1);

    QHBoxLayout *bas = new QHBoxLayout();
    bas->addWidget(labelF);
    bas->addStretch(1);
    bas->addWidget(labelFDerivate);
    bas->addStretch(1);
    bas->addWidget(labelFSecondDerivate);


    QVBoxLayout *main = new QVBoxLayout(this);
    main->addLayout(bas);
    main->addWidget(graphique);
    main->addLayout(btns);


    connect(btnFonction1, SIGNAL(clicked()), this, SLOT(slot_fonction1()));
    connect(btnFonction2, SIGNAL(clicked()), this, SLOT(slot_fonction2()));
}


//Slots
void FonctionsGraphique::slot_fonction1()
{
    Fonction1* f = new Fonction1();
    graphique->setFonction(f);
}
void FonctionsGraphique::slot_fonction2()
{
    Fonction2* f = new Fonction2();
    graphique->setFonction(f);
}
void FonctionsGraphique::print()
{
    graphique->print();
}
