#ifndef RETIRADASALDO_H
#define RETIRADASALDO_H

#include <QDialog>
#include <QWidget>
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
#include "validaciones.h"

namespace Ui {
class retiradasaldo;
}

class retiradasaldo : public QDialog
{
    Q_OBJECT

public:
    explicit retiradasaldo(QWidget *parent = nullptr);
    ~retiradasaldo();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::retiradasaldo *ui;
    QSqlDatabase db;
    validaciones *val = new validaciones();
};

#endif // RETIRADASALDO_H
