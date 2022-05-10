#ifndef MAINUSER_H
#define MAINUSER_H
#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QObject>
#include "login.h"
#include "ingresosaldo.h"
#include "retiradasaldo.h"


using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainUser; }
QT_END_NAMESPACE

class MainUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainUser(QWidget *parent = nullptr);
    ~MainUser();

    void crearTablaClinetesBBDD();
    void insertarTablaClinetesBBDD(QString, QString, QString, QString, QString);

private slots:
    void on_alta_clicked();

    void on_detalle_clicked();

    void on_ingreso_clicked();

    void on_retirada_clicked();

    void on_modificar_clicked();

    void on_exit_clicked();

private:
    Ui::MainUser *ui;
    QSqlDatabase db;
    login *logn;



};
#endif // MAINUSER_H
