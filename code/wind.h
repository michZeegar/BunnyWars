#ifndef WIND_H
#define WIND_H

#include <QGraphicsPixmapItem>
#include <QtMath>
#include <stdlib.h>
#include <QLabel>
#include <math.h>



/*!
 *  \brief     This class is used to create the Wind.
 *  \details   Wind is used to influence the Bullet's movement in air.
 *  \details   Each turn a new random Wind is created and the vane adapts to the Wind's direction.
 */
class Wind {
public:
    // constructors
    Wind(int xPos, int yPos);

    // methods
    qreal getWind();
    void newWind();

    // attributes
    QPixmap imageLeftWind;

    int imageHeight;
    int imageWidth;

    QGraphicsPixmapItem * actualWindVane;
    QGraphicsPixmapItem * windToLeft;
    QGraphicsPixmapItem * windToRight;

    QLabel * wind_label;
    QString wind_string;


protected:
    // attributes
    qreal wind;
};



#endif // WIND_H
