#ifndef GAME_H
#define GAME_H

#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "player.h"
#include "wind.h"
#include "bullet.h"

#include <QGraphicsScene>
#include <QKeyEvent>
#include <QObject>

class Bullet;
class Battlefield;


/*!
 *  \brief     The name of this class should answer its purpose.
 *  \details   The Game class contains all important information to handle the turn-based play.
 *  \details   It is also used to create the scene and view in which menu and levels are loaded.
 */
class Game: public QObject, public QGraphicsPixmapItem {
public:
    // constructors
    Game(Battlefield * actualLevel, QGraphicsScene * levelScene, QGraphicsView * levelView, Player * startPlayer, Player * hisCounterPlayer);

    // attributes
    Battlefield * level;

protected:
    // events
    void keyPressEvent(QKeyEvent * event);

    // methods
    void mdelay(int time);
    void getPlayerWeapon();
    void setPlayerAngle();

    // attributes
    QGraphicsScene * scene;
    QGraphicsView * view;

    Player * focusedPlayer;
    Player * counterPlayer;
    Player * ptrstorage;

    Wind * wind;

    int i;

    qreal save_angle;
    qreal save_speed;

    //QMap<*Bullet,*Bullet> bullets;

};



#endif // GAME_H
