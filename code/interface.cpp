#include "button.h"
#include "interface.h"
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "lifepoint.h"
#include "mainwindow.h"
#include "player.h"

#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QGraphicsScene>
#include <QGraphicsView>



Interface::Interface()
{
    level=false;
    QPixmap backgroundImg(":/code/Images/Interface.png");
    backgroundImg = backgroundImg.scaled(1920,1080,Qt::KeepAspectRatioByExpanding);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgroundImg);
    scene = new QGraphicsScene();
    scene->setBackgroundBrush(backgroundImg);
    QWidget * widget = new QWidget();
    QVBoxLayout *lay = new QVBoxLayout(widget);

    btn_play = new Button(400, 100, QString("Play"));
    btn_highscore=new Button(400, 100, QString("Highscore"));
    btn_exit  =new Button(400, 100, QString("Exit"));
    btn_l1=new Button(400, 100, QString("Level 1"));
    btn_l2=new Button(400, 100, QString("Level 2"));
    btn_l3=new Button(400, 100, QString("Level 3"));
    btn_back=new Button(400, 100, QString("Back"));
    player1=new QLineEdit();
    player2=new QLineEdit();

    lay->setAlignment(Qt::AlignBottom);

    QObject::connect(btn_play, SIGNAL(clicked()), this, SLOT(playclicked()));
    QObject::connect(btn_highscore, SIGNAL(clicked()), this, SLOT(highscoreclicked()));
    QObject::connect(btn_exit, SIGNAL(clicked()), this, SLOT(exitclicked()));
    QObject::connect(btn_l1, SIGNAL(clicked()), this, SLOT(level1clicked()));
    QObject::connect(btn_l2, SIGNAL(clicked()), this, SLOT(level2clicked()));
    QObject::connect(btn_l3, SIGNAL(clicked()), this, SLOT(level3clicked()));
    QObject::connect(btn_back, SIGNAL(clicked()), this, SLOT(backclicked()));


    btn_play->setPos(1500/2, 500);
    btn_highscore->setPos(1500/2, 610);
    btn_exit->setPos(1500/2, 720);
    btn_back->setPos(1500/2, 830);
    btn_l1->setPos(1500/2, 500);
    btn_l2->setPos(1500/2, 610);
    btn_l3->setPos(1500/2, 720);

    scene->addItem(btn_play);
    scene->addItem(btn_highscore);
    scene->addItem(btn_exit);

    view= new QGraphicsView(scene);
    view->setFixedSize(1920,1080);
    scene->setSceneRect(0,0,1920,1080);




    view->show();
}



void Interface::playclicked() {

    scene->clear();

    btn_l1=new Button(400, 100, QString("Level 1"));
    btn_l2=new Button(400, 100, QString("Level 2"));
    btn_l3=new Button(400, 100, QString("Level 3"));
    btn_back=new Button(400, 100, QString("Back"));
    player1=new QLineEdit();
    player2=new QLineEdit();

    QLabel * label= new QLabel("VS");
    label->setStyleSheet("background-color: tgba(0,0,0,0,0%)");
    label->setText("<font color='White'>VS</font>");
    QFont font = label->font();
    font.setPointSize(20);
    font.setBold(true);
    label->setFont(font);
    font.setBold(false);
    font.setPointSize(14);
    player1->setFont(font);
    player2->setFont(font);
    player1->setText("Player 1");
    player2->setText("Player 2");
    label->setAttribute(Qt::WA_TranslucentBackground);
    //lay->setAlignment(Qt::AlignBottom);

    QGraphicsTextItem *text = new QGraphicsTextItem("Data");

     int y_offset=110;
     int x_offset=0;
    btn_back->setPos(1500/2+x_offset, 830+y_offset);
    btn_l1->setPos(1500/2+x_offset, 500+y_offset);
    btn_l2->setPos(1500/2+x_offset, 610+y_offset);
    btn_l3->setPos(1500/2+x_offset, 720+y_offset);
    player1->setGeometry(QRect(550, 500, 300,100));
    player2->setGeometry(QRect(1000, 500, 300,100));
    label->setGeometry(QRect(900, 500, 200,100));
    QObject::connect(btn_l1, SIGNAL(clicked()), this, SLOT(level1clicked()));
    QObject::connect(btn_l2, SIGNAL(clicked()), this, SLOT(level2clicked()));
    QObject::connect(btn_l3, SIGNAL(clicked()), this, SLOT(level3clicked()));
    QObject::connect(btn_back, SIGNAL(clicked()), this, SLOT(backclicked()));

    scene->addItem(btn_l1);
    scene->addItem(btn_l2);
    scene->addItem(btn_l3);
    scene->addItem(btn_back);
    scene->addItem(text);
    scene->addWidget(player1);
    scene->addWidget(player2);
    scene->addWidget(label);
    qDebug() << "play clicked";

}

