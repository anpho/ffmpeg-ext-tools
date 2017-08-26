#include "mainwindow.h"
#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include <QDesktopWidget>
#include <QDebug>
#include <QLocale>
//#include <QLibraryInfo>

int main(int argc, char *argv[])
{
    // Application Manifest
    QCoreApplication::setOrganizationName("anpho");
    QCoreApplication::setOrganizationDomain("anpho.cn");
    QCoreApplication::setApplicationName("FFmpeg-ext");

    QApplication a(argc, argv);

    // init translator


    QTranslator apptrans;
    QString langfile =QString(":/ts/app_%1").arg(QLocale::system().name());
    qDebug()<<"Loading translator file: "<<langfile;
    if (apptrans.load(langfile)){
        qDebug()<<"App translator Loaded.";
        a.installTranslator(&apptrans);
    }

    MainWindow w;
    w.resize(QDesktopWidget().availableGeometry(QDesktopWidget().primaryScreen()).size()*0.5);
    w.setFiles(argc,argv);
    w.show();

    return a.exec();
}
