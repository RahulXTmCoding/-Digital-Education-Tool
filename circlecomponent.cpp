#include "circlecomponent.h"

double CircleComponent::getX() const
{
    return x;
}

void CircleComponent::setX(double value)
{
    x = value;
}

double CircleComponent::getY() const
{
    return y;
}

void CircleComponent::setY(double value)
{
    y = value;
}

double CircleComponent::getRadius() const
{
    return radius;
}

void CircleComponent::setRadius(double value)
{
    radius = value;
}

QPen *CircleComponent::getPen() const
{
    return pen;
}

void CircleComponent::setPen(QPen *value)
{
    pen = value;
}

QBrush *CircleComponent::getBrush() const
{
    return brush;
}

void CircleComponent::setBrush(QBrush *value)
{
    brush = value;
}

CircleComponent::CircleComponent()
{
    pen=NULL;
    brush=NULL;
}

void CircleComponent::draw(QPainter *painter)
{
    if(pen==NULL)
    {


        pen=new QPen();
        pen->setWidth(painter->pen().width());
        pen->setColor(painter->pen().color());
    }
     painter->setPen(*pen);
    painter->drawEllipse(this->getX()-this->getRadius(),this->getY()-this->getRadius(),this->getRadius()*2,this->getRadius()*2);
}

bool CircleComponent::isClicked(QPoint *point)
{
if(pow(point->x()-this->getX(),2)+pow(point->y()-this->getY(),2)-pow(this->getRadius(),2)<=0)
{
    return true;
}
return false;
}

QString CircleComponent::componentName()
{
    return "Circle";
}

QJsonObject *CircleComponent::toJsonObject()
{
QJsonObject *obj=new QJsonObject();

obj->insert("code",4);
obj->insert("x",this->getX());
obj->insert("y",this->getY());
obj->insert("radius",this->getRadius());

obj->insert("color",this->getPen()->color().name());
obj->insert("pwidth",this->getPen()->width());

return obj;
}

void CircleComponent::select(QPainter *p)
{
    p->drawRect(x-radius-5,y-5,10,10);
    p->drawRect(x-5,y-radius-5,10,10);
    p->drawRect(x-5,y+radius-5,10,10);
    p->drawRect(x+radius-5,y-5,10,10);
}

void CircleComponent::update(int x, int y)
{
    this->setX(this->getX()+x);
    this->setY(this->getY()+y);
}
