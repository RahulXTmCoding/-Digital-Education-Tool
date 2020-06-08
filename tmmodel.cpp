#include "tmmodel.h"

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
    bool found=false;
    for(int i=this->drawables->length()-1;i>=0;i--)
    {
        d=this->drawables->at(i);
        bool result=d->isClicked(point);
        if(result)
        {
            found=true;
            this->setSelectedInex(i);
            this->setSelectedComponent(d);
            break;
        }

    }
    if(found==false)
    {
        this->setSelectedInex(-1);
        this->setSelectedComponent(NULL);
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
    if(this->drawables->size()>0)
    {
        DrawableComponent *temp=this->drawables->last();
      this->tempDrawables->append(temp);
    this->drawables->pop_back();
    }

}

void TmModel::redo()
{
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
     qDebug()<<i<<"       *";
     d->draw(painter);
    }
    int index=this->getSelectedInex();
    d=this->getSelectedComponent();
    if(index==-1)
    {
        return;
    }
    painter->setPen(Qt::DefaultContextMenu);
    d->select(painter);
    this->dsList->setCurrentRow((this->drawables->size()-1)-index);

}
