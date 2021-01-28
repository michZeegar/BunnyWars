#ifndef WEAPONLABELS_H
#define WEAPONLABELS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QLabel>
#include <QPixmap>



/*!
 *  \brief     This class is used to create the Weaponlabels.
 *  \details   The Weaponlabels show the different weapons you can choose from.
 *  \details   For each box the QList<int>weaponAmmunitionList contains the number of the shots left.
 */
class WeaponLabels {
public:
    // constructors
    WeaponLabels(QGraphicsScene * levelScene,int xPos, int yPos, QList<bool> weaponFlagList, QList<int>weaponAmmunitionList);

    // methods
    void showSquares(int xPos,int Pos, QList<int> weaponAmmunitionList);
    void showB_WSquare(int k);

    // attributes
    QList<QPixmap> pixmapList;
    QList<QPixmap> pixmapListB_W;
    QList<QPoint> posList;

    int j = 0;

    QList<QGraphicsPixmapItem*> labelList;
    QList<QLabel*> ammunitionLabelList;

    int i;

    QGraphicsScene * scene;

    QGraphicsPixmapItem * newsquare;
    QLabel * newlabel;
};



#endif // WEAPONLABELS_H
