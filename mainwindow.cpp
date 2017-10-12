#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newtrajdialog.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    NewTrajDialog NTDlg;
    if(NTDlg.exec() == QDialog::Accepted)
    {
        // show the database.
        model = new QSqlTableModel(this);
        model->setTable("gait");
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();

        ui->tableView->setModel(model);
        // automatically resize the section to fill the available space.
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        // unable to edit this table.
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }
}
