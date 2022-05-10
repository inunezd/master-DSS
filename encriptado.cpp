#include "encriptado.h"

encriptado::encriptado()
{

}
encriptado::~encriptado()
{

}
QString encriptado::encriptacion(QString contrasenha) // Funcion para el encriptado
{
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023)); //some random number
     QString testString(contrasenha);

     //Encryption
     QString encrypted = crypto.encryptToString(testString);

     return encrypted;


}

QString encriptado::desencriptacion(QString contrasenha) // Funcion para el desencriptado
{
    SimpleCrypt crypto(Q_UINT64_C(0x0c2ad4a4acb9f023));
    QString decrypted = crypto.decryptToString(contrasenha);
    return decrypted;
}
