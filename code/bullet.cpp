#include "bullet.h"

#include <iostream>
#include <QTimer>
#include <QtMath>


Bullet::Bullet(int xPos, int yPos,QGraphicsScene * levelScene, Game* levelGame) {
    QPixmap carrot = QPixmap(":/code/Images/carrot.png");
    carrot = carrot.scaledToWidth(carrot.width()/3);
    setPixmap(carrot);
    setPos(xPos, yPos);

    damage = 1;

    soundEnginePointer = new SoundEngine();
    connect(this, SIGNAL(soundPlay(int)), soundEnginePointer, SLOT(playSound(int)));

    NumberOfBulletMoves = 0;
    hitObstacle = 0;
    numberOfGroundHits = 0;
    hitGround = false;

    x_speed = 0;
    y_speed = 0;
    scene = levelScene;
    game = levelGame;
}

void Bullet::setEnemy(Player * player) {
    enemyPlayer = player;
}

void Bullet::setObstacle(Obstacle * obstacle) {
    obstacleloc = obstacle;
}

void Bullet::setGround(Obstacle * ground) {
     groundloc = ground;
}

void Bullet::setShootingPlayer(Player * player) {
    shootingPlayer = player;
}


void Bullet::advance(int phase) {
    doCollision();
}

void Bullet::doCollision() {
    //check if there is a collision --> yes, the colliding element would be saved in the collide List
    collideList = scene->collidingItems(this);
    if(!(collideList.isEmpty())) {
        if(collideList[0]==enemyPlayer || collideList[0]==shootingPlayer) {    // current Player can hurt himself
            this->hitEnemy(static_cast<Player*>(collideList.at(0)));
        }
        else if(collideList[0]==obstacleloc && hitObstacle==0) {
            collisionObstacle();
            collideList.removeAll(obstacleloc);
        }
        else if(collideList.contains(groundloc)) {
            collisionGround();
        }
    }
}

void Bullet::shoot(qreal x, qreal y, qreal angle, qreal speed, qreal actual_wind) {
    x_speed = 0.3 * qCos(qDegreesToRadians(angle)) * speed;
    y_speed = -0.3 * qSin(qDegreesToRadians(angle)) * speed;
    wind = actual_wind;
    setPos(x, y);
    playShotSound();

    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    timer->start(50);
}

void Bullet::hitEnemy(Player * hitPlayer) {
    actual_damage = sqrt(x_speed*x_speed+y_speed*y_speed) * 0.4 * damage;
    hitPlayer->decreaseLifePoints((int)actual_damage);
    if(hitPlayer->lifePoints <= 0) {
        //enemyPlayer->interface->backclicked();
        enemyPlayer->insertPoints(enemyPlayer->lifePoints+200);
        hitPlayer->interface->backFromGame();

        hitPlayer->die();
    }
    shootingPlayer->actual_bullet = NULL;
    delete this;
}

void Bullet::collisionObstacle() {
    hitObstacle = 1;
    if(hitObstacle == 1) {
        x_speed = -0.8 * x_speed;
        y_speed = y_speed;
    }
    enemyPlayer=shootingPlayer;
}

void Bullet::collisionGround() {
    hitGround = true;
    numberOfGroundHits++;
    if(hitGround == true) {
        x_speed = 0.8*x_speed;
        y_speed = -0.8*y_speed;
    }
    if(numberOfGroundHits > 1) {
        shootingPlayer->actual_bullet = NULL;
        delete this;
    }
    else if(damage < 1) {
        shootingPlayer->actual_bullet = NULL;
        bullet_gone = true;
        delete this;
    }
}

void Bullet::move() {
    //if ground fails:
    if(NumberOfBulletMoves>1){
        scene->addItem(this);
    }

    if (!bullet_gone) {
        if(y() > 2000) {
            shootingPlayer->actual_bullet = NULL;
            delete this;
            return;
        }
    }
    if (bullet_gone) {
        return;
    }
    setPos(x()+x_speed, y()+y_speed);
    //Gravity:
    y_speed += 0.2;
    x_speed += wind/900;

    NumberOfBulletMoves++;

    if(NumberOfBulletMoves > 20) {
        advance(0);
    }
}

void Bullet::playShotSound() {
    emit soundPlay(SoundEngine::shotSound);
}
