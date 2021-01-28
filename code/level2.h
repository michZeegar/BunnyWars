#ifndef LEVEL2_H
#define LEVEL2_H

#include "battlefield.h"
#include "game.h"
#include "lifepoint.h"
#include "player.h"
#include "interface.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>



class Game;
class Battlefield;

/*!
 *  \brief     This class is used to create Level 2.
 *  \details   The constructor loads the correct QList points for the horizon of the landscape for Level 2.
 *  \details   Then it adds the background of Level 2 and puts the players in the wanted position.
 */
class Level2: public Battlefield {
public:
    // constructors
    Level2(QLabel * p1, QLabel * p2, Interface * face);

    // attributes
    Game * playLevel2;

    QGraphicsView * view;
    QGraphicsScene * scene;

    QPixmap pixmapPlayer1;
    QPixmap pixmapPlayer2;
};



#endif // LEVEL2_H
