#ifndef CANVAS_H
#define CANVAS_H
#pragma once
#endif // CANVAS_H
#include <QPainter>
#include <QFrame>

#include "tmmodel.h"
#include "textcomponent.h"
#include "tmmodel.h"
#include "linescompoent.h"
#include "ellipsecomponent.h"
#include "rectanglecomponent.h"
#include "linecomponent.h"
#include "circlecomponent.h"
class Canvas : public QFrame
{
Q_OBJECT

public:
    Canvas( QWidget* );
     TmModel *model;
     double c_x;
     double c_y;
     double c_width;
     double c_height;
     void changeComponentName(QString name,QModelIndexList li);
     int mode=1;
     LinesCompoent *lineTemp=NULL;
     EllipseComponent *ellipse=NULL;
     RectangleComponent *rectangle=NULL;
     LineComponent *line=NULL;
     CircleComponent *circle=NULL;
     QPen *pen=NULL;
     QBrush *brush=NULL;
     int penWidth=1;
     QColor color=Qt::black;
     void selectAll(QModelIndexList il);
     void groupSelected();
     void ungroupSelected();
     void clear();
     QJsonObject * save();
     void open(QJsonArray &);
     void drawPixmap(QString path);
     int getMode() const;
     void setMode(int value);

     QPen *getPen() const;
     void setPen(QPen *value);

     QBrush *getBrush() const;
     void setBrush(QBrush *value);

     int getPenWidth() const;
     void setPenWidth(int value);

     QColor getColor() const;
     void setColor(const QColor &value);

protected:
     void paintEvent( QPaintEvent* );
     void mouseMoveEvent(QMouseEvent *eventMove);
    void mousePressEvent(QMouseEvent *eventPress);
    void mouseReleaseEvent(QMouseEvent *releaseEvent);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *ev);
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);

private:


};
