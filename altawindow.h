#ifndef ALTAWINDOW_H
#define ALTAWINDOW_H

#include <QDialog>
#include "mainuser.h"
#include "encriptado.h"
#include "cliente.h"
#include "validaciones.h"
#include <QRegExpValidator>


namespace Ui {
class altaWindow;
}

class altaWindow : public QDialog
{
    Q_OBJECT

public:
    explicit altaWindow(QWidget *parent = nullptr);
    ~altaWindow();

private slots:
    void on_enviarExit_clicked();

private:
    Ui::altaWindow *ui;
    MainUser insert;
    //cliente client;
    //validaciones *validador;

};

#endif // ALTAWINDOW_H
