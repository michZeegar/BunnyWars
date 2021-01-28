#ifndef BULLET_H
#define BULLET_H

#include "obstacle.h"
#include "player.h"
#include "soundengine.h"
#include "game.h"

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QObject>
#include <QPainter>
#include <QStyleOptionGraphicsItem>



class Bullet;
class Obstacle;
class Player;

/*!
 *  \brief     This class is used to create and work with the Bullet.
 *  \details   The Bullet represents one projectile of a fired shot.
 *  \details   The Bullet's starting position is given by the player's position.
 *  \details   The Bullet class also keeps track of collisions.
 */
class Bullet: public QObject, public QGraphicsPixmapItem {
    Q_OBJECT
public:
    // constructors
    Bullet(int xPos, int yPos,QGraphicsScene * levelScene, Game* levelGame);

    // methods
    void advance(int phase) override;
    void collisionGround();
    void collisionObstacle();
    void doCollision();
    void hitEnemy(Player * hitPlayer);
    void playShotSound();
    void setEnemy(Player * player);
    void setGround(Obstacle * ground);
    void setObstacle(Obstacle * obstacle);
    void setShootingPlayer(Player * player);
    void shoot(qreal x_pos, qreal y_pos, qreal angle, qreal speed, qreal wind);

    // attributes
    Obstacle * obstacleloc;
    Obstacle * groundloc;

    Player * enemyPlayer;
    Player * shootingPlayer;

    QPixmap carrot;

    bool hitGround;

    int hitObstacle;
    int numberOfGroundHits;

    qreal x_speed;
    qreal y_speed;

    qreal x_pos;
    qreal y_pos;

    qreal wind;

    qreal damage;

    int groundHeight;

    double actual_damage;

    QGraphicsScene* scene;

    Game* game;


signals:
    // Signal that a sound effect occurs
    void soundPlay(int);

public slots:
    void move();

private:
    // attributes
    SoundEngine * soundEnginePointer;

    int NumberOfBulletMoves;
    bool bullet_gone;
    QList<QGraphicsItem*> collideList;
};



#endif // BULLET_H
