#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include "textcomponent.h"
#include "tmmodel.h"
#include "linescompoent.h"
#include "ellipsecomponent.h"
#include <QDebug>
#include <QFileDialog>
#include <QJsonDocument>
#include <QtWidgets>
#include <QAbstractItemView>
#include <QDesktopWidget>

#include <QColorDialog>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->ui->canvas->setSizePolicy(QSizePolicy::Expanding,
                               QSizePolicy::Expanding);

    //this->scene->setSceneRect(this->ui->graphicsView->sceneRect());
    canvasList=new QList<Canvas *>();
    radioList=new QList<QRadioButton *>();
    listWidgets=new QList<QListWidget *>();
    listWidgets->append(this->ui->DsList);
    radioList->append(this->ui->ff);
    this->ui->ff->setChecked(true);
    this->ui->frameRadio->setFrameStyle(QFrame::NoFrame);
    canvasList->append(this->ui->canvas);
    selectedCanvas=this->ui->canvas;
    this->ui->textFrame->hide();
    this->ui->textFrame->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->ui->textFrame->move(QPoint(200,200));
    this->ui->toolbox->setMinimumHeight(820);
    this->ui->dslistbox->setMinimumHeight(810);
    this->resize(QDesktopWidget().availableGeometry(this).size()* 1);
    setFixedSize(QDesktopWidget().availableGeometry(this).size()* 1);
     this->ui->background->resize(QDesktopWidget().availableGeometry(this).size()* 1);
     double width=(this->width())-310;
     double height=this->height()*.9;
     this->ui->canvas->setFixedWidth(width);
     this->ui->canvas->setFixedHeight(height);
 this->ui->colourFrame->setFrameStyle(QFrame::NoFrame);
      this->ui->toolFramef->setFrameStyle(QFrame::NoFrame);

     this->ui->frameRadio->resize(width,this->ui->frameRadio->height());
     this->ui->dslistbox->move(this->ui->canvas->width()+this->ui->canvas->x()+5,3);
     this->ui->dslistbox->resize(this->ui->dslistbox->width(),this->ui->canvas->height());
     this->ui->DsList->resize(this->ui->DsList->width(),this->ui->canvas->height());
     this->ui->toolbox->resize(this->ui->toolbox->width(),this->ui->canvas->height());
     this->ui->toolL->move(16,9);
    this->ui->canvas->model->setDsList(this->ui->DsList);
    this->ui->canvas->c_x=this->ui->canvas->x();
    this->ui->canvas->c_y=this->ui->canvas->y();
    this->ui->canvas->c_width=this->ui->canvas->width();
    this->ui->canvas->c_height=this->ui->canvas->height();
    this->ui->DsList->setSelectionMode(QAbstractItemView::ExtendedSelection);
     QObject::connect(this->ui->ff, &QRadioButton::clicked, this, &MainWindow::changeCanvas);
    this->ui->line->setIcon(QIcon(":/images/line.png"));
    this->ui->line->setIconSize(this->ui->line->size());
     this->ui->ellipsepush->setIcon(QIcon(":/images/oval.png"));
    this->ui->ellipsepush->setIconSize(this->ui->ellipsepush->size());
     this->ui->circle->setIcon(QIcon(":/images/plain.png"));
     this->ui->circle->setIconSize(this->ui->circle->size());
    this->ui->polylinedraw->setIcon(QIcon(":/images/pencil.png"));\
     this->ui->polylinedraw->setIconSize(this->ui->polylinedraw->size());
    this->ui->S_and_M->setIcon(QIcon(":/images/move.png"));
     this->ui->S_and_M->setIconSize(this->ui->S_and_M->size());
    this->ui->textDraw_5->setIcon(QIcon(":/images/rectangle.png"));
     this->ui->textDraw_5->setIconSize(this->ui->textDraw_5->size());
    this->ui->textDraw->setIcon(QIcon(":/images/text.png"));
