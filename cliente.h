#ifndef CLIENTE_H
#define CLIENTE_H

#include <QObject>


class cliente
{
public:
    cliente();
    cliente(int codigoCliente = -1, const QString &nombreClie = "",
            const QString &emailClie = "", int saldoClie =0, const QString &contrasenhaClie = "");
    int codigo() const { return mCodigoClie; }
    QString nombre() const { return mNombreClie; }
    QString email() const { return mEmailClie; }
    QString contrasenha() const { return mContrasenhaClie; }
    int saldo() const { return mSaldoClie; }
    void setCodigo(int codigoClie) { mCodigoClie = codigoClie; }
    void setNombre(const QString &nombreClie) { mNombreClie = nombreClie; }
    void setEmail(const QString &email) { mEmailClie = email; }
    void setSaldo(int saldo) { mSaldoClie = saldo; }

    void setContrasenha(const QString &contrasenha)
    {
        mContrasenhaClie = contrasenha;
    }

private:
    int mCodigoClie;
    QString mNombreClie;
    QString mEmailClie;
    int mSaldoClie;
    QString mContrasenhaClie;

};

#endif // CLIENTE_H
