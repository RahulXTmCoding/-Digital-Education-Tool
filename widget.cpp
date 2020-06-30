#include "widget.h"

Widget::Widget(QWidget* parent): QWidget(parent )
{

}

void Widget::setParent(Physics_wid *parent)
{
    this->parent=parent;
}

void Widget::paintEvent(QPaintEvent *pe)
{

    qDebug()<<path;
    QPainter p(this);

    p.drawPixmap(0,0,100,100,QPixmap(path));
}

void Widget::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"rahul is clicked";
parent->drawPixmap(path);
}
