#include "graph.h"
#include <QtWidgets>

#include <QList>
#include <QPoint>
#include <QRect>

#include <QPainter>

#include <QtPrintSupport>
#include <QtPrintSupport/QPrinter>

#include <QDebug>

Graph::Graph(Fonction* f, QWidget *parent) : QWidget(parent)
{
    fonction = f;
    xmax = 10;
    ymax = 40;
}

Graph::~Graph()
{
    delete fonction;
}

void Graph::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    QRect viewport=painter.viewport();

    QRect window;
    window.setRect(-xmax/2, ymax/2, xmax, -ymax);

    painter.setViewport(viewport);
    painter.setWindow(window);

    draw(painter);
}

/**
 * draw the graph with the functions
 * @param painter
 */
void Graph::draw(QPainter &painter)
{
    QPen pen;
    pen.setWidth(0);
    pen.setColor(Qt::black);

    painter.setPen(pen);

    //line
    painter.drawLine(-xmax/2,0, xmax/2, 0);
//    for (int i = -xmax/2+1; i <= xmax/2; i++)
//    {
//        painter.drawLine(i, 1, i, -1);
//        //painter.drawText(i,-1, QString::number(i));
//    }

    painter.drawLine(0,ymax/2, 0, -ymax/2);
//    for (int i = -ymax/2+1; i <= ymax/2; i++)
//    {
//        painter.drawLine(-1, i, 1, i);
//        //painter.drawText(i,-1, QString::number(i));
//    }


    pen.setColor(Qt::green);
    painter.setPen(pen);

    drawSecondDerivateFonction(painter);

    pen.setColor(Qt::blue);
    painter.setPen(pen);

    drawFonction(painter);

    pen.setColor(Qt::red);
    painter.setPen(pen);

    drawDerivateFonction(painter);

}

/**
 * draw f(x)
 * @param painter
 */
void Graph::drawFonction(QPainter &painter)
{
    double y=fonction->f(-xmax/2.0);
    QPointF start ,dest;
    start = QPointF(-xmax/2, y); // Premier point

    for (double i = -xmax/2+1; i <= xmax/2; i+=0.1)
    {
        y = fonction->f(i); //draw f
        dest = QPointF(i, y);
        painter.drawLine(start, dest);
        start = dest;
    }
}

/**
 * draw f'(x)
 * @param painter
 */
void Graph::drawDerivateFonction(QPainter &painter)
{
    double y=fonction->f_derivate(-xmax/2.0);
    QPointF start ,dest;
    start = QPointF(-xmax/2, y);

    for (double i = -xmax/2+1; i <= xmax/2; i+=0.1)
    {
        y = fonction->f_derivate(i); //draw f'
        dest = QPointF(i, y);
        painter.drawLine(start, dest);
        start = dest;
    }
}

/**
 * draw f''(x)
 * @param painter
 */
void Graph::drawSecondDerivateFonction(QPainter &painter)
{
    double y=fonction->f_derivateSecond(-xmax/2.0);
    QPointF start ,dest;
    start = QPointF(-xmax/2, y); // Premier point

    for (double i = -xmax/2+1; i <= xmax/2; i+=0.1)
    {
        y = fonction->f_derivateSecond(i); //draw f''
        dest = QPointF(i, y);
        painter.drawLine(start, dest);
        start = dest;
    }
}

void Graph::print()
{
    QPrinter printer;
    QPrintDialog dialogue(&printer, this);
    if (dialogue.exec() == QDialog::Accepted)
    {
        QPainter paint(&printer);
        QRect rect = paint.viewport();
        QSize size = this->size();
        size.scale(rect.size(), Qt::KeepAspectRatio);
        paint.setViewport(rect.x(), rect.y(), size.width(), size.height());
        paint.setWindow(-xmax/2, ymax/2, xmax, -ymax);
        draw(paint);
    }
}

/**
 * Change function and delete the old
 * @param f : new function
 */
void Graph::setFonction(Fonction* f)
{
    delete fonction;
    fonction = f;
    repaint();
}
