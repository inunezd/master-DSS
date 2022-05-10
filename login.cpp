#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QRegExp expresion("[0-9]{1,8}");
    QRegExp expresion1("[A-Z]{1,20}");
    QRegExp expresion2("[A-Za-z]{1,50}");
    QRegExp expresion3("[0-9A-Za-z.,-+- ]{1,50}");
    QRegExp expresion4("[0-9a-z.@]{1,50}");

    ui->codeClie->setValidator(new QRegExpValidator(expresion,this));

}

login::~login()
{
    delete ui;
}

void login::on_buttonBox_accepted()
{
    bool passValida=false;
    QString pass = ui->passClie->text();
    QString codeClie = ui->codeClie->text();
    //comenzamos validaciones de pass
    validator = new (validaciones);

    if(validator->passValidationBBDD(pass,codeClie))
    {//validacion de la pass contra la bbdd
               passValida=true;
    }
    if(validator->passValidation(pass)){ //validacion de la pass contra en fichero de pass incorrectas
        //Contraseña en lista incorrecta
        passValida=false;
    }
    if(passValida==true){
         mostrarDetalle *detalleCliente = new mostrarDetalle(this);
         detalleCliente->setModal(true);
         detalleCliente->show();
    }
    else
    {
    QMessageBox::information(this, "ERROR:", "Contraseña o usuario no validos", QMessageBox::Ok);
    close();
    }
delete ui;
}






