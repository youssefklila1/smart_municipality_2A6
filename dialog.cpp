#include "dialog.h"
#include "ui_dialog.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include<QString>
#include"employe.h"
#include"conges.h"
#include"tache.h"
#include <QMessageBox>
#include<QComboBox>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
     ui->setupUi(this);
     ui->tableView->setModel(tempemploye.afficher());
     ui->tableView_2->setModel(tempconge.afficher());
     ui->tableView_3->setModel(temptache.afficher());
     ui->combobox_matricule_conge->setModel(tempemploye.afficher());
     ui->matricule_employe_modifier->setModel(tempemploye.afficher());
     ui->recherche_employe_matricule->setModel(tempemploye.afficher());





}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QString situationfamiliale;
    if(ui->situationfamilialeC->isChecked()){ situationfamiliale =ui->situationfamilialeC->text();}//radiobutton
    if(ui->situationfamilialeM->isChecked()){ situationfamiliale =ui->situationfamilialeM->text();}//radiobutton
    if(ui->situationfamilialeD->isChecked()){ situationfamiliale =ui->situationfamilialeD->text();}//radiobutton
    QString fonction;
    if(ui->fonctionE->isChecked()){ fonction =ui->fonctionE->text();}//checkbox
    if(ui->fonctionA->isChecked()){ fonction =ui->fonctionA->text();}//checkbox
    int matricule =ui->matricule_employe_ajouter->text().toInt();
        QString nom =ui->nom_employe_ajouter->text();
        QString prenom =ui->prenom_employe_ajouter->text();
        QString email =ui->email_employe_ajouter->text();
        int datenaiss =ui->date_employe_ajouter->text().toInt();
        int anneesexp=ui->anneesexp_ajouter->text().toInt();
        employe e(matricule,nom,prenom,email,situationfamiliale,fonction,datenaiss,anneesexp);
        bool test= e.ajouter();
        if (test)

        {

            ui->recherche_employe_matricule->setModel(tempemploye.afficher());
            ui->matricule_employe_modifier->setModel(tempemploye.afficher());
            ui->combobox_matricule_conge->setModel(tempemploye.afficher());
            ui->tableView->setModel(tempemploye.afficher());
            QMessageBox::information(nullptr, QObject::tr("Ajouter un employé "),
                              QObject::tr("employé ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
                {
              QMessageBox::critical(nullptr, QObject::tr("Ajouter un employé "),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                }
}

void Dialog::on_supprimer_employe_2_clicked()
{
    int res=ui->supprimer_employe->text().toInt();
        bool test=tempemploye.supprimer(res);
        if(test)
        {

            ui->recherche_employe_matricule->setModel(tempemploye.afficher());
            ui->matricule_employe_modifier->setModel(tempemploye.afficher());
            ui->combobox_matricule_conge->setModel(tempemploye.afficher());
            ui->tableView->setModel(tempemploye.afficher());
            QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                        QObject::tr("employé supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un employé"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_Ajouter_clicked()
{   int matricule =ui->combobox_matricule_conge->currentText().toInt();
    int nbrej =ui->nbrej_conge_ajouter->text().toInt();
    QString dateconge =ui->date_conge_ajouter->text();
    QString typeconge =ui->combobox_conge_type->currentText();

    Conges C(matricule,nbrej,dateconge,typeconge);
    bool test= C.ajouter();
    if (test)
    {    ui->tableView_2->setModel(tempconge.afficher());
        QMessageBox::information(nullptr, QObject::tr("Ajouter un congé "),
                          QObject::tr("congé ajouté.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
            {
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un congé "),
                        QObject::tr("Erreur !\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            }

}

void Dialog::on_supprimer_conge_clicked()
{
    int res=ui->supprimer_conge_2->text().toInt();
        bool test=tempconge.supprimer(res);
        if(test)
        {
            ui->tableView_2->setModel(tempconge.afficher());
            QMessageBox::information(nullptr, QObject::tr("Supprimer un congé"),
                        QObject::tr("congé supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un congé"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_AJOUTER_TACHE_clicked()
{
    int matricule =ui->matricule_tache_ajouter->text().toInt();
        int identifiant =ui->identifiant_tache_ajouter->text().toInt();
        int debut =ui->debut_tache_ajouter->text().toInt();
        int fin =ui->fin_tache_ajouter->text().toInt();
        QString libelle =ui->libelle_tache_ajouter->text();

        tache t(matricule,identifiant,debut,fin,libelle);
        bool test= t.ajouter();
        if (test)
        {    ui->tableView_3->setModel(temptache.afficher());
            QMessageBox::information(nullptr, QObject::tr("Ajouter une tache "),
                              QObject::tr("tache ajouté.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        }
        else
                {
              QMessageBox::critical(nullptr, QObject::tr("Ajouter une tache "),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                }

}





void Dialog::on_supprimer_tache_clicked()
{
    int res=ui->lineEdit_5->text().toInt();
        bool test=temptache.supprimer(res);
        if(test)
        {
            ui->tableView_3->setModel(temptache.afficher());
            QMessageBox::information(nullptr, QObject::tr("Supprimer une tache"),
                        QObject::tr("tache supprimé.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Supprimer une tache"),
                        QObject::tr("Erreur !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void Dialog::on_modifier_employe_clicked()
{
    QString situationfamiliale;
    if(ui->situationfamilialeC_employe_modifier->isChecked()){ situationfamiliale =ui->situationfamilialeC_employe_modifier->text();}//radiobutton
    if(ui->situationfamilialeM_employe_modifier->isChecked()){ situationfamiliale =ui->situationfamilialeM_employe_modifier->text();}//radiobutton
    if(ui->situationfamilialeD_employe_modifier->isChecked()){ situationfamiliale =ui->situationfamilialeD_employe_modifier->text();}//radiobutton
    QString fonction;
    if(ui->fonctionE_employe_modifier->isChecked()){ fonction =ui->fonctionE_employe_modifier->text();}//checkbox
    if(ui->fonctionA_employe_modifier->isChecked()){ fonction =ui->fonctionA_employe_modifier->text();}//checkbox
    int matricule =ui->matricule_employe_modifier->currentText().toInt();
        QString nom =ui->nom_employe_modifier->text();
        QString prenom =ui->prenom_employe_modifier->text();
        QString email =ui->email_employe_modifier->text();
        int datenaiss =ui->date_employe_modifier->text().toInt();
        int anneesexp=ui->anneesex_employe_modifier->text().toInt();

        employe e;
        bool test = e.modifier(matricule,nom,prenom,email,situationfamiliale,fonction,datenaiss,anneesexp);
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un employe "),
            QObject::tr("employe modifier.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tempemploye.afficher());

        }
        else
                {
              QMessageBox::critical(nullptr, QObject::tr("modifier un employe"),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                }
}

void Dialog::on_rechercher_employe_clicked()
{
    QString reff = ui->recherche_employe_matricule->currentText();
       ui->tableView->setModel(tempemploye.afficher_rech(reff));
}

void Dialog::on_Trier_employe_clicked()
{
    ui->tableView->setModel(tempemploye.tri_ref());

}
