#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include "bourse.h"
#include "qcustomplot.h"
#include <QLabel>

class Graph : public QWidget
{
    Q_OBJECT
public:
    Graph(Bourse *bourse, QWidget *parent = 0);
    virtual ~Graph();

signals:

public slots:

private :
    Bourse* bourse;
    QCustomPlot* customPlot;
    QLabel* labelPeriod;
    QLabel* labelYear;

};

#endif // GRAPH_H
