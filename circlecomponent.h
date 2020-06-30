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
    int rectNo;
    QString name="Circle";
    AModel * parent;
public:
    CircleComponent();
    void draw(QPainter *painter);
    bool isClicked(QPoint *);
    QString componentName();
    void changeCompoentName(QString name);
    QJsonObject *toJsonObject();
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
     void setParent(AModel *model);
     AModel * getParent();
    void setBrush(QBrush *value);
    int getRectNo();
    void setRectNo(int value);
};

#endif // CIRCLECOMPONENT_H
