#ifndef INTERFACE_H
#define INTERFACE_H

#include "button.h"
#include "highscore.h"

#include <QDebug>
#include <QFocusEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QLineEdit>
#include <QObject>
#include <QPushButton>
#include <QVBoxLayout>

class Bullet;

/*!
 *  \brief     This class is used to create and change the menu.
 *  \details   The Interface has a main-menu and several sub-menus:
 *  \details   With 'play' you can enter your names and choose the level to start with.
 *  \details   In 'Highscore' you can checkout the current ranking.
 *  \details   In 'Settings' you can change some settings.
 *  \details   With 'Exit' you - for some unknown reason - decide to quit the game.
 *  \warning   Pressing play might cause your social life to change drastically due to the fact of immediat addiction.
 */
class Interface: public QObject {
    Q_OBJECT
public:
    // constructors
    Interface();

    // methods
    void closeView();

    // attributes
    QGraphicsScene * scene;
    QGraphicsView * view;
    Highscore * score;
    QGraphicsProxyWidget * wid;
    void backFromGame();
public slots:
    void playclicked();
    void backclicked();
    void level1clicked();
    void level2clicked();
    void level3clicked();
    void highscoreclicked();
    void settingsclicked();
    void exitclicked();


private:
    // attributes
    bool level;

    QWidget * widget;
    QVBoxLayout * lay;

    QLineEdit * player1;
    QLineEdit * player2;

    QLabel * labelVS;

    Button * btn_play;
    Button * btn_highscore;
    Button * btn_exit;
    Button * btn_l1;
    Button * btn_l2;
    Button * btn_l3;
    Button * btn_back;
};



#endif // INTERFACE_H
