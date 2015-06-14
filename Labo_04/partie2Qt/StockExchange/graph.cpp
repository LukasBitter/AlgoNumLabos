#include "graph.h"
#include "bourse.h"

#include <QPainter>
#include <QMap>
#include <QDebug>
#include <QPainterPath>
#include <QDate>

#include "qcustomplot.h"

/**
 * @brief Graph::Graph
 * Widget that contains the graphical elements displayed to the user
 * @param bourse
 * @param parent
 */
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
        QDateTime dateTime(QDate::fromJulianDay(i.key()));
        x.append(dateTime.toTime_t());
        y.append(i.value());
        j++;
    }

    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    customPlot->xAxis->setTickLabelRotation(90);
    customPlot->xAxis->setDateTimeFormat("dd'-'MM'-'yyyy");

    customPlot->xAxis->setAutoTickStep(false);
    customPlot->xAxis->setAutoSubTicks(false);
    customPlot->xAxis->setSubTickCount(7);
    customPlot->xAxis->setTickStep(3600*24*7*4);

    customPlot->addGraph();
    customPlot->graph(0)->setData(x, y);

    customPlot->xAxis->setLabel("Date");
    customPlot->yAxis->setLabel("Price");

    customPlot->xAxis->setRange(x.last(), x.first());
    customPlot->yAxis->setRange(bourse->getMin(), bourse->getMax());
    customPlot->replot();

    labelPeriod = new QLabel(bourse->getMaxInflation());
    labelYear = new QLabel(bourse->getMaxYearInflation());

    QVBoxLayout *layout = new QVBoxLayout;

    layout->addWidget(customPlot,2);
    layout->addWidget(labelPeriod, 0);
    layout->addWidget(labelYear, 0);

    setLayout(layout);
}


Graph::~Graph()
{
    delete customPlot;
    delete labelPeriod;
    delete labelYear;
}

