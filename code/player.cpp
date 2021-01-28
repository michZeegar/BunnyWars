#include "player.h"
#include "bullet.h"

#include <QKeyEvent>
#include <QThread>
#include <QGraphicsScene>
#include <QDebug>
#include <QLabel>
#include <stdlib.h>
#include <QtMath>
#include "lifepoint.h"
#include <QTime>
#include <QCoreApplication>
#include <QFont>
#include<QColorDialog>
#include <QGraphicsItem>
#include "interface.h"
#include <QGraphicsPixmapItem>
#include <iostream>

using namespace std;



Player::Player(QGraphicsScene * levelScene, QPixmap Image, int xPos, int yPos, int labelX, int labelY,QLabel * name, Interface * face) {
    interface=face;
    scene = levelScene;
    setPos(xPos,yPos);
    Image =Image.scaledToWidth(Image.width()/3);
    height = Image.height();
    width = Image.width();
    setPixmap(Image);
    lifePoints = 30;
    movePoints = 150;
    angle = 90;
    speed = 0;

    arrows = QString("(")+QString(QChar(0x2191))+QString("/")+QString(QChar(0x2193))+QString("): ");
    angle_label = new QLabel();
    angle_string = QString::number(angle);
    angle_label->setText("Angle"+ arrows + angle_string);
    angle_label->setFixedSize(QSize(300,40));
    angle_label->setGeometry(QRect(labelX,labelY,0,0));
    speed_label = new QLabel();
    speed_string = QString::number(speed);
    speed_label->setText("Speed(+/-): "+ speed_string);
    speed_label->setFixedSize(QSize(300,40));
    speed_label->setGeometry(QRect(labelX,labelY+60,0,0));
    name_label=new QLabel();
    name_label=name;
    name_label->setGeometry(QRect(labelX,labelY-60,300,40));
    //name_label->setFixedSize(QSize(300,20));

    speed_label->setAttribute(Qt::WA_TranslucentBackground);
    angle_label->setAttribute(Qt::WA_TranslucentBackground);
    name_label->setAttribute(Qt::WA_TranslucentBackground);


    QFont f("Calibri", 16, QFont::Bold);
    QColor color = QColor(Qt::white);
    QPalette palette =name_label->palette();
    palette.setColor(QPalette::WindowText, color);
    name_label->setPalette(palette);
    speed_label->setPalette(palette);
    angle_label->setPalette(palette);

    speed_label->setFont(f);
    angle_label->setFont(f);
    name_label->setFont(f);
   // name_label->setStyleSheet("{color:white}");
   // name_label->setText("<font color='White'></font>");

    in_delay = false;

    actual_angle = NULL;

    weaponFlagList = {
        machinegun_startstate = false,
        half_automatic_startstate = false,
        spray_startstate = false,
        gigaspray_startstate = false
    };

    weaponAmmunitionList = {
        machinegun_startammunition = 5,
        halfautomatic_startammunition = 3,
        spray_startammunition = 5,
        gigaspray_startammuntion = 1
    };


    if(labelX < 200 ){
        weapon_labels = new WeaponLabels(scene,labelX+200,labelY,weaponFlagList,weaponAmmunitionList);
    }
    else {
        weapon_labels = new WeaponLabels(scene,labelX-400,labelY,weaponFlagList,weaponAmmunitionList);
    }


    /*
    weaponFlagMap["machinegun"] = false;
    weaponFlagMap["half_automatic"] = false;
    weaponFlagMap["spray"] = false;
    weaponFlagMap["giga_spray"] = false;
*/
    QPixmap frame = QPixmap(":/code/Images/SquareFrame.png").scaledToHeight(100);
    label_frame = new QGraphicsPixmapItem(frame);
    label_frame->setZValue(11);
}

void Player::updateEnabledWeapon(QString weapon) {
    int k;
    if(weapon == "Machinegun")          {k=0;}
    else if(weapon == "Halfautomatic")  {k=1;}
    else if(weapon == "Spray")          {k=2;}
    else if(weapon == "Gigaspray")      {k=3;}

    if(weaponAmmunitionList[k]) {
        if(weaponFlagList[k] == true) {
            weaponFlagList[k] =false;
        }
        else {
            clearWeaponFlagList();
            weaponFlagList[k] = true;
        }
        updateWeaponFrame();
    }
}

void Player::weaponUsed(QString weapon){
    int k;
    if(weapon == "Machinegun")          {k=0;}
    else if(weapon == "Halfautomatic")  {k=1;}
    else if(weapon == "Spray")          {k=2;}
    else if(weapon == "Gigaspray")      {k=3;}

    if(!weaponFlagList.isEmpty()){
        weaponFlagList[k] = false;
    }
    else{
        return;
    }
    if(!weaponAmmunitionList.isEmpty()){
        weaponAmmunitionList[k]--;
    }
    else{
        return;
    }
    if(!weaponAmmunitionList[k]) {
        weapon_labels->showB_WSquare(k);
    }
    if(k<weapon_labels->ammunitionLabelList.size() && k<weaponAmmunitionList.size()) {
        weapon_labels->ammunitionLabelList[k]->setText(QString::number(weaponAmmunitionList[k]));
    }
    updateWeaponFrame();
}

