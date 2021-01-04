#include "first.h"
#include "ui_first.h"
#include <QMessageBox>
#include "gestion_materiaux.h"
#include "gestion_employe.h"
#include "gestion_dons.h"
#include "gestion_evenement.h"
#include "gestion_fournisseurs.h"
#include "gestion_chantiers.h"
#include "arduino.h"

first::first(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::first)
{
    ui->setupUi(this);
}

first::~first()
{
    delete ui;
}

void first::on_connection_clicked()
{

    QString email = ui->utilisateur->text();
    QString password = ui->motdepasse->text();

    if (email == "mariem" && password == "mariem")
    {
        gestion_dons d;
        d.exec();
    }
    else if(email == "youssef" && password == "youssef")
    {
            gestion_materiaux m;
            m.exec();
    }
    else if(email == "eya" && password == "eya")
    {
        gestion_employe e;
        e.exec();
    }
    else if(email == "ahmed" && password == "ahmed")
    {
        gestion_fournisseurs f;
        f.exec();
    }
    else if(email == "karim" && password == "karim")
    {
        gestion_evenement e;
        e.exec();
    }
    else if(email == "selim" && password == "selim")
    {
        gestion_chantiers c;
        c.exec();
    }
    else if(email == "admin" && password == "admin")
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if(email == "alarme" && password == "alarme")
    {
       arduino A;
       A.exec();
    }

    else
    {
        QMessageBox::critical (this, "login", "email ou password sont incorrectes");
    }
}

void first::on_gestion_materiaux_clicked()
{
    gestion_materiaux m;
        m.exec();
}
void first::on_gestion_employe_clicked()
{
    gestion_employe e;
    e.exec();
}
void first::on_gestion_dons_clicked()
{
    gestion_dons d;
    d.exec();
}
void first::on_gestion_evenement_clicked()
{
    gestion_evenement e;
    e.exec();
}
void first::on_gestion_fournisseurs_clicked()
{
    gestion_fournisseurs f;
    f.exec();
}
void first::on_gestion_chantiers_clicked()
{
    gestion_chantiers c;
    c.exec();
}


