#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>
#include "mainuser.h"
#include "ui_mainuser.h"
#include "altawindow.h"
#include "mostrardetalle.h"


using namespace std;

MainUser::MainUser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainUser)
{
    ui->setupUi(this);
    qDebug()<<"Aplicación iniciada...";

    QString nombreBBDD;
    nombreBBDD.append("clientesBBDD.sqlite");
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(nombreBBDD);
    if(db.open()){
        qDebug()<<"BBDD iniciada...";
    }
    else
    {
        qDebug()<<"Error acceso BBDD...";
    };

    crearTablaClinetesBBDD();
}

MainUser::~MainUser()
{
    delete ui;
}

void MainUser::crearTablaClinetesBBDD()
{

    QString consulta;

    consulta.append("CREATE TABLE IF NOT EXISTS clientes("
    "id INTEGER PRIMARY KEY AUTOINCREMENT,"
    "Codigo INTEGER NOT NULL,"
    "Nombre VARCHAR(100),"
    "email VARCHAR(100),"
    "saldo INTEGER NOT NULL,"
     "pass VARCHAR(100)"
    ");");
    QSqlQuery crear;
    crear.prepare(consulta);


     if(crear.exec()){
        qDebug()<<"Tabla existe/creada de forma correcta...";
        }
        else
        {
            qDebug()<<"Error" << crear.lastError();
        };
}

void MainUser::insertarTablaClinetesBBDD(QString codigo, QString nombre, QString email, QString saldo, QString contrasenha)
{
    QSqlQuery insertar;

     insertar.prepare("INSERT INTO clientes (Codigo, Nombre, email, saldo, pass) "
                      "VALUES (:Codigo, :Nombre, :email, :saldo, :contrasenha)");
        insertar.bindValue(":Codigo", codigo);
        insertar.bindValue(":Nombre", nombre);
        insertar.bindValue(":email", email);
        insertar.bindValue(":saldo", saldo);
        insertar.bindValue(":contrasenha", contrasenha);

     if(insertar.exec()){
        qDebug()<<"Cliente insertado de forma correcta...";
        }
        else
        {
            qDebug()<<"Error" << insertar.lastError();
        }

}


void MainUser::on_alta_clicked()
{

    altaWindow *altaCliente = new altaWindow(this);
    altaCliente->setModal(true);
    altaCliente->show();


   //Programamos un timer para cerrar la ventana si el ususario no introduce datos en un tiempo.
    QTimer *timer;
    timer = new QTimer();
    QObject::connect(timer ,  SIGNAL(timeout()),altaCliente,SLOT(accept()));
   // QObject::connect(timer ,  SIGNAL(timeout()),altaCliente,SLOT(show()));
    timer->start(50000);
    delete timer;

}


void MainUser::on_detalle_clicked()
{
// Primero llaamos para hacer el login antes de mostrar los datos
    logn = new login(this);
    logn->setModal(true);
    logn->show();
    //Programamos un timer para cerrar la ventana si el ususario no introduce datos en un tiempo.
     QTimer *timer;
     timer = new QTimer();
     QObject::connect(timer ,  SIGNAL(timeout()),logn,SLOT(accept()));
    // QObject::connect(timer ,  SIGNAL(timeout()),altaCliente,SLOT(show()));
     timer->start(20000);

}


void MainUser::on_ingreso_clicked()
{
    ingresoSaldo *ingreso = new ingresoSaldo(this);
    ingreso ->setModal(true);
    ingreso ->show();


    //QMessageBox::information(this, "QMessageBox", "Funcion temporalmente no disponible", QMessageBox::Ok);
}


void MainUser::on_retirada_clicked()
{
    retiradasaldo *retirada = new retiradasaldo(this);
    retirada ->setModal(true);
    retirada ->show();
//QMessageBox::information(this, "QMessageBox", "Funcion temporalmente no disponible", QMessageBox::Ok);
}


void MainUser::on_modificar_clicked()
{
QMessageBox::information(this, "QMessageBox", "Funcion temporalmente no disponible", QMessageBox::Ok);
}


void MainUser::on_exit_clicked()
{


    QString text = "Gracias por su visita.";
    QMessageBox::information(this, "QMessageBox", text, QMessageBox::Ok);
    close();

}