void Interface::level1clicked() {
    level=true;
    QLabel *p1=new QLabel(player1->text());
    QLabel *p2=new QLabel(player2->text());

    scene->clear();
    Level1* level = new Level1(p1,p2,this);
    scene=level->scene;
    view->setScene(scene);

}

void Interface::level2clicked(){
    // Level 2
    QLabel *p1=new QLabel(player1->text());
    QLabel *p2=new QLabel(player2->text());
    scene->clear();
    Level2* level = new Level2(p1,p2,this);
    scene=level->scene;
    view->setScene(scene);

}


void Interface::level3clicked() {

    QLabel *p1=new QLabel(player1->text());
    QLabel *p2=new QLabel(player2->text());
    scene->clear();

    Level3* level = new Level3(p1,p2,this);
    scene=level->scene;
    view->setScene(scene);
}
void Interface::backFromGame(){
    view->close();
    scene = new QGraphicsScene();
    QPixmap backgroundImg(":/code/Images/Interface.png");
    backgroundImg = backgroundImg.scaled(1920,1080,Qt::KeepAspectRatioByExpanding);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgroundImg);
    scene->setBackgroundBrush(backgroundImg);
    QWidget * widget = new QWidget();
    QVBoxLayout *lay = new QVBoxLayout(widget);

    btn_play = new Button(400, 100, QString("Play"));
    btn_highscore=new Button(400, 100, QString("Highscore"));
    btn_exit  =new Button(400, 100, QString("Exit"));
    btn_l1=new Button(400, 100, QString("Level 1"));
    btn_l2=new Button(400, 100, QString("Level 2"));
    btn_l3=new Button(400, 100, QString("Level 3"));
    btn_back=new Button(400, 100, QString("Back"));
    player1=new QLineEdit();
    player2=new QLineEdit();


    lay->setAlignment(Qt::AlignBottom);

    QObject::connect(btn_play, SIGNAL(clicked()), this, SLOT(playclicked()));
    QObject::connect(btn_highscore, SIGNAL(clicked()), this, SLOT(highscoreclicked()));
    QObject::connect(btn_exit, SIGNAL(clicked()), this, SLOT(exitclicked()));
    QObject::connect(btn_l1, SIGNAL(clicked()), this, SLOT(level1clicked()));
    QObject::connect(btn_l2, SIGNAL(clicked()), this, SLOT(level2clicked()));
    QObject::connect(btn_l3, SIGNAL(clicked()), this, SLOT(level3clicked()));
    QObject::connect(btn_back, SIGNAL(clicked()), this, SLOT(backclicked()));


    btn_play->setPos(1500/2, 500);
    btn_highscore->setPos(1500/2, 610);
    btn_exit->setPos(1500/2, 720);
    btn_back->setPos(1500/2, 830);
    btn_l1->setPos(1500/2, 500);
    btn_l2->setPos(1500/2, 610);
    btn_l3->setPos(1500/2, 720);


    scene->addItem(btn_play);
    scene->addItem(btn_highscore);
    scene->addItem(btn_exit);

    view= new QGraphicsView(scene);
    view->setFixedSize(1920,1080);
    scene->setSceneRect(0,0,1920,1080);
     view->show();

}
void Interface::backclicked() {



    scene->clear();
    QPixmap backgroundImg(":/code/Images/Interface.png");
    backgroundImg = backgroundImg.scaled(1920,1080,Qt::KeepAspectRatioByExpanding);
    QPalette palette;
    palette.setBrush(QPalette::Background, backgroundImg);

    btn_play = new Button(400, 100, QString("Play"));
    btn_highscore=new Button(400, 100, QString("Highscore"));
    btn_exit  =new Button(400, 100, QString("Exit"));


    btn_play->setPos(1500/2, 500);
    btn_highscore->setPos(1500/2, 610);
    btn_exit->setPos(1500/2, 720);
    scene->addItem(btn_play);
    scene->addItem(btn_highscore);
    scene->addItem(btn_exit);
    QObject::connect(btn_play, SIGNAL(clicked()), this, SLOT(playclicked()));
    QObject::connect(btn_highscore, SIGNAL(clicked()), this, SLOT(highscoreclicked()));
    QObject::connect(btn_exit, SIGNAL(clicked()), this, SLOT(exitclicked()));

}


void Interface::closeView() {
}

void Interface::highscoreclicked(){

    scene->clear();
    Highscore * highscore=new Highscore();

    btn_back=new Button(400, 100, QString("Back"));
    btn_back->setPos(1500/2, 830);
    QObject::connect(btn_back, SIGNAL(clicked()), this, SLOT(backclicked()));
    highscore->view->setGeometry(QRect(540, 430, 700,300));
    scene->addWidget(highscore->view);
    scene->addItem(btn_back);

    highscore->update();

    //highscore->readFromFile();
    //highscore->insertHighsore("Amrit",200);
    qDebug() << "highscore clicked";



}

void Interface::settingsclicked() {
    qDebug() << "settings clicked";
}

void Interface::exitclicked() {
    view->close();
    qDebug()<<"exit clicked";
}
