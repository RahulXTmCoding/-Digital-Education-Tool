#ifndef TEXTCOMPONENT_H
#define TEXTCOMPONENT_H

#include "drawablecomponent.h"

class TextComponent:public DrawableComponent
{
private:
    QFont *font;
    QPen * pen;
    QString text;
    float x;
    float y;
    int rectNo;
    QString name="Text";
    AModel * parent;

public:
    TextComponent();
    void draw(QPainter *);
     bool isClicked(QPoint *);
     QString componentName();
     QJsonObject *toJsonObject();
      void select(QPainter *p);
      void update(int x,int y);
      void changeCompoentName(QString name);
    QFont *getFont() const;
    void setFont(QFont *value);
    QPen *getPen() const;
    void setPen(QPen *value);
    void setParent(AModel *model);
    AModel * getParent();
    QString getText() const;
    void setText(const QString &value);
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);

    int getRectNo();
    void setRectNo(int value);
};

#endif // TEXTCOMPONENT_H
