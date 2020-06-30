#ifndef PHYSICS_WID_H
#define PHYSICS_WID_H
#include <QPainter>
#include <QtEvents>
#include <QWidget>
#include <QList>
#include "pixmapcomponent.h"
#include <QGridLayout>
#include "canvas.h"
class Physics_wid:public QWidget
{

public:
    Canvas *c=NULL;

    QGridLayout *layout;
    Physics_wid(QWidget*);
    void populateDs();
    void drawPixmap(QString path);

};

#endif // PHYSICS_WID_H
