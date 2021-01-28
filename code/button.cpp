#include "button.h"

#include <QBrush>
#include <QGraphicsTextItem>



Button::Button(int width, int height, QString name, QGraphicsItem * parent):QGraphicsRectItem(parent) {
    // button
    setRect(0, 0, width, height);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);

    // text
    text = new QGraphicsTextItem(name, this);
    int button_xPos = (rect().width() - text->boundingRect().width())/2;
    int button_yPos = (rect().height() - text->boundingRect().height())/2;
    text->setPos(button_xPos, button_yPos);

    // hoverEvent
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *  ) {
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *  ) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::yellow);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent * ) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
}
