#ifndef ENCRIPTADO_H
#define ENCRIPTADO_H


#include <QObject>
#include <QWidget>
#include "simplecrypt.h"


class encriptado
{
public:
    encriptado(QString &contrasenha);
    encriptado();
    ~encriptado();
    QString encriptacion (QString); //Funcion para el encriptado
    QString desencriptacion (QString); //Funcion para el desencriptado
private:
    QString contrasenha;

};

#endif // ENCRIPTADO_H