this->ui->textDraw->setIconSize(this->ui->textDraw->size());

   this->ui->new_canvas->setIcon(QIcon(":/images/portable-document-format.png"));
     this->ui->new_canvas->setIconSize(this->ui->new_canvas->size());
     this->ui->recording->setIcon(QIcon(":/images/record.png"));
this->ui->recording->setIconSize(this->ui->recording->size());
     this->ui->stop_recording->setIcon(QIcon(":/images/stop.png"));
this->ui->stop_recording->setIconSize(this->ui->stop_recording->size());
   this->ui->colourgradient->setIcon(QIcon(":/images/pride.png"));
this->ui->colourgradient->setIconSize(this->ui->colourgradient->size());
    this->ui->Clear->setIcon(QIcon(":/images/cross.png"));
     this->ui->Clear->setIconSize(this->ui->Clear->size());
    this->ui->Save->setIcon(QIcon(":/images/save.png"));
     this->ui->Save->setIconSize(this->ui->Save->size());

    this->ui->open->setIcon(QIcon(":/images/book.png"));
     this->ui->open->setIconSize(this->ui->open->size());
     this->ui->del->setIcon(QIcon(":/images/bin.png"));
     this->ui->del->setIconSize(this->ui->del->size());
     this->ui->group->setIcon(QIcon(":/images/group.png"));
     this->ui->group->setIconSize(this->ui->group->size());
     this->ui->ungroup->setIcon(QIcon(":/images/ungroup.png"));
     this->ui->ungroup->setIconSize(this->ui->ungroup->size());


     this->ui->physics_drawings->setIcon(QIcon(":/images/physic2.png"));
      this->ui->physics_drawings->setIconSize(this->ui->physics_drawings->size());

     this->ui->undo->setIcon(QIcon(":/images/undo.png"));
      this->ui->undo->setIconSize(this->ui->undo->size());
      this->ui->redo->setIcon(QIcon(":/images/redo.png"));
      this->ui->redo->setIconSize(this->ui->redo->size());
      this->ui->pixmap->setIcon(QIcon(":/images/photo.png"));
      this->ui->pixmap->setIconSize(this->ui->pixmap->size());

     this->ui->close_physics_book->setIcon(QIcon(":/images/close.png"));
      this->ui->close_physics_book->setIconSize(this->ui->close_physics_book->size());

    this->ui->c1->setStyleSheet("background-color: red");
    this->ui->c2->setStyleSheet("background-color: black");
    this->ui->c3->setStyleSheet("background-color: yellow");
    this->ui->c4->setStyleSheet("background-color: green");
    this->ui->c5->setStyleSheet("background-color: blue");
    this->ui->c6->setStyleSheet("background-color: brown");
    this->ui->c7->setStyleSheet("background-color: gray");

     this->ui->DsList->setContextMenuPolicy(Qt::CustomContextMenu);
     //connect(this->ui->DsList, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
      QObject::connect(this->ui->DsList,&QWidget::customContextMenuRequested , this, &MainWindow::showContextMenu);
     int yy=this->ui->toolbox->height()-(this->ui->toolFramef->y()+this->ui->toolFramef->height());
     int rr=yy-this->ui->colourFrame->height();
     this->ui->colourFrame->move(this->ui->colourFrame->x(),this->ui->toolFramef->y()+this->ui->toolFramef->height()+rr+30);


/*

     this->setStyleSheet("background-color: black;");
     this->ui->toolbox->setStyleSheet("background-color:  #ebebe0;");
    this->ui->dslistbox->setStyleSheet("background-color:  #ebebe0;");
    this->ui->frameRadio->setStyleSheet("background-color:white");
  this->ui->toolL->setStyleSheet("background-color:  #ebebe0;");
*/
this->ui->physics_book_frame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
this->ui->physics_book_frame->layout=new QGridLayout();
this->ui->physics_book_frame->populateDs();
this->ui->physics_book_frame->setLayout(this->ui->physics_book_frame->layout);

