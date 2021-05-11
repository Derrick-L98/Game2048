#include <QtGui/QApplication>
#include <QTextCodec>
#include "widget2048.h"

int main(int argc, char *argv[])
{
    QTextCodec *codec=QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    QApplication a(argc, argv);
    Widget2048 w;
    w.show();
    
    return a.exec();
}
