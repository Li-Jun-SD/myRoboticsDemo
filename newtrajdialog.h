#ifndef NEWTRAJDIALOG_H
#define NEWTRAJDIALOG_H

#include <QDialog>

namespace Ui {
class NewTrajDialog;
}

class NewTrajDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTrajDialog(QWidget *parent = 0);
    ~NewTrajDialog();

private slots:

    void on_pushButtonCreate_clicked();

private:
    Ui::NewTrajDialog *ui;
};

#endif // NEWTRAJDIALOG_H
