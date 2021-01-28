#include "level3.h"

#include <iostream>



using namespace std;

Level3::Level3(QLabel * p1, QLabel * p2, Interface * face) {
     //This is the part where we define the landscape and movement of the bunnies

    points << QPointF(0,625) << QPointF(20, 605) << QPointF(45,565) << QPointF(70, 580)
           << QPointF(120, 575) << QPointF(125,625) << QPointF(145, 660) << QPointF(250,660)
           << QPointF(270, 625) << QPointF(320,610) << QPointF(350, 705) << QPointF(395,810)
           << QPointF(470, 810) << QPointF(480,775) << QPointF(555, 750) << QPointF(580,695)
           << QPointF(695, 760) << QPointF(995,800) << QPointF(1145, 775) << QPointF(1185, 700)
           << QPointF(1285,700) << QPointF(1320, 605) << QPointF(1370,590) << QPointF(1445, 675)
           << QPointF(1470,640) << QPointF(1570, 690) << QPointF(1675,690) << QPointF(1690, 650)
           << QPointF(1735,625) << QPointF(1755, 550) << QPointF(1820,600) << QPointF(1825, 660)
           << QPointF(1920,675);


    int NumberOfPoints = points.size();

    scale_factor=1;
    for(iterationValue=0; iterationValue<NumberOfPoints-1; iterationValue++) {  //checkout for the -1!!!
        points[iterationValue].setX(round(points[iterationValue].x()*scale_factor));
        points[iterationValue].setY(round(points[iterationValue].y()*scale_factor));
    }


   scene = new QGraphicsScene();
    QImage background = QImage(":/code/Images/Level3.png");
    background = background.scaledToWidth(1920);
    scene->setBackgroundBrush(background);

    // add gathered information to view
    view = new QGraphicsView(scene);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->setFixedSize(1920, 1080);
    scene->setSceneRect(0, 0, 1920, 1080);


    Player * player1 = new Player(scene, QPixmap(":/code/Images/BunnySmall.png"), 270, 625, 0, view->height()/1.2, p1, face);
    Player * player2 = new Player(scene, QPixmap(":/code/Images/InvertedBunnySmall.png"), 1690, 650, view->width()-210, view->height()/1.2, p2, face);

    //creation of the ground
    QPixmap groundPix= QPixmap (":/code/Images/Level3JustGround.png");
    Obstacle * ground= new Obstacle(player1, player2);
    scene->addItem(ground);
    ground->setObstaclePix(groundPix, 0, 0);
    ground->getGroundToPlayer();

    //creation of the obstacle

    Obstacle * obstacle1= new Obstacle(player1, player2);
    scene->addItem(obstacle1);
    obstacle1->createRandomObstacle(3);

    // add the item (player1) to the scene
    scene->addItem(player1);
    scene->addItem(player2);

    player1->showLabel(p1);
    player2->showLabel(p2);


    // only "focused" item of scene responds to events:
    // make rect focusable and convert into the focus item
    player1->setFlag(QGraphicsItem::ItemIsFocusable);
    player2->setFlag(QGraphicsItem::ItemIsFocusable);
    player1->setFocus();

    //show lifePoints
    player1->initializeLifePoints(0,view->height()/1000);
    player2->initializeLifePoints(view->width()-350, view->height()/1000);
    playLevel3 = new Game(this, scene, view, player1, player2);
    scene->addItem(playLevel3);
    playLevel3->setFlag(QGraphicsItem::ItemIsFocusable);
    playLevel3->grabKeyboard();
}
