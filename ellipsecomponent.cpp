#include "ellipsecomponent.h"

int EllipseComponent::getRectNo()
{
    return rectNo;
}

void EllipseComponent::setRectNo(int value)
{
    rectNo = value;
}

EllipseComponent::EllipseComponent()
{
    pen=NULL;
    brush=NULL;
}

QBrush *EllipseComponent::getBrush() const
{
    return brush;
}

void EllipseComponent::setBrush(QBrush *value)
{
    brush = value;
}

float EllipseComponent::getX() const
{
    return x;
}


void EllipseComponent::setX(float value)
{
    x = value;
}

float EllipseComponent::getY() const
{
    return y;
}

void EllipseComponent::setParent(AModel *model)
{
     parent=model;
}

AModel *EllipseComponent::getParent()
{
   return parent;
}

void EllipseComponent::setY(float value)
{
    y = value;
}

float EllipseComponent::getWidth() const
{
    return width;
}

void EllipseComponent::setWidth(float value)
{
    width = value;
}

float EllipseComponent::getHeight() const
{
    return height;
}

void EllipseComponent::setHeight(float value)
{
    height = value;
}

QPen *EllipseComponent::getPen() const
{
    return pen;
}

void EllipseComponent::setPen(QPen *value)
{
    pen = value;
}
void EllipseComponent::draw(QPainter *painter)
{

    if(pen==NULL)
    {


        pen=new QPen();
        pen->setWidth(painter->pen().width());
        pen->setColor(painter->pen().color());
    }
   painter->setPen(*pen);
    //painter->setPen(*(this->getPen()));
    //painter->setBrush(*(this->getBrush()));
    painter->drawEllipse(this->getX(),this->getY(),this->getWidth(),this->getHeight());

}

bool EllipseComponent::isClicked(QPoint *point)
{
    QPainterPath *path=new QPainterPath();
if(getRectNo()!=-1)
   {
    path=new QPainterPath();
   path->addRect(x-5,y-5,10,10);
   if(path->contains(*point))
   {
       setRectNo(1);
return true;
   }
   path=new QPainterPath();
  path->addRect(x+width-5,y-5,10,10);
  if(path->contains(*point))
  {
      setRectNo(3);
return true;
  }
  path=new QPainterPath();
 path->addRect(x-5,y+height-5,10,10);
 if(path->contains(*point))
 {
     setRectNo(7);
return true;
 }
 path=new QPainterPath();
path->addRect(x+width-5,y+height-5,10,10);
if(path->contains(*point))
{
    setRectNo(5);
return true;
}
path=new QPainterPath();
path->addRect((x+(width)/2)-5,y-5,10,10);
if(path->contains(*point))
{
    setRectNo(2);
return true;
}
path=new QPainterPath();
path->addRect(x+width-5,(y+(height)/2)-5,10,10);
if(path->contains(*point))
{
    setRectNo(4);
return true;
}
path=new QPainterPath();
path->addRect(x-5,(y+(height)/2)-5,10,10);
if(path->contains(*point))
{
    setRectNo(8);
return true;

}
path=new QPainterPath();
path->addRect((x+(width)/2)-5,y+height-5,10,10);
if(path->contains(*point))
{
setRectNo(6);
return true;
}
}
    path->addRect(this->getX(),this->getY(),this->getWidth(),this->getHeight());
    if(path->contains(*point))
    { setRectNo(0);
        return true;
    }


   /* if(point->y()>=this->getY() and point->y()<=(this->getY()+this->height) and point->x()>=this->getX() and point->x()<=(this->getX()+this->getWidth()))
    {
        return true;
    }

    if(sqrt((point->x()-this->getX())*(this->getX()+this->getWidth()-point->x()))*sqrt((point->y()-this->getY())*(this->getY()+this->getHeight()-point->y()))>=0)
    {
        return true;
    }
    */
    setRectNo(-1);
    return false;
}

QJsonObject *EllipseComponent::toJsonObject()
{
    QJsonObject *obj=new QJsonObject();

    obj->insert("code",5);
    obj->insert("x",this->getX());
    obj->insert("y",this->getY());
    obj->insert("width",this->getWidth());
    obj->insert("height",this->getHeight());
    obj->insert("color",this->getPen()->color().name());
    obj->insert("pwidth",this->getPen()->width());

    return obj;

}

void EllipseComponent::changeCompoentName(QString name)
{
this->name=name;
}

QString EllipseComponent::componentName()
{
return name;
}

void EllipseComponent::select(QPainter *p)
{
    p->drawRect(x+(width/2)-5,y-5,10,10);
    p->drawRect(x+width-5,y+(height/2)-5,10,10);
    p->drawRect(x-5,y+(height/2)-5,10,10);
    p->drawRect(x+(width/2)-5,y+height-5,10,10);
    p->drawRect(x-5,y-5,10,10);
    p->drawRect(x+width-5,y-5,10,10);
    p->drawRect(x-5,y+height-5,10,10);
    p->drawRect(x+width-5,y+height-5,10,10);
}

