/**
    Graph - Header File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 03.05.2015
*/

#ifndef CHAMPS_H
#define CHAMPS_H
#include <QWidget>

#include <QList>
#include <QPoint>
#include <QGraphicsItem>

class Champs : public QWidget
{
    Q_OBJECT
public:
    explicit Champs(QWidget *parent = 0);
    ~Champs();

private:
    void paintEvent(QPaintEvent *event);
    void draw(QPainter &painter);
    void drawArrow(QPainter *p, QPointF from, QPointF to, int size);

    float f(float x, float y);
    void drawVect(QPainter *p, float x, float y, double pas);

signals:

public slots:

};

#endif // CHAMPS_H
