#include "gestion_dons.h"
#include "ui_gestion_dons.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QMessageBox>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>



gestion_dons::gestion_dons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_dons)
{
    ui->setupUi(this);
    //update table don
     ui->tableDon->setModel(tmp1.afficher());
    //update table famille
     ui->table_famille->setModel(tmp2.afficher());
     ui->id_don_ajouter_famille->setModel(tmp1.afficher());
     gestion_dons::afficherStatistique();
     //for email tab
           connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
           connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));


}





gestion_dons::~gestion_dons()
{
    delete ui;
}



//------------------------------------------ CRUD DON ----------------------------------------------------//
//ajouter don


void gestion_dons::on_ajoute_don_clicked()
{
    QMessageBox msg;


        int matricule=ui->matricule_ajouter_don->text().toInt();
        int valeur=ui->valeur_ajouter_don->text().toInt();

        QString source=ui->Source_ajouter_don->text();
        QString type;
        QString autre;

    if(ui->argent->isChecked())
    {
        type="argent";
        autre="-";
    }
    else if(ui->autre->isChecked())
    {
        type="autre";
        autre=ui->autre_ajouter_don->currentText();
        valeur=0;
    }
    //don constructor
        Don d(matricule ,valeur ,source ,autre ,type);

    if(d.ajouter())
    {
    ui->tableDon->setModel(tmp1.afficher());
     gestion_dons::afficherStatistique();
    msg.setText("add succ");
    msg.exec();

    }else
    {
        msg.setText("failed to add");
        msg.exec();
    }
}

void gestion_dons::on_supprimer_don_clicked()
{
    QMessageBox msg;
        Don d;
        int matricule =ui->matricule_supprimer_don->text().toInt();
        if(d.supprimer(matricule)){
            ui->tableDon->setModel(tmp1.afficher());
             gestion_dons::afficherStatistique();
            msg.setText("element deleted succ");
            msg.exec();

        }
        else
        {
            msg.setText("failed to delete");
            msg.exec();
        }
}



void gestion_dons::on_modifier_don_clicked()
{
    QMessageBox msg;
       int matricule=ui->matricule_modifier_don->text().toInt();
       int valeur=ui->valeur_modifier_don->text().toInt();
       QString source=ui->source_modifier_don->text();
       QString type;
       if(ui->argent_modifier->isChecked()){ type =ui->argent_modifier->text();}
       if(ui->autre_modifier->isChecked()){ type =ui->autre_modifier->text();}
       QString autre;
        autre = ui->autre_modifier_don->currentText();

       if(ui->argent->isChecked())
       {
           type="argent";
           autre="N/A";
       }
       else if(ui->autre->isChecked())
       {
           type="autre";
           autre=ui->autre_modifier_don->currentText();
           valeur=0;
       }

       Don d;
   if(d.modifier(matricule,valeur,source,autre,type))
   {
   ui->tableDon->setModel(tmp1.afficher());
   msg.setText("update succ");
   msg.exec();

   }
   else
   {
       msg.setText("failed to update");
       msg.exec();
    }
}


//-----------------------------------CRUD FAMILLE--------------------------------------------//

void gestion_dons::on_ajouter_famille_clicked()
{
    QMessageBox msg;


            int matricule=ui->matricule_ajouter_famille->text().toInt();
            int nb_membres=ui->nombre_ajouter_famille->text().toInt();
            int don=ui->id_don_ajouter_famille->currentText().toInt();
            QString nom=ui->nom_ajouter_famille->text();
            QString besoin=ui->besoin_ajouter_famille->currentText();
            QString region=ui->region_ajouter_famille->text();



         famille f(matricule,nb_membres,don,nom,besoin,region);
           //famille f(matricule,nb_membres,don,nom,besoin,region);
        if(f.ajouter())
        {
        ui->table_famille->setModel(tmp2.afficher());
         gestion_dons::afficherStatistique();
        msg.setText("add succ");
        msg.exec();

        }else{
            msg.setText("failed to add");
            msg.exec();
        }
    }


void gestion_dons::on_supprimer_famille_clicked()
{
    QMessageBox msg;
        famille f;
        int matricule =ui->matricule_supprimer_famille->text().toInt();

        if(f.supprimer(matricule)){
    ui->table_famille->setModel(tmp2.afficher());
     gestion_dons::afficherStatistique();
    msg.setText("famille deleted succ");
            msg.exec();

        }else {
            msg.setText("failed to delete");
            msg.exec();
        }
}



