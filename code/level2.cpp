#include "level2.h"
#include "player.h"

#include <iostream>



Level2::Level2(QLabel * p1, QLabel * p2, Interface * face) {

     //This is the part where we define the landscape and movement of the bunnies

    points << QPointF(0,680) << QPointF(100, 680) << QPointF(250,525) << QPointF(350, 525)
           << QPointF(525, 625) << QPointF(600,650) << QPointF(650, 680) << QPointF(875,680)
           << QPointF(1000, 650) << QPointF(1125,680) << QPointF(1425, 650) << QPointF(1600,575)
           << QPointF(1700, 575) << QPointF(1800,475) << QPointF(1920, 475);


    int NumberOfPoints = points.size();

    scale_factor=1;
    for(iterationValue=0; iterationValue<NumberOfPoints-1; iterationValue++) {  //checkout for the -1!!!
        points[iterationValue].setX(round(points[iterationValue].x()*scale_factor));
        points[iterationValue].setY(round(points[iterationValue].y()*scale_factor));
    }


    scene = new QGraphicsScene();
    QImage background = QImage(":/code/Images/Level2.png");

    background = background.scaledToWidth(1920);
    scene->setBackgroundBrush(background);

    // add gathered information to view
    view = new QGraphicsView(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // make view visible:
    view->setFixedSize(1920, 1080);
    scene->setSceneRect(0, 0, 1920, 1080);


    Player * player1 = new Player(scene, QPixmap(":/code/Images/BunnySmall.png"), 250, 525, 0, view->height()/1.2, p1,face);
    Player * player2 = new Player(scene, QPixmap(":/code/Images/InvertedBunnySmall.png"), 1600, 575, view->width()-210, view->height()/1.2, p2, face);

    //creation of the ground
    QPixmap groundPix= QPixmap(":/code/Images/Level2JustGround.png");
    Obstacle * ground= new Obstacle(player1, player2);
    scene->addItem(ground);
    ground->setObstaclePix(groundPix, 0, 0);
    ground->getGroundToPlayer();

    //creation of the obstacle

    Obstacle * obstacle1= new Obstacle(player1, player2);
    scene->addItem(obstacle1);
    obstacle1->createRandomObstacle(2);


    // add the item (player1) to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    player1->showLabel(p1);
    player2->showLabel(p2);



    //show lifePoints
    player1->initializeLifePoints(0, view->height()/1000);
    player2->initializeLifePoints(view->width()-350, view->height()/1000);
    playLevel2 = new Game(this, scene, view, player1, player2);
    scene->addItem(playLevel2);
    playLevel2->setFlag(QGraphicsItem::ItemIsFocusable);
    playLevel2->grabKeyboard();
}
