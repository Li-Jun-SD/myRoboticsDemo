#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"
#include "conndb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(!createConnection())
        return 1;

    MainWindow w;

    LoginDialog LoginDlg;
    if(LoginDlg.exec() == QDialog::Accepted)
    {
        w.show();

        return a.exec();
    }
    else
    {
        return 0;
    }
}
