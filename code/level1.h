#ifndef LEVEL1_H
#define LEVEL1_H

#include "battlefield.h"
#include "game.h"
#include "lifepoint.h"
#include "player.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>



class Game;
class Interface;
class Battlefield;

/*!
 *  \brief     This class is used to create Level 1.
 *  \details   The constructor loads the correct QList points for the horizon of the landscape for Level 1.
 *  \details   Then it adds the background of Level 1 and puts the players in the wanted position.
 */
class Level1: public Battlefield {
    public:
        // constructors
        Level1(QLabel * p1, QLabel * p2, Interface * interface);

        // attributes
        Game * playLevel1;

        QGraphicsView * view;
        QGraphicsScene * scene;

        QPixmap pixmapPlayer1;
        QPixmap pixmapPlayer2;
};



#endif // LEVEL1_H
