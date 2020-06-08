#ifndef TMMODEL_H
#define TMMODEL_H
#include "drawablecomponent.h"
#include <QList>
#include <QListWidget>
class TmModel
{
private:
    QList<DrawableComponent *> *drawables;

    QList<DrawableComponent *> *tempDrawables;

    QListWidget *dsList;
    int selectedInex=-1;
    DrawableComponent *selectedComponent=NULL;
    int initialX;
    int initialY;
public:
    TmModel();
    void add(DrawableComponent *);
    void draw(QPainter *);
    void setDsList(QListWidget *value);
    QListWidget *getDsList() const;
    int getSelectedInex() const;
    void setSelectedInex(int value);
    DrawableComponent *getSelectedComponent() const;
    void setSelectedComponent(DrawableComponent *value);
    void findClicked(QPoint *);
    QList<DrawableComponent *> *getDrawables() const;
    int getInitialX() const;
    void setInitialX(int value);
    int getInitialY() const;
    void setInitialY(int value);
    void undo();
    void redo();
};

#endif // TMMODEL_H
