#include "angle.h"

#include <QPen>
#include <QtMath>



Angle::Angle(int xPos, int yPos, qreal angle, qreal speed, QGraphicsItem * parent): QGraphicsLineItem(parent) {
    // line
    int xHead = xPos + qCos(qDegreesToRadians(angle)) * speed;
    int yHead = yPos - qSin(qDegreesToRadians(angle)) * speed;
    setLine(xPos, yPos, xHead, yHead);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(6);
    pen.setColor(Qt::red);
    setPen(pen);
}
