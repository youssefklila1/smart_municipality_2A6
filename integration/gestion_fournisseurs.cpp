#include "gestion_fournisseurs.h"
#include "ui_gestion_fournisseurs.h"

gestion_fournisseurs::gestion_fournisseurs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_fournisseurs)
{
    ui->setupUi(this);
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




        Fournisseurs.setMatricule(matricule);
        Fournisseurs.setNom(NOM);
        Fournisseurs.setAdresse(adresse);
        Fournisseurs.setTel(tel);


        if (Fournisseurs.add())
        {
            QMessageBox::information(this, "success ", "ajouter avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }
}



void gestion_fournisseurs::on_afficher_fournisseur_clicked()
{
    ui->tableView->setModel(Fournisseurs.list());
}

void gestion_fournisseurs::on_pushButton_clicked()
{
        QString matricule = ui->le_Matricule_supp->text();
        Fournisseurs.setMatricule(matricule);
        if (Fournisseurs.delet())
        {
            QMessageBox::information(this, "success ", "supprimé avec success");  }

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
           ui->lineEdit_8->setText(query.value(0).toString());
           ui->lineEdit_9->setText(query.value(1).toString());
           ui->lineEdit_10->setText(query.value(2).toString());
       }
}

void gestion_fournisseurs::on_modifier_fournisseur_clicked()
{
    QString matricule = ui->lineEdit_4->text();
        QString NOM = ui->lineEdit->text();
        QString adresse = ui->lineEdit_2->text();
        QString tel = ui->lineEdit_3->text();

        Fournisseurs.setNom(NOM);
        Fournisseurs.setAdresse(adresse);
        Fournisseurs.setTel(tel);
        QSqlQuery query;

        query.prepare("update Fournisseurs set NOM=:nom,TELEPHONE=:TEL,ADRESSE=:ADRESSE where matricule=:matricule");

        query.bindValue(":matricule",matricule);

        query.bindValue(":nom",NOM);
        query.bindValue(":TEL",tel);
        query.bindValue(":ADRESSE",adresse);
        query.exec();
        if(query.exec())
        {
            QMessageBox::information (this, "update", "client updated");
            ui->lineEdit_4->setText("");
        }


        else {QMessageBox::critical (this, "Error", "unexpected error");}
}
//=========================================================BON DE COMMANDE===================================================



void gestion_fournisseurs::on_ajouterbon_clicked()
{
       QString id = ui->le_id->text();
       QString liste = ui->le_liste->text();
       QString type = ui->le_type->text();
       QString prix = ui->le_prix->text();
       QString matricule = ui->matricule_bon->currentText();



       Bondescommandes.setListedeproduit(liste);
       Bondescommandes.setIDdecommande(id);
       Bondescommandes.setTypedeproduit(type);
       Bondescommandes.setPrixtotal(prix);
       Bondescommandes.setMatricule(matricule);


       if (Bondescommandes.add())
       {
           QMessageBox::information(this, "success ", "ajouter avec success");  }

       else
       {
           QMessageBox::critical(this, "failure !", "completer les champs!");
       }

}

void gestion_fournisseurs::on_afficher_don_clicked()
{
    ui->tableView_2->setModel(Bondescommandes.list());
}

void gestion_fournisseurs::on_supprimer_bon_clicked()
{
    QString id = ui->le_id_supp->text();
       Bondescommandes.setIDdecommande(id);
       if (Bondescommandes.delet())
       {
           QMessageBox::information(this, "success ", "supprimé avec success");  }

       else
       {
           QMessageBox::critical(this, "failure !", "completer les champs!");
       }
}


void gestion_fournisseurs::on_rechercher_bon_clicked()
{

    QString id = ui->lineEdit_5->text();
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

        Bondescommandes.setTypedeproduit(type);
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
        }


        else {QMessageBox::critical (this, "Error", "unexpected error");}
}

void gestion_fournisseurs::on_ajouter_pro_clicked()
{
    QString NOM = ui->le_nomm->text();
        QString reference = ui->le_reference->text();
        QString quantite = ui->le_quantite->text();
        QString prix = ui->le_pri->text();




        produit.setNom(NOM);
        produit.setreference (reference);
        produit.setquantite (quantite);
        produit.setprix(prix);


        if (produit.add())
        {
            QMessageBox::information(this, "success ", "ajouter avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }

}

void gestion_fournisseurs::on_supprimer_pro_clicked()
{
    QString reference = ui->le_ref_supp->text();
      produit.setreference(reference);
      if (produit.delet())
      {
          QMessageBox::information(this, "success ", "supprimé avec success");  }

      else
      {
          QMessageBox::critical(this, "failure !", "completer les champs!");
      }
}

void gestion_fournisseurs::on_afficher_pro_clicked()
{
    ui->tableView_3->setModel(produit.list());
}



void gestion_fournisseurs::on_chercher_pro_clicked()
{
    QString reference = ui->lineEdit_23->text();
           QSqlQuery query;
           query.prepare("Select * from produit where reference=:id");
           query.bindValue(":id", reference);
           query.exec();
           if(query.next())
           {
               ui->lineEdit_12->setText(query.value(0).toString());
               ui->lineEdit_26->setText(query.value(1).toString());
               ui->lineEdit_30->setText(query.value(2).toString());
           }
}

void gestion_fournisseurs::on_modifier_pro_clicked()
{
    QString reference = ui->lineEdit_23->text();
        QString NOM = ui->lineEdit_13->text();
        QString quantite = ui->lineEdit_25->text();
        QString prix = ui->lineEdit_31->text();

        produit.setNom(NOM);
        produit.setquantite(quantite);
        produit.setprix(prix);
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
        }


        else {QMessageBox::critical (this, "Error", "unexpected error");}
}

void gestion_fournisseurs::on_tri_bon_clicked()
{
    ui->tableView_2->setModel(Bondescommandes.tri());
}

void gestion_fournisseurs::on_tri_four_clicked()
{
    ui->tableView->setModel(Fournisseurs.tri1());
}

void gestion_fournisseurs::on_tri_pro_clicked()
{
     ui->tableView_3->setModel(produit.tri2());
}
