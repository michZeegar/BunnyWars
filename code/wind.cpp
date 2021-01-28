#include "wind.h"

#include <math.h>
#include <QTime>
#include <QtMath>



Wind::Wind(int xPos, int yPos) {
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    windToLeft = new QGraphicsPixmapItem();
    windToRight = new QGraphicsPixmapItem();

    imageLeftWind = QPixmap(":/code/Images/WindToLeft.png");
    imageHeight = imageLeftWind.height();
    imageWidth = imageLeftWind.width();
    windToLeft->setPixmap(imageLeftWind);
    windToRight->setPixmap(QPixmap(":/code/Images/WindToRight.png"));

    windToLeft->setPos(xPos-41,yPos);
    windToRight->setPos(xPos,yPos);


    wind_label = new QLabel();
    newWind();
    wind_label->setFixedSize(QSize(300,20));
    wind_label->setGeometry(QRect(xPos-29,yPos+50,0,0));
    wind_label->setAttribute(Qt::WA_TranslucentBackground);
    QFont f("Calibri", 16, QFont::Bold);
    wind_label->setFont(f);

}

void Wind::newWind() {
    wind = (qrand()%210)-100;
    //To have no wind more often:
    if(wind>100) {
        wind = 0;
    }

    wind_string = QString::number(wind);
    wind_label->setText("Wind: " + wind_string);
    if(wind<=0) {
       actualWindVane = windToLeft;
    }
    else if(wind>0) {
        actualWindVane = windToRight;
    }

}

qreal Wind::getWind() {
    return wind;
}