this->ui->physics_book_frame->c=this->ui->canvas;




     this->scroll=new QScrollArea(this);
       this->scroll->setWidget(this->ui->physics_book_frame);
       this->scroll->viewport()->setAutoFillBackground(true);
       this->scroll->setWindowTitle(QObject::tr("Icon Editor"));
       this->scroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
       this->scroll->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
       this->scroll->move(this->ui->physics_drawings->x()+140,this->ui->physics_drawings->y()+90);
     this->scroll->resize(781,321);
     this->scroll->hide();

 closeButton=new QPushButton(this);
 closeButton->setIcon(QIcon(":/images/close.png"));
 closeButton->resize(this->ui->close_physics_book->size());
  closeButton->setIconSize(this->ui->close_physics_book->size());
  closeButton->move(this->scroll->x()-25,this->scroll->y()-25);
    closeButton->show();
  QRegion region(this->ui->close_physics_book->rect(), QRegion::Ellipse);
        qDebug() << region.boundingRect().size();

        closeButton->setMask(region);
        this->ui->close_physics_book->hide();
          QObject::connect(closeButton,SIGNAL(clicked()), this, SLOT(on_close_physics_book_clicked()));
         this->closeButton->hide();

  this->scroll->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool | Qt::WindowStaysOnTopHint);

          this->closeButton->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool  | Qt::WindowStaysOnTopHint);




}

void MainWindow::showContextMenu(const QPoint &pos)
{

    QPoint globalPos = this->listWidgets->at(selectedCanvasIndex)->mapToGlobal(pos);


    QMenu myMenu(this);
    auto *a=myMenu.addAction("edit");
    QObject::connect(a,&QAction::triggered, this, &MainWindow::editQList);
    auto *a2=myMenu.addAction("delete");
  QObject::connect(a2,&QAction::triggered, this, &MainWindow::deleteQList);

    myMenu.exec(globalPos);
}


void MainWindow::editQList()
{
    //this->listWidgets->at(selectedCanvasIndex)->selectedIndexes()
    QModelIndexList il=this->listWidgets->at(selectedCanvasIndex)->selectionModel()->selectedIndexes();
    QString text = QInputDialog::getText(this,"QList Edit","Enter Component Name:");
    if(text=="") return ;
    qDebug()<<text;
    this->selectedCanvas->changeComponentName(text,il);
}

