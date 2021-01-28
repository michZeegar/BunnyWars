#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H


#include "lifepoint.h"
#include "player.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QLabel>
#include <QtMath>
#include <stdlib.h>


class Bullet;
class Player;

/*!
 *  \brief     This class is used to create the Battlefield.
 *  \details   The Battlefield is parent of each Level.
 *  \details   The Battlefield's QList points contains horizon of the landscape.
 *  \details   The Battlefield' move-functions move the players along the horizon.
 */
class Battlefield : public QGraphicsPixmapItem {
public:
    // constructors
    Battlefield();
    Battlefield(int Background_Width, int Background_Height);

    // methods
    void getdistToLeftPoint(Player * player);
    void getdistToRightPoint(Player * player);

    void move_left(Player * player);
    void move_right(Player * player);

protected:
    // attributes
    QList<QPointF> points;

    float currentXcoordinate;
    float currentYcoordinate;
    float deltaX;
    float deltaY;
    float distToPoint;
    float dy_dx;
    float newXcoordinate;
    float newYcoordinate;
    float steepnessAngle;
    float steepnessAngleInRadians;

    int iterationValue;

    qreal scale_factor;
};


#endif // BATTLEFIELD_H
