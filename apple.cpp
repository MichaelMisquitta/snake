#include "apple.h"
#include <QPainter>

apple::apple()
{
    this->xpos = 20*15;
    this->ypos = 20*12;
    this->appleState = no;
}
void apple::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    painter->setBrush(Qt::red);
    QImage laytonPix("/Users/randomguy/Documents/QTProjects/snakegame2/LaytonLow.jpg");
    //laytonPix = laytonPix.scaledToHeight(20);
    //laytonPix = laytonPix.scaledToWidth(20);

    painter->drawImage(0,0,laytonPix);
    //painter->drawEllipse(0,0,20,20);
}
void apple::advance(int phase){
    if(phase){


    }
}
QRectF apple::boundingRect() const{
    return QRectF(-10,-10,10,10);
}

void apple::randomPos(){
    int xGen = 20*this->myGenerator.bounded(0,15);
    int yGen = 20*this->myGenerator.bounded(2,15);
    this->setPos(xGen,yGen);
    xpos = xGen;
    ypos = yGen;

}