void MainWindow::deleteQList()
{
    QModelIndexList il=this->listWidgets->at(selectedCanvasIndex)->selectionModel()->selectedIndexes();
    selectedCanvas->selectAll(il);
    //selectedCanvas->model->setSelectedInex(selectedCanvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow());
    //selectedCanvas->model->setSelectedComponent();
    selectedCanvas->setMode(0);
    selectedCanvas->model->deleteSelected();
    selectedCanvas->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textDraw_clicked()
{
this->ui->textFrame->show();


}


void MainWindow::resizeEvent(QResizeEvent *event)
{

    this->ui->background->resize(this->size()* 1);
    double width=this->width()-245;
    double height=this->height()*.9;
    this->ui->canvas->resize(width,height);
    this->ui->dslistbox->move(this->ui->canvas->width()+this->ui->canvas->x()+5,3);
    this->ui->dslistbox->resize(this->ui->dslistbox->width(),height+18);
    this->ui->DsList->resize(this->ui->DsList->width(),height+18);
    this->ui->toolbox->resize(this->ui->toolbox->width(),height+28);
   this->ui->canvas->c_x=this->ui->canvas->x();
   this->ui->canvas->c_y=this->ui->canvas->y();
   this->ui->canvas->c_width=this->ui->canvas->width();
   this->ui->canvas->c_height=this->ui->canvas->height();

    qDebug()<<this->ui->canvas->height()<<"     "<<this->ui->toolbox->height()<<"    "<<this->ui->dslistbox->height();

}





void MainWindow::on_polylinedraw_clicked()
{

    selectedCanvas->setMode(1);
     qDebug() << "poly lines pe click";
   // this->ui->polyLines->show();
   // this->points=new QList<QPoint *>();

}

void MainWindow::on_Draw_Text_clicked()
{

    TextComponent *t=new TextComponent();
    t->setFont(new QFont(this->ui->Font_family_text->currentText(),this->ui->text_font_size->text().toInt()));
    QString color=this->ui->color_text->currentText();
    if(color=="red")
    {
    t->setPen(new QPen(QBrush(Qt::red),this->ui->PenwidthText->text().toFloat()));
    }
    else
    if(color=="black")
    {
    t->setPen(new QPen(QBrush(Qt::black),this->ui->PenwidthText->text().toFloat()));
    }
    else
    if(color=="blue")
    {
    t->setPen(new QPen(QBrush(Qt::blue),this->ui->PenwidthText->text().toFloat()));
    }else
        if(color=="yellow")
        {
        t->setPen(new QPen(QBrush(Qt::yellow),this->ui->PenwidthText->text().toFloat()));
        }
        else
        if(color=="pink")
        {
        t->setPen(new QPen(QBrush(Qt::PinchGesture),this->ui->PenwidthText->text().toFloat()));
        }
        else
        if(color=="green")
        {
        t->setPen(new QPen(QBrush(Qt::green),this->ui->PenwidthText->text().toFloat()));
        }
    t->setText(this->ui->text_string->toPlainText());
    t->setX(this->ui->X_CORD_text->text().toFloat());
    t->setY(this->ui->Y_CORD_text->text().toFloat());
    selectedCanvas->model->add(t);

    selectedCanvas->update();
    this->ui->textFrame->hide();
    this->ui->text_font_size->clear();
    this->ui->X_CORD_text->clear();
    this->ui->Y_CORD_text->clear();
    this->ui->PenwidthText->clear();
    this->ui->text_string->clear();
}

void MainWindow::on_cancle_text_clicked()
{

    this->ui->textFrame->hide();
    this->ui->text_font_size->clear();
    this->ui->X_CORD_text->clear();
    this->ui->Y_CORD_text->clear();
    this->ui->PenwidthText->clear();
    this->ui->text_string->clear();

}



void MainWindow::on_textDraw_5_clicked()
{
   selectedCanvas->setMode(3);
}

void MainWindow::on_circle_clicked()
{
selectedCanvas->setMode(4);
}

void MainWindow::on_line_clicked()
{
selectedCanvas->setMode(2);
}

void MainWindow::on_S_and_M_clicked()
{
selectedCanvas->setMode(0);
}

void MainWindow::on_DsList_itemClicked(QListWidgetItem *item)
{

    QModelIndexList il=this->listWidgets->at(selectedCanvasIndex)->selectionModel()->selectedIndexes();
   selectedCanvas->selectAll(il);
    //selectedCanvas->model->setSelectedInex(selectedCanvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow());
    //selectedCanvas->model->setSelectedComponent();
   selectedCanvas->setMode(0);
}

void MainWindow::on_c1_clicked()
{
    selectedCanvas->setColor(Qt::red);
}

void MainWindow::on_c2_clicked()
{
     selectedCanvas->setColor(Qt::black);
}

void MainWindow::on_c3_clicked()
{
     selectedCanvas->setColor(Qt::yellow);
}

void MainWindow::on_c4_clicked()
{
     selectedCanvas->setColor(Qt::green);
}

void MainWindow::on_c5_clicked()
{
     selectedCanvas->setColor(Qt::blue);
}

void MainWindow::on_c6_clicked()
{
     selectedCanvas->setColor(*(new QColor(139,69,19)));
}

void MainWindow::on_c7_clicked()
{
     selectedCanvas->setColor(Qt::gray);
}

void MainWindow::on_penWidth_valueChanged(int arg1)
{
    qDebug()<<arg1<<"   *args*";
    selectedCanvas->setPenWidth(arg1);
}

void MainWindow::on_undo_clicked()
{
    selectedCanvas->model->undo();
    update();
}

void MainWindow::on_redo_clicked()
{
    selectedCanvas->model->redo();
    update();
}

void MainWindow::on_ellipsepush_clicked()
{
    selectedCanvas->setMode(5);
}

void MainWindow::on_Clear_clicked()
{
selectedCanvas->clear();
    update();
}

void MainWindow::on_Save_clicked()
{

QString fileName = QFileDialog::getSaveFileName(this, ("Save File"),"/home",("text (*.ppad)"));
if(fileName.endsWith(".ppad")==false)
{
    if(fileName.endsWith("."))
    {
        fileName+="ppad";
    }
    else
    {
        fileName+=".ppad";
    }
}
if(fileName!=NULL)
{
 QJsonArray ja;
 for(int i=0;i<canvasList->size();i++)
 {
     ja.append(*(canvasList->at(i)->save()));
 }
 QJsonDocument jd(ja);
 QFile file(fileName);
 if(file.exists())
 {
 file.remove();
 }
     if (file.open(QIODevice::ReadWrite)) {

         QTextStream stream(&file);
         stream <<jd.toJson()<< endl;
     }
}
}

void MainWindow::on_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, ("Open File"), "/home",("text (*.ppad)"));
    if(fileName!=NULL)
    {
     QFile file(fileName);
     if(file.open(QIODevice::ReadOnly))
     {
         QTextStream stream(&file);
         QString str= stream.readAll();
         QJsonDocument *d=new QJsonDocument();
         QJsonArray arr=(d->fromJson(str.toUtf8())).array();
         int canvasListSize=canvasList->size();
         int jarrSize=arr.size();
         int i=0;
         for(i=0;i<canvasListSize && i<jarrSize;i++)
         {
             qDebug()<<i;
          QJsonObject obj=arr.at(i).toObject();
          QJsonArray arr2=obj["canvas"].toArray();
          canvasList->at(i)->open(arr2);
         }
         if(jarrSize>canvasListSize)
         {
           for(i;i<jarrSize;i++)
           {
           on_new_canvas_clicked();
           QJsonObject obj=arr.at(selectedCanvasIndex).toObject();
           QJsonArray arr2=obj["canvas"].toArray();

           selectedCanvas->open(arr2);

         }
           selectedCanvas->hide();
           listWidgets->at(selectedCanvasIndex)->hide();
         selectedCanvasIndex=0;
         selectedCanvas=this->ui->canvas;
         selectedCanvas->show();
         radioList->at(selectedCanvasIndex)->setChecked(true);
         listWidgets->at(selectedCanvasIndex)->show();
         }
         else
         {
             int lim=i;
             for(i=canvasListSize-1;i>=lim;i--)
             {
                 qDebug()<<i<<"   extra one";
                 Canvas *c=canvasList->at(i);
                 canvasList->removeAt(i);
                 c->hide();
                 QRadioButton* r=radioList->at(i);
                 radioList->removeAt(i);
                 r->hide();
                 QListWidget *w=listWidgets->at(i);
                 listWidgets->removeAt(i);
                 w->hide();

             }
           selectedCanvasIndex=0;
           selectedCanvas=this->ui->canvas;
           selectedCanvas->show();
           radioList->at(selectedCanvasIndex)->setChecked(true);
           listWidgets->at(selectedCanvasIndex)->show();
         }
     }

    }

}

