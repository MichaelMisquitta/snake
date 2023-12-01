#include "snake.h"
#include <QGraphicsScene>
#include <QPainter>
#include <QRandomGenerator>
#include <QStyleOption>
#include <QtMath>
#include <QKeyEvent>
#include <iostream>
#include <QWidget>
#include <QRandomGenerator>

snake::snake() : color(150,20,20)

{
    this->right();
    this->mydirection = Right;
    for (int i = 0; i < (this->bodyx).size();i++) {
        (this->bodyx)[i] = this->xpos-20*i-20;
        (this->bodyy)[i] = this->ypos;
    }

}

void snake::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setBrush(Qt::black);
    painter->drawRect(0,0,20,20); //x  y width height
    //int x = 0;
    //int y = 0;
    painter->setBrush(Qt::blue);
    for(size_t i = 0; i< (this->bodyx).size();i++){
        QPointF coord =  mapFromScene(this->bodyx[i],this->bodyy[i]);
        // could also subtract snake position and body calculated coords to get local coords?
        painter->drawRect(coord.x(),coord.y(),20,20);
   }


}


QRectF snake::boundingRect() const{
    return QRectF(-10,-10,10,10);
}

QPainterPath snake::shape() const
{
    QPainterPath path;
    path.addRect(-10, -20, 20, 40);
    return path;
}
void snake::keyReleaseEvent(QKeyEvent *event){
    //qDebug()<<"Keyevent";
    switch(event->key())
    {
    case Qt::Key_Up:{
        this->up();
        break;
    }
    case Qt::Key_Down:{
        this->down();
        break;
    }
    case Qt::Key_Left:{
        this->left();
        break;
    }
    case Qt::Key_Right:{
        this->right();
        break;
    }
    }
}

void snake::up(){
   //mapToParent adds values to your coords, doesnt just
    // use coords as actual coordinates - send (20,0) to mapToParent means add 20 to xparent coord
    // where you are now. not set x to coord (20,0). if current x pos is 10, new pos is 30

    //qDebug()<<"up pressed";
    this->mydirection = Up;
}
void snake::down(){


    this->mydirection = Down;
}
void snake::left(){


    this->mydirection = Left;
}
void snake::right(){


    this->mydirection = Right;
}

void snake::advance(int phase){

    if(phase)
    {
        checkTangled();
        this->updateBody();
        this->updateScore();
        //(this->bodyx)[0] = this->xpos;
        //(this->bodyy)[0] = this->ypos;

        //need snake length here, can't use body size since its 20, not snake length
        for(size_t i = (this->bodyx).size()-1; i >= 1; i--){
            (this->bodyx)[i] = this->bodyx[i-1];
            (this->bodyy)[i] = this->bodyy[i-1];


        }
        (this->bodyx)[0] = this->xpos;
        (this->bodyy)[0] = this->ypos;


        switch(mydirection){
            case(Up):{
                this->ypos += -20;
                break;
            }
            case(Down):{
                this->ypos += 20;
                break;
            }
            case(Left):{
                this->xpos += -20;
                break;
            }
            case(Right):{
                this->xpos += 20;
                break;
            }
        }
            std::cout << "head" << " : "<< this->xpos << std::endl;
            std::cout << 1 << " : "<< (this->bodyx)[1] << std::endl;
            std::cout << 0 << " : "<< (this->bodyx)[0] << std::endl;
    //this->setPos(mapToParent(x,y));
        this->setPos(this->xpos,this->ypos);


    }
}

void snake::updateBody(){


    if (snakeapple->xpos == this->xpos && snakeapple->ypos == this->ypos){

        this->bodyx.push_back(0);
        this->bodyy.push_back(0);


    }

}
void snake::updateScore(){
    if (snakeapple->xpos == this->xpos && snakeapple->ypos == this->ypos){
        score++;
        QString scoreString = QString("Score: %2").arg(score);
        label->setText(scoreString);
        snakeapple->randomPos();
    }


}
void snake::checkTangled(){
    bool reset = false;
    for(size_t i = 0; i< (this->bodyx).size()-1;i++){
        if(xpos == bodyx[i] && ypos == bodyy[i]){
                reset = true;
        }
    }
    if(reset){
        score = 0;
    }
    QString scoreString = QString("Score: %2").arg(score);
    label->setText(scoreString);
}







