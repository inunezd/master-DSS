#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <QObject>
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
#include "cliente.h"
#include <QFile>
#include <QTextStream>
#include "encriptado.h"
#include <QRegularExpression>


using namespace std;


class validaciones
{

public:
    //explicit validaciones(QWidget *parent = nullptr);

    validaciones (QString contrasenha);
    validaciones (cliente *client);
    validaciones();
    ~validaciones();
    bool passValidation(QString contrasenha);
    bool passValidationBBDD(QString contrasenha, QString cliente);
    bool validarCaracteres(QString dato);
    bool validarEnteros(QString dato);

private:
    QString pass;
    cliente *clie;
    QSqlDatabase dbleer;
    encriptado *encry;

};

#endif // VALIDACIONES_H
