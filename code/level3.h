#ifndef LEVEL3_H
#define LEVEL3_H

#include "battlefield.h"
#include "game.h"
#include "lifepoint.h"
#include "player.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>



class Game;

/*!
 *  \brief     This class is used to create Level 3.
 *  \details   The constructor loads the correct QList points for the horizon of the landscape for Level 3.
 *  \details   Then it adds the background of Level 3 and puts the players in the wanted position.
 */
class Level3: public Battlefield {
public:
    // constructors
    Level3(QLabel * p1, QLabel * p2, Interface * face);

    // attributes
    Game * playLevel3;

    QGraphicsView * view;
    QGraphicsScene * scene;

    QPixmap pixmapPlayer1;
    QPixmap pixmapPlayer2;
};



#endif // LEVEL3_H
