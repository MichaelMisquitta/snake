#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QLabel>
#include <QApplication>
#include <QtWidgets>
#include "snake.h"
#include "apple.h"

class mainwindow : public QMainWindow
{
public:
    mainwindow(snake*, apple*);
    void createScene();
    QGraphicsScene *scene;
    QGraphicsView *view;
    QLabel *label;
    QDockWidget *dock;
    int* score{0};
private:
    QDockWidget* createScoreWidget();
};

#endif // MAINWINDOW_H
