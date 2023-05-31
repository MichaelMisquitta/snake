#ifndef GAME_H
#define GAME_H
#include "apple.h"
#include "snake.h"
#include "mainwindow.h"


class game
{
public:
    game();
    apple *gameapple;
    snake *gamesnake;
    mainwindow *window;
    QTimer timer;
    void startGame();
private:

};

#endif // GAME_H
