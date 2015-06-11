#include "graph.h"
#include "bourse.h"

#include <QPainter>
#include <QMap>
#include <QDebug>
#include <QPainterPath>
#include <QDate>

#include "qcustomplot.h"

Graph::Graph(Bourse* bourse, QWidget *parent) : QWidget(parent)
{
    this->bourse = bourse;

    customPlot = new QCustomPlot();

    QVector<double> x;
    QVector<double> y;

    QMap<int, double>::iterator i;
    QMap<int, double> cours = bourse->getCours();

    int j = 0;
    for (i = cours.begin(); i != cours.end(); ++i)
    {
        x.append(i.key());
        y.append(i.value());
        j++;
    }

    // customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
//     customPlot->xAxis->setDateTimeFormat("MM'-'dd");

      // set a fixed tick-step to one tick per month:
      customPlot->xAxis->setAutoTickStep(false);
      customPlot->xAxis->setTickStep(30*6); // one month in seconds
      //this->xAxis->setTickStep(86400);
//      customPlot->xAxis->setSubTickCount(30);

    // create graph and assign data to it:
    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    // give the axes some labels:
    customPlot->xAxis->setLabel("x");
    customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:

    customPlot->xAxis->setRange(x.last(), x.first());
    customPlot->yAxis->setRange(bourse->getMin(), bourse->getMax());
    customPlot->replot();

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(customPlot);

    setLayout(layout);
}
