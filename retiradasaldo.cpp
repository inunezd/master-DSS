#include "retiradasaldo.h"
#include "ui_retiradasaldo.h"

retiradasaldo::retiradasaldo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::retiradasaldo)
{
    ui->setupUi(this);

    QRegExp expresion("[0-9]{1,5}");

    ui->idCliente->setValidator(new QRegExpValidator(expresion,this)); //Valida que solo se puedan introducir numeros y un maximo de longitud de 5 para evitar desbordamiento de enteros.
    ui->saldo->setValidator(new QRegExpValidator(expresion,this));

    //Se inicia la BBDD
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
}

retiradasaldo::~retiradasaldo()
{
    delete ui;
}

void retiradasaldo::on_buttonBox_accepted()
{
        QString Cliente;
        QString saldoN;
        int NuevoSaldo;
        int saldoBBDD;

        Cliente = ui->idCliente->text();
        saldoN = ui->saldo->text();

        if(!(val->validarEnteros(Cliente))){
            QMessageBox::information(this, "ERROR", "El codigo de cliente no cumple con el formato adecuado: "+Cliente, QMessageBox::Ok);
            close();
        }
        if(!(val->validarEnteros(saldoN))){
            QMessageBox::information(this, "ERROR", "El saldo no cumple con el formato adecuado: "+saldoN, QMessageBox::Ok);
            close();
        }
        QSqlQuery leer;
        QSqlQuery insertar;
         leer.prepare("SELECT saldo FROM clientes WHERE Codigo = "+Cliente+""); //Buscamos  saldo actual del cliente en la BBDD
         if(leer.exec()){
            qDebug()<<"Lectura de BBDD correcta...";
            }
            else
            {
                qDebug()<<"Error" << leer.lastError();
            }

         while (leer.next()){
            saldoBBDD = leer.value(0).toInt();
             qDebug() <<"El saldo de la BBDD es" << saldoBBDD;

         }


         qDebug()<<"El saldo de a retirar es" << saldoN.toInt();
         NuevoSaldo = saldoBBDD - saldoN.toInt();

         qDebug() << "El nuevo saldo es:" << NuevoSaldo;
         QString Nsaldo = QString::number(NuevoSaldo); //Lo convertirmos a string para poder mostrarlo en un cuadro de dialogo

      if(NuevoSaldo>=0){
         insertar.prepare("UPDATE clientes SET saldo = :NuevoSaldo WHERE Codigo = "+Cliente+"");
         insertar.bindValue(":NuevoSaldo", NuevoSaldo);
         if(insertar.exec()){
            qDebug()<<"Inserción de Saldo en BBDD correcta...";
             }
            else
             {
                 qDebug()<<"Error" << leer.lastError();
             }

           ui -> mostrarResultados->setText(Nsaldo); //Mostramos el cliente en la consola
          QMessageBox::information(this,"El nuevo saldo es: ", Nsaldo, QMessageBox::Ok); //Mostramos el saldo en una venta de dialogo
        }
        else
        {
            QMessageBox::information(this,"El importe a retirar excede la cantidad de saldo que posee el cliente", Nsaldo, QMessageBox::Ok); //MOstramos el saldo en una venta de dialogo
        }

        //ui -> mostrarResultados->setText(leer.value(2).toByteArray().constData()); //Mostramos el cliente en el cuadro de dialogo

 }

