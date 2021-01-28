#include "battlefield.h"
#include "bullet.h"
#include "lifepoint.h"
#include "player.h"

#include <stdlib.h>
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QLabel>
#include <QtMath>



Battlefield::Battlefield() {

}

void Battlefield::getdistToLeftPoint(Player * player) {

    currentXcoordinate = player->x();
    currentYcoordinate = player->y();

    // If between 0 & 1, i = 0, if between 1 & 2, i = 1...
    iterationValue = 0;
    while (points[iterationValue].x() < currentXcoordinate) {
        iterationValue++;
    }
    iterationValue--;

    deltaX = currentXcoordinate - points[iterationValue].x();
    deltaY = currentYcoordinate - points[iterationValue].y();

    dy_dx = deltaY/deltaX;
    steepnessAngle = qAtan(dy_dx);
    distToPoint = qSqrt((deltaX*deltaX)+(deltaY*deltaY));
}

void Battlefield::getdistToRightPoint(Player * player) {

    currentXcoordinate = player->x();
    currentYcoordinate = player->y();

    // If between 0 & 1, i = 1, if between 1 & 2, i = 2...
    iterationValue = 0;
    while (points[iterationValue].x() <= currentXcoordinate) {
        iterationValue++;
    }

    deltaX = points[iterationValue].x() - currentXcoordinate;
    deltaY = points[iterationValue].y() - currentYcoordinate;

    dy_dx = deltaY/deltaX;
    steepnessAngle = qAtan(dy_dx);
    distToPoint = qSqrt((deltaX*deltaX)+(deltaY*deltaY));
}

void Battlefield::move_left(Player * player) {
    if(player->x() >= 2 && (player->x() < player->obstacle->x() || player->x() >player->obstacle->x()+400 )) {
        getdistToLeftPoint(player);
        if (distToPoint >= 1) {
            newXcoordinate = currentXcoordinate - qCos(steepnessAngle);
            newYcoordinate = currentYcoordinate - qSin(steepnessAngle);
        }
        else {
            int distToNewCoordinate = 1 - distToPoint;
            player -> setPos(points[iterationValue].x(), points[iterationValue].y());
            if(iterationValue != 0) {
                getdistToLeftPoint(player);
                if (distToNewCoordinate < distToPoint) {
                    newXcoordinate = currentXcoordinate - distToNewCoordinate*qCos(steepnessAngle);
                    newYcoordinate = currentYcoordinate - distToNewCoordinate*qSin(steepnessAngle);
                }
            }
        }
        player->setPos(newXcoordinate, newYcoordinate);
    }
}

void Battlefield::move_right(Player * player) {
    if(player->x() <= 1918 && (player->x()+100 < player->obstacle->x() || player->x() >player->obstacle->x() )) {
        getdistToRightPoint(player);
        if (distToPoint >= 1) {
            newXcoordinate = currentXcoordinate + qCos(steepnessAngle);
            newYcoordinate = currentYcoordinate + qSin(steepnessAngle);
        }
        else {
            int distToNewCoordinate = 1 - distToPoint;
            player -> setPos(points[iterationValue].x(), points[iterationValue].y());
            if(iterationValue != 0) {
                getdistToRightPoint(player);
                if (distToNewCoordinate < distToPoint) {
                    newXcoordinate = currentXcoordinate + distToNewCoordinate*qCos(steepnessAngle);
                    newYcoordinate = currentYcoordinate + distToNewCoordinate*qSin(steepnessAngle);
                }
            }
        }
        player->setPos(newXcoordinate, newYcoordinate);
    }
}
