#include "newtrajdialog.h"
#include "ui_newtrajdialog.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QString>
#include <QDebug>

NewTrajDialog::NewTrajDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewTrajDialog)
{
    ui->setupUi(this);
}

NewTrajDialog::~NewTrajDialog()
{
    delete ui;
}

void NewTrajDialog::on_pushButtonCreate_clicked()
{
    // make sure every blank is not empty.
    if(ui->lineEditAuthor->text().isEmpty() ||
       ui->lineEditName->text().isEmpty())
    {
        QMessageBox::warning(this, tr("warning!"),
                             tr("every blank must be completed!"),
                             QMessageBox::Yes);
    }
    // create one description for gait, and create a table to store gait data.
    else
    {
        QSqlQuery query;
        QString str = QString("insert into gait (name, author) values ('%1', '%2')")
                .arg(ui->lineEditName->text())
                .arg(ui->lineEditAuthor->text());
        query.exec(str);
        // get the primary key of this record.
        query.exec("select * from gait;");
        query.last();
        int num = query.value(0).toInt();
        // create table cartesian# to store gait data.
        str = QString("create table cartesian%1 ("
                      "id integer primary key autoincrement,"
                      "x real,"
                      "y real)"
                      )
                     .arg(num);
        query.exec(str);
        // create table joint# to store joint state data. we can use inverse kinematic to get these data.
        str = QString("create table joint%1 ("
                      "id integer primary key autoincrement,"
                      "hip real,"
                      "knee real)"
                      )
                     .arg(num);
        query.exec(str);
        accept();
    }
}
