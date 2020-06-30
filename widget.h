#ifndef WIDGET_H
#define WIDGET_H


#include <QPainter>
#include <QtEvents>
#include <QWidget>
#include <QList>
#include "pixmapcomponent.h"
#include <QGridLayout>
#include "physics_wid.h"
class Widget:public QWidget
{


public:
   Physics_wid *parent;
    int x=0;
    int y=0;
    int width=130;
    int height=130;
    QString path;
     Widget(QWidget *);
     void setParent(Physics_wid *);
    void paintEvent( QPaintEvent* );
    void mouseDoubleClickEvent(QMouseEvent * event);
    //void mouseMoveEvent(QMouseEvent *eventMove);
   //void mousePressEvent(QMouseEvent *eventPress);
   //void mouseReleaseEvent(QMouseEvent *releaseEvent);
};

#endif // WIDGET_H
