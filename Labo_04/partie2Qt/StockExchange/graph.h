#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include "bourse.h"
#include "qcustomplot.h"

class Graph : public QWidget
{
    Q_OBJECT
public:
    Graph(Bourse *bourse, QWidget *parent = 0);

signals:

public slots:

private :
    Bourse* bourse;
    QCustomPlot* customPlot;

};

#endif // GRAPH_H
