/**
    Champs - Implementation File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 03.05.2015
*/

#include "champs.h"
#include <QtWidgets>

#include <QList>
#include <QPoint>
#include <QRect>

#include <QPainter>

//#include <QtPrintSupport>
//#include <QtPrintSupport/QPrinter>

#include <QDebug>

Champs::Champs(QWidget *parent) : QWidget(parent)
{
    // set black background
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    this->setAutoFillBackground(true);
    this->setPalette(Pal);
}

Champs::~Champs()
{

}

void Champs::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    draw(painter);
}

/**
 * draw the Champs
 * @param painter
 */
void Champs::draw(QPainter &painter)
{
    QPen pen;
    pen.setWidth(0);
    pen.setColor(Qt::green);

    painter.setPen(pen);

    int pas = 50;
    for(int y = 0; y<this->height(); y+=pas)
    {
        for(int x = 0; x<this->width(); x+=pas)
        {
            drawVect(&painter, x, y, pas);
        }
    }

}


void Champs::drawVect(QPainter *p, float x, float y, double pas)
{
    //get the influences
    float valueTop = f(x, y+pas);
    float valueBottom = f(x, y-pas);
    float valueLeft = f(x-pas, y);
    float valueRight = f(x+pas, y);

    //find the bigger
    QList<float> tri;
    tri.append(valueTop);
    tri.append(valueBottom);
    tri.append(valueLeft);
    tri.append(valueRight);

    float bigger = 0;
    foreach (float val, tri) {
        if(bigger<val)
        {
            bigger = val;
        }
    }

    //moyenne
    valueTop /= bigger;
    valueLeft /= bigger;
    valueBottom /= bigger;
    valueRight /= bigger;

    //calculate the vector from x and y
    float xFinal = x + (valueRight - valueLeft)*pas;
    float yFinal = y + (valueTop - valueBottom)*pas;

    //draw the vector
    //p->drawLine(QPointF(x, y), QPointF(xFinal,yFinal));
    drawArrow(p, QPointF(x, y), QPointF(xFinal,yFinal), 1);
}

float Champs::f(float x, float y)
{
    //     TODO
    //      / \
    //     / | \
    //    /  |  \
    //   /   |   \
    //  /    o    \
    // -------------
    // Calculate the Differential Equa HERE !
    //
    return rand() % 10;
}

/**
 * @brief Champs::drawArrow
 * @param p
 * @param from
 * @param to
 * @param size
 * @param blanc_dist
 */
void Champs::drawArrow(QPainter *p, QPointF from, QPointF to, int size)
{
    //draw the line
    p->drawLine(from, to);

    //draw the direction
    p->drawEllipse(to, size,size);
}
