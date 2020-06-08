#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include "tmmodel.h"
#include <QList>
#include <QPoint>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void paintEvent(QPaintEvent * paint);
    QGraphicsScene *scene;

    QList<QPoint *> *points;

private slots:
    void on_textDraw_clicked();

    void on_polylinedraw_clicked();

    void on_Draw_Text_clicked();

    void on_cancle_text_clicked();

    void on_addPoints_clicked();

    void on_DrawLines_clicked();

    void on_Cancle_lines_clicked();

    void on_elipse_clicked();

    void on_Draw_Ellipse_clicked();

    void on_cancle_ellipse_clicked();

    void on_textDraw_5_clicked();

    void on_circle_clicked();

    void on_line_clicked();

    void on_S_and_M_clicked();

    void on_DsList_itemClicked(QListWidgetItem *item);

    void on_c1_clicked();

    void on_c2_clicked();

    void on_c3_clicked();

    void on_c4_clicked();

    void on_c5_clicked();

    void on_c6_clicked();

    void on_c7_clicked();

    void on_penWidth_valueChanged(int arg1);

    void on_undo_clicked();

    void on_redo_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
