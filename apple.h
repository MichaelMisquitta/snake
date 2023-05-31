#ifndef APPLE_H
#define APPLE_H

#include <QGraphicsItem>
#include <QWidget>
#include <QRandomGenerator>

class apple : public QGraphicsItem
{
public:
    apple();
    int xpos;
    int ypos;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    void advance(int phase) override;
    QRectF boundingRect() const override;
    enum eatenState{yes,no};
    eatenState appleState;
    QRandomGenerator myGenerator{1};
    void randomPos();
};

#endif // APPLE_H
