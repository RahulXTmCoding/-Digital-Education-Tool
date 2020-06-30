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

void CircleComponent::setParent(AModel *model)
{
    parent=model;
}

AModel *CircleComponent::getParent()
{
    return parent;
}

void CircleComponent::setBrush(QBrush *value)
{
    brush = value;
}

int CircleComponent::getRectNo()
{
    return rectNo;
}

void CircleComponent::setRectNo(int value)
{
    rectNo = value;
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

    QPainterPath *path=new QPainterPath();
if(getRectNo()!=-1)
   {
    path=new QPainterPath();
   path->addRect(x-5,y-radius-5,10,10);
   if(path->contains(*point))
   {
       setRectNo(1);
return true;
   }
   path=new QPainterPath();
  path->addRect(x+radius-5,y-5,10,10);
  if(path->contains(*point))
  {
      setRectNo(2);
return true;
  }
  path=new QPainterPath();
 path->addRect(x-5,y+radius-5,10,10);
 if(path->contains(*point))
 {
     setRectNo(3);
return true;
 }
 path=new QPainterPath();
path->addRect(x-radius-5,y-5,10,10);
if(path->contains(*point))
{
    setRectNo(4);
return true;
}

}

if(pow(point->x()-this->getX(),2)+pow(point->y()-this->getY(),2)-pow(this->getRadius(),2)<=0)
{
    setRectNo(0);
    return true;
}
setRectNo(-1);
return false;
}

QString CircleComponent::componentName()
{
    return name;
}

void CircleComponent::changeCompoentName(QString name)
{
this->name=name;
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
    int rect=getRectNo();
    if(rect==0)
    {
    this->setX(this->getX()+x);
    this->setY(this->getY()+y);

    }
    else
    if(rect==1)
    {
        this->setRadius(radius-y);

    }
    else
        if(rect==2)
        {
        this->setRadius(radius+x);
        }
    else
     if(rect==3)
     {
         this->radius=radius+y;
     }
    else
         if(rect==4)
         {
             this->radius=radius-x;
         }
}