void gestion_dons::on_modifier_famille_clicked()
{
    QMessageBox msg;


        int matricule=ui->matricule_modifier_famille->text().toInt();
        int nb_membres=ui->nombre_modifier_famille->text().toInt();
        int don=ui->id_don_modifier_famille->currentText().toInt();
        QString nom=ui->nom_modifier_famille->text();
        QString besoin=ui->besoin_modifier_famille->currentText();
        QString region=ui->region_modifier_famille->text();



     famille f;
     //(int matricule ,int nbr_membres,int don ,QString nom ,QString besoin ,QString region)
    if(f.modifier(matricule,nb_membres,don,nom,besoin,region))
    {
    ui->table_famille->setModel(tmp2.afficher());
    msg.setText("update succ");
    msg.exec();

    }
    else
    {
        msg.setText("failed to update");
        msg.exec();

}
   }
//----------------------------------------------les metiers--------------------------------//


void gestion_dons::on_afficher_don_trier_clicked()
{

    if(ui->matricule_trie->isChecked())
    {

        ui->tableDon->setModel(tmp1.afficherMatricule());
    }
    else if(ui->type_trie->isChecked())
    {

        ui->tableDon->setModel(tmp1.afficherType());
    }
    else
    {
        ui->tableDon->setModel(tmp1.afficher());
    }
}

void gestion_dons::on_afficher_tri_famille_clicked()
{
    if(ui->besoin_trie_famille->isChecked())
    {
        ui->table_famille->setModel(tmp2.afficherBesoin());

    }
    else if(ui->nbr_trie_famille->isChecked())
    {

        ui->table_famille->setModel(tmp2.afficherNBR());
    }
    else
    {
        ui->table_famille->setModel(tmp2.afficher());
    }
}

//recherche par nom dynamique

void gestion_dons::on_recherche_dynamique_famille_textChanged(const QString &arg1)
{
    ui->table_famille->setModel(tmp2.rechercheDynamic(arg1));
}

//statistique!!!!!!!!!!!!!!!!!
void gestion_dons::afficherStatistique(){


    QSqlQuery query;

    //nombre de dons
            QString nb_don="";
            query.prepare("SELECT COUNT(*) FROM DON");
            query.exec();
            while(query.next()){
            nb_don= query.value(0).toString();}

     //nombre de famille

            QString nb_famille="";
            query.prepare("SELECT COUNT(*) FROM FAMILLES");
            query.exec();
            while(query.next()){
            nb_famille= query.value(0).toString();}



        QBarSet *set0 = new QBarSet("Jane");


           *set0 << nb_don.toInt()  << nb_famille.toInt()   ;
        QBarSeries *series = new QBarSeries();
         series->append(set0);
         QChart *chart = new QChart();
             chart->addSeries(series);
             chart->setTitle("statistique dons");
             chart->setAnimationOptions(QChart::SeriesAnimations);

             QStringList categories;
                categories << "nombre don" <<  "nombre famille" ;
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

void gestion_dons::on_imprimer_clicked()
{
    QPdfWriter pdf("C:/Users/asus/Desktop/imprimer_mariem/Pdf.pdf");
        QPainter painter(&pdf);
       int i = 4000;
            painter.setPen(Qt::red);
            painter.setFont(QFont("Arial Black", 30));
            painter.drawText(1100,1200,"liste don ");
            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", 50));

            painter.drawRect(100,100,7300,2600);

            painter.drawRect(0,3000,9600,500);
            painter.setFont(QFont("Arial", 9));
            painter.drawText(200,3300,"MATRICULE");
            painter.drawText(1700,3300,"SOURCE");
            painter.drawText(3200,3300,"TYPE");
            painter.drawText(4900,3300,"VALEUR");

            QSqlQuery query;
            query.prepare("select * from DON");
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
                    QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/asus/Desktop/imprimer_mariem/Pdf.pdf"));
                    painter.end();
                }
                if (reponse == QMessageBox::No)
                {
                     painter.end();
                }
}
void  gestion_dons::browse()
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

void   gestion_dons::sendMail()
{
    Smtp* smtp = new Smtp("youssef.klila@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("youssef.klila@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("youssef.klila@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void   gestion_dons::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}
