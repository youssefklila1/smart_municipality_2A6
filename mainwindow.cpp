#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabAfficher->setModel(tmpclient.afficher());
    ui->tabAfficher2->setModel(tmpsalles.afficher());


    //QString cin=ui->comboBox_2->currentText() ;
    //ui->comboBox_2->setModel(tmpclient.afficher2()) ;
    ui->comboBox->setModel(tmpsalles.afficherCLIENT()) ;


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pb_ajouter_clicked()
{
    bool verif=MainWindow::verif();
    if(verif)
    {

        QString nom= ui->lineEdit_nom->text();
        QString prenom= ui->lineEdit_prenom->text();
        QString cin = ui->lineEdit_cin->text();
        QString date = ui->dateEdit_date->date().toString();

      Client c(nom,prenom,cin,date);
      bool test=c.ajouter();



      if(test)
    {ui->tabAfficher->setModel(tmpclient.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("Client ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un client"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

        }
    }

    void MainWindow::on_pb_supprimer_clicked()
    {
    QString cin = ui->lineEdit_Supprimer->text();
    bool test=tmpclient.supprimer(cin);
    if(test)
    {ui->tabAfficher->setModel(tmpclient.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Client supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un client"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}









void MainWindow::on_pushButton_modifier_clicked()
{
       QString cin=ui->lineEdit_cin1->text();
       QString nom=ui->lineEdit_nom1->text();
       QString prenom=ui->lineEdit_prenom1->text();
       QString date=ui->dateEdit_date1->date().toString();

       Client c(nom,prenom,cin,date);


       bool test=c.modifier(cin);

       if(test)
       {
           ui->tabAfficher->setModel(tmpclient.afficher());
       QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("Modification effectuée \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
       }
       else{
       QMessageBox::critical(nullptr,QObject::tr("OK"),
                                QObject::tr("Modification non effectuée! \n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
       }

}

void MainWindow::on_radioButton_clicked()
{
    ui->tabAfficher->setModel(tmpclient.trierCIN());
}

void MainWindow::on_radioButton_2_clicked()
{
    ui->tabAfficher->setModel(tmpclient.trierNOM());
}

void MainWindow::on_pushButton_rechercher_clicked()
{

    QString cin = ui->lineEdit_rechercher->text();
           ui->tabAfficher->setModel(tmpclient.rechercheCIN(cin));

}

void MainWindow::on_pushButton_ajouter_clicked()
{
if(verifS())
{
    QString ref= ui->lineEdit_ref->text();
    QString lieu= ui->lineEdit_lieu->text();
    QString date = ui->dateEdit->date().toString();
    QString nom = ui->comboBox->currentText();

  salles s(ref,lieu,date,nom);
  bool test=s.ajouter();

  if(test)
{ui->tabAfficher2->setModel(tmpsalles.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("Salle ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void MainWindow::on_pushButton_supprimer_clicked()
{
    QString ref = ui->lineEdit_supprimer->text();
    bool test=tmpsalles.supprimer(ref);
    if(test)
    {ui->tabAfficher2->setModel(tmpsalles.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("Salle supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_modifier_2_clicked()
{
   QString ref=ui->lineEdit_2->text();
   QString lieu=ui->lineEdit_3->text();
   QString date=ui->dateEdit_4->date().toString();
   QString nom;

   salles s(ref,lieu,date,nom);


   bool test=s.modifier(ref);

   if(test)
   {
       ui->tabAfficher2->setModel(tmpsalles.afficher());
   QMessageBox::information(nullptr,QObject::tr("OK"),
                            QObject::tr("Modification effectuée \n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
   }
   else{
   QMessageBox::critical(nullptr,QObject::tr("OK"),
                            QObject::tr("Modification non effectuée! \n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
   }
}

void MainWindow::on_radioButton_3_clicked()
{
     ui->tabAfficher2->setModel(tmpsalles.trierREF());
}

void MainWindow::on_radioButton_4_clicked()
{
    ui->tabAfficher2->setModel(tmpsalles.trierLIEU());
}

void MainWindow::on_radioButton_5_clicked()
{
    ui->tabAfficher->setModel(tmpclient.trierDATE());
}

void MainWindow::on_radioButton_6_clicked()
{
    ui->tabAfficher2->setModel(tmpsalles.trierDATE());

}


void MainWindow::on_pushButton_rechercherNOM_clicked()
{
    QString nom = ui->lineEdit_rechercherNOM->text();
    ui->tabAfficher->setModel(tmpclient.rechercheNOM(nom));
}

void MainWindow::on_pushButton_rechercherPRENOM_clicked()
{
    QString prenom = ui->lineEdit_rechercherPRENOM->text();
    ui->tabAfficher->setModel(tmpclient.recherchePRENOM(prenom));
}


void MainWindow::on_pushButton_rechercherREF_clicked()
{
    QString ref = ui->lineEdit_rechercherREF->text();
    ui->tabAfficher2->setModel(tmpsalles.rechercheREF(ref));
}

void MainWindow::on_pushButton_rechercherLIEU_clicked()
{
    QString lieu = ui->lineEdit_rechercherLIEU->text();
    ui->tabAfficher2->setModel(tmpsalles.rechercheLIEU(lieu));
}

void MainWindow::on_pushButton_rechercherDATE_clicked()
{
    QString date = ui->lineEdit_rechercherDATE->text();
    ui->tabAfficher2->setModel(tmpsalles.rechercheDATE(date));
}

bool MainWindow::verif()
{
    if (ui->lineEdit_nom->text().contains(QRegExp("[^a-zA-Z]") ) ||
        ui->lineEdit_cin->text().contains(QRegExp("[^0-9]") ) ||
                              ui->lineEdit_nom->text().isEmpty() ||
                              ui->lineEdit_cin->text().isEmpty() ||
                              ui->lineEdit_prenom->text().contains(QRegExp("[^a-zA-Z ]") ) ||
                              ui->lineEdit_prenom->text().isEmpty() )
       {
           ui->lineEdit_nom->clear();

           QMessageBox::critical(0, "Paramétres non valides", "Valider les paramétres");
           return false;
       }
       else
       {
           return true;
       }
}
bool MainWindow::verifS()
{
    if (
            ui->lineEdit_ref->text().contains(QRegExp("[^0-9]") ) ||
                              ui->lineEdit_ref->text().isEmpty() ||
                              ui->lineEdit_lieu->text().contains(QRegExp("[^a-zA-Z ]") ) ||
                              ui->lineEdit_lieu->text().isEmpty() )
       {

           QMessageBox::critical(0, "Paramétres non valides", "Valider les paramétres");
           return false;
       }
       else
       {
           return true;
       }
}
