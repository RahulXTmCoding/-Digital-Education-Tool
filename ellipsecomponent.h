#ifndef ELLIPSECOMPONENT_H
#define ELLIPSECOMPONENT_H
#include "drawablecomponent.h"

class EllipseComponent:public DrawableComponent
{
private:
    QPen *pen;
    QBrush *brush;
    float x;
    float y;
    float width;
    float height;
 public:
    EllipseComponent();
    void draw(QPainter *);
    bool isClicked(QPoint *);
    QJsonObject *toJsonObject();
    QString componentName();
     void select(QPainter *p);
     void update(int x,int y);
    QPen *getPen() const;
    void setPen(QPen *value);
    QBrush *getBrush() const;
    void setBrush(QBrush *value);
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);
    float getWidth() const;
    void setWidth(float value);
    float getHeight() const;
    void setHeight(float value);
};

#endif // ELLIPSECOMPONENT_H
