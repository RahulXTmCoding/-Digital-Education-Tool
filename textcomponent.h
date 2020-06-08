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


public:
    TextComponent();
    void draw(QPainter *);
     bool isClicked(QPoint *);
     QString componentName();
      void select(QPainter *p);
      void update(int x,int y);
    QFont *getFont() const;
    void setFont(QFont *value);
    QPen *getPen() const;
    void setPen(QPen *value);
    QString getText() const;
    void setText(const QString &value);
    float getX() const;
    void setX(float value);
    float getY() const;
    void setY(float value);
};

#endif // TEXTCOMPONENT_H
