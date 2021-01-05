#include "gestion_chantiers.h"
#include "ui_gestion_chantiers.h"

gestion_chantiers::gestion_chantiers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_chantiers)
{
    ui->setupUi(this);
}

gestion_chantiers::~gestion_chantiers()
{
    delete ui;
}

void gestion_chantiers::on_pushButton_4_clicked()
{
                       QString id=ui->lineEdit_12->text();
                       QString nom=ui->lineEdit_13->text();
                       Societes societes(id,nom);
                       societes.ajouter();
                       //ui->comboBox_3->addItem(nom);
                       ui->Affichage_2->setModel(tmpsocietes.afficher());
                       ui->lineEdit_12->setText("");
                       ui->lineEdit_13->setText("");
}


void gestion_chantiers::on_pushButton_5_clicked()
{
    if (ui->pushButton_5->isChecked())
                    {
                        ui->pushButton_5->setDisabled(true);
                        ui->pushButton_5->setText("Modifiable");
                        QSqlTableModel *tableModel= new QSqlTableModel();
                        tableModel->setTable("SOCIETES");
                        tableModel->select();
                        ui->Affichage_2->setModel(tableModel);
                    }
                    else
                    {
                        ui->pushButton_5->setText("Modifier");QSqlQueryModel * model = tmpsocietes.afficher();
                        ui->Affichage_2->setModel(model);
                    }
}



void gestion_chantiers::on_pushButton_2_clicked()
{
    QItemSelectionModel *select = ui->Affichage_2->selectionModel();

            QString id =select->selectedRows(0).value(0).data().toString();

            if(tmpsocietes.supprimer(id))
            {
                ui->Affichage_2->setModel(tmpsocietes.afficher());
            }
}



void gestion_chantiers::on_pushButton_3_clicked()
{
    QString id=ui->lineEdit_10->text();
        QString nom=ui->lineEdit->text();
        QString region=ui->comboBox_2->currentText();
        QString etat=ui->comboBox->currentText();
        QString rue=ui->lineEdit_2->text();
        QString affectation=ui->lineEdit_3->text();

                        Chantiers chantiers(id,nom,region,rue,affectation,etat);
                        chantiers.ajouter();
                        ui->Affichage_3->setModel(tmpchantiers.afficher());
                        ui->lineEdit_10->setText("");
                        ui->lineEdit->setText("");
                        ui->lineEdit_2->setText("");
                       ui->Affichage_4->setModel(tmpchantiers.afficher_societes());
}

void gestion_chantiers::on_pushButton_6_clicked()
{
    if (ui->pushButton_6->isChecked())
                   {
                       ui->pushButton_6->setDisabled(true);
                       ui->pushButton_6->setText("Modifiable");
                       QSqlTableModel *tableModel= new QSqlTableModel();
                       tableModel->setTable("CHANTIERS");
                       tableModel->select();
                       ui->Affichage_3->setModel(tableModel);
                   }
                   else
                   {
                       ui->pushButton_6->setText("Modifier");QSqlQueryModel * model = tmpchantiers.afficher();
                       ui->Affichage_3->setModel(model);
                   }
}



void gestion_chantiers::on_pushButton_11_clicked()
{
    QItemSelectionModel *select = ui->Affichage_3->selectionModel();

           QString id =select->selectedRows(0).value(0).data().toString();

           if(tmpchantiers.supprimer(id))
           {
               ui->Affichage_3->setModel(tmpchantiers.afficher());
           }
}

void gestion_chantiers::on_radioButton_clicked()
{
    bool test = true;
             if (test)
                 {
                 ui->Affichage_2->setModel(tmpsocietes.afficher());

                     ui->Affichage_2->setModel(tmpsocietes.trier());



                 }

             else
             {
                 QMessageBox::critical(nullptr, QObject::tr("trier societes"),
                                       QObject::tr("Erreur !.\n"
                                                   "Click Cancel to exit."), QMessageBox::Cancel);
             }
}

