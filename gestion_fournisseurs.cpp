#include "gestion_fournisseurs.h"
#include "ui_gestion_fournisseurs.h"
#include "fournisseurs.h"
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>

gestion_fournisseurs::gestion_fournisseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_fournisseurs)
{
     ui->setupUi(this);
     ui->matricule_bon->setModel(tempfour.list());
     ui->mat_fourn->setModel(tempfour.list());
//===========================fournisseur=========================================
ui->tableView->setModel(tempfour.list()); // refrech table
//============================bon================================================
ui->tableView_2->setModel(tempband.list()); // refrech table
//===========================produit=============================================
ui->tableView_3->setModel(tempprod.list()); // refrech table

}

gestion_fournisseurs::~gestion_fournisseurs()
{
    delete ui;
}

void gestion_fournisseurs::on_ajouter_fournisseur_clicked()
{
        QString matricule = ui->le_Matricule->text();
        QString NOM = ui->le_nom->text();
        QString adresse = ui->le_Adresse->text();
        QString tel = ui->le_Telephone->text();
        tempfour.setMatricule(matricule);
        tempfour.setNom(NOM);
        tempfour.setAdresse(adresse);
        tempfour.setTel(tel);


        if (tempfour.add())
        {
            QMessageBox::information(this, "success ", "ajouter avec success");
            ui->matricule_bon->setModel(tempfour.list());
            ui->tableView->setModel(tempfour.list());
        }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }
}



void gestion_fournisseurs::on_afficher_fournisseur_clicked()
{
    ui->tableView->setModel(tempfour.list());
}

void gestion_fournisseurs::on_pushButton_clicked()
{
        QString matricule = ui->le_Matricule_supp->text();
        tempfour.setMatricule(matricule);
        if (tempfour.delet())
        {
            QMessageBox::information(this, "success ", "supprimé avec success");
            ui->tableView->setModel(tempfour.list());
        }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }
}

void gestion_fournisseurs::on_rechercher_fournisseur_clicked()
{
       QString matricule = ui->lineEdit_4->text();
       QSqlQuery query;
       query.prepare("Select * from Fournisseurs where matricule=:id");
       query.bindValue(":id", matricule);
       query.exec();
       if(query.next())
       {
           ui->lineEdit_8->setText(query.value(2).toString());
           ui->lineEdit_9->setText(query.value(3).toString());
           ui->lineEdit_10->setText(query.value(1).toString());
       }
}

