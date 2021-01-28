#ifndef ANGLE_H
#define ANGLE_H

#include <QGraphicsLineItem>



class Angle: public QObject, public QGraphicsLineItem {
    Q_OBJECT
public:
    // constructors
    Angle(int xPos, int yPos, qreal angle, qreal speed, QGraphicsItem * parent = NULL);
};



#endif // ANGLE_H
