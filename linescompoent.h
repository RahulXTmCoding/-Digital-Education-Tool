#ifndef LINESCOMPOENT_H
#define LINESCOMPOENT_H

#include "drawablecomponent.h"
class LinesCompoent:public DrawableComponent
{
private:
    QList<QPoint *> *points;
    QPen *pen;
    QBrush *brush;

public:
    LinesCompoent();
    void draw(QPainter *);
     bool isClicked(QPoint *);
     QString componentName();
      void select(QPainter *p);
      void update(int x,int y);
    QList<QPoint *> *getPoints() const;
    void setPoints(QList<QPoint *> *value);
    QPen *getPen() const;
    void setPen(QPen *value);
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);
    void append(QPoint *);
    QBrush *getBrush() const;
    void setBrush(QBrush *value);
};

#endif // LINESCOMPOENT_H
