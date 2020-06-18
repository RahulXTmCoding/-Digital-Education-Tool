#include <QPainter>

#include "canvas.h"
#include<QDebug>
#include <QtMath>
#include "math.h"

Canvas::Canvas( QWidget* parent )
    : QFrame( parent )

{
    setFrameStyle( QFrame::Box );
     this->model=new TmModel();
    this->setStyleSheet("background-color: rgb(255, 255, 255);");
    this->setFocusPolicy(Qt::StrongFocus);
}

void Canvas::selectAll(QModelIndexList il)
{
 this->model->selectAll(il);
    update();
}

void Canvas::groupSelected()
{
    this->model->groupSelected();
update();
}

void Canvas::ungroupSelected()
{
    this->model->ungroupSelected();
update();
}



void Canvas::clear()
{
    this->model->clear();
}

QString Canvas::save()
{
    return this->model->save();
}

void Canvas::open(QJsonArray &arr)
{
    this->model->open(arr);
    update();
}

QColor Canvas::getColor() const
{
    return color;
}

void Canvas::setColor(const QColor &value)
{
    color = value;

    this->model->setSelectedInex(-1);
    this->model->setSelectedComponent(NULL);
    update();
}

int Canvas::getPenWidth() const
{
    return penWidth;
}

void Canvas::setPenWidth(int value)
{
    penWidth = value;
    this->model->setSelectedInex(-1);
    this->model->setSelectedComponent(NULL);
    update();

}

QBrush *Canvas::getBrush() const
{
    return brush;
}

void Canvas::setBrush(QBrush *value)
{
    brush = value;
}

QPen *Canvas::getPen() const
{
    return pen;
}

void Canvas::setPen(QPen *value)
{
    pen = value;
}

int Canvas::getMode() const
{
    return mode;
}

void Canvas::setMode(int value)
{
     mode = value;
    if(value!=0)
    {
        this->model->clearSelected();

    }update();


}


void Canvas::paintEvent( QPaintEvent* pe )
{

    this->setAttribute(Qt::WA_OpaquePaintEvent, false);


    QFrame::paintEvent( pe );
    QPainter p(this);


    //p.setViewport(this->c_x,this->c_y,this->c_width,this->c_height);


    model->draw(&p);

    if(pen==NULL)
    {
        pen=new QPen();
    }
 this->pen->setColor(color);
 this->pen->setWidth(this->penWidth);
p.setPen(*pen);

    if(lineTemp!=NULL && mode==1)
    {
     lineTemp->draw(&p);
    }else
       if(this->rectangle!=NULL && mode==3 )
       {

           rectangle->draw(&p);

       }else
           if(this->line!=NULL && mode==2)
           {

               line->draw(&p);
           }
    else
     if(this->circle!=NULL && mode==4)
     {

         this->circle->draw(&p);
     }
    else
    if(this->ellipse!=NULL && mode==5)
    {
    this->ellipse->draw(&p);
    }



}

void Canvas::mouseMoveEvent(QMouseEvent *event)
{

    if(mode==1)
    {
    lineTemp->append(new QPoint(event->x(),event->y()));
    }else

        if(mode==3)
        {


            this->rectangle->setWidth(event->x()-this->rectangle->getX());
            this->rectangle->setHeight(event->y()-this->rectangle->getY());
        }
    else
    if(mode==2)
    {
        this->line->setX2(event->x());
        this->line->setY2(event->y());
    }
    else
    if(mode==4)
    {
        this->circle->setRadius(sqrt(pow(event->x()-this->circle->getX(),2)+pow(event->y()-this->circle->getY(),2)));
    }
    else
    if(mode==5)
    {
        this->ellipse->setWidth(event->x()-this->ellipse->getX());
        this->ellipse->setHeight(event->y()-this->ellipse->getY());
    }
    else
       if(mode==0)
       {
        int movedX=event->x()-this->model->getInitialX();
        int movedY=event->y()-this->model->getInitialY();

        this->model->setInitialX(event->x());
        this->model->setInitialY(event->y());
        /*if(this->model->getSelectedInex()!=-1)
        {
            this->model->getSelectedComponent()->update(movedX,movedY);
        }
*/
        this->model->update(movedX,movedY);
        this->model->selection=false;
       }

    update();
}

