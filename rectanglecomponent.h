#ifndef RECTANGLECOMPONENT_H
#define RECTANGLECOMPONENT_H

#include "drawablecomponent.h"
class RectangleComponent:public DrawableComponent
{
private:
    double x;
    double y;
    double width;
    double height;
    QPen *pen;
    QBrush *brush;
    int rectNo;
    QString name="Rectangle";
    AModel * parent;
public:
    RectangleComponent();
   void draw(QPainter *);
   bool isClicked(QPoint *);
   QString componentName();
   QJsonObject *toJsonObject();
    void changeCompoentName(QString name);
    void select(QPainter *p);
    void update(int x,int y);
   double getX() const;
   void setX(double value);
   double getY() const;
   void setY(double value);
   double getWidth() const;
   void setWidth(double value);
   void setParent(AModel *model);
   AModel * getParent();
   int getHeight() const;
   void setHeight(int value);
   QPen *getPen() const;
   void setPen(QPen *value);
   QBrush *getBrush() const;
   void setBrush(QBrush *value);
   int getRectNo();
   void setRectNo(int value);
};

#endif // RECTANGLECOMPONENT_H
