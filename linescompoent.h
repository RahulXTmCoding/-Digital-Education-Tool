#ifndef LINESCOMPOENT_H
#define LINESCOMPOENT_H

#include "drawablecomponent.h"
class LinesCompoent:public DrawableComponent
{
private:
    QList<QPoint *> *points;
    QPen *pen;
    QBrush *brush;
    int rectNo;
    QString name="Free Style";
    AModel * parent;

public:
    LinesCompoent();
    void draw(QPainter *);
     bool isClicked(QPoint *);
     QString componentName();
     QJsonObject *toJsonObject();
     void changeCompoentName(QString name);
      void select(QPainter *p);
      void update(int x,int y);
    QList<QPoint *> *getPoints() const;
    void setPoints(QList<QPoint *> *value);
    QPen *getPen() const;
    void setPen(QPen *value);
    float getX() const;
    void setX(float value);
    float getY() const;
    void setParent(AModel *model);
    AModel * getParent();
    void setY(float value);
    void append(QPoint *);
    QBrush *getBrush() const;
    void setBrush(QBrush *value);
    int getRectNo();
    void setRectNo(int value);
};

#endif // LINESCOMPOENT_H
