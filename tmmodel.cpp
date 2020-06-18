#include "tmmodel.h"
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
void TmModel::setDsList(QListWidget *value)
{
    dsList = value;
}

QListWidget *TmModel::getDsList() const
{
    return dsList;
}

int TmModel::getSelectedInex() const
{
    return selectedInex;
}

void TmModel::setSelectedInex(int value)
{
    selectedInex = value;
}

DrawableComponent *TmModel::getSelectedComponent() const
{
    return selectedComponent;
}

void TmModel::setSelectedComponent(DrawableComponent *value)
{
    selectedComponent = value;
}

void TmModel::findClicked(QPoint *point)
{
    DrawableComponent *d;
   qDebug()<< groups.size()<<"find clicked pe click hi hua just";
    for(int k=groups.size()-1;k>=0;k--)
    {
        QList<QPair<int,DrawableComponent *> *> *ll=groups.at(k);
        qDebug()<< "inner loop se phle";
        for(int j=0;j<ll->size();j++)
        {

    d=ll->at(j)->second;
    qDebug()<< "inner loop ke andar";
if(d->isClicked(point))
{
    qDebug()<< "inner loop clicked";
    if(controllKey!=-1)
    {
     for(int f=0;f<selectedGroups.size();f++)
     {
         if(selectedGroups.at(f)==k)
             return;
     }
     selectedList.append(*(groups.at(k)));
     selectedGroups.append(k);
    }
    else
    {
        qDebug()<< "inner loop else mai";
selectedList=*(groups.at(k));
selectedGroup=k;

selectedGroups.clear();
selectedGroups.append(k);
qDebug()<< "else end phle";
    }
qDebug()<< "return e";
return;
}
    }
}

qDebug()<< groups.size()<<"list se phle wala";
    for(int k=0;k<selectedList.size();k++)
    {
    d=selectedList.at(k)->second;
if(d->isClicked(point))
{
selection=true;
return;
}
    }


    bool found=false;
    for(int i=this->drawables->length()-1;i>=0;i--)
    {
        d=this->drawables->at(i);
        bool result=d->isClicked(point);
        if(result)
        {



            found=true;
            QPair<int,DrawableComponent *> *pair=new QPair<int,DrawableComponent *>();
            pair->first=i;
            pair->second=d;
            if(controllKey!=-1)
            {
             selectedList.append(pair);
            }
            else
            {
                selectedList.clear();
                selectedList.append(pair);
            }
           // this->setSelectedInex(i);
            //this->setSelectedComponent(d);
            break;
        }

    }
    if(found==false)
    {
        if(controllKey==-1)
        {
        selectedList.clear();
        selectedGroups.clear();
        }
        //this->setSelectedInex(-1);
        //this->setSelectedComponent(NULL);
    }
}

void TmModel::clickedRemove(QPoint *point)
{
    if(selectedList.size()<=1) return;
    DrawableComponent *d=NULL;
    for(int k=0;k<selectedList.size();k++)
    {
    d=selectedList.at(k)->second;
if(d->isClicked(point) and selection)
{
selectedList.removeAt(k);
selection=false;
return;
}
    }

}

QList<DrawableComponent *> *TmModel::getDrawables() const
{
    return drawables;
}

int TmModel::getInitialX() const
{
    return initialX;
}

void TmModel::setInitialX(int value)
{
    initialX = value;
}

int TmModel::getInitialY() const
{
    return initialY;
}

void TmModel::setInitialY(int value)
{
    initialY = value;
}

void TmModel::undo()
{
   selectedList.clear();
    if(this->drawables->size()>0)
    {
        int index=drawables->size()-1;
        for(int k=groups.size()-1;k>=0;k--)
        {
             QList<QPair<int,DrawableComponent *>*> *l2=groups.at(k);
            for(int j=0;j<l2->size();j++)
            {
                if(index==l2->at(j)->first)
                {
                    l2->removeAt(j);
                    break;
                }
            }
        }


        DrawableComponent *temp=this->drawables->last();
      this->tempDrawables->append(temp);
    this->drawables->pop_back();
    }

}

