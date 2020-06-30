#include "physics_wid.h"
#include "widget.h"
#include <QPushButton>
#include <QDir>
Physics_wid::Physics_wid(QWidget* parent): QWidget(parent )
{

}

void Physics_wid::populateDs()
{
    QString path = ":/images/images";

    QDir dir( path );

    dir.setFilter( QDir::AllEntries);

    int total_files = dir.count();
    qDebug()<<total_files;
    qDebug()<<"sdfghjktgyhjklfghjklftghjkl";
  for(int i=0;i<(total_files/6+1);i++)
  {
   for(int j=0;j<6;j++)
   {

  int height=130*i;
  if(height>this->height())
  {
      this->resize(this->width(),height);
  }
Widget *w=new Widget(this);
w->setParent(this);
w->path=":/images/images/"+QString::number((i*6)+(j+1))+".png";
w->resize(100,100);
layout->addWidget(w,i,j);


   }
  }

}

void Physics_wid::drawPixmap(QString path)
{
 c->drawPixmap(path);
}





