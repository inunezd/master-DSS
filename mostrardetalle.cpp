#include "mostrardetalle.h"


using namespace std;

mostrarDetalle::mostrarDetalle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mostrarDetalle)
{
    ui->setupUi(this);
//Se inicia la BBDD
    QString nombreBBDD;
    nombreBBDD.append("clientesBBDD.sqlite");
    dbleer = QSqlDatabase::addDatabase("QSQLITE");
    dbleer.setDatabaseName(nombreBBDD);
    if(dbleer.open()){
        qDebug()<<"BBDD iniciada...";
    }
    else
    {
        qDebug()<<"Error acceso BBDD...";
    };


}

mostrarDetalle::~mostrarDetalle()
{
    delete ui;
}

void mostrarDetalle::on_detalle_clicked()
{
        QString auxCodigo;
        QFile archivo("Clientes.csv");
        auxCodigo = ui->idCliente->toPlainText();
        QSqlQuery leer;
         leer.prepare("SELECT * FROM clientes WHERE Codigo = "+auxCodigo+""); //Buscamos el cliente en la BBDD
         if(leer.exec()){
            qDebug()<<"Lectura de BBDD correcta...";
            }
            else
            {
                qDebug()<<"Error" << leer.lastError();
            };
         while (leer.next()){
         ui -> mostrarResultados->setText(leer.value(2).toByteArray().constData()); //Mostramos el cliente en el cuadro de dialogo
         }

        bool encontrado=false;
        QString line;

        if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream datosArchivo(&archivo);
            QStringList data;
            QString separator(",");
            string dato;
                while (archivo.atEnd() == false) //Recorremos el fichero de clientes.txt en busca de nuestro cliente
                {
                    line = archivo.readLine();
                    data << line.split(separator);
                    foreach (const QString var, data)
                    {
                        if(var==auxCodigo){
                            QMessageBox::information(this, "El cliente es:", line, QMessageBox::Ok);
                            encontrado=true;
                            archivo.close();
                            close();}
                    }
                }
            if(encontrado==false)
            {
                 QMessageBox::information(this, "ERROR:Not found", "No existe el cliente: "+auxCodigo, QMessageBox::Ok); //MOstramos error si no existe
            }

        }
        else
        {
            QMessageBox::information(this, "Error","Problemas de lectura de fichero de clientes", QMessageBox::Ok); //MOstramos error si no se puede leer el fichero
        }

        archivo.close();
     close();

}
