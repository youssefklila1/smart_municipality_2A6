#include "gestion_employe.h"
#include "ui_gestion_employe.h"
#include "gestion_employe.h"
#include "ui_gestion_employe.h"
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
#include<QPdfWriter>
#include<QPainter>
#include<QDesktopServices>
#include<QUrl>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QMessageBox>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>

gestion_employe::gestion_employe(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_employe)
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

          gestion_employe::afficherStatistique();

          //for email tab
                connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
                connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
}

gestion_employe::~gestion_employe()
{
    delete ui;
}

//======================================================================EMPLOYE================================================
void gestion_employe::on_ajoute_employe_clicked()
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


           if(matricule>999999|| nom==""||prenom==""||email==""||datenaiss==""||anneesexp==0||nom.length()>10||prenom.length()>10)


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
               gestion_employe::afficherStatistique();
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



void gestion_employe::on_supprimer_employe_clicked()
{
    int res=ui->comboBox__supprimer_employe->currentText().toInt();
            bool test=tempemploye.supprimer(res);
            if(test)

            {   gestion_employe::afficherStatistique();
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



void gestion_employe::on_modifier_employe_clicked()
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

void gestion_employe::on_rechercher_employe_clicked()
{
    QString reff = ui->recherche_employe_matricule->currentText();
    ui->tableView->setModel(tempemploye.afficher_rech(reff));
}

void gestion_employe::on_Trier_employe_clicked()
{
    if(ui->combobox_tri_employe->currentText()=="decroissant"){ui->tableView->setModel(tempemploye.tri_ref());}
          if(ui->combobox_tri_employe->currentText()=="Ordre alphabetique"){ui->tableView->setModel(tempemploye.tri_nom());}
}


void gestion_employe::on_recherche_dynamique_employe_textChanged(const QString &arg1)
{
    ui->tableView->setModel(tempemploye.rechercheDynamic(arg1));
}

//==========================================================Congee============================================================




void gestion_employe::on_ajouter_conge_clicked()
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
            gestion_employe::afficherStatistique();
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


void gestion_employe::on_supprimer_conge_clicked()
{
    int res=ui->comboBox_supprimer_conge->currentText().toInt();
            bool test=tempconge.supprimer(res);
            if(test)
            {
                ui->comboBox_supprimer_conge->setModel(tempemploye.afficher());
                gestion_employe::afficherStatistique();
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



void gestion_employe::on_modifier_conge_clicked()
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






void gestion_employe::on_ajouter_tache_clicked()
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
else
        {
        tache t(matricule,identifiant,debut,fin,libelle);
         test= t.ajouter();
        }
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

void gestion_employe::on_supprimer_tache_clicked()
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

void gestion_employe::on_modifier_tache_clicked()
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

void gestion_employe::on_recherche_dynamique_textChanged(const QString &arg1)
{
    ui->tableView_3->setModel(temptache.rechercheDynamic(arg1));
}

void gestion_employe::on_rechercher_statique_taches_clicked()
{
    QString reff =ui->rechercher_tache_employe->currentText();
        ui->tableView_3->setModel(temptache.afficher_rech(reff));
}

void gestion_employe::on_pushButton_clicked()
{
    QMessageBox::critical(nullptr, QObject::tr("modifier un employe"),
                  QObject::tr("Erreur !\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestion_employe::on_imprimer_clicked()
{

                          QPdfWriter pdf("C:/Users/asus/Desktopeya/Pdf.pdf");
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
                                      QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/asus/Desktopeya/Pdf.pdf"));
                                      painter.end();
                                  }
                                  if (reponse == QMessageBox::No)
                                  {
                                       painter.end();
                                  }
}
void gestion_employe::afficherStatistique(){


    QSqlQuery query;

    //nombre de dons
            QString nb_conge="";
            query.prepare("SELECT COUNT(*) FROM CONGE");
            query.exec();
            while(query.next()){
            nb_conge= query.value(0).toString();}

     //nombre de famille

            QString nb_employe="";
            query.prepare("SELECT COUNT(*) FROM EMPLOYEN");
            query.exec();
            while(query.next()){
            nb_employe= query.value(0).toString();}



        QBarSet *set0 = new QBarSet("Jane");


           *set0 << nb_conge.toInt()  << nb_employe.toInt()   ;
        QBarSeries *series = new QBarSeries();
         series->append(set0);
         QChart *chart = new QChart();
             chart->addSeries(series);
             chart->setTitle("statistique employe");
             chart->setAnimationOptions(QChart::SeriesAnimations);

             QStringList categories;
                categories << "nombre employe" <<  "nombre conge" ;
                QBarCategoryAxis *axisX = new QBarCategoryAxis();
                axisX->append(categories);
                chart->addAxis(axisX, Qt::AlignBottom);
                series->attachAxis(axisX);



                chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);

                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->setParent(ui->horizontalFrame);
}
void  gestion_employe::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void   gestion_employe::sendMail()
{
    Smtp* smtp = new Smtp("youssef.klila@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("youssef.klila@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("youssef.klila@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void   gestion_employe::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
