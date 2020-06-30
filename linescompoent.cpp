#include "linescompoent.h"

QList<QPoint *> *LinesCompoent::getPoints() const
{
    return points;
}

void LinesCompoent::setPoints(QList<QPoint *> *value)
{
    points = value;
}

QPen *LinesCompoent::getPen() const
{
    return pen;
}

void LinesCompoent::setPen(QPen *value)
{
    pen = value;
}

void LinesCompoent::setParent(AModel *model)
{
     parent=model;
}

AModel *LinesCompoent::getParent()
{
    return parent;
}

void LinesCompoent::append(QPoint *point)
{
   this->points->append(point);
}


QBrush *LinesCompoent::getBrush() const
{
    return brush;
}

void LinesCompoent::setBrush(QBrush *value)
{
    brush = value;
}

int LinesCompoent::getRectNo()
{
    return rectNo;
}


void LinesCompoent::setRectNo(int value)
{
    rectNo = value;
}

LinesCompoent::LinesCompoent()
{
    pen=NULL;
    brush=NULL;
    this->points=new QList<QPoint *>();
}
void LinesCompoent::draw(QPainter *painter)
{

    if(points->length()==2) return;
    if(pen==NULL)
    {


        pen=new QPen();
        pen->setWidth(painter->pen().width());
        pen->setColor(painter->pen().color());
    }

   painter->setPen(*pen);

QPoint *p;
QPoint *p2;
//painter->setPen(*(this->getPen()));
for(int i=0;i<this->points->size()-1;i++)
{
    p=this->points->at(i);
    p2=this->points->at(i+1);

    painter->drawLine(*p,*p2);
}
}

bool LinesCompoent::isClicked(QPoint *point)
{

   for(int i=0;i<points->size()-1;i++)
   {

    double d1;
    double d2;
    double td;
    d1=sqrt(pow(point->x()-points->at(i)->x(),2)+pow(point->y()-points->at(i)->y(),2));
    d2=sqrt(pow(point->x()-points->at(i+1)->x(),2)+pow(point->y()-points->at(i+1)->y(),2));
    td=sqrt(pow(points->at(i)->x()-points->at(i+1)->x(),2)+pow(points->at(i)->y()-points->at(i+1)->y(),2));

if(abs(td-(d1+d2))<.2)
 {
            return true;
 }
   }
return false;
}

QString LinesCompoent::componentName()
{
    return name;
}

QJsonObject *LinesCompoent::toJsonObject()
{

    QJsonObject *obj=new QJsonObject();

    obj->insert("code",1);
    QJsonArray *arr=new QJsonArray();
    for(int i=0;i<this->getPoints()->length();i++)
    {
        QJsonObject *o=new QJsonObject();
        o->insert("x",this->points->at(i)->x());
        o->insert("y",this->points->at(i)->y());
        arr->push_back(*o);
    }
    obj->insert("points",*arr);
    obj->insert("color",this->getPen()->color().name());
    obj->insert("pwidth",this->getPen()->width());

    return obj;

}

void LinesCompoent::changeCompoentName(QString name)
{
this->name=name;
}

void LinesCompoent::select(QPainter *p)
{

    p->drawRect(points->at(0)->x()-5,points->at(0)->y()-5,10,10);
    p->drawRect(points->at(points->size()-1)->x()-5,points->at(points->size()-1)->y()-5,10,10);

    for(int i=10;i<points->size();i=i+10)
    {
        p->drawRect(points->at(i)->x()-5,points->at(i)->y()-5,10,10);

    }
}

void LinesCompoent::update(int x, int y)
{
for(int i=0;i<points->size();i++)
{
    points->at(i)->setX(points->at(i)->x()+x);
    points->at(i)->setY(points->at(i)->y()+y);

}
}
