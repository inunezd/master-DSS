#include "altawindow.h"
#include "ui_altawindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>




altaWindow::altaWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::altaWindow)
{
    ui->setupUi(this);
    QRegExp expresion("[0-9]{1,5}");
    QRegExp expresion1("[A-Z]{1,20}");
    QRegExp expresion2("[A-Za-z]{1,50}");
    QRegExp expresion3("[0-9A-Za-z.,-+ ]{1,50}");
    QRegExp expresion4("[0-9a-z.@]{1,50}");

    ui->codigoClie->setValidator(new QRegExpValidator(expresion,this));
    ui->saldoClie->setValidator(new QRegExpValidator(expresion,this));
    ui->nombreClie->setValidator(new QRegExpValidator(expresion3,this));
    ui->dirClie->setValidator(new QRegExpValidator(expresion4,this));

}

altaWindow::~altaWindow()
{
    delete ui;
}

void altaWindow::on_enviarExit_clicked()
{


    QString codigocliente = ui->codigoClie->text();
    QString email = ui->dirClie->text();
    QString nombre = ui->nombreClie->text();
    QString saldo = ui ->saldoClie->text();
    QString contrasenha = ui ->contrasenhaClie->toPlainText();
    QString contrasenha2 = ui ->contrasenhaClie2->toPlainText();
    validaciones *val = new validaciones();
    bool valPass = val->passValidation(contrasenha);

    if(!(val->validarEnteros(codigocliente))){
        QMessageBox::information(this, "ERROR", "El codigo de cliente no cumple con el formato adecuado: "+codigocliente, QMessageBox::Ok);
        valPass = true;
        close();
    }

    if(!(val->validarEnteros(saldo))){
        QMessageBox::information(this, "ERROR", "El saldo no cumple con el formato adecuado: "+saldo, QMessageBox::Ok);
        valPass = true;
        close();
    }
    if(!(val->validarCaracteres(nombre))){
        QMessageBox::information(this, "ERROR", "El nombre de cliente no cumple con el formato adecuado: "+nombre, QMessageBox::Ok);
        valPass = true;
        close();
    }
    if(!(val->validarCaracteres(contrasenha))){
        QMessageBox::information(this, "ERROR", "La contraseña no cumple con el formato adecuado: "+contrasenha, QMessageBox::Ok);
        valPass = true;
        close();
    }


if (contrasenha==contrasenha2&&valPass!=true){

    encriptado *pass = new encriptado();

    QString passEncrypted = pass->encriptacion(contrasenha);
    insert.MainUser::insertarTablaClinetesBBDD(codigocliente, nombre, email, saldo, passEncrypted);

    QFile archivo("Clientes.csv");

        if(archivo.open(QIODevice::Append | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            datosArchivo << codigocliente << "," << email << "," << nombre << ","<< saldo << endl;

        }
        archivo.close();

        QString text = "Cliente añadido correctamente.";
        QMessageBox::information(this, "QMessageBox", text, QMessageBox::Ok);
        archivo.close();
        close();
    }

else
{

QMessageBox::information(this, "ERROR", "Las contraseñas no son validas", QMessageBox::Ok);
close();

}
}
