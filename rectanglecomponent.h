#ifndef RECTANGLECOMPONENT_H
#define RECTANGLECOMPONENT_H

#include "drawablecomponent.h"
class RectangleComponent:public DrawableComponent
{
private:
    int x;
    int y;
    int width;
    int height;
    QPen *pen;
    QBrush *brush;
public:
    RectangleComponent();
   void draw(QPainter *);
   bool isClicked(QPoint *);
   QString componentName();
   QJsonObject *toJsonObject();
    void select(QPainter *p);
    void update(int x,int y);
   int getX() const;
   void setX(int value);
   int getY() const;
   void setY(int value);
   int getWidth() const;
   void setWidth(int value);
   int getHeight() const;
   void setHeight(int value);
   QPen *getPen() const;
   void setPen(QPen *value);
   QBrush *getBrush() const;
   void setBrush(QBrush *value);
};

#endif // RECTANGLECOMPONENT_H
