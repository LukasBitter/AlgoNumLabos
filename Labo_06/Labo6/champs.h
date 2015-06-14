/**
    Champs - Header File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
    @date 14.06.2015
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

    double f(double x, double y);
    void drawVect(QPainter *p, float x, float y, double pas);

    double eulerMethod(double x, double y);

signals:

public slots:

};

#endif // CHAMPS_H
