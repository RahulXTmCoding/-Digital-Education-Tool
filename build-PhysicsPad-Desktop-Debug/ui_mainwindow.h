/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "canvas.h"
#include "physics_wid.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *background;
    QGroupBox *dslistbox;
    QListWidget *DsList;
    QLabel *label_31;
    QGroupBox *toolbox;
    QFrame *colourFrame;
    QPushButton *colourgradient;
    QPushButton *c2;
    QPushButton *c1;
    QPushButton *c6;
    QPushButton *c3;
    QPushButton *c4;
    QPushButton *c5;
    QPushButton *c7;
    QSpinBox *penWidth;
    QFrame *toolFramef;
    QPushButton *group;
    QPushButton *pixmap;
    QPushButton *open;
    QPushButton *textDraw;
    QPushButton *new_canvas;
    QPushButton *ellipsepush;
    QPushButton *del;
    QPushButton *line;
    QPushButton *redo;
    QPushButton *ungroup;
    QPushButton *Save;
    QPushButton *circle;
    QPushButton *textDraw_5;
    QPushButton *Clear;
    QPushButton *S_and_M;
    QPushButton *undo;
    QPushButton *polylinedraw;
    QPushButton *physics_drawings;
    QPushButton *stop_recording;
    QPushButton *recording;
    Canvas *canvas;
    QFrame *frameRadio;
    QRadioButton *ff;
    QLabel *toolL;
    QFrame *textFrame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *X_CORD_text;
    QLabel *label_4;
    QLineEdit *Y_CORD_text;
    QLabel *label_7;
    QLabel *label_5;
    QLineEdit *text_font_size;
    QLabel *label_6;
    QLabel *label_8;
    QComboBox *color_text;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *PenwidthText;
    QPushButton *Draw_Text;
    QPushButton *cancle_text;
    QComboBox *Font_family_text;
    QLabel *label_11;
    QTextEdit *text_string;
    QPushButton *close_physics_book;
    Physics_wid *physics_book_frame;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1423, 1018);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        background = new QFrame(centralWidget);
        background->setObjectName(QStringLiteral("background"));
        background->setGeometry(QRect(0, 0, 1401, 1011));
        background->setFrameShape(QFrame::StyledPanel);
        background->setFrameShadow(QFrame::Raised);
        dslistbox = new QGroupBox(background);
        dslistbox->setObjectName(QStringLiteral("dslistbox"));
        dslistbox->setGeometry(QRect(1220, 20, 141, 801));
        DsList = new QListWidget(dslistbox);
        DsList->setObjectName(QStringLiteral("DsList"));
        DsList->setGeometry(QRect(10, 40, 121, 761));
        label_31 = new QLabel(dslistbox);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setGeometry(QRect(10, 10, 101, 21));
        QFont font;
        font.setPointSize(15);
        label_31->setFont(font);
        toolbox = new QGroupBox(background);
        toolbox->setObjectName(QStringLiteral("toolbox"));
        toolbox->setGeometry(QRect(10, -10, 141, 1011));
        toolbox->setFont(font);
        colourFrame = new QFrame(toolbox);
        colourFrame->setObjectName(QStringLiteral("colourFrame"));
        colourFrame->setGeometry(QRect(0, 620, 141, 271));
        colourFrame->setFrameShape(QFrame::StyledPanel);
        colourFrame->setFrameShadow(QFrame::Raised);
        colourgradient = new QPushButton(colourFrame);
        colourgradient->setObjectName(QStringLiteral("colourgradient"));
        colourgradient->setGeometry(QRect(80, 220, 51, 41));
        c2 = new QPushButton(colourFrame);
        c2->setObjectName(QStringLiteral("c2"));
        c2->setGeometry(QRect(80, 70, 51, 41));
        c1 = new QPushButton(colourFrame);
        c1->setObjectName(QStringLiteral("c1"));
        c1->setGeometry(QRect(10, 70, 51, 41));
        c6 = new QPushButton(colourFrame);
        c6->setObjectName(QStringLiteral("c6"));
        c6->setGeometry(QRect(80, 170, 51, 41));
        c3 = new QPushButton(colourFrame);
        c3->setObjectName(QStringLiteral("c3"));
        c3->setGeometry(QRect(10, 120, 51, 41));
        c4 = new QPushButton(colourFrame);
        c4->setObjectName(QStringLiteral("c4"));
        c4->setGeometry(QRect(80, 120, 51, 41));
        c5 = new QPushButton(colourFrame);
        c5->setObjectName(QStringLiteral("c5"));
        c5->setGeometry(QRect(10, 170, 51, 41));
        c7 = new QPushButton(colourFrame);
        c7->setObjectName(QStringLiteral("c7"));
        c7->setGeometry(QRect(10, 220, 51, 41));
        penWidth = new QSpinBox(colourFrame);
        penWidth->setObjectName(QStringLiteral("penWidth"));
        penWidth->setGeometry(QRect(10, 20, 51, 41));
        toolFramef = new QFrame(toolbox);
        toolFramef->setObjectName(QStringLiteral("toolFramef"));
        toolFramef->setGeometry(QRect(0, 40, 141, 511));
        toolFramef->setFrameShape(QFrame::StyledPanel);
        toolFramef->setFrameShadow(QFrame::Raised);
        group = new QPushButton(toolFramef);
        group->setObjectName(QStringLiteral("group"));
        group->setGeometry(QRect(80, 60, 51, 41));
        pixmap = new QPushButton(toolFramef);
        pixmap->setObjectName(QStringLiteral("pixmap"));
        pixmap->setGeometry(QRect(80, 310, 51, 41));
        open = new QPushButton(toolFramef);
        open->setObjectName(QStringLiteral("open"));
        open->setGeometry(QRect(80, 210, 51, 41));
        textDraw = new QPushButton(toolFramef);
        textDraw->setObjectName(QStringLiteral("textDraw"));
        textDraw->setGeometry(QRect(10, 10, 51, 41));
        new_canvas = new QPushButton(toolFramef);
        new_canvas->setObjectName(QStringLiteral("new_canvas"));
        new_canvas->setGeometry(QRect(10, 360, 51, 41));
        ellipsepush = new QPushButton(toolFramef);
        ellipsepush->setObjectName(QStringLiteral("ellipsepush"));
        ellipsepush->setGeometry(QRect(10, 110, 51, 41));
        del = new QPushButton(toolFramef);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(80, 260, 51, 41));
        line = new QPushButton(toolFramef);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 310, 51, 41));
        redo = new QPushButton(toolFramef);
        redo->setObjectName(QStringLiteral("redo"));
        redo->setGeometry(QRect(80, 410, 51, 41));
        ungroup = new QPushButton(toolFramef);
        ungroup->setObjectName(QStringLiteral("ungroup"));
        ungroup->setGeometry(QRect(80, 110, 51, 41));
        Save = new QPushButton(toolFramef);
        Save->setObjectName(QStringLiteral("Save"));
        Save->setGeometry(QRect(80, 160, 51, 41));
        circle = new QPushButton(toolFramef);
        circle->setObjectName(QStringLiteral("circle"));
        circle->setGeometry(QRect(10, 160, 51, 41));
        textDraw_5 = new QPushButton(toolFramef);
        textDraw_5->setObjectName(QStringLiteral("textDraw_5"));
        textDraw_5->setGeometry(QRect(10, 210, 51, 41));
        Clear = new QPushButton(toolFramef);
        Clear->setObjectName(QStringLiteral("Clear"));
        Clear->setGeometry(QRect(80, 10, 51, 41));
        S_and_M = new QPushButton(toolFramef);
        S_and_M->setObjectName(QStringLiteral("S_and_M"));
        S_and_M->setGeometry(QRect(10, 260, 51, 41));
        undo = new QPushButton(toolFramef);
        undo->setObjectName(QStringLiteral("undo"));
        undo->setGeometry(QRect(10, 410, 51, 41));
        polylinedraw = new QPushButton(toolFramef);
        polylinedraw->setObjectName(QStringLiteral("polylinedraw"));
        polylinedraw->setGeometry(QRect(10, 60, 51, 41));
        physics_drawings = new QPushButton(toolFramef);
        physics_drawings->setObjectName(QStringLiteral("physics_drawings"));
        physics_drawings->setGeometry(QRect(80, 360, 51, 41));
        stop_recording = new QPushButton(toolFramef);
        stop_recording->setObjectName(QStringLiteral("stop_recording"));
        stop_recording->setGeometry(QRect(80, 460, 51, 41));
        recording = new QPushButton(toolFramef);
        recording->setObjectName(QStringLiteral("recording"));
        recording->setGeometry(QRect(10, 460, 51, 41));
        canvas = new Canvas(background);
        canvas->setObjectName(QStringLiteral("canvas"));
        canvas->setGeometry(QRect(160, 20, 1051, 781));
        canvas->setFrameShape(QFrame::StyledPanel);
        canvas->setFrameShadow(QFrame::Raised);
        frameRadio = new QFrame(background);
        frameRadio->setObjectName(QStringLiteral("frameRadio"));
        frameRadio->setGeometry(QRect(160, 0, 1051, 21));
        frameRadio->setFrameShape(QFrame::StyledPanel);
        frameRadio->setFrameShadow(QFrame::Raised);
        ff = new QRadioButton(frameRadio);
        ff->setObjectName(QStringLiteral("ff"));
        ff->setGeometry(QRect(10, 0, 112, 23));
        toolL = new QLabel(background);
        toolL->setObjectName(QStringLiteral("toolL"));
        toolL->setGeometry(QRect(1030, 820, 67, 17));
        QFont font1;
        font1.setPointSize(14);
        toolL->setFont(font1);
        textFrame = new QFrame(background);
        textFrame->setObjectName(QStringLiteral("textFrame"));
        textFrame->setGeometry(QRect(920, 860, 511, 391));
        textFrame->setFrameShape(QFrame::StyledPanel);
        textFrame->setFrameShadow(QFrame::Raised);
        label = new QLabel(textFrame);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(200, 10, 101, 31));
        label->setFont(font1);
        label_2 = new QLabel(textFrame);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 67, 17));
        label_3 = new QLabel(textFrame);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 90, 67, 17));
        X_CORD_text = new QLineEdit(textFrame);
        X_CORD_text->setObjectName(QStringLiteral("X_CORD_text"));
        X_CORD_text->setGeometry(QRect(40, 90, 61, 25));
        label_4 = new QLabel(textFrame);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(110, 90, 67, 17));
        Y_CORD_text = new QLineEdit(textFrame);
        Y_CORD_text->setObjectName(QStringLiteral("Y_CORD_text"));
        Y_CORD_text->setGeometry(QRect(130, 90, 61, 25));
        label_7 = new QLabel(textFrame);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(220, 90, 67, 17));
        label_5 = new QLabel(textFrame);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(220, 70, 67, 17));
        text_font_size = new QLineEdit(textFrame);
        text_font_size->setObjectName(QStringLiteral("text_font_size"));
        text_font_size->setGeometry(QRect(410, 90, 61, 25));
        label_6 = new QLabel(textFrame);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 90, 67, 17));
        label_8 = new QLabel(textFrame);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 140, 67, 17));
        color_text = new QComboBox(textFrame);
        color_text->setObjectName(QStringLiteral("color_text"));
        color_text->setGeometry(QRect(70, 170, 86, 25));
        label_9 = new QLabel(textFrame);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 170, 67, 17));
        label_10 = new QLabel(textFrame);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(170, 170, 67, 17));
        PenwidthText = new QLineEdit(textFrame);
        PenwidthText->setObjectName(QStringLiteral("PenwidthText"));
        PenwidthText->setGeometry(QRect(220, 170, 61, 25));
        Draw_Text = new QPushButton(textFrame);
        Draw_Text->setObjectName(QStringLiteral("Draw_Text"));
        Draw_Text->setGeometry(QRect(140, 334, 89, 31));
        cancle_text = new QPushButton(textFrame);
        cancle_text->setObjectName(QStringLiteral("cancle_text"));
        cancle_text->setGeometry(QRect(270, 334, 89, 31));
        Font_family_text = new QComboBox(textFrame);
        Font_family_text->setObjectName(QStringLiteral("Font_family_text"));
        Font_family_text->setGeometry(QRect(270, 90, 86, 25));
        label_11 = new QLabel(textFrame);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 210, 67, 17));
        text_string = new QTextEdit(textFrame);
        text_string->setObjectName(QStringLiteral("text_string"));
        text_string->setGeometry(QRect(60, 210, 431, 101));
        close_physics_book = new QPushButton(background);
        close_physics_book->setObjectName(QStringLiteral("close_physics_book"));
        close_physics_book->setGeometry(QRect(950, 830, 31, 25));
        physics_book_frame = new Physics_wid(background);
        physics_book_frame->setObjectName(QStringLiteral("physics_book_frame"));
        physics_book_frame->setGeometry(QRect(180, 810, 781, 321));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        dslistbox->setTitle(QString());
        label_31->setText(QApplication::translate("MainWindow", "Ds List:-", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        toolbox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        toolbox->setWhatsThis(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
#endif // QT_NO_WHATSTHIS
        toolbox->setTitle(QString());
        colourgradient->setText(QString());
#ifndef QT_NO_TOOLTIP
        c2->setToolTip(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:15pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Black</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        c2->setText(QString());
#ifndef QT_NO_TOOLTIP
        c1->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Red</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        c1->setText(QString());
#ifndef QT_NO_TOOLTIP
        c6->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Brown</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        c6->setText(QString());
#ifndef QT_NO_TOOLTIP
        c3->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Yellow</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        c3->setText(QString());
#ifndef QT_NO_TOOLTIP
        c4->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Green</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        c4->setText(QString());
#ifndef QT_NO_TOOLTIP
        c5->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Blue</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        c5->setText(QString());
        c7->setText(QString());
#ifndef QT_NO_TOOLTIP
        penWidth->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Pen Width</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        group->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Group</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        group->setText(QString());
#ifndef QT_NO_TOOLTIP
        pixmap->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Image loader</p><p><br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pixmap->setText(QString());
#ifndef QT_NO_TOOLTIP
        open->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>open</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        open->setText(QString());
#ifndef QT_NO_TOOLTIP
        textDraw->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Text Component</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        textDraw->setText(QString());
#ifndef QT_NO_TOOLTIP
        new_canvas->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>New Canvas</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        new_canvas->setText(QString());
#ifndef QT_NO_TOOLTIP
        ellipsepush->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">ellipse</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ellipsepush->setText(QString());
#ifndef QT_NO_TOOLTIP
        del->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Delete</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        del->setText(QString());
#ifndef QT_NO_TOOLTIP
        line->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Line</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        line->setText(QString());
#ifndef QT_NO_TOOLTIP
        redo->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>redo</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        redo->setText(QString());
#ifndef QT_NO_TOOLTIP
        ungroup->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Ungroup</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        ungroup->setText(QString());
#ifndef QT_NO_TOOLTIP
        Save->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Save</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Save->setText(QString());
#ifndef QT_NO_TOOLTIP
        circle->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Circle</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        circle->setText(QString());
#ifndef QT_NO_TOOLTIP
        textDraw_5->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Rectangle</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        textDraw_5->setText(QString());
#ifndef QT_NO_TOOLTIP
        Clear->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">clear</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        Clear->setText(QString());
#ifndef QT_NO_TOOLTIP
        S_and_M->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Select &amp; Drag</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        S_and_M->setText(QString());
#ifndef QT_NO_TOOLTIP
        undo->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">undo</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        undo->setText(QString());
#ifndef QT_NO_TOOLTIP
        polylinedraw->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Pen</span></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        polylinedraw->setText(QString());
#ifndef QT_NO_TOOLTIP
        physics_drawings->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Physics book<br/></p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        physics_drawings->setText(QString());
#ifndef QT_NO_TOOLTIP
        stop_recording->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Stop Recording</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        stop_recording->setText(QString());
#ifndef QT_NO_TOOLTIP
        recording->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Record</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        recording->setText(QString());
        ff->setText(QString());
        toolL->setText(QApplication::translate("MainWindow", "Tools", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Draw Text", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Position:", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "family:", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Font:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "size:", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "Pen:", Q_NULLPTR));
        color_text->clear();
        color_text->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "red", Q_NULLPTR)
         << QApplication::translate("MainWindow", "black", Q_NULLPTR)
         << QApplication::translate("MainWindow", "blue", Q_NULLPTR)
         << QApplication::translate("MainWindow", "yellow", Q_NULLPTR)
         << QApplication::translate("MainWindow", "green", Q_NULLPTR)
         << QApplication::translate("MainWindow", "pink", Q_NULLPTR)
        );
        label_9->setText(QApplication::translate("MainWindow", "Color:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "width:", Q_NULLPTR));
        Draw_Text->setText(QApplication::translate("MainWindow", "Draw", Q_NULLPTR));
        cancle_text->setText(QApplication::translate("MainWindow", "Cancle", Q_NULLPTR));
        Font_family_text->clear();
        Font_family_text->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Times", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Arial", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Ubuntu", Q_NULLPTR)
        );
        label_11->setText(QApplication::translate("MainWindow", "Text:", Q_NULLPTR));
        close_physics_book->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
