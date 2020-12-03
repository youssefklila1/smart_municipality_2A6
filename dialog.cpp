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
#include<QPrinter>
#include<QPrintDialog>
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
     ui->setupUi(this);
     ui->tableView->setModel(tempemploye.afficher());
     ui->tableView_2->setModel(tempconge.afficher());
     ui->tableView_3->setModel(temptache.afficher());
//employe
     ui->matricule_employe_modifier->setModel(tempemploye.afficher());
     ui->recherche_employe_matricule->setModel(tempemploye.afficher());
     ui->comboBox__supprimer_employe->setModel(tempemploye.afficher());
//conge
     ui->matricule_conge_modifier->setModel(tempemploye.afficher());
     ui->combobox_matricule_conge->setModel(tempemploye.afficher());
     ui->comboBox_supprimer_conge->setModel(tempemploye.afficher());
//tache
     ui->matricule_tache_ajouter->setModel(tempemploye.afficher());
     ui->matricule_tache_modifier->setModel(tempemploye.afficher());
     ui->comboBox_supprimer_tache->setModel(tempemploye.afficher());
     ui->rechercher_tache_employe->setModel(tempemploye.afficher());
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    bool test;
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
        QString datenaiss =ui->date_employe_ajouter->text();
        int anneesexp=ui->anneesexp_ajouter->text().toInt();


        if(matricule>999999|| nom==""||prenom==""||email==""||datenaiss=="0"||anneesexp==0||nom.length()>10||prenom.length()>10)


                     {
                                   QMessageBox::critical(nullptr, QObject::tr("vide"),
                                   QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                   test=false;

                     }

        else {
        employe e(matricule,nom,prenom,email,situationfamiliale,fonction,datenaiss,anneesexp);
         test= e.ajouter(); }
        if (test)

        {
            ui->matricule_tache_modifier->setModel(tempemploye.afficher());
            ui->matricule_tache_ajouter->setModel(tempemploye.afficher());
            ui->comboBox_supprimer_conge->setModel(tempemploye.afficher());
            ui->matricule_conge_modifier->setModel(tempemploye.afficher());
            ui->comboBox__supprimer_employe->setModel(tempemploye.afficher());
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
    int res=ui->comboBox__supprimer_employe->currentText().toInt();
        bool test=tempemploye.supprimer(res);
        if(test)
        {
            ui->matricule_tache_modifier->setModel(tempemploye.afficher());
            ui->matricule_tache_ajouter->setModel(tempemploye.afficher());
            ui->comboBox_supprimer_conge->setModel(tempemploye.afficher());
            ui->matricule_conge_modifier->setModel(tempemploye.afficher());
            ui->comboBox__supprimer_employe->setModel(tempemploye.afficher());
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
{
    bool test;
    int matricule =ui->combobox_matricule_conge->currentText().toInt();
    int nbrej =ui->nbrej_conge_ajouter->text().toInt();
    QString dateconge =ui->date_conge_ajouter->text();
    QString typeconge =ui->combobox_conge_type->currentText();


    if(matricule>999999|| nbrej==0||dateconge==""||typeconge=="")


                 {
                               QMessageBox::critical(nullptr, QObject::tr("vide"),
                               QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                               test=false;

                 }
else{
    Conges C(matricule,nbrej,dateconge,typeconge);
     test= C.ajouter(); }
    if (test)

    {
        ui->comboBox_supprimer_conge->setModel(tempemploye.afficher());
        ui->matricule_conge_modifier->setModel(tempemploye.afficher());
        ui->tableView_2->setModel(tempconge.afficher());
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
    int res=ui->comboBox_supprimer_conge->currentText().toInt();
        bool test=tempconge.supprimer(res);
        if(test)
        {
            ui->comboBox_supprimer_conge->setModel(tempemploye.afficher());

            ui->matricule_conge_modifier->setModel(tempemploye.afficher());
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
    bool test;
    int matricule =ui->matricule_tache_ajouter->currentText().toInt();
        int identifiant =ui->identifiant_tache_ajouter->text().toInt();
        QString debut =ui->debut_tache_ajouter->text();
        QString fin =ui->fin_tache_ajouter->text();
        QString libelle=ui->combobox_libelle_tache->currentText();

        if(matricule>999999|| identifiant==0||debut==""||fin==""||libelle=="")


                     {
                                   QMessageBox::critical(nullptr, QObject::tr("vide"),
                                   QObject::tr("veuillez saisir tous les champs correctement!\n"), QMessageBox::Cancel);
                                   test=false;

                     }
else{
        tache t(matricule,identifiant,debut,fin,libelle);
         test= t.ajouter(); }
        if (test)
        {
            ui->rechercher_tache_employe->setModel(tempemploye.afficher());
            ui->comboBox_supprimer_tache->setModel(tempemploye.afficher());
            ui->matricule_tache_modifier->setModel(tempemploye.afficher());
            ui->tableView_3->setModel(temptache.afficher());
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
    int identifiant =ui->comboBox_supprimer_tache->currentText().toInt();
        bool test=temptache.supprimer(identifiant);
        if(test)
        {
            ui->rechercher_tache_employe->setModel(tempemploye.afficher());
            ui->comboBox_supprimer_tache->setModel(temptache.afficher_id());
            ui->matricule_tache_modifier->setModel(tempemploye.afficher());

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
        QString datenaiss =ui->date_employe_modifier->text();
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
    if(ui->combobox_tri_employe->currentText()=="decroissant"){ui->tableView->setModel(tempemploye.tri_ref());}
      if(ui->combobox_tri_employe->currentText()=="Ordre alphabetique"){ui->tableView->setModel(tempemploye.tri_nom());}

}



void Dialog::on_modifier_conge_clicked()
{
    int matricule =ui->matricule_conge_modifier->currentText().toInt();
    int nbrej =ui->nbrej_conge_modifier->text().toInt();
    QString dateconge =ui->date_conge_modifier->text();
    QString typeconge =ui->type_conge_modifier->currentText();
        Conges C;
        bool test = C.modifier(matricule,nbrej,dateconge,typeconge);
        if (test)
        {
            ui->tableView_2->setModel(tempconge.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier un conge "),
            QObject::tr("conge modifier.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
                {
              QMessageBox::critical(nullptr, QObject::tr("modifier un conge"),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                }

}

void Dialog::on_modifier_tache_clicked()
{
    int matricule =ui->matricule_tache_modifier->currentText().toInt();
       int identifiant =ui->identifiant_tache_modifier->text().toInt();
        QString debut =ui->debut_tache_modifier->text();
        QString fin =ui->fin_tache_modifier->text();
        QString libelle =ui->libelle_tache_modifier->currentText();

        tache t;
        bool test = t.modifier(matricule,identifiant,debut,fin,libelle);
        if (test)
        {
            ui->comboBox_supprimer_tache->setModel(temptache.afficher_id());
            ui->tableView_3->setModel(temptache.afficher());
            QMessageBox::information(nullptr, QObject::tr("modifier une tache "),
            QObject::tr("tache modifier.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);

        }
        else
                {
              QMessageBox::critical(nullptr, QObject::tr("modifier une tache"),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                }
}




void Dialog::on_pushButton_2_clicked()
{
    QString reff =ui->rechercher_tache_employe->currentText();
    ui->tableView_3->setModel(temptache.afficher_rech(reff));

}




void Dialog::on_imprimer_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
               //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
                      QPdfWriter pdf("C:/Users/dell/Desktop/eya/Pdf.pdf");
                      QPainter painter(&pdf);
                     int i = 4000;
                          painter.setPen(Qt::red);
                          painter.setFont(QFont("Arial Black", 30));
                          painter.drawText(1100,1200,"Liste des conges ");
                          painter.setPen(Qt::black);
                          painter.setFont(QFont("Arial", 50));
                         // painter.drawText(1100,2000,afficheDC);
                          painter.drawRect(100,100,7300,2600);
                          //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
                          painter.drawRect(0,3000,9600,500);
                          painter.setFont(QFont("Arial", 9));
                          painter.drawText(200,3300,"MATRICULE");
                          painter.drawText(1700,3300,"NBREJ");
                          painter.drawText(3200,3300,"DATECONGE");
                          painter.drawText(4900,3300,"TYPECONGE");

                          QSqlQuery query;
                          query.prepare("select * from CONGE");
                          query.exec();
                          while (query.next())
                          {
                              painter.drawText(200,i,query.value(0).toString());
                              painter.drawText(1700,i,query.value(1).toString());
                              painter.drawText(3200,i,query.value(2).toString());
                              painter.drawText(4900,i,query.value(3).toString());

                             i = i + 500;
                          }
                          int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
                              if (reponse == QMessageBox::Yes)
                              {
                                  QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/dell/Desktop/eya/Pdf.pdf"));
                                  painter.end();
                              }
                              if (reponse == QMessageBox::No)
                              {
                                   painter.end();
                              }
}



void Dialog::on_recherche_dynamique_textChanged(const QString &arg1)
{
    ui->tableView_3->setModel(temptache.rechercheDynamic(arg1));
}
