#ifndef CIRCLECOMPONENT_H
#define CIRCLECOMPONENT_H

#include "drawablecomponent.h"
class CircleComponent:public DrawableComponent
{
  private:
    double x;
    double y;
    double radius;
    QPen *pen;
    QBrush *brush;
public:
    CircleComponent();
    void draw(QPainter *painter);
    bool isClicked(QPoint *);
    QString componentName();
     void select(QPainter *p);
    void update(int x,int y);
    double getX() const;
    void setX(double value);
    double getY() const;
    void setY(double value);
    double getRadius() const;
    void setRadius(double value);
    QPen *getPen() const;
    void setPen(QPen *value);
    QBrush *getBrush() const;
    void setBrush(QBrush *value);
};

#endif // CIRCLECOMPONENT_H
