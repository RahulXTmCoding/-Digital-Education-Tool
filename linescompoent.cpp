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

bool LinesCompoent::isClicked(QPoint *)
{

return false;
}

QString LinesCompoent::componentName()
{
    return "Free Style";
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

void LinesCompoent::select(QPainter *p)
{

}

void LinesCompoent::update(int x, int y)
{

}