void MainWindow::on_DsList_itemSelectionChanged()
{


   //selectedCanvas->select(selectedCanvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow(),selectedCanvas->model->getDrawables()->at(selectedCanvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow()));

}

void MainWindow::on_group_clicked()
{
    selectedCanvas->groupSelected();
}

void MainWindow::on_ungroup_clicked()
{
    selectedCanvas->ungroupSelected();
}

void MainWindow::on_del_clicked()
{
    selectedCanvas->model->deleteSelected();
    selectedCanvas->update();
}

void MainWindow::on_new_canvas_clicked()
{
    Canvas *c=new Canvas(this);

    double width=this->ui->canvas->width();
    double height=this->ui->canvas->height();

    c->move(this->ui->canvas->x(),this->ui->canvas->y());
    c->setFixedWidth(width);
    c->setFixedHeight(height);
    canvasList->append(c);
    QListWidget *w=new QListWidget(this->ui->dslistbox);
    w->move(this->ui->DsList->x(),this->ui->DsList->y());
    w->resize(this->ui->DsList->width(),this->ui->canvas->height());
    listWidgets->append(w);
    listWidgets->at(selectedCanvasIndex)->hide();
     w->setSelectionMode(QAbstractItemView::ExtendedSelection);
     w->setContextMenuPolicy(Qt::CustomContextMenu);
       QObject::connect(w,&QWidget::customContextMenuRequested , this, &MainWindow::showContextMenu);
     //connect(this->ui->DsList, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
     QObject::connect(w, &QListWidget::itemClicked, this, &MainWindow::on_DsList_itemClicked);
    w->show();
    c->model->setDsList(w);
    selectedCanvas->hide();
    selectedCanvas=c;
    c->show();
    QRadioButton *r=new QRadioButton(this->ui->frameRadio);
    radioList->append(r);
    radioList->at(selectedCanvasIndex)->setChecked(false);
    r->setChecked(true);
    selectedCanvasIndex=radioList->size()-1;
    r->move(radioList->at(radioList->size()-2)->x()+20,this->ui->ff->y()+4);
    r->show();
    //r->connect(r,&(QRadioButton::clicked()),this,SLOT(changeCanvas()));
    QObject::connect(r, &QRadioButton::clicked, this, &MainWindow::changeCanvas);
    this->ui->physics_book_frame->c=selectedCanvas;
}

