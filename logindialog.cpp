#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_pushButtonLogin_clicked()
{
    if(ui->lineEditUsr->text() == tr("") &&
       ui->lineEditPwd->text() == tr(""))
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this, tr("warning!"),
                             tr("user or password wrong!"),
                             QMessageBox::Yes);

        ui->lineEditUsr->clear();
        ui->lineEditPwd->clear();
        ui->lineEditUsr->setFocus();
    }
}
