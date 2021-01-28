#ifndef PLAYER_H
#define PLAYER_H

#include "anglearrow.h"
//#include "bullet.h"
#include "interface.h"
#include "lifepoint.h"
#include "obstacle.h"
#include "player.h"
#include "weaponlabels.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QLabel>
#include <QMap>
#include <QThread>
#include <QtMath>
#include <stdlib.h>



class Bullet;
class Obstacle;
class Interface;

/*!
 *  \brief     This class is used to create the Players.
 *  \details   As this is propably the most difficult class further information is given on each function.
 */
class Player: public QGraphicsPixmapItem {
public:
    //! Player constructor.
    /*!
      \param levelScene to know in which scene the Player is placed.
      \param Image      to make the player visible.
      \param xPos       to determine the x starting position in the scene.
      \param yPos       to determine the y starting position in the scene.
      \param labelX     to place the Player's Angle-Label. The Speed-Label's position has the same x-coordinate.
      \param labelY     to place the Player's Angle-Label. The Speed-Label's position adds the Angle-Label's height.
      \param name       to adjust the Player's name to the one he gave himself in the Interface's sub-menu before starting.
      \param interface  to be able to change highscores.
    */
    Player(QGraphicsScene * levelScene, QPixmap Image, int xPos, int yPos, int labelX, int labelY, QLabel * name, Interface * interface);

    // methods
    void changeAngle(int delta);
    void changeSpeed(int delta);
    void clearWeaponFlagList();
    void decreaseLifePoints(int damage);
    void die();
    void initializeLifePoints(int xPos, int yPos);
    void insertPoints(int points);
    void recoverMovePoints(int recovery);
    void setCounterPlayer(Player * pointerPlayer);
    void setGround(Obstacle * obstaceloc);
    void setObstacle(Obstacle * obstacleloc);
    void showLabel(QLabel *player);
    void showLifePoints(int currentLifePoints, int xPos, int yPos);
    void updateAngleDisplay();
    void updateEnabledWeapon(QString weapon);
    void updateSpeedDisplay();
    void updateWeaponFrame();
    void weaponUsed(QString weapon);
    void changeColorToGreen();
    void changeColorToWhite();
    // attributes
    AngleArrow * actual_angle = NULL;

    Bullet * actual_bullet;

    Interface * interface;

    Obstacle * ground;
    Obstacle * obstacle;

    Player * counterPlayer;

    QGraphicsPixmapItem * label_frame;

    QGraphicsScene * scene;

    QLabel * angle_label;
    QLabel * name_label;
    QLabel * speed_label;

    QList<bool> weaponFlagList;
    QList<int> weaponAmmunitionList;
    QList<QGraphicsPixmapItem*> lifePointsList;

    QMap<QString, bool> weaponFlagMap;

    QString angle_string;
    QString arrows;
    QString speed_string;

    WeaponLabels * weapon_labels;


    bool giga_spray = false;
    bool gigaspray_startstate;
    bool half_automatic = false;
    bool half_automatic_startstate;
    bool machinegun = false;
    bool machinegun_startstate;
    bool machinegun_used = false;
    bool spray = false;
    bool spray_startstate;

    bool shotfired;

    bool in_delay;

    int width;
    int height;

    int lifePoints;
    int movePoints;

    int gigaspray_startammuntion;
    int halfautomatic_startammunition;
    int machinegun_startammunition;
    int spray_startammunition;


    qreal angle;
    qreal speed;
};

class Sleeper: public QThread {
public:
    static void usleep(unsigned long usecs) {
        QThread::usleep(usecs);
    }
    static void msleep(unsigned long msecs) {
        QThread::msleep(msecs);
    }
    static void sleep(unsigned long secs) {
        QThread::sleep(secs);
    }
};



#endif
