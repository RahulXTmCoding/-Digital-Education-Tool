#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPaintEvent>
#include "textcomponent.h"
#include "tmmodel.h"
#include "linescompoent.h"
#include "ellipsecomponent.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //this->scene->setSceneRect(this->ui->graphicsView->sceneRect());
    this->ui->textFrame->hide();
    this->ui->textFrame->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->ui->textFrame->move(QPoint(200,200));
    this->ui->polyLines->hide();
    this->ui->polyLines->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->ui->polyLines->move(QPoint(200,200));
    this->ui->canvas->model->setDsList(this->ui->DsList);
    this->ui->canvas->c_x=this->ui->canvas->x();
    this->ui->canvas->c_y=this->ui->canvas->y();
    this->ui->canvas->c_width=this->ui->canvas->width();
    this->ui->canvas->c_height=this->ui->canvas->height();
    this->ui->EllipseFrame->hide();
    this->ui->EllipseFrame->setWindowFlags(Qt::Popup | Qt::FramelessWindowHint);
    this->ui->EllipseFrame->move(QPoint(200,200));
    this->ui->line->setIcon(QIcon(":/images/line.png"));
    this->ui->elipse->setIcon(QIcon(":/images/oval.png"));
    this->ui->circle->setIcon(QIcon(":/images/plain.png"));
    this->ui->polylinedraw->setIcon(QIcon(":/images/pencil.png"));
    this->ui->S_and_M->setIcon(QIcon(":/images/move.png"));
    this->ui->textDraw_5->setIcon(QIcon(":/images/rectangle.png"));
    this->ui->textDraw->setIcon(QIcon(":/images/text.png"));

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

void MainWindow::on_addPoints_clicked()
{
this->points->append(new QPoint(this->ui->newPointXpolyLine->text().toFloat(),this->ui->newPointYpolyLine->text().toFloat()));
 this->ui->newPointXpolyLine->clear();
    this->ui->newPointYpolyLine->clear();
}

void MainWindow::on_DrawLines_clicked()
{
    if(this->points->size()<=1)
    {
        return;
    }
    LinesCompoent *lc=new LinesCompoent();
    lc->setPoints(this->points);
    QString color=this->ui->polyColor->currentText();
    if(color=="red")
    {
    lc->setPen(new QPen(QBrush(Qt::red),this->ui->PenwidthpolyLine->text().toFloat()));
    }
    else
    if(color=="black")
    {
    lc->setPen(new QPen(QBrush(Qt::black),this->ui->PenwidthpolyLine->text().toFloat()));
    }
    else
    if(color=="blue")
    {
    lc->setPen(new QPen(QBrush(Qt::blue),this->ui->PenwidthpolyLine->text().toFloat()));
    }else
    if(color=="yellow")
    {
     lc->setPen(new QPen(QBrush(Qt::yellow),this->ui->PenwidthpolyLine->text().toFloat()));
    }
     else
     if(color=="pink")
     {
     lc->setPen(new QPen(QBrush(Qt::PinchGesture),this->ui->PenwidthpolyLine->text().toFloat()));
     }
     else
     if(color=="green")
     {
     lc->setPen(new QPen(QBrush(Qt::green),this->ui->PenwidthpolyLine->text().toFloat()));
     }

    this->ui->canvas->model->add(lc);
    this->ui->canvas->update();
    this->ui->polyLines->hide();

    this->ui->PenwidthpolyLine->clear();

}

void MainWindow::on_Cancle_lines_clicked()
{
    this->ui->polyLines->hide();

    this->ui->PenwidthpolyLine->clear();

}

void MainWindow::on_elipse_clicked()
{
    this->ui->canvas->setMode(5);

}

void MainWindow::on_Draw_Ellipse_clicked()
{

    EllipseComponent *ec=new EllipseComponent();

    QString color=this->ui->color_ellipse_pen->currentText();
    if(color=="red")
    {
    ec->setPen(new QPen(QBrush(Qt::red),this->ui->Penwidth_ellipse->text().toFloat()));
    }
    else
    if(color=="black")
    {
    ec->setPen(new QPen(QBrush(Qt::black),this->ui->Penwidth_ellipse->text().toFloat()));
    }
    else
    if(color=="blue")
    {
    ec->setPen(new QPen(QBrush(Qt::blue),this->ui->Penwidth_ellipse->text().toFloat()));
    }else
    if(color=="yellow")
    {
     ec->setPen(new QPen(QBrush(Qt::yellow),this->ui->Penwidth_ellipse->text().toFloat()));
    }
     else
     if(color=="pink")
     {
     ec->setPen(new QPen(QBrush(Qt::PinchGesture),this->ui->Penwidth_ellipse->text().toFloat()));
     }
     else
     if(color=="green")
     {
     ec->setPen(new QPen(QBrush(Qt::green),this->ui->Penwidth_ellipse->text().toFloat()));
     }


  color=this->ui->color_ellipse_Brush->currentText();
    if(color=="red")
    {
    ec->setBrush(new QBrush(Qt::red));
    }
    else
    if(color=="black")
    {
    ec->setBrush(new QBrush(Qt::black));
    }
    else
    if(color=="blue")
    {
    ec->setBrush(new QBrush(Qt::blue));
    }else
    if(color=="yellow")
    {
    ec->setBrush(new QBrush(Qt::yellow));
    }
     else
     if(color=="pink")
     {
     ec->setBrush(new QBrush(Qt::PinchGesture));
     }
     else
     if(color=="green")
     {
     ec->setBrush(new QBrush(Qt::green));
     }
    else
     {
         ec->setBrush(new QBrush(Qt::white));
     }

    ec->setX(this->ui->X_CORD_ellipse->text().toFloat());
    ec->setY(this->ui->Y_CORD_ellipse->text().toFloat());
    ec->setWidth(this->ui->width_ellipse->text().toFloat());
    ec->setHeight(this->ui->height_elipse->text().toFloat());
     this->ui->canvas->model->add(ec);
    this->ui->canvas->update();



    this->ui->EllipseFrame->hide();
    this->ui->X_CORD_ellipse->clear();
    this->ui->Y_CORD_ellipse->clear();
    this->ui->width_ellipse->clear();
    this->ui->height_elipse->clear();
    this->ui->Penwidth_ellipse->clear();


}

void MainWindow::on_cancle_ellipse_clicked()
{

    this->ui->EllipseFrame->hide();
    this->ui->X_CORD_ellipse->clear();
    this->ui->Y_CORD_ellipse->clear();
    this->ui->width_ellipse->clear();
    this->ui->height_elipse->clear();
    this->ui->Penwidth_ellipse->clear();
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
    this->ui->canvas->model->setSelectedInex(this->ui->canvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow());
    this->ui->canvas->model->setSelectedComponent(this->ui->canvas->model->getDrawables()->at(this->ui->canvas->model->getDrawables()->size()-1-this->ui->DsList->currentRow()));
    update();
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
