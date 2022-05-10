#include "mainuser.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <QApplication>
#include <QLocale>
#include <QTranslator>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "cajero_ui_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainUser *window = new MainUser();
    //MainUser w;
    window->show();
    return a.exec();
    delete window;

}
