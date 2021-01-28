#include "bullet.h"
#include "obstacle.h"
#include "player.h"

#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QLabel>
#include <QtMath>
#include <stdlib.h>



Obstacle::Obstacle(Player * player1, Player * player2) {
        uno = player1;
        due = player2;
        uno->setObstacle(this);
        due->setObstacle(this);

        isLavaFountain = false;
        //QPixmap lavaFountain = QPixmap(":/code/Images/Lava_fountain.png");
        //obstaclePixMap=obstaclePix;

        //setPixmap(obstaclePixMap);
        //setPos(750,0);
}

int Obstacle::getResilience() {
   return resilience;
}
void Obstacle::setObstaclePix(QPixmap obstaclePix, int xPos, int yPos) {
    obstaclePixMap = obstaclePix;
    setPixmap(obstaclePixMap);
    setPos(xPos, yPos);

}

void Obstacle::createRandomObstacle(int level) {
    srand(time(NULL));
    int randNum = (rand()%4) + 1;
    //randNum=1;
    int height=400;
    int height2=400;
    int scalObstFac=350;
    if(level==1){
         height=400;
         height2=height;
         scalObstFac=350;

    }
    else if (level==2){
        height=380;
        height2=400;
        scalObstFac=350;

    }
    else if (level==3){
        height=520;
        height2=470;
        scalObstFac=400;

    }

    switch (randNum){
        case 1: {
        QPixmap lavaFountain = QPixmap(":/code/Images/Lava_fountain.png");
        lavaFountain=lavaFountain.scaledToHeight(scalObstFac);
        setObstaclePix(lavaFountain,(scene()->width()/2)-lavaFountain.width()/2,height2);
        isLavaFountain=true;
        break;}
    case 2:{
        QPixmap stopSign = QPixmap(":/code/Images/Stop_sign.png");
        //lavaFountain=lavaFountain.scaledToHeight(350);
       setObstaclePix(stopSign,((scene()->width()/2)-(stopSign.width()/2)),height-20);
        break;}
    case 3:{
        QPixmap angryCarrot= QPixmap(":/code/Images/Angry_carrot.png");
        angryCarrot=angryCarrot.scaledToHeight(scalObstFac+100);

        if(level==3){
           setObstaclePix(angryCarrot,900,height-20);
        } else {
          setObstaclePix(angryCarrot,900,height+20);
        }
        break;}
    case 4:{
        QPixmap angryCarrot= QPixmap(":/code/Images/Big_scared_carrot.png");
        angryCarrot=angryCarrot.scaledToHeight(scalObstFac+100);

        if(level==3){
           setObstaclePix(angryCarrot,900,height-20);
        } else {
          setObstaclePix(angryCarrot,900,height+20);
        }
        break;}
    }
}

void Obstacle::getGroundToPlayer() {
    uno->setGround(this);
    due->setGround(this);
}

QPixmap Obstacle::scaleObstacle(int scaleFactor) {
    return obstaclePixMap.scaledToHeight(scaleFactor);
}

