#include "game.h"
#include "snake.h"
#include "apple.h"

game::game()
{
//    gameapple = new apple;
//    gamesnake = new snake;

//    gamesnake->snakeapple = gameapple;
//    gamesnake->setPos(300,300);
//    gameapple->setPos(gameapple->xpos,gameapple->ypos);
//    window = new mainwindow(gamesnake,gameapple);
//    gamesnake->grabKeyboard();



}

void game::startGame(){
    \
    gameapple = new apple;
    gamesnake = new snake;

    gamesnake->snakeapple = gameapple;
    gamesnake->setPos(300,300);
    gameapple->setPos(gameapple->xpos,gameapple->ypos);
    window = new mainwindow(gamesnake,gameapple);
    gamesnake->grabKeyboard();

    gamesnake->label = window->label;

   // timer = new QTimer;
    //QObject::connect(timer, &QTimer::timeout, window->scene, [](){qDebug()<<"timer";});
    QObject::connect(&timer, &QTimer::timeout, window->scene, &QGraphicsScene::advance);

    timer.start(1000/4);
    qDebug()<<"timer started";
}
