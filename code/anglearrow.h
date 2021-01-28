#ifndef ANGLEARROW_H
#define ANGLEARROW_H

#include <QGraphicsLineItem>



/*!
 *  \brief     This class is used to create the Arrow.
 *  \details   The Arrow helps visualizing the elevation-angle of the Bullet.
 *  \details   The Arrow's angle is a given parameter.
 *  \details   The Arrow's head (and length) is calculated with given angle and speed.
 */
class AngleArrow:  public QGraphicsLineItem {
public:
    // constructors
    AngleArrow(int xPos, int yPos, qreal angle, qreal speed, QGraphicsItem * parent = NULL);
};



#endif // ANGLEARROW_H
