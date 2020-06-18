#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <QMovie>
#include <QTime>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        QSplashScreen *splash = new QSplashScreen;
        QMovie *m=new QMovie(":/images/gif-animations-replace-loading-screen-11.gif");

        splash->setPixmap(m->currentPixmap()); // splash picture
        splash->show();


        QTime finishingTime = QTime::currentTime().addSecs(7);
        m->start();
        while(QTime::currentTime()<=finishingTime)
        {

              splash->setPixmap(m->currentPixmap());

        }
        splash->hide();


    MainWindow w;
    w.show();
    //QTimer::singleShot(5000, splash,SLOT(close())); // Timer
    //QTimer::singleShot(5000,&w,SLOT(show()));
    return a.exec();
}
