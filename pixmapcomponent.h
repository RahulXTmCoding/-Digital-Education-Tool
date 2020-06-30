#ifndef PIXMAPCOMPONENT_H
#define PIXMAPCOMPONENT_H

#include<drawablecomponent.h>
class PixmapComponent : public DrawableComponent
{
  private:
    QString path;
    int x;
    int y;
    int width;
    int height;
     QPixmap *map;
     int rectNo;
     QString name="Pixmap";
     AModel * parent;
public:
    PixmapComponent();
    QString getPath() const;
    void setPath(const QString &value);
    void draw(QPainter *);
    bool isClicked(QPoint *);
    QJsonObject *toJsonObject();
    void changeCompoentName(QString name);
    QString componentName();
     void select(QPainter *p);
     void update(int x,int y);

     int getX() const;
     void setX(int value);
     int getY() const;
     void setY(int value);
     int getWidth() const;
     void setParent(AModel *model);
     AModel * getParent();
     void setWidth(int value);
     int getHeight() const;
     void setHeight(int value);
     QPixmap *getMap() const;
     void setMap(QPixmap *value);
     int getRectNo();
     void setRectNo(int value);
};

#endif // PIXMAPCOMPONENT_H
