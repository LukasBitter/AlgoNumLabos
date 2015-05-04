/**
    Graph - Header File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 03.05.2015
*/

#ifndef GRAPH_H
#define GRAPH_H
#include <QWidget>

#include <QList>
#include <QPoint>
#include <QGraphicsItem>

#include "fonction.h"

class Graph : public QWidget
{
    Q_OBJECT
public:
    explicit Graph(Fonction* f, QWidget *parent = 0);
    ~Graph();

private:
    void paintEvent(QPaintEvent *event);
    void draw(QPainter &painter);

    void drawFonction(QPainter &painter);
    void drawDerivateFonction(QPainter &painter);
    void drawSecondDerivateFonction(QPainter &painter);

    QGraphicsLineItem *lineX;
    QGraphicsLineItem *lineY;

    double xmax;
    double ymax;
    Fonction* fonction;


signals:

public slots:
    void print();
    void setFonction(Fonction* f);

};

#endif // GRAPH_H