void Player::updateWeaponFrame(){
   int j;
   QList<QGraphicsItem*> itemsInScene = scene->items();

    for(j=0; j<weaponFlagList.size() && j<weapon_labels->labelList.size(); j++){
        if(weaponFlagList[j]==true) {
           label_frame->setPos(weapon_labels->labelList[j]->x(), weapon_labels->labelList[j]->y());
           if(!itemsInScene.contains(label_frame)) {
               scene->addItem(label_frame);
           }
        }
        else if(j==(weapon_labels->labelList.size()-1) && itemsInScene.contains(label_frame)){
            scene->removeItem(label_frame);
        }
    }
}


void Player::recoverMovePoints(int recovery) {
    movePoints += recovery;
}

void Player::showLabel(QLabel * player) {
    scene->addWidget(angle_label);
    scene->addWidget(speed_label);
    scene->addWidget(name_label);
    angle_label->setCursor(Qt::BlankCursor);
    speed_label->setCursor(Qt::BlankCursor);
    name_label->setCursor(Qt::BlankCursor);
    for(int i=0; i<weapon_labels->ammunitionLabelList.size(); i++) {
        scene->addWidget(weapon_labels->ammunitionLabelList[i]);
        weapon_labels->ammunitionLabelList[i]->setCursor(Qt::BlankCursor);
    }
}

void Player::die(){
   // interface->backclicked();
    weaponFlagList.clear();
    weaponAmmunitionList.clear();
    delete this;
}
void Player::changeColorToGreen(){

    QFont f("Calibri", 16, QFont::Bold);
    QColor color = QColor(Qt::darkGreen);
    QPalette palette =name_label->palette();
    palette.setColor(QPalette::WindowText, color);
    name_label->setPalette(palette);
    speed_label->setPalette(palette);
    angle_label->setPalette(palette);


}
void Player::changeColorToWhite(){
    QFont f("Calibri", 16, QFont::Bold);
    QColor color = QColor(Qt::white);
    QPalette palette =name_label->palette();
    palette.setColor(QPalette::WindowText, color);
    name_label->setPalette(palette);
    speed_label->setPalette(palette);
    angle_label->setPalette(palette);


}
void Player::initializeLifePoints(int xPos, int yPos){

    lifepoint * newlifepoint = new lifepoint;
    newlifepoint->setPos(xPos, yPos);
    scene->addItem(newlifepoint);
    lifePointsList.append(newlifepoint);

    for(int i=1; i<lifePoints; i++){

        newlifepoint = new lifepoint;
        newlifepoint->setPos(lifePointsList[0]->x()+(i%10)*30, lifePointsList[0]->y()+(i/10)*40);
        scene->addItem(newlifepoint);
        lifePointsList.append(newlifepoint);
    }
}

void Player::decreaseLifePoints(int damage){
    for(int i=0; i<damage; i++) {
        if(lifePoints>0 && !(lifePointsList.isEmpty())) {
            delete lifePointsList.takeLast();
            lifePoints -= 1;
        }
    }
}


void Player::insertPoints(int points){
   // interface->score->insertHighsore(name_label->text(),points);
}


void Player::setCounterPlayer(Player * pointerPlayer) {
    counterPlayer=pointerPlayer;
}

void Player::setObstacle(Obstacle * obstacleloc) {
    obstacle = obstacleloc;
}

void Player::setGround(Obstacle * obstacleloc) {
    ground = obstacleloc;
}

void Player::clearWeaponFlagList() {
    for(int i=0; i<weaponFlagList.size(); i++) {
        weaponFlagList.replace(i, false);
    }
}

void Player::changeAngle(int delta) {
    if(delta == 0) {
        return;
    }
    if(delta < 0) {
        for(int i=0; i>delta; i--) {
            if(angle > 0){
                angle--;
            }
        }
    }
    else if(delta > 0) {
        for(int i=0; i<delta; i++) {
            if(angle < 180) {
                angle++;
            }
        }
    }
    updateAngleDisplay();
}

void Player::changeSpeed(int delta) {
    if(delta < 0) {
        for(int i=0; i>delta; i--) {
            if(speed > 0) {
                speed--;
            }
        }
    }
    else if(delta > 0) {
        for(int i=0; i<delta; i++) {
            if(speed < 100) {
                speed++;
            }
        }
    }
    updateSpeedDisplay();
}

void Player::updateAngleDisplay() {
    angle_string = QString::number(angle);
    angle_label->setText("Angle"+ arrows + angle_string);
    if(actual_angle != NULL) {
        delete actual_angle;
    }
    if(speed){
        actual_angle = new AngleArrow(x()+40, y(), angle, speed);
        scene->addItem(actual_angle);
    }
}

void Player::updateSpeedDisplay() {
    speed_string = QString::number(speed);
    speed_label->setText("Speed(+/-): " + speed_string);
    if(actual_angle != NULL) {
        delete actual_angle;
    }
    if(speed) {
        actual_angle = new AngleArrow(x()+40, y(), angle, speed);
        scene->addItem(actual_angle);
    }
}
