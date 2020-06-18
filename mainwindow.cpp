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
#include <QtGui>
#include <QAbstractItemView>
#include <QDesktopWidget>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->ui->canvas->setSizePolicy(QSizePolicy::Expanding,
                               QSizePolicy::Expanding);

    //this->scene->setSceneRect(this->ui->graphicsView->sceneRect());
    this->ui->textFrame->hide();
    this->ui->textFrame->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->ui->textFrame->move(QPoint(200,200));
    this->ui->toolbox->setMinimumHeight(820);
    this->ui->dslistbox->setMinimumHeight(810);
    this->resize(QDesktopWidget().availableGeometry(this).size()* 1);
    setFixedSize(QDesktopWidget().availableGeometry(this).size()* 1);
     this->ui->background->resize(QDesktopWidget().availableGeometry(this).size()* 1);
     double width=this->width()-245;
     double height=this->height();
     this->ui->canvas->resize(width,height);
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

    this->ui->line->setIcon(QIcon(":/images/line.png"));
    this->ui->ellipsepush->setIcon(QIcon(":/images/oval.png"));
    this->ui->circle->setIcon(QIcon(":/images/plain.png"));
    this->ui->polylinedraw->setIcon(QIcon(":/images/pencil.png"));
    this->ui->S_and_M->setIcon(QIcon(":/images/move.png"));
    this->ui->textDraw_5->setIcon(QIcon(":/images/rectangle.png"));
    this->ui->textDraw->setIcon(QIcon(":/images/text.png"));


    this->ui->Clear->setIcon(QIcon(":/images/cross.png"));
    this->ui->Save->setIcon(QIcon(":/images/save.png"));
    this->ui->open->setIcon(QIcon(":/images/book.png"));
      this->ui->del->setIcon(QIcon(":/images/bin.png"));
     this->ui->group->setIcon(QIcon(":/images/group.png"));
     this->ui->ungroup->setIcon(QIcon(":/images/ungroup.png"));
    this->ui->c1->setStyleSheet("background-color: red");
    this->ui->c2->setStyleSheet("background-color: black");
    this->ui->c3->setStyleSheet("background-color: yellow");
    this->ui->c4->setStyleSheet("background-color: green");
    this->ui->c5->setStyleSheet("background-color: blue");
    this->ui->c6->setStyleSheet("background-color: brown");
    this->ui->c7->setStyleSheet("background-color: gray");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_textDraw_clicked()
{
this->ui->textFrame->show();


}
void MainWindow::paintEvent(QPaintEvent *paint)
{


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

    this->ui->canvas->setMode(1);
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
    this->ui->canvas->model->add(t);

    this->ui->canvas->update();
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
   this->ui->canvas->setMode(3);
}

void MainWindow::on_circle_clicked()
{
this->ui->canvas->setMode(4);
}

void MainWindow::on_line_clicked()
{
this->ui->canvas->setMode(2);
}

void MainWindow::on_S_and_M_clicked()
{
this->ui->canvas->setMode(0);
}

void MainWindow::on_DsList_itemClicked(QListWidgetItem *item)
{
    QModelIndexList il=this->ui->DsList->selectionModel()->selectedIndexes();
   this->ui->canvas->selectAll(il);
    //this->ui->canvas->model->setSelectedInex(this->ui->canvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow());
    //this->ui->canvas->model->setSelectedComponent();
   this->ui->canvas->setMode(0);
}

void MainWindow::on_c1_clicked()
{
    this->ui->canvas->setColor(Qt::red);
}

void MainWindow::on_c2_clicked()
{
     this->ui->canvas->setColor(Qt::black);
}

void MainWindow::on_c3_clicked()
{
     this->ui->canvas->setColor(Qt::yellow);
}

void MainWindow::on_c4_clicked()
{
     this->ui->canvas->setColor(Qt::green);
}

void MainWindow::on_c5_clicked()
{
     this->ui->canvas->setColor(Qt::blue);
}

void MainWindow::on_c6_clicked()
{
     this->ui->canvas->setColor(*(new QColor(139,69,19)));
}

void MainWindow::on_c7_clicked()
{
     this->ui->canvas->setColor(Qt::gray);
}

void MainWindow::on_penWidth_valueChanged(int arg1)
{
    qDebug()<<arg1<<"   *args*";
    this->ui->canvas->setPenWidth(arg1);
}

void MainWindow::on_undo_clicked()
{
    this->ui->canvas->model->undo();
    update();
}

void MainWindow::on_redo_clicked()
{
    this->ui->canvas->model->redo();
    update();
}

void MainWindow::on_ellipsepush_clicked()
{
    this->ui->canvas->setMode(5);
}

void MainWindow::on_Clear_clicked()
{
this->ui->canvas->clear();
    update();
}

void MainWindow::on_Save_clicked()
{

QString fileName = QFileDialog::getSaveFileName(this, ("Save File"),"/home",("text (*.txt)"));
if(fileName!=NULL)
{
 QString jsonS=this->ui->canvas->save();
 QFile file(fileName);
 if(file.exists())
 {
 file.remove();
 }
     if (file.open(QIODevice::ReadWrite)) {

         QTextStream stream(&file);
         stream <<jsonS<< endl;
     }
}
}

void MainWindow::on_open_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, ("Open File"), "/home",("text (*.txt)"));
    if(fileName!=NULL)
    {
     QFile file(fileName);
     if(file.open(QIODevice::ReadOnly))
     {
         QTextStream stream(&file);
         QString str= stream.readAll();
         QJsonDocument *d=new QJsonDocument();
         QJsonArray arr=(d->fromJson(str.toUtf8())).array();
         this->ui->canvas->open(arr);
     }
    qDebug()<<"open call hua";
    }

}

void MainWindow::on_DsList_itemSelectionChanged()
{


   //this->ui->canvas->select(this->ui->canvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow(),this->ui->canvas->model->getDrawables()->at(this->ui->canvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow()));

}

void MainWindow::on_group_clicked()
{
    this->ui->canvas->groupSelected();
}

void MainWindow::on_ungroup_clicked()
{
    this->ui->canvas->ungroupSelected();
}

void MainWindow::on_del_clicked()
{
    this->ui->canvas->model->deleteSelected();
    this->ui->canvas->update();
}