void MainWindow::changeCanvas()
{
qDebug()<<"chal chla";

    for(int i=0;i<radioList->size();i++)
    {
        if(radioList->at(i)->isChecked())
        {
            selectedCanvasIndex=i;
            break;
        }
    }

    for(int i=0;i<canvasList->size();i++)
    {
        if(i==selectedCanvasIndex)
        {
            canvasList->at(i)->show();
        }
        else
        {
            canvasList->at(i)->hide();
        }
    }

    for(int i=0;i<listWidgets->size();i++)
    {
        if(i==selectedCanvasIndex)
        {
            listWidgets->at(i)->show();
        }
        else
        {
            listWidgets->at(i)->hide();
        }
    }
    selectedCanvas=canvasList->at(selectedCanvasIndex);
    this->ui->physics_book_frame->c=selectedCanvas;

}

void MainWindow::on_ff_clicked()
{

}

void MainWindow::on_pixmap_clicked()
{

    QString fileName = QFileDialog::getOpenFileName(this, ("Select Image"), "/home",("image (*.*)"));
    if(fileName==NULL)
    {
        return;
    }
  selectedCanvas->drawPixmap(fileName);
}

void MainWindow::on_colourgradient_clicked()
{
    QColor color=QColorDialog::getColor(Qt::black,this);
    if(color.isValid())
    {
        selectedCanvas->setColor(color);
    }

}

void MainWindow::on_recording_clicked()
{

}

void MainWindow::on_stop_recording_clicked()
{

}

void MainWindow::on_physics_drawings_clicked()
{
//this->ui->physics_book_frame->show();
    //this->ui->physics_area->show();

    //this->ui->physics_book_frame2->show();

this->scroll->show();
 this->closeButton->show();


}

void MainWindow::on_close_physics_book_clicked()
{
    this->scroll->hide();
    this->closeButton->hide();
   // this->ui->physics_area->hide();
    //this->ui->close_physics_book->hide();
   // this->ui->physics_book_frame2->hide();
}
