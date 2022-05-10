#ifndef INGRESOSALDO_H
#define INGRESOSALDO_H

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
class ingresoSaldo;
}

class ingresoSaldo : public QDialog
{
    Q_OBJECT

public:
    explicit ingresoSaldo(QWidget *parent = nullptr);
    ~ingresoSaldo();

private slots:
    void on_buttonBox_accepted();


private:
    Ui::ingresoSaldo *ui;
     QSqlDatabase db;
     validaciones *val = new validaciones();
};

#endif // INGRESOSALDO_H
