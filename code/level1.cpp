#include "level1.h"
#include "obstacle.h"
#include "wind.h"



Level1::Level1(QLabel * p1, QLabel * p2, Interface * face) {
    // This is the part where we define the landscape and movement of the bunnies:

    points << QPointF(0,610) << QPointF(1920,610);

    int NumberOfPoints = points.size();

    scale_factor=1;
    for(iterationValue=0; iterationValue<NumberOfPoints-1; iterationValue++) {  //checkout for the -1!!!
        points[iterationValue].setX(round(points[iterationValue].x()*scale_factor));
        points[iterationValue].setY(round(points[iterationValue].y()*scale_factor));
    }

    scene = new QGraphicsScene();
    QImage background = QImage(":/code/Images/Level1_scaled.png");
    background = background.scaledToWidth(1920);
    scene->setBackgroundBrush(background);

    // add gathered information to view
    view = new QGraphicsView(scene);
    view->setCursor(Qt::BlankCursor);
    // view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    // make view visible:
    const int width = 1920;
    const int height = 1080;
    view->setFixedSize(width, height);
    scene->setSceneRect(0, 0, width, height);

    pixmapPlayer1 = QPixmap(":/code/Images/BunnySmall.png");
    pixmapPlayer2 = QPixmap(":/code/Images/InvertedBunnySmall.png");

    pixmapPlayer1 = pixmapPlayer1.scaledToHeight(1700);
    pixmapPlayer2 = pixmapPlayer2.scaledToHeight(1700);

    Player * player1 = new Player(scene,pixmapPlayer1,view->width()/10, 610, 0,view->height()/1.2,p1,face);
    Player * player2 = new Player(scene,pixmapPlayer2,view->width()/1.25, 610 ,view->width()-210,view->height()/1.2,p2,face);

    //creation of the ground
    QPixmap groundPix= QPixmap (":/code/Images/Level1JustGround.png");
    Obstacle * ground= new Obstacle(player1, player2);
    scene->addItem(ground);
    ground->setObstaclePix(groundPix, 0, 0);
    ground->getGroundToPlayer();

    // add the item (player1) to the scene
    scene->addItem(player1);
    scene->addItem(player2);


    //creation of the obstacle

    Obstacle * obstacle1= new Obstacle(player1, player2);
    scene->addItem(obstacle1);
    obstacle1->createRandomObstacle(1);

    player1->showLabel(p1);
    player2->showLabel(p2);


    //show lifePoints
    player1->initializeLifePoints(0, view->height()/1000);
    player2->initializeLifePoints(view->width()-350, view->height()/1000);

    //start game engine
    playLevel1 = new Game(this,scene, view, player1, player2);
    scene->addItem(playLevel1);
    playLevel1->setFlag(QGraphicsItem::ItemIsFocusable);
    playLevel1->grabKeyboard();
}
