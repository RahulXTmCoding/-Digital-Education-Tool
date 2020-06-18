#include "rectanglecomponent.h"



int RectangleComponent::getX() const
{
    return x;
}

void RectangleComponent::setX(int value)
{
    x = value;
}

int RectangleComponent::getY() const
{
    return y;
}

void RectangleComponent::setY(int value)
{
    y = value;
}

int RectangleComponent::getWidth() const
{
    return width;
}

void RectangleComponent::setWidth(int value)
{
    width = value;
}

int RectangleComponent::getHeight() const
{
    return height;
}

void RectangleComponent::setHeight(int value)
{
    height = value;
}

QPen *RectangleComponent::getPen() const
{
    return pen;
}

void RectangleComponent::setPen(QPen *value)
{
    pen = value;
}

QBrush *RectangleComponent::getBrush() const
{
    return brush;
}

void RectangleComponent::setBrush(QBrush *value)
{
    brush = value;
}

RectangleComponent::RectangleComponent()
{
    pen=NULL;
    brush=NULL;
}

void RectangleComponent::draw(QPainter *painter)
{


    if(pen==NULL)
    {


        pen=new QPen();
        pen->setWidth(painter->pen().width());
        pen->setColor(painter->pen().color());
    }
  painter->setPen(*pen);
    painter->drawRect(this->getX(),this->getY(),this->getWidth(),this->getHeight());
}

bool RectangleComponent::isClicked(QPoint *point)
{

    QPainterPath *path=new QPainterPath();
    path->addRect(this->getX(),this->getY(),this->getWidth(),this->getHeight());
    if(path->contains(*point))
    {return true;}

   /* if(point->y()>=this->getY() and point->y()<=(this->getY()+this->height) and point->x()>=this->getX() and point->x()<=(this->getX()+this->getWidth()))
    {
        return true;
    }

    if(sqrt((point->x()-this->getX())*(this->getX()+this->getWidth()-point->x()))*sqrt((point->y()-this->getY())*(this->getY()+this->getHeight()-point->y()))>=0)
    {
        return true;
    }
    */
    return false;
}

QString RectangleComponent::componentName()
{
    return "Rectangle";
}

QJsonObject *RectangleComponent::toJsonObject()
{

    QJsonObject *obj=new QJsonObject();
    obj->insert("code",3);
    obj->insert("x",this->getX());
    obj->insert("y",this->getY());
    obj->insert("width",this->getWidth());
    obj->insert("height",this->getHeight());
   obj->insert("color",this->getPen()->color().name());
    obj->insert("pwidth",this->getPen()->width());

    return obj;
}

void RectangleComponent::select(QPainter *p)
{

    p->drawRect(x-5,y-5,10,10);
    p->drawRect(x+width-5,y-5,10,10);
    p->drawRect(x-5,y+height-5,10,10);
    p->drawRect(x+width-5,y+height-5,10,10);
}

void RectangleComponent::update(int x, int y)
{
    this->setX(this->getX()+x);
    this->setY(this->getY()+y);
}
