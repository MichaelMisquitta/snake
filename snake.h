#ifndef SNAKE_H
#define SNAKE_H

#include <QGraphicsItem>

#include <QWidget>
#include <QLabel>
#include <vector>
#include "apple.h"


class snake : public QGraphicsItem
{


public:
    snake();
    int xpos = 300;
    int ypos = 300;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
    void advance(int phase) override;
    void updateBody();
    void updateScore();
    void checkTangled();
    enum direction {Up, Down, Left, Right};
    direction mydirection;
    int y = 0;
    std::vector<int> bodyx = std::vector<int>(6);
    std::vector<int> bodyy = std::vector<int>(6);
    apple *snakeapple;
    QLabel *label;

    int score = 0;



private:
    QColor color;
    void keyReleaseEvent(QKeyEvent *event) override;
    void up();
    void down();
    void left();
    void right();


};
#endif // SNAKE_H
