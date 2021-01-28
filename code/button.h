#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>



/*!
 *  \brief     This class is used to create the Buttons for the menu.
 *  \details   With a given size (width and heigth) a Button is drawn.
 *  \details   HoverEvents are used to highlite the selected Button.
 *  \details   The signal clicked is used to connect slots in the menu.
 */
class Button: public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
    // constructors
    Button(int width, int heigth, QString name, QGraphicsItem * parent = NULL);

    // events
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

signals:
    void clicked();

private:
    // attributes
    QGraphicsTextItem * text;
};



#endif