void TmModel::redo()
{

     selectedList.clear();
    this->setSelectedInex(-1);
    this->setSelectedComponent(NULL);
    if(this->tempDrawables->size()>0)
    {
      DrawableComponent *temp=this->tempDrawables->last();
    this->drawables->append(temp);
      this->tempDrawables->pop_back();
    }
}

TmModel::TmModel()
{
    this->drawables=new QList<DrawableComponent *>();
    this->tempDrawables=new QList<DrawableComponent *>();
}

void TmModel::clear()
{
    this->drawables->clear();
    this->selectedList.clear();
    this->selectedGroups.clear();
    this->groups.clear();
}

QString TmModel::save()
{
QJsonArray *arr=new QJsonArray();
int i=0;
for(;i<this->drawables->length();i++)
{
    DrawableComponent *d;
    d=this->drawables->at(i);
    arr->push_back(*(d->toJsonObject()));
}

return (new QJsonDocument(*arr))->toJson();
}

void TmModel::selectAll(QModelIndexList il)
{
    selectedList.clear();
    selectedGroups.clear();

    for(QModelIndex index:il)
    {
       int i=this->getDrawables()->size()-1-index.row();
       DrawableComponent *d=drawables->at(i);
       QPair<int,DrawableComponent *> *pair=new QPair<int,DrawableComponent *>();
       pair->first=i;
       pair->second=d;
       selectedList.append(pair);
    }


}

void TmModel::deleteSelected()
{
    if(selectedList.size()<=0) return;

    QList<int> ind;
 for(int i=0;i<selectedList.size();i++)
 {
    ind.append(this->drawables->indexOf(this->selectedList.at(i)->second));
 }
 qSort(ind);
 for(int i=ind.size()-1;i>=0;i--)
 {
   drawables->removeAt(ind.at(i));
 }
 selectedList.clear();
 if(selectedGroup==-1) return;
 selectedGroups.removeOne(selectedGroup);
 QList<QPair<int,DrawableComponent *> *> *l=groups.at(selectedGroup);
int gn=selectedGroup;
qDebug()<< groups.size()<<"sabse phle detele mai";
 groups.removeAt(selectedGroup);
 for(int i=0;i<l->size();i++)
 {
     for(int k=gn-1;k>=0;k--)
     {
          QList<QPair<int,DrawableComponent *>*> *l2=groups.at(k);
         for(int j=0;j<l2->size();j++)
         {
             if(l->at(i)->first==l2->at(j)->first)
             {
                 groups.removeAt(k);
                 gn--;
                 qDebug()<< groups.size()<<"loop ke andar delete";
                 break;
             }
         }
     }
 }

 for(int k=groups.size()-1-1;k>=0;k--)
 {
      QList<QPair<int,DrawableComponent *>*> *l2=groups.at(k);
     for(int j=0;j<l2->size();j++)
     {
         l2->at(j)->first=drawables->indexOf(l2->at(j)->second);
     }
 }
selectedGroup=-1;


}


int TmModel::getControllKey() const
{
    return controllKey;
}

void TmModel::setControllKey(int value)
{
    controllKey = value;
}