void gestion_chantiers::on_radioButton_2_clicked()
{
    bool test = true;
              if (test)
                  {
                  ui->Affichage_2->setModel(tmpsocietes.afficher());

                      ui->Affichage_2->setModel(tmpsocietes.trier_i());



                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier societes"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }
}

void gestion_chantiers::on_radioButton_3_clicked()
{
    bool test = true;
              if (test)
                  {
                  ui->Affichage_3->setModel(tmpchantiers.afficher());

                      ui->Affichage_3->setModel(tmpchantiers.trier_c());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier chantiers"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }
}

void gestion_chantiers::on_radioButton_4_clicked()
{
    bool test = true;
              if (test)
                  {
                  ui->Affichage_3->setModel(tmpchantiers.afficher());

                      ui->Affichage_3->setModel(tmpchantiers.trier_cr());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier chantiers"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }
}

void gestion_chantiers::on_radioButton_5_clicked()
{
    bool test = true;
              if (test)
                  {
                  ui->Affichage_3->setModel(tmpchantiers.afficher());

                      ui->Affichage_3->setModel(tmpchantiers.trier_ce());

                  }

              else
              {
                  QMessageBox::critical(nullptr, QObject::tr("trier chantiers"),
                                        QObject::tr("Erreur !.\n"
                                                    "Click Cancel to exit."), QMessageBox::Cancel);
              }
}

void gestion_chantiers::on_tabWidget_2_tabBarClicked(int index)
{
    index=0;
    ui->Affichage_2->setModel(tmpsocietes.afficher());
}

void gestion_chantiers::on_tabWidget_3_tabBarClicked(int index)
{
    index=0;
         ui->Affichage_4->setModel(tmpchantiers.afficher_societes());
         ui->Affichage_3->setModel(tmpchantiers.trier_ce());
}

void gestion_chantiers::on_Affichage_4_clicked(const QModelIndex &index)
{
    ui->lineEdit_3->setText(QString (ui->Affichage_4->model()->data(ui->Affichage_4->model()->index(index.row(),1)).toString()));
}

void gestion_chantiers::on_commandLinkButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
}

void gestion_chantiers::on_pushButton_8_clicked()
{
          QString NOM = ui->lineEdit_18->text();
          bool test = ui->lineEdit_18->text()==NULL ;
    if(test)
         {
             ui->Affichage_3->setModel(tmpchantiers.afficher());


         }
         else
        {
          ui->Affichage_3->setModel(tmpchantiers.afficher_chantiers(NOM));
        }
}

void gestion_chantiers::on_pushButton_7_clicked()
{
    QString NOM = ui->lineEdit_17->text();
          bool test = ui->lineEdit_17->text()==NULL ;
    if(test)
         {
             ui->Affichage_2->setModel(tmpsocietes.afficher());


         }
         else
        {
          ui->Affichage_2->setModel(tmpsocietes.afficher_societes(NOM));

        }

}

void gestion_chantiers::on_lineEdit_17_textChanged(const QString &arg1)
{


    QString NOM = ui->lineEdit_17->text();

       bool test = ui->lineEdit_17->text()==NULL ;
       if(test)
       {
           ui->Affichage_2->setModel(tmpsocietes.afficher());


       }
       else
       {
           ui->Affichage_2->setModel(tmpsocietes.afficher_societes(NOM));

       }
}

void gestion_chantiers::on_lineEdit_18_textChanged(const QString &arg1)
{
    QString NOM = ui->lineEdit_18->text();


       bool test = ui->lineEdit_18->text()==NULL ;
       if(test)
       {
           ui->Affichage_3->setModel(tmpchantiers.afficher());


       }
       else
       {
           ui->Affichage_3->setModel(tmpchantiers.afficher_chantiers(arg1));

       }

}

void gestion_chantiers::on_imprimer_clicked()
{

        QPdfWriter pdf("C:/Users/asus/Desktop/imprimer_selim/Pdf.pdf");
        QPainter painter(&pdf);
        int i = 4000;
        painter.setPen(Qt::color1);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des Societes ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);
        painter.drawPixmap(QRect(6600,70,1920*2,1080*2),QPixmap("C:/Users/asus/Desktop/imprimer_selim/baladitech.png"));
        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"ID");
        painter.drawText(1700,3300,"NOM");

        QSqlQuery query;
        query.prepare("select * from SOCIETES");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());

            i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/asus/Desktop/imprimer_selim/Pdf.pdf"));
            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}

void gestion_chantiers::on_retour_clicked()
{
    hide();
}

void gestion_chantiers::on_retour_2_clicked()
{
    hide();
}
