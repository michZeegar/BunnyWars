#include "anglearrow.h"

#include <QPen>
#include <QtMath>



AngleArrow::AngleArrow(int xPos, int yPos, qreal angle, qreal speed, QGraphicsItem * parent):
QGraphicsLineItem(parent) {
    // calculates arrowhead
    int xHead = xPos + qCos(qDegreesToRadians(angle)) * speed;
    int yHead = yPos - qSin(qDegreesToRadians(angle)) * speed;

    // draws line
    setLine(xPos, yPos, xHead, yHead);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(8);
    pen.setColor(Qt::black);
    setPen(pen);
}

