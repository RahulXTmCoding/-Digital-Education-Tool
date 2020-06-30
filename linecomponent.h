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
    int rectNo;
    QString name="Line";
    AModel * parent;
public:
    LineComponent();
    void draw(QPainter *);
    bool isClicked(QPoint *);
    QString componentName();
    void changeCompoentName(QString name);
    QJsonObject *toJsonObject();
     void select(QPainter *p);
     void update(int x,int y);
    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);
    int getX2() const;
    void setParent(AModel *model);
    AModel * getParent();
    void setX2(int value);
    int getY2() const;
    void setY2(int value);
    QPen *getPen() const;
    void setPen(QPen *value);
    QBrush *getBrush() const;
    void setBrush(QBrush *value);
    int getRectNo();
    void setRectNo(int value);
};

#endif // LINECOMPONENT_H
