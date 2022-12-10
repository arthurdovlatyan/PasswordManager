#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile style_sheet("../PasswordGenerator/a.qss");
    style_sheet.open(QFile::ReadOnly);
    QString style = QLatin1String(style_sheet.readAll());
    a.setStyleSheet(style);

    MainWindow w;
    w.show();
    return a.exec();
}
