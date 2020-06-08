#ifndef LINECOMPONENT_H
#define LINECOMPONENT_H
#include "drawablecomponent.h"

class LineComponent: public DrawableComponent
{
 private:
    int x;
    int y;
    int x2;
    int y2;
    QPen *pen;
    QBrush *brush;
public:
    LineComponent();
    void draw(QPainter *);
    bool isClicked(QPoint *);
    QString componentName();
     void select(QPainter *p);
     void update(int x,int y);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getX2() const;
    void setX2(int value);
    int getY2() const;
    void setY2(int value);
    QPen *getPen() const;
    void setPen(QPen *value);
    QBrush *getBrush() const;
    void setBrush(QBrush *value);
};

#endif // LINECOMPONENT_H
