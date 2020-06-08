#ifndef DRAWABLECOMPONENT_H
#define DRAWABLECOMPONENT_H
#include <QGraphicsScene>
#include <QPainter>
#include <QDebug>
#include <math.h>
#include <stdexcept>
class DrawableComponent
{
public:
    DrawableComponent();
    virtual void draw(QPainter *)=0;
    virtual bool isClicked(QPoint *)=0;
    virtual QString componentName()=0;
    virtual void select(QPainter *p)=0;
    virtual void update(int x,int y)=0;

};

#endif // DRAWABLECOMPONENT_H
