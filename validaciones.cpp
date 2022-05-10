#include "validaciones.h"

validaciones::validaciones()
{
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

bool validaciones::passValidation(QString contrasenha)
{
     QFile archivo("validation_pass.txt");
     bool encontrado=false;
     QString line;
    if(archivo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream datosArchivo(&archivo);

       while(!archivo.atEnd()) {   //Lee hasta el final del archivo

            line = archivo.readLine(); //Leemos cada linea del fichero

            if(line.compare(contrasenha+"\n", Qt::CaseInsensitive ) == 0)
                {
                encontrado=true; //Marcamos la variable a True si encontramos coincidencia con el fichero.

                }

            }
         }

       else {

            encontrado=true;
         qDebug()<<"Error" << "Validacion fichero"<< archivo.error();
       // QMessageBox::information(this, "Error","Problemas de lectura de fichero de contraseñas", QMessageBox::Ok);
        }

    return encontrado;
    archivo.close();
}

bool validaciones::passValidationBBDD(QString contrasenha, QString cliente)
{
    bool validacion = false;
    QString passDesencryp;
    encry = new encriptado();


    QSqlQuery leer;

     leer.prepare("SELECT pass FROM clientes WHERE Codigo = "+cliente+"");

     if(leer.exec()){
        qDebug()<<"Lectura de BBDD correcta...";
        }
        else
        {
            qDebug()<<"Error" << leer.lastError();
        }

    leer.next();
    passDesencryp = encry->desencriptacion(leer.value(0).toByteArray().constData());
    if(contrasenha==passDesencryp){
            validacion = true;
     };
    return validacion;
}

bool validaciones::validarCaracteres(QString dato)
{
    QString patron = "^[a-zA-Z0-9]+$";
    bool retorno=false;
    QRegularExpression validador(patron);
    bool valido = validador.match(dato).hasMatch();
    if(valido){
        retorno=true;
    }

    return retorno;
}

bool validaciones::validarEnteros(QString dato)
{
 QString patron = "^[0-9]+$"; //Validamos que solo se pueden insertar numeros de 0-9 y positivo al no poder introducr el simbolo "-"
 bool retorno=false;
 QRegularExpression validador(patron);
 bool valido = validador.match(dato).hasMatch();
 if(valido){
     retorno=true;
 }
 if(dato.toInt()>32767){ //Devolvemos falso si el numero es mayor que un int4
     retorno=false;
 }

 return retorno;
}

