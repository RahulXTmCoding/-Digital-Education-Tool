#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include <math.h>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <stdexcept>
#include "amodel.h"
class DrawableComponent
{
public:
    DrawableComponent();
    virtual void draw(QPainter *)=0;
    virtual bool isClicked(QPoint *)=0;
    virtual QString componentName()=0;
    virtual void changeCompoentName(QString name)=0;

    virtual void select(QPainter *p)=0;
    virtual void update(int x,int y)=0;
    virtual QJsonObject* toJsonObject()=0;
    virtual int getRectNo()=0;
    virtual void setRectNo(int value)=0;
    virtual void setParent(AModel *model)=0;
    virtual AModel * getParent()=0;


};

#endif // DRAWABLECOMPONENT_H
