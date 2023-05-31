
#include "game.h"
#include <QApplication>
#include <QTimer>
#include <QtWidgets>
#include <iostream>


//open mp
//mpi
//cuda


//note that cmake will not auto add new files, must be added manually :P
int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    game mygame;
    mygame.startGame();

    /// timer wont work in game object for some reason

    return app.exec();
}