void EllipseComponent::update(int x, int y)
{

    int rect=getRectNo();

    if(parent->getShiftKey()==-1)
    {
    if(rect==0)
    {
    this->setX(this->getX()+x);
    this->setY(this->getY()+y);
    }
    else
    if(rect==1)
    {
        int w=width-x;
        int h=height-y;
        if(w<=2 or h<=2) return;
        this->setX(this->getX()+x);
        this->setY(this->getY()+y);
        this->setWidth(w);
        this->setHeight(h);
    }
    else
   if(rect==2)
   {


       int h=height-y;
       if(h<=2) return;

       this->setY(this->getY()+y);

       this->setHeight(height-y);
   }
    else
       if(rect==3)
       {

           int w=width+x;
           int h=height-y;
           if(w<=2 or h<=2) return;

           this->setY(this->getY()+y);
           this->setWidth(width+x);
           this->setHeight(height-y);
       }
    else
    if(rect==4)
    {

        int w=width+x;

        if(w<=2) return;
        this->setWidth(width+x);
    }
    else
        if(rect==5)
        {

            int w=width+x;
            int h=height+y;
            if(w<=2 or h<=2) return;
            this->setWidth(width+x);
            this->setHeight(height+y);

        }
    else
    if(rect==6)
    {


        int h=height+y;
        if(h<=2) return;
        this->setHeight(height+y);
    }
    else
        if(rect==7)
        {

            int w=width-x;
            int h=height+y;
            if(w<=2 or h<=2) return;
            this->setX(this->getX()+x);
            this->setWidth(width-x);
            this->setHeight(height+y);
        }
    else
            if(rect==8)
            {

                int w=width-x;

                if(w<=2 ) return;
                this->setX(this->getX()+x);
                this->setWidth(this->getWidth()-x);
            }
    }
    else
     {
        qDebug()<<"else mai aaya kya";
        double ratio=abs(((double)this->width)/this->height);
        double ratio2=abs((double)height/width);
        if(rect==0)
        {

        this->setX(this->getX()+x);
        this->setY(this->getY()+y);
        }
        else
        if(rect==1)
        {


            if(abs(y)>=abs(x))
            {
                        int h=height-y;
                        if(h<2) return;
                        this->setY(this->getY()+y);

                        this->setHeight(h);

                        double w2=height*ratio;
                        double w3=w2-width;
                         this->x=this->x-(w3);
                        width=w2;
            }
            else
            {    int w=width-x;
                if(w<2) return;
                this->setX(this->getX()+x);
                this->setWidth(w);
                double h=width*ratio2;
                double h2=h-height;
                this->y=this->y-(h2);
                height=h;
            }
            qDebug()<<(width/height);
        }
        else
       if(rect==2)
       {
           int h=height-y;
           if(h<2) return;
           this->setY(this->getY()+y);

           this->setHeight(h);

           double w2=height*ratio;
           double w3=w2-width;
            this->x=this->x-(w3/2);
           width=w2;


       }
        else
           if(rect==3)
           {
               if(abs(y)>=abs(x))
               {
                   int h=height-y;
                   if(h<2) return;
                   this->setY(this->getY()+y);

                   this->setHeight(h);
                   double w2=height*ratio;
                   width=w2;
               }
               else
               {
                   int w=width+x;
                   if(w<2) return;
                   this->setWidth(w);

                   double h=width*ratio2;
                   double h2=h-height;
                   this->y=this->y-h2;
                   height=h;
               }


           }
        else
        if(rect==4)
        {
            int w=width+x;
            if(w<2) return;

            this->setWidth(w);

            double h=width*ratio2;
            double h2=h-height;
            this->y=this->y-(h2/2);
            height=h;
        }
        else
            if(rect==5)
            {

                if(abs(y)>=abs(x))
                {
                    int h=height+y;
                    if(h<2) return;


                    this->setHeight(h);

                    double w2=height*ratio;
                    width=w2;
                }
                else
                {
                    int w=width+x;
                    if(w<2) return;


                    this->setWidth(width+x);

                    double h=width*ratio2;

                    height=h;
                }





            }
        else
        if(rect==6)
        {
            int h=height+y;
            if(h<2) return;


            this->setHeight(h);
            double w2=height*ratio;
            double w3=w2-width;
             this->x=this->x-(w3/2);
            width=w2;

        }
        else
            if(rect==7)
            {



                    if(abs(y)>=abs(x))
                    {

                        int h=height+y;
                        if(h<2) return;


                        this->setHeight(h);

                        double w2=height*ratio;
                        double w3=w2-width;
                        this->x=this->x-w3;
                        width=w2;
                    }
                    else
                    {
                        int w=width-x;
                        if(w<2) return;

                        this->setWidth(w);
                        this->x=this->x+x;
                        double h=width*ratio2;

                        height=h;
                    }



            }
        else
                if(rect==8)
                {
                    int w=width-x;
                    if(w<2) return;

                    this->setX(this->getX()+x);
                    this->setWidth(w);
                    double h=width*ratio2;
                    double h2=h-height;
                    this->y=this->y-(h2/2);
                    height=h;

                }




    }
}
