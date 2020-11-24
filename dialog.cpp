#include "dialog.h"
#include "ui_dialog.h"
#include "materiauxPoss.h"
#include "materiauxmanq.h"
#include "matmaint.h"
#include <QMessageBox>
#include <QComboBox>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tableView->setModel(tempmatposs.afficher());
    ui->tableView_3->setModel(tempmatmanq.afficher());
    ui->tableView_2->setModel(tempmatmaint.afficher());
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_ajouterposs_clicked()
{
    QString etat ;
    int referance =ui->referancePoss->text().toInt();
    QString nom =ui->nomPoss->text();


    if(ui->ajouterEtatMateriauxPoss1->isChecked()){ etat =ui->ajouterEtatMateriauxPoss1->text();}
    if(ui->ajouteretatMateriauxposs0->isChecked()){ etat =ui->ajouteretatMateriauxposs0->text();}
    Materiauxposs m(referance,nom,etat);
    bool test= m.ajouter();
    if (test)
    {
        ui->tableView->setModel(tempmatposs.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel en possessions "),
                          QObject::tr("meteriel ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
            {
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel en possessions"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            }
}


void Dialog::on_supp_mat_poss1_clicked()  //supprimer materiel possessions methode 1
{

    int ref=ui->ref_mat_poss_a_supp1->text().toInt();
    bool test=tempmatposs.supprimer(ref);
    if(test)
    {
        ui->tableView->setModel(tempmatposs.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                    QObject::tr("materiel supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}




void Dialog::on_pushButton_4_clicked()
{
    QString ETAT ;
    int ref =ui->mat_poss_reff_mod->text().toInt();
    QString NOM =ui->mat_poss_nom_mod->text();
    QString RES = QString::number(ref);


    if(ui->mat_poss_etat_b_mod->isChecked()){ ETAT =ui->mat_poss_etat_b_mod->text();}
    if(ui->mat_poss_m__mod->isChecked()){ ETAT =ui->mat_poss_m__mod->text();}

    QSqlQuery qry;
    qry.prepare("update MATERIAUX_POSS set REFERANCE='"+RES+"',NOM='"+NOM+"',ETAT='"+ETAT+"' where REFERANCE='"+RES+"'  ");



}


void Dialog::on_ajoutermateriauxmanq_clicked()
{


 QString dispo;
 int referance=ui->refmatmanq->text().toInt();
 int prix=ui->prixmanq->text().toInt();
 QString nom =ui->nommanq->text();
 if(ui->dispo_oui->isChecked()){ dispo =ui->dispo_oui->text();}
 if(ui->dispo_non->isChecked()){ dispo =ui->dispo_non->text();}

    Materiauxmanq mq(referance,prix,nom,dispo);
  bool test= mq.ajouter();

        if (test)
  {

      ui->tableView_3->setModel(tempmatmanq.afficher()); //refraich afich
      QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel en possessions "),
                        QObject::tr("meteriel ajouté.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
  }
        else
          {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel en possessions"),
                    QObject::tr("Erreur !\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
          }


}

void Dialog::on_supprimermatmanq1_clicked() // suprimer materiel manquant methode 1
{

 int ref=ui->ref_mat_manq_a_supp1->text().toInt();
 bool test=tempmatmanq.supprimer(ref);
 if(test)
 {
     ui->tableView_3->setModel(tempmatmanq.afficher());
     QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                 QObject::tr("materiel supprimé.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

 }
 else
     QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


}




void Dialog::on_ajouter_mat_maintenace_clicked()
{
    QString date = ui->dateTimeEdit->text();
    int  referance=ui->ref_mat_maint_a_ajouter->text().toInt();
    QString nom =ui->nom_mat_maint_a_ajouter->text();
    QString region =ui->region_mat_maint_a_ajouter->text();
    Matmaint mt(referance,nom,region,date);
    bool test = mt.ajouter();
    if (test)

    {
        ui->tableView_2->setModel(tempmatmaint.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel en maintenace "),
                          QObject::tr("meteriel ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
            {
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel en maintenace"),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            }

}

void Dialog::on_supprimer_mat_maintenace1_clicked()
{
    int ref=ui->ref_mat_maint_a_supp1->text().toInt();
    bool test=tempmatmaint.supprimer(ref);
    if(test)
    {
        ui->tableView_2->setModel(tempmatmaint.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                    QObject::tr("materiel supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}







