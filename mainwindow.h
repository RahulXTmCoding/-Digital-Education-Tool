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
#include "canvas.h"
#include <QRadioButton>
#include <QPushButton>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void resizeEvent(QResizeEvent* event);
    QGraphicsScene *scene;
    QList<QFrame *> *Frames;
     QPushButton *closeButton;

    QList<QPoint *> *points;
    QList<Canvas *> *canvasList;
    Canvas *selectedCanvas;
    QList<QRadioButton *> *radioList;
     QList<QListWidget *> *listWidgets;
    int selectedCanvasIndex=0;
      QScrollArea *scroll;
      void showContextMenu(const QPoint &pos);
      void editQList();
      void deleteQList();
    void changeCanvas();
private slots:
    void on_textDraw_clicked();


    void on_polylinedraw_clicked();

    void on_Draw_Text_clicked();

    void on_cancle_text_clicked();

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

    void on_ellipsepush_clicked();

    void on_Clear_clicked();

    void on_Save_clicked();

    void on_open_clicked();

    void on_DsList_itemSelectionChanged();

    void on_group_clicked();

    void on_ungroup_clicked();

    void on_del_clicked();

    void on_new_canvas_clicked();

    void on_ff_clicked();



    void on_pixmap_clicked();

    void on_colourgradient_clicked();

    void on_recording_clicked();

    void on_stop_recording_clicked();

    void on_physics_drawings_clicked();

    void on_close_physics_book_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