void TmModel::open(QJsonArray &arr)
{
    drawables->clear();
    selectedGroups.clear();
    groups.clear();
    selectedGroup=-1;
    selectedList.clear();
    for(int i=0;i<arr.size();i++)
    {
        QJsonObject obj=arr.at(i).toObject();

       int code=obj["code"].toInt();
       if(code==1)
       {
        LinesCompoent *comp=new LinesCompoent();
        QJsonArray arr2=obj["points"].toArray();
        for(int k=0;k<arr2.size();k++)
        {
            QJsonObject ob=arr2.at(k).toObject();
            comp->append(new QPoint(ob["x"].toInt(),ob["y"].toInt()));
        }
        QPen *p=new QPen();
        p->setColor(obj["color"].toString());
        p->setWidth(obj["pwidth"].toInt());
        comp->setPen(p);
        drawables->append(comp);

       }
       else
           if(code==2)
           {
            LineComponent *comp=new LineComponent();
            comp->setX(obj["x"].toInt());
            comp->setX2(obj["x2"].toInt());
            comp->setY(obj["y"].toInt());
            comp->setY2(obj["y2"].toInt());
            QPen *p=new QPen();
            p->setColor(obj["color"].toString());
            p->setWidth(obj["pwidth"].toInt());
            comp->setPen(p);
            drawables->append(comp);

           }
       else
           if(code==3)
               {
                RectangleComponent *rect=new RectangleComponent();
                rect->setX(obj["x"].toInt());
                rect->setY(obj["y"].toInt());
                rect->setWidth(obj["width"].toInt());
                rect->setHeight(obj["height"].toInt());
                QPen *p=new QPen();
                p->setColor(obj["color"].toString());
                p->setWidth(obj["pwidth"].toInt());
                rect->setPen(p);
                drawables->append(rect);

               }
       else
               if(code==4)
               {
                CircleComponent *comp=new CircleComponent();
                 comp->setX(obj["x"].toInt());
                 comp->setY(obj["y"].toInt());
                 comp->setRadius(obj["radius"].toDouble());
                QPen *p=new QPen();
                p->setColor(obj["color"].toString());
                p->setWidth(obj["pwidth"].toInt());
                comp->setPen(p);
                drawables->append(comp);

               }
       else
                   if(code==5)
                   {
                   EllipseComponent *comp=new EllipseComponent();
                   comp->setX(obj["x"].toInt());
                   comp->setY(obj["y"].toInt());
                   comp->setWidth(obj["width"].toDouble());
                   comp->setHeight(obj["height"].toDouble());
                    QPen *p=new QPen();
                    p->setColor(obj["color"].toString());
                    p->setWidth(obj["pwidth"].toInt());
                    comp->setPen(p);
                    drawables->append(comp);

                   }
       else
                       if(code==6)
                       {

                           TextComponent *comp=new TextComponent();
                           comp->setX(obj["x"].toInt());
                           comp->setY(obj["y"].toInt());
                           comp->setText(obj["text"].toString() );
                           QPen *p=new QPen();
                        p->setColor(obj["color"].toString());
                        p->setWidth(obj["pwidth"].toInt());
                        comp->setPen(p);
                        drawables->append(comp);

                       }

    }
}

void TmModel::groupSelected()
{
    QList<QPair<int,DrawableComponent *> *> *li=new QList<QPair<int,DrawableComponent *> *>(selectedList);
    groups.append(li);
    selectedGroup=groups.size()-1;
    //selectedList.clear();

}

void TmModel::ungroupSelected()
{
    for(int i=0;i<selectedGroups.size();i++)
    {
    groups.removeAt(selectedGroups.at(i));
    selectedGroups.removeAt(i);
    }
    selectedList.clear();
    selectedGroup=-1;


}

void TmModel::update(int movedX, int movedY)
{
    if(selectedList.size()!=0)
    {
        for(int i=0;i<selectedList.size();i++)
        {
            selectedList.at(i)->second->update(movedX,movedY);
        }
    }
}
void TmModel::add(DrawableComponent * Item)
{
    this->drawables->append(Item);
}
void TmModel::draw(QPainter *painter)
{
    int i=0;
   this->dsList->clear();
    DrawableComponent *d;
    for(;i<this->drawables->size();i++)
    {
     d=this->drawables->at(i);
     this->dsList->insertItem(0,d->componentName());
     //this->dsList->addItem(d->componentName());

     d->draw(painter);
    }
   /* int index=this->getSelectedInex();
    d=this->getSelectedComponent();
    if(index==-1)
    {
        return;
    }
    painter->setPen(QPen(Qt::black,3));
    d->select(painter);
*/
    painter->setPen(QPen(Qt::black,3));
    qDebug()<< "selected list sdraw mai phle";
    for(i=0;i<this->selectedList.size();i++)
    {
     d=this->selectedList.at(i)->second;
     //this->dsList->addItem(d->componentName());
     d->select(painter);

     this->dsList->item(((this->drawables->size()-1)-this->drawables->indexOf(this->selectedList.at(i)->second)))->setSelected(true);
    }

//this->dsList->((this->drawables->size()-1)-index);

}

void TmModel::addSelected(QPair<int, DrawableComponent *> *pair)
{
    selectedList.append(pair);
}

void TmModel::clearSelected()
{
    selectedList.clear();
    selectedGroups.clear();

}
