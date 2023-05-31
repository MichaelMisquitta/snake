#include "mainwindow.h"


mainwindow::mainwindow(snake *gamesnake, apple *gameapple)
{
    scene = new QGraphicsScene;
    view = new QGraphicsView;
    dock = new QDockWidget();

    view->setScene(scene);
    scene->setSceneRect(0,0,600,600);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->addItem(gamesnake);
    scene->addItem(gameapple);
    this->setCentralWidget(this->view);
    this->addDockWidget(Qt::TopDockWidgetArea,dock);

//   label = new QLabel;
//    label->setText("THIS is the label");
    createScoreWidget();





    QPixmap bkgrnd("/Users/randomguy/Documents/QTProjects/snakegame2/grey.jpeg");

    bkgrnd = bkgrnd.scaledToHeight(600);
    bkgrnd = bkgrnd.scaledToWidth(600);
    view->setRenderHint(QPainter::Antialiasing);
    view->setBackgroundBrush(bkgrnd);

    view->setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
    view->setDragMode(QGraphicsView::ScrollHandDrag);

    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView,"Snake Game"));

    this->show();
    //qDebug() <<"setwindow";
}

QDockWidget* mainwindow::createScoreWidget(){

    label = new QLabel;
    label->setAlignment(Qt::AlignHCenter);
    QString scoreString = QString("Score: %1").arg(int(0));
    label->setText(scoreString);


    dock->setWidget(label);
    dock->show();
    return dock;
}