void gestion_fournisseurs::on_modifier_fournisseur_clicked()
{
        QString matricule = ui->mat_fourn->currentText();
        QString NOM = ui->lineEdit->text();
        QString adresse = ui->lineEdit_2->text();
        QString tel = ui->lineEdit_3->text();
        Fournisseurs f;

        bool test= f.modifier(matricule,NOM,tel,adresse);

        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur  "),
            QObject::tr("fournisseur  modifier.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView->setModel(tempfour.list());


        }
        else
                {
              QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur "),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                }


        //Fournisseurs.setNom(NOM);
       // Fournisseurs.setAdresse(adresse);
       //Fournisseurs.setTel(tel);
       //QSqlQuery query;

        //query.prepare("update Fournisseurs set NOM=:nom,TELEPHONE=:TEL,ADRESSE=:ADRESSE where matricule=:matricule");

       /* query.bindValue(":matricule",matricule);
        query.bindValue(":nom",NOM);
        query.bindValue(":TEL",tel);
        query.bindValue(":ADRESSE",adresse);
        query.exec();
        if(query.exec())
        {
            QMessageBox::information (this, "update", "client updated");
            ui->lineEdit_4->setText("");
            ui->tableView->setModel(Fournisseurs.list());
        }


        else {QMessageBox::critical (this, "Error", "unexpected error");}*/



}
//=========================================================BON DE COMMANDE===================================================



void gestion_fournisseurs::on_ajouterbon_clicked()
{
       QString id = ui->le_id->text();
       QString liste = ui->le_liste->text();
       QString type = ui->le_type->text();
       QString prix = ui->le_prix->text();
       QString matricule = ui->matricule_bon->currentText();



       tempband.setListedeproduit(liste);
       tempband.setIDdecommande(id);
       tempband.setTypedeproduit(type);
       tempband.setPrixtotal(prix);
       tempband.setMatricule(matricule);


       if (tempband.add())
       {
           QMessageBox::information(this, "success ", "ajouter avec success");
           ui->tableView_2->setModel(tempband.list());
       }

       else
       {
           QMessageBox::critical(this, "failure !", "completer les champs!");
       }

}

void gestion_fournisseurs::on_afficher_don_clicked()
{
    ui->tableView_2->setModel(tempband.list());
}

void gestion_fournisseurs::on_supprimer_bon_clicked()
{
    QString id = ui->le_id_supp->text();
       tempband.setIDdecommande(id);
       if (tempband.delet())
       {
           QMessageBox::information(this, "success ", "supprimé avec success");
           ui->tableView_2->setModel(tempband.list());
       }

       else
       {
           QMessageBox::critical(this, "failure !", "completer les champs!");
       }
}


void gestion_fournisseurs::on_rechercher_bon_clicked()
{

    QString id = ui->lineEdit_11->text();
    QSqlQuery query;
    query.prepare("Select * from Bondescommandes where Id_de_commande=:id");
    query.bindValue(":id", id);
    query.exec();
    if(query.next())
    {
        ui->lineEdit_6->setText(query.value(0).toString());
        ui->lineEdit_15->setText(query.value(1).toString());
    }
}

void gestion_fournisseurs::on_pushButton_2_clicked()//modifier
{
        QString id = ui->lineEdit_5->text();
        QString type = ui->lineEdit_16->text();
        QString liste = ui->lineEdit_17->text();
        QString matricule =ui->lineEdit_20->text();
        QString prix = ui->lineEdit_19->text();

         Bondescommandes B;
      bool test=   B.modifier(matricule,type,prix,id,liste);
      if (test)
      {
          QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur  "),
          QObject::tr("fournisseur  modifier.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            ui->tableView_2->setModel(tempband.list());
      }
      else
              {
            QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur "),
                          QObject::tr("Erreur !\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
              }

       /* Bondescommandes.setTypedeproduit(type);
        Bondescommandes.setListedeproduit(liste);

        QSqlQuery query;

        query.prepare("update Bondescommandes set type_de_produit=:type,liste_de_produit=:liste where id_de_commande=:id");

        query.bindValue(":id",id);

        query.bindValue(":type",type);
        query.bindValue(":liste",liste);
        query.exec();
        if(query.exec()){
            QMessageBox::information (this, "update", "client updated");
            ui->lineEdit_4->setText("");
            ui->tableView_2->setModel(Bondescommandes.list());
        }


        else {QMessageBox::critical (this, "Error", "unexpected error");}*/
}

void gestion_fournisseurs::on_ajouter_pro_clicked()
{
    QString NOM = ui->le_nomm->text();
        QString reference = ui->le_reference->text();
        QString quantite = ui->le_quantite->text();
        QString prix = ui->le_pri->text();




        tempprod.setNom(NOM);
        tempprod.setreference (reference);
        tempprod.setquantite (quantite);
        tempprod.setprix(prix);


        if (tempprod.add())
        {
            QMessageBox::information(this, "success ", "ajouter avec success");
            ui->tableView_3->setModel(tempprod.list());
        }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }

}

void gestion_fournisseurs::on_supprimer_pro_clicked()
{
    QString reference = ui->le_ref_supp->text();
      tempprod.setreference(reference);
      if (tempprod.delet())
      {
          QMessageBox::information(this, "success ", "supprimé avec success");
            ui->tableView_3->setModel(tempprod.list());
      }

      else
      {
          QMessageBox::critical(this, "failure !", "completer les champs!");
      }
}

void gestion_fournisseurs::on_afficher_pro_clicked()
{
    ui->tableView_3->setModel(tempprod.list());
}



void gestion_fournisseurs::on_chercher_pro_clicked()
{
    QString reference = ui->lineEdit_7->text();
           QSqlQuery query;
           query.prepare("Select * from produit where reference=:id");
           query.bindValue(":id", reference);
           query.exec();
           if(query.next())
           {
               ui->lineEdit_12->setText(query.value(0).toString());
               ui->lineEdit_26->setText(query.value(3).toString());
               ui->lineEdit_30->setText(query.value(2).toString());
           }
}

void gestion_fournisseurs::on_modifier_pro_clicked()
{
        QString reference = ui->lineEdit_23->text();
        QString NOM = ui->lineEdit_13->text();
        QString quantite = ui->lineEdit_25->text();
        QString prix = ui->lineEdit_31->text();


        produit p;
        bool test= p.modifier(NOM,reference,quantite,prix);
        if (test)
        {
            QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur  "),
            QObject::tr("fournisseur  modifier.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);
              ui->tableView_3->setModel(tempprod.list());
        }
        else
                {
              QMessageBox::critical(nullptr, QObject::tr("modifier un fournisseur "),
                            QObject::tr("Erreur !\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
                }
        /*tempprod.setNom(NOM);
         tempprod.setquantite(quantite);
       tempprod.setprix(prix);
        QSqlQuery query;

        query.prepare("update produit set NOM=:nom,QUANTITE=:quantite,PRIX=:prix where reference=:reference");

        query.bindValue(":reference",reference);

        query.bindValue(":nom",NOM);
        query.bindValue(":QUANTITE",quantite);
        query.bindValue(":PRIX",prix);
        query.exec();
        if(query.exec()){
            QMessageBox::information (this, "update", "produit updated");
            ui->lineEdit_23->setText("");
            ui->tableView_3->setModel(tempprod.list());
        }


        else {QMessageBox::critical (this, "Error", "unexpected error");}*/
}

void gestion_fournisseurs::on_tri_bon_clicked()
{
    ui->tableView_2->setModel(tempband.tri());
}

void gestion_fournisseurs::on_tri_four_clicked()
{
    ui->tableView->setModel(tempfour.tri1());
}

void gestion_fournisseurs::on_tri_pro_clicked()
{
     ui->tableView_3->setModel(tempprod.tri2());
}

void gestion_fournisseurs::on_pushButton_3_clicked()
{
    QPdfWriter pdf("C:/Users/asus/Desktop/ahmed/Pdf.pdf");
                                  QPainter painter(&pdf);
                                 int i = 4000;
                                      painter.setPen(Qt::red);
                                      painter.setFont(QFont("Arial Black", 30));
                                      painter.drawText(1100,1200,"Liste des conges ");
                                      painter.setPen(Qt::black);
                                      painter.setFont(QFont("Arial", 50));

                                      painter.drawRect(100,100,7300,2600);

                                      painter.drawRect(0,3000,9600,500);
                                      painter.setFont(QFont("Arial", 9));
                                      painter.drawText(200,3300,"NOM");
                                      painter.drawText(1700,3300,"REFERENCE");
                                      painter.drawText(3200,3300,"QUANTITE");
                                      painter.drawText(4900,3300,"PRIX");

                                      QSqlQuery query;
                                      query.prepare("select * from produit");
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
                                              QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/asus/Desktop/ahmed/Pdf.pdf"));
                                              painter.end();
                                          }
                                          if (reponse == QMessageBox::No)
                                          {
                                               painter.end();
                                          }
}

void gestion_fournisseurs::on_retour_2_clicked()
{
    hide();
}

void gestion_fournisseurs::on_retour_3_clicked()
{
    hide();
}

void gestion_fournisseurs::on_retour_4_clicked()
{
    hide();
}