void Canvas::mousePressEvent(QMouseEvent *event)
{

    if(mode==1)
    {
    this->lineTemp=new LinesCompoent();
    lineTemp->append(new QPoint(event->x(),event->y()));
    }else
     /*if(this->elipseDraw)
     {
         this->ellipse=new EllipseComponent();
         this->ellipse->setX(event->x());
         this->ellipse->setY(event->y());

     }
     */
     if(mode==3)
     {
         this->rectangle=new RectangleComponent();
         this->rectangle->setX(event->x());
         this->rectangle->setY(event->y());
         this->rectangle->setWidth(0);
         this->rectangle->setHeight(0);

     }else
     if(mode==2)
     {
         this->line=new LineComponent();
         this->line->setX(event->x());
         this->line->setY(event->y());
         this->line->setX2(event->x());
         this->line->setY2(event->y());
     }
    else
    if(mode==4)
    {
        this->circle=new CircleComponent();
        this->circle->setX(event->x());
        this->circle->setY(event->y());
        this->circle->setRadius(0);
    }
    else
        if(mode==5)
        {

            this->ellipse=new EllipseComponent();

            ellipse->setX(event->x());
            ellipse->setY(event->y());
            ellipse->setWidth(0);
            ellipse->setHeight(0);



        }
    else
    if(mode==0)
    {
        this->model->findClicked(new QPoint(event->x(),event->y()));

        this->model->setInitialX(event->x());
        this->model->setInitialY(event->y());
        update();
    }


}

void Canvas::mouseReleaseEvent(QMouseEvent *event)
{

  if(mode==1)
  {
   this->lineTemp->append(new QPoint(event->x(),event->y()));
  if(this->lineTemp->getPoints()->length()>2)
  {
  this->model->add(lineTemp);
  lineTemp=NULL;
  }
  }
  else
      if(mode==3)
      {
          this->rectangle->setWidth(event->x()-this->rectangle->getX());
          this->rectangle->setHeight(event->y()-this->rectangle->getY());
          if(this->rectangle->getWidth()!=0 and this->rectangle->getHeight()!=0)
          {
          this->model->add(this->rectangle);
              this->rectangle=NULL;
      }
          else
          {
              this->rectangle=NULL;
             // this->model->findClicked(new QPoint(event->x(),event->y()));
              //update();
          }
  }
  else
   if(mode==2)
   {
   this->line->setX2(event->x());
   this->line->setY2(event->y());
   if(this->line->getX()!=this->line->getX2() and this->line->getY()!=this->line->getY2())
   {
   this->model->add(this->line);
       this->line=NULL;
   }
   else
   {this->line=NULL;
       //this->model->findClicked(new QPoint(event->x(),event->y()));
       //update();
   }
   }
  else
  if(mode==5)
  {

      this->ellipse->setWidth(event->x()-this->ellipse->getX());
      this->ellipse->setHeight(event->y()-this->ellipse->getY());

      if(this->ellipse->getWidth()!=0 and this->ellipse->getHeight()!=0)
      {
      this->model->add(this->ellipse);
          this->ellipse=NULL;
  }
      else
      {  this->ellipse=NULL;
         // this->model->findClicked(new QPoint(event->x(),event->y()));
          //update();
      }

  }
  else
      if(mode==4)
      {

          this->circle->setRadius(sqrt(pow(event->x()-this->circle->getX(),2)+pow(event->y()-this->circle->getY(),2)));
          if(this->circle->getRadius()!=0)
          {
          this->model->add(this->circle);
          this->circle=NULL;
          }
          else
          {  this->circle=NULL;
            //  this->model->findClicked(new QPoint(event->x(),event->y()));
              //update();
          }
      }
  else
     if(mode==0)
     {

         this->model->clickedRemove(new QPoint(event->x(),event->y()));
     }

  update();
}

void Canvas::keyPressEvent(QKeyEvent *event)
{

    if(event->key()==Qt::Key_Control)
    {
        this->model->setControllKey(Qt::Key_Control);
    }
if(event->key()==Qt::Key_Delete)
{
this->model->deleteSelected();


     this->update();
}
}

void Canvas::keyReleaseEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_Control)
    {
        this->model->setControllKey(-1);
    }
}

void Canvas::enterEvent(QEvent *event)
{
    setCursor(QCursor(QPixmap(":/images/feather.png"),4,62));

}

void Canvas::leaveEvent(QEvent *event)
{

}
