#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString email = ui->utilisateur->text();
            QString password = ui->motdepasse->text();
            if (email == "test" && password == "test")
            {
              ui->stackedWidget->setCurrentIndex(1);

            }
            else
            {
                QMessageBox::critical (this, "login", "email ou password sont incorrectes");
            }
}

void MainWindow::on_pushButton_3_clicked()
{
    Dialog d;
        d.exec();
}
