#include "weaponlabels.h"



WeaponLabels::WeaponLabels(QGraphicsScene * levelScene, int xPos, int yPos, QList<bool> weaponFlagList, QList<int>weaponAmmunitionList) {
    scene = levelScene;
    pixmapList = {
                 QPixmap(":/code/Images/MinigunSquare.png"),
                 QPixmap(":/code/Images/MachineGunSquare.png"),
                 QPixmap(":/code/Images/Spray.png"),
    };
    pixmapListB_W = {
                 QPixmap(":/code/Images/MinigunSquareB_W.png"),
                 QPixmap(":/code/Images/MachineGunSquareB_W.png"),
                 QPixmap(":/code/Images/SprayB_W.png"),
    };
    showSquares(xPos,yPos,weaponAmmunitionList);
}

void WeaponLabels::showSquares(int xPos, int yPos,QList<int>WeaponAmmunitionList) {
    for(i=0; i<pixmapList.size(); i++) {
        newsquare = new QGraphicsPixmapItem();
        pixmapList[i] = pixmapList[i].scaledToHeight(100);
        pixmapListB_W[i] = pixmapListB_W[i].scaledToHeight(100);
        newsquare->setPixmap(pixmapList[i]);
        newsquare->setPos(xPos+80*i,yPos);
        posList.append(QPoint(xPos+80*i,yPos));
        j++;
        scene->addItem(newsquare);
        newsquare->setZValue(10);
        labelList.append(newsquare);

        newlabel = new QLabel;
        QString label_text = QString::number(WeaponAmmunitionList[i]);
        newlabel->setText(label_text);
        newlabel->setGeometry(QRect(xPos+80*i+20,yPos+60,50,50));
        //newlabel->show();
        //newlabel->raise();
        ammunitionLabelList.append(newlabel);

        QFont f("Calibri", 13, QFont::Bold);
        QColor color = QColor(Qt::white);
        QPalette palette = newlabel->palette();
        palette.setColor(QPalette::WindowText, color);
        newlabel->setPalette(palette);
        newlabel->setFont(f);
        newlabel->setAttribute(Qt::WA_TranslucentBackground);
        newlabel->activateWindow();
    }
}

void WeaponLabels::showB_WSquare(int k) {
    if(k<posList.size()){
        newsquare = new QGraphicsPixmapItem();
        newsquare->setPixmap(pixmapListB_W[k]);
        newsquare->setPos(posList[k]);
        scene->addItem(newsquare);
        newsquare->setZValue(11);
    }
}
