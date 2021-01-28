#include "game.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"

#include <QCoreApplication>
#include <QTime>



Game::Game(Battlefield * actualLevel, QGraphicsScene * levelScene, QGraphicsView * levelView, Player * startPlayer, Player * hisCounterPlayer) {
    focusedPlayer = startPlayer;
    counterPlayer = hisCounterPlayer;
    focusedPlayer->changeColorToGreen();
    counterPlayer->changeColorToWhite();
    scene = levelScene;
    view = levelView;
    level = actualLevel;
    wind = new Wind(scene->width()/2,0);

    scene->addWidget(wind->wind_label);
    if(wind->getWind()) {
        scene->addItem(wind->actualWindVane);
    }

}

void Game::mdelay(int time) {
    QTime dieTime= QTime::currentTime().addMSecs(time);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Game::getPlayerWeapon(){
    focusedPlayer->actual_bullet = new Bullet(focusedPlayer->x(),focusedPlayer->y(),scene,this);
    focusedPlayer->actual_bullet->setEnemy(counterPlayer);
    focusedPlayer->actual_bullet->setShootingPlayer(focusedPlayer);
    focusedPlayer->actual_bullet->setObstacle(focusedPlayer->obstacle);
    focusedPlayer->actual_bullet->setGround(focusedPlayer->ground);
}

void Game::setPlayerAngle() {
    if (focusedPlayer->actual_angle != NULL)
        delete focusedPlayer->actual_angle;
    if (focusedPlayer->speed != 0) {
        focusedPlayer->actual_angle = new AngleArrow((focusedPlayer->x()+40), focusedPlayer->y(), focusedPlayer->angle, focusedPlayer->speed);
        scene->addItem(focusedPlayer->actual_angle);
    }
}


void Game::keyPressEvent(QKeyEvent * event) {
    // First lets check which key was pressed:

    if(!focusedPlayer->in_delay || focusedPlayer->weaponFlagList[1]) {
        if(event->key()== Qt::Key_Up) {

            focusedPlayer->changeAngle(1);
        }
        else if(event->key()== Qt::Key_Escape){
                    focusedPlayer->interface->backFromGame();
        }
        else if(event->key() == Qt::Key_Down) {
            focusedPlayer->changeAngle(-1);
        }
        else if(event->key() == Qt::Key_Plus) {
            focusedPlayer->changeSpeed(1);
        }
        else if(event->key() == Qt::Key_Minus) {
            focusedPlayer->changeSpeed(-1);
        }
        if(!focusedPlayer->in_delay) {
            if (event->key() == Qt::Key_Left) {
                if(focusedPlayer->movePoints > 0) {
                    level->move_left(focusedPlayer);
                    focusedPlayer->movePoints--;
                    focusedPlayer->updateAngleDisplay();
                }
            }
            else if(event->key() == Qt::Key_Right) {
                if(focusedPlayer->movePoints > 0) {
                    level->move_right(focusedPlayer);
                    focusedPlayer->movePoints--;
                    focusedPlayer->updateAngleDisplay();
                }
            }
            else if(event->key() == Qt::Key_M) {
                focusedPlayer->updateEnabledWeapon("Machinegun");
            }
            else if(event->key() == Qt::Key_H) {
                focusedPlayer->updateEnabledWeapon("Halfautomatic");
            }
            else if(event->key() == Qt::Key_S) {
                focusedPlayer->updateEnabledWeapon("Spray");
            }
            else if(event->key() == Qt::Key_G) {
                focusedPlayer->updateEnabledWeapon("Gigaspray");
            }
            else if(event->key() == Qt::Key_Space) {
                if(!focusedPlayer->actual_angle == NULL){
                    focusedPlayer->actual_angle->setVisible(false);
                }
                if(focusedPlayer->weaponFlagList[0]==true) {
                    focusedPlayer->in_delay = true;
                    counterPlayer->in_delay = true;
                    for (i=0; i<15; i++){
                        getPlayerWeapon();
                        focusedPlayer->actual_bullet->damage = focusedPlayer->actual_bullet->damage/2;
                        focusedPlayer->actual_bullet->shoot(focusedPlayer->x(), focusedPlayer->y(), focusedPlayer->angle, focusedPlayer->speed, wind->getWind());
                        //scene->addItem(focusedPlayer->actual_bullet);
                        mdelay(200);
                    }
                    focusedPlayer->weaponUsed("Machinegun");
                }
                else if(focusedPlayer->weaponFlagList[1] == true) {
                    counterPlayer->in_delay = true;
                    focusedPlayer->in_delay = true;
                    for (i=0; i<10; i++){
                        getPlayerWeapon();
                        focusedPlayer->actual_bullet->damage = focusedPlayer->actual_bullet->damage/3;
                        focusedPlayer->actual_bullet->shoot(focusedPlayer->x(), focusedPlayer->y(), focusedPlayer->angle, focusedPlayer->speed, wind->getWind());
                        //scene->addItem(focusedPlayer->actual_bullet);
                        mdelay(1000);
                    }
                    focusedPlayer->weaponUsed("Halfautomatic");
                }
                else if(focusedPlayer->weaponFlagList[2] == true) {
                    counterPlayer->in_delay = true;
                    save_angle = focusedPlayer->angle;
                    focusedPlayer->changeAngle(-15);
                    if(!focusedPlayer->actual_angle == NULL){
                        focusedPlayer->actual_angle->setVisible(false);
                    }
                    for(i=0; i<10; i++){
                        getPlayerWeapon();
                        focusedPlayer->actual_bullet->damage = focusedPlayer->actual_bullet->damage/3;
                        focusedPlayer->actual_bullet->shoot(focusedPlayer->x(), focusedPlayer->y(), focusedPlayer->angle, focusedPlayer->speed, wind->getWind());

                        //scene->addItem(focusedPlayer->actual_bullet);
                        focusedPlayer->changeAngle(3);
                        if(!focusedPlayer->actual_angle == NULL){
                            focusedPlayer->actual_angle->setVisible(false);
                        }
                        mdelay(5);
                    }
                    focusedPlayer->angle = save_angle;
                    focusedPlayer->weaponUsed("Spray");
                }
                else if(focusedPlayer->weaponFlagList[3] == true) {
                    counterPlayer->in_delay = true;
                    focusedPlayer->in_delay = true;
                    save_angle = focusedPlayer->angle;
                    save_speed = focusedPlayer->speed;
                    focusedPlayer->changeAngle(-15);
                    focusedPlayer->changeSpeed(-10);
                    if(!focusedPlayer->actual_angle == NULL){
                        focusedPlayer->actual_angle->setVisible(false);
                    }
                    for(int j=0; j<5; j++) {

                        for(i=0; i<30; i++) {
                            getPlayerWeapon();
                            focusedPlayer->actual_bullet->damage = focusedPlayer->actual_bullet->damage/3;
                            focusedPlayer->actual_bullet->shoot(focusedPlayer->x(), focusedPlayer->y(), focusedPlayer->angle, focusedPlayer->speed, wind->getWind());
                            //scene->addItem(focusedPlayer->actual_bullet);
                            focusedPlayer->changeAngle(1);
                            if(!focusedPlayer->actual_angle == NULL){
                                focusedPlayer->actual_angle->setVisible(false);
                            }
                            mdelay(1);
                        }
                        focusedPlayer->angle = save_angle;
                        focusedPlayer->changeAngle(-15);
                        focusedPlayer->changeSpeed(4);
                        if(!focusedPlayer->actual_angle == NULL){
                            focusedPlayer->actual_angle->setVisible(false);
                        }
                        mdelay(500);
                    }
                    focusedPlayer->angle = save_angle;
                    focusedPlayer->speed = save_speed;
                    focusedPlayer->weaponUsed("Gigaspray");

                }
                else {
                    getPlayerWeapon();
                    focusedPlayer->actual_bullet->shoot(focusedPlayer->x(), focusedPlayer->y(), focusedPlayer->angle, focusedPlayer->speed, wind->getWind());
                    //scene->addItem(focusedPlayer->actual_bullet);
                    counterPlayer->in_delay = true;
                }
                if(!focusedPlayer->actual_angle == NULL){
                    focusedPlayer->actual_angle->setVisible(false);
                }

                counterPlayer->in_delay = true;
                focusedPlayer->in_delay = true;

                i = 0;
                mdelay(1000);
                while(focusedPlayer->actual_bullet != NULL) {
                    if(i > 30)
                        break;
                    mdelay(200);
                    i++;
                }
                scene->removeItem(wind->actualWindVane);
                wind->newWind();
                if(wind->getWind()){
                    scene->addItem(wind->actualWindVane);
                }

                counterPlayer->recoverMovePoints(20);
                focusedPlayer->in_delay = false;
                counterPlayer->in_delay = false;



                ptrstorage = focusedPlayer;
                focusedPlayer = counterPlayer;
                counterPlayer = ptrstorage;
                focusedPlayer->changeColorToGreen();
                counterPlayer->changeColorToWhite();

                if (focusedPlayer->actual_angle != NULL){
                  focusedPlayer->actual_angle->setVisible(true);
                }
            }
        }
    }
}
