#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "player.h"
#include "soundengine.h"

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <stdlib.h>



class Player;

/*!
 *  \brief     This class is used to create the Obstacle.
 *  \details   The three Obstacles are a LavaFountain, a StopSign and a huge AngryCarrot.
 */
class Obstacle: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    // constructors
    Obstacle(Player * uno, Player * due);

    //methods
    void createObstacle();
    void createRandomObstacle(int level);
    void getGroundToPlayer();
    int getResilience();
    void setObstaclePix(QPixmap obstaclePix, int xPos, int yPos);

    // attributes
    QPixmap obstaclePixMap;

    Player * uno;
    Player * due;

    int resilience = 0.8;

    QPixmap scaleObstacle(int scaleFactor);
    bool isLavaFountain;

    //list of all obstacle
    enum eSound {
        stopSignSound = 0,
        lavaFountainSound,
        angryCarrotSound
    };
};



#endif // OBSTACLE_H
