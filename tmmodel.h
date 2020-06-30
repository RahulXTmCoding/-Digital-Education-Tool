#ifndef TMMODEL_H
#define TMMODEL_H
#include "drawablecomponent.h"
#include <QList>
#include <QListWidget>
#include "textcomponent.h"
#include <QPair>
#include "linescompoent.h"
#include "ellipsecomponent.h"
#include "rectanglecomponent.h"
#include "linecomponent.h"
#include "pixmapcomponent.h"
#include "circlecomponent.h"
#include "amodel.h"
class TmModel:public AModel
{
private:
    QList<DrawableComponent *> *drawables;

    QList<DrawableComponent *> *tempDrawables;

    QListWidget *dsList;
    QList<QPair<int, DrawableComponent *> *> selectedList;
    int selectedInex=-1;
    QList<QList<QPair<int,DrawableComponent *> *> *> groups;
    QList<int> selectedGroups;
    int selectedGroup=-1;
    DrawableComponent *selectedComponent=NULL;
    int initialX;
    int initialY;
public:
    TmModel();
    void drawPixmap(QString path);
    void clear();
    void changeComponentName(QString name,QModelIndexList li);
    QJsonObject * save();
    void selectAll(QModelIndexList il);
    void deleteSelected();
    int controllKey=-1;
    int shiftKey=-1;
    void open(QJsonArray &arr);
    void groupSelected();
    void ungroupSelected();
    void update(int,int);
    void add(DrawableComponent *);
    void draw(QPainter *);
    void addSelected(QPair<int,DrawableComponent *> *);
    void clearSelected();
    void setDsList(QListWidget *value);
    QListWidget *getDsList() const;
    int getSelectedInex() const;
    void setSelectedInex(int value);
    DrawableComponent *getSelectedComponent() const;
    void setSelectedComponent(DrawableComponent *value);
    void findClicked(QPoint *);
     void clickedRemove(QPoint *);
     bool selection=false;
    QList<DrawableComponent *> *getDrawables() const;
    int getInitialX() const;
    void setInitialX(int value);
    int getInitialY() const;
    void setInitialY(int value);
    void undo();
    void redo();
    int getControllKey() const;
    void setControllKey(int value);
    int getShiftKey();
    void setShiftKey(int value);
};

#endif // TMMODEL_H
