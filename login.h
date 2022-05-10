#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "validaciones.h"
#include "encriptado.h"
#include "mostrardetalle.h"
#include <QRegExpValidator>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::login *ui;
    validaciones *validator;
    encriptado *encryp;
};

#endif // LOGIN_H
