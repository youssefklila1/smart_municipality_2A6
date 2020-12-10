#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "gestion_materiaux.h"
#include "gestion_employe.h"
#include "gestion_dons.h"
#include "gestion_evenement.h"
#include "gestion_fournisseurs.h"
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


void MainWindow::on_connection_clicked()
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

void MainWindow::on_gestion_materiaux_clicked()
{
    gestion_materiaux m;
        m.exec();
}
void MainWindow::on_gestion_employe_clicked()
{
    gestion_employe e;
    e.exec();
}
void MainWindow::on_gestion_dons_clicked()
{
    gestion_dons d;
    d.exec();
}
void MainWindow::on_gestion_evenement_clicked()
{
    gestion_evenement e;
    e.exec();
}
void MainWindow::on_gestion_fournisseurs_clicked()
{
    gestion_fournisseurs f;
    f.exec();
}
