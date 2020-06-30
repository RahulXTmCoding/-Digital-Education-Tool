#include "linecomponent.h"

int LineComponent::getX() const
{
    return x;
}

void LineComponent::setX(int value)
{
    x = value;
}

int LineComponent::getY() const
{
    return y;
}

void LineComponent::setY(int value)
{
    y = value;
}

int LineComponent::getX2() const
{
    return x2;
}

void LineComponent::setParent(AModel *model)
{
     parent=model;
}

AModel *LineComponent::getParent()
{
    return parent;
}

void LineComponent::setX2(int value)
{
    x2 = value;
}

int LineComponent::getY2() const
{
    return y2;
}

void LineComponent::setY2(int value)
{
    y2 = value;
}

QPen *LineComponent::getPen() const
{
    return pen;
}

void LineComponent::setPen(QPen *value)
{
    pen = value;
}

QBrush *LineComponent::getBrush() const
{
    return brush;
}

void LineComponent::setBrush(QBrush *value)
{
    brush = value;
}

int LineComponent::getRectNo()
{
    return rectNo;
}

void LineComponent::setRectNo(int value)
{
    rectNo = value;
}

LineComponent::LineComponent()
{
    pen=NULL;
    brush=NULL;
}

void LineComponent::draw(QPainter *painter)
{

    if(pen==NULL)
    {


        pen=new QPen();
        pen->setWidth(painter->pen().width());
        pen->setColor(painter->pen().color());
    }
   painter->setPen(*pen);
    painter->drawLine(this->getX(),this->getY(),this->getX2(),this->getY2());
}

bool LineComponent::isClicked(QPoint *point)
{
    QPainterPath *path=new QPainterPath();
if(getRectNo()!=-1)
   {
    path=new QPainterPath();
   path->addRect(x-5,y-5,10,10);
   if(path->contains(*point))
   {
       setRectNo(1);
return true;
   }
   path=new QPainterPath();
  path->addRect(x2-5,y2-5,10,10);
  if(path->contains(*point))
  {
      setRectNo(2);
return true;
  }


}





  double d1;
  double d2;
  double td;
  d1=sqrt(pow(point->x()-this->getX(),2)+pow(point->y()-this->getY(),2));
  d2=sqrt(pow(point->x()-this->getX2(),2)+pow(point->y()-this->getY2(),2));
  td=sqrt(pow(this->getX()-this->getX2(),2)+pow(this->getY()-this->getY2(),2));

if(abs(td-(d1+d2))<.2)
  {
    setRectNo(0);
          return true;
}
setRectNo(-1);
return false;
}

QString LineComponent::componentName()
{
    return name;
}

void LineComponent::changeCompoentName(QString name)
{
this->name=name;
}

QJsonObject *LineComponent::toJsonObject()
{

    QJsonObject *obj=new QJsonObject();

    obj->insert("code",2);
    obj->insert("x",this->getX());
    obj->insert("y",this->getY());
    obj->insert("x2",this->getX2());
    obj->insert("y2",this->getY2());
   obj->insert("color",this->getPen()->color().name());
    obj->insert("pwidth",this->getPen()->width());

    return obj;
}

void LineComponent::select(QPainter *p)
{
    p->drawRect(x-5,y-5,10,10);
    p->drawRect(x2-5,y2-5,10,10);
}

void LineComponent::update(int x, int y)
{
    int rect=getRectNo();
    if(rect==0)
    {
    this->setX(this->getX()+x);
    this->setX2(this->getX2()+x);
    this->setY(this->getY()+y);
    this->setY2(this->getY2()+y);
    }
    else
    if(rect==1)
    {
        this->setX(this->getX()+x);

        this->setY(this->getY()+y);
    }
    else
        if(rect==2)
        {
            this->setX2(this->getX2()+x);

            this->setY2(this->getY2()+y);
        }
}
