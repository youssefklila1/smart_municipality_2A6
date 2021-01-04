#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->Affichage_2->setModel(tmpsocietes.afficher());
        ui->Affichage_2->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->Affichage_2->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->Affichage_3->setModel(tmpchantiers.afficher());
            ui->Affichage_3->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->Affichage_3->setSelectionMode(QAbstractItemView::SingleSelection);
         ui->Affichage_4->setModel(tmpchantiers.afficher_societes());
         ui->Affichage_4->setSelectionBehavior(QAbstractItemView::SelectRows);
         ui->Affichage_4->setSelectionMode(QAbstractItemView::SingleSelection);

}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_4_clicked()
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



void Dialog::on_pushButton_5_clicked()
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

void Dialog::on_pushButton_2_clicked()
{
    QItemSelectionModel *select = ui->Affichage_2->selectionModel();

        QString id =select->selectedRows(0).value(0).data().toString();

        if(tmpsocietes.supprimer(id))
        {
            ui->Affichage_2->setModel(tmpsocietes.afficher());
        }
}

void Dialog::on_pushButton_3_clicked()
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

void Dialog::on_pushButton_6_clicked()
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

void Dialog::on_pushButton_11_clicked()
{
    QItemSelectionModel *select = ui->Affichage_3->selectionModel();

        QString id =select->selectedRows(0).value(0).data().toString();

        if(tmpchantiers.supprimer(id))
        {
            ui->Affichage_3->setModel(tmpchantiers.afficher());
        }
}

//void Dialog::on_comboBox_3_currentIndexChanged(const QString &arg1)
//{
//    QString nom=ui->comboBox_3->currentText();
//        QSqlQuery query ;
//    query.prepare("select * from SOCIETES where NOM='"+nom+"'");
//}



//void Dialog::on_checkBox_clicked()
//{
//    bool test = true;
//          if (test)
//              {
//              ui->Affichage_2->setModel(tmpsocietes.afficher());

//                  ui->Affichage_2->setModel(tmpsocietes.trier());



//              }

//          else
//          {
//              QMessageBox::critical(nullptr, QObject::tr("trier societes"),
//                                    QObject::tr("Erreur !.\n"
//                                                "Click Cancel to exit."), QMessageBox::Cancel);
//          }
//}

//void Dialog::on_checkBox_2_clicked()
//{
//    bool test = true;
//          if (test)
//              {
//              ui->Affichage_2->setModel(tmpsocietes.afficher());

//                  ui->Affichage_2->setModel(tmpsocietes.trier_i());



//              }

//          else
//          {
//              QMessageBox::critical(nullptr, QObject::tr("trier societes"),
//                                    QObject::tr("Erreur !.\n"
//                                                "Click Cancel to exit."), QMessageBox::Cancel);
//          }
//}

void Dialog::on_radioButton_clicked()
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

void Dialog::on_radioButton_2_clicked()
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

void Dialog::on_radioButton_3_clicked()
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

void Dialog::on_radioButton_4_clicked()
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

void Dialog::on_radioButton_5_clicked()
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

void Dialog::on_Affichage_4_clicked(const QModelIndex &index)
{
    ui->lineEdit_3->setText(QString (ui->Affichage_4->model()->data(ui->Affichage_4->model()->index(index.row(),1)).toString()));
}

void Dialog::on_tabWidget_3_currentChanged(int index)
{
     ui->Affichage_4->setModel(tmpchantiers.afficher_societes());
     ui->Affichage_3->setModel(tmpchantiers.trier_ce());
}

void Dialog::on_tabWidget_2_currentChanged(int index)
{
     ui->Affichage_2->setModel(tmpsocietes.afficher());
}


void Dialog::on_commandLinkButton_clicked()
{
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget_2->setCurrentIndex(0);
}

void Dialog::on_pushButton_8_clicked()
{
    QString NOM = ui->lineEdit_18->text();
//        QString type_filmm = ui->TypeFilm->currentText();
//        QString date_filmm = ui->DateFilm->text();
    //     bool test = tempcommandes.afficher_films(nom_filmm,type_filmm,date_filmm);

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

void Dialog::on_pushButton_7_clicked()
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



void Dialog::on_lineEdit_18_textChanged(const QString &arg1)
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

void Dialog::on_lineEdit_17_textChanged(const QString &arg1)
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
