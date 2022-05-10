#ifndef MOSTRARDETALLE_H
#define MOSTRARDETALLE_H

#include <QWidget>
#include <QDialog>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include "ui_mostrardetalle.h"
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include "login.h"
#include <QTimer>
#include <QStringList>

#include <QList>

using namespace std;

namespace Ui {
class mostrarDetalle;
}

class mostrarDetalle : public QDialog
{
    Q_OBJECT

public:
    explicit mostrarDetalle(QWidget *parent = nullptr);
    ~mostrarDetalle();

private slots:
    void on_detalle_clicked();

private:
    Ui::mostrarDetalle *ui;
    QSqlDatabase dbleer;

};

#endif // MOSTRARDETALLE_H
