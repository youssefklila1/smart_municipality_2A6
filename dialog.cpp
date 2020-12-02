#include "dialog.h"
#include "ui_dialog.h"
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include<QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //afficher don
    ui->tableDon->setModel(tmp1.afficher());
    //afficher famille
    ui->table_famille->setModel(tmp2.afficher());

Dialog::afficherLesDons();
Dialog::afficherStatistique();
}

Dialog::~Dialog()
{
    delete ui;
}
// afficher les donnees sur la table don
void Dialog::on_afficher_table_don_clicked()
{    ui->tableDon->setModel(tmp1.afficher());


}


//--------------------------------------- CRUD DON ----------------------------------------------------//
//ajouter don
void Dialog::on_pushButton_2_clicked()
{QMessageBox msg;


    int matricule=ui->matricule_ajouter_don->text().toInt();
    int valeur=ui->valeur_ajouter_don->text().toInt();

    QString source=ui->Source_ajouter_don->text();
    QString type;
    QString autre;

if(ui->argent->isChecked()){
    type="argent";
    autre="N/A";
}else if(ui->autre->isChecked()) {
    type="autre";
    autre=ui->autre_ajouter_don->currentText();
    valeur=0;
}

    Don d(matricule ,valeur ,source ,autre ,type);
if(d.ajouter())
{
ui->tableDon->setModel(tmp1.afficher());
msg.setText("add succ");
msg.exec();

}else{
    msg.setText("failed to add");
    msg.exec();
}

}
//supprimer don
void Dialog::on_pushButton_5_clicked()
{QMessageBox msg;
    Don d;
    int matricule =ui->matricule_supprimer_don->text().toInt();
    if(d.supprimer(matricule)){
        ui->tableDon->setModel(tmp1.afficher());
        msg.setText("element deleted succ");
        msg.exec();

    }else {
        msg.setText("failed to delete");
        msg.exec();
    }

}
//modifierr don
void Dialog::on_modifier_don_clicked()
{
    QMessageBox msg;
    int matricule=ui->matricule_modifier_don->text().toInt();
    int valeur=ui->valeur_modifier_don->text().toInt();
    QString source=ui->source_modifier_don->text();
    QString type;
    QString autre;

    if(ui->argent->isChecked()){
        type="argent";
        autre="N/A";
    }else if(ui->autre->isChecked()) {
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

}else{
    msg.setText("failed to update");
    msg.exec();
}

}
//----------------CRUD FAMILLE--------------------------------------------//
//remplir combo box des dons
void Dialog::afficherLesDons(){

ui->id_don_modifier_famille->clear();

ui->id_don_ajouter_famille->clear();

    QSqlQuery query;
            query.prepare("SELECT ID FROM MYRIAM.DON ");
            if(query.exec()){
                while(query.next()){
                    ui->id_don_modifier_famille->addItem(query.value(0).toString());
                    ui->id_don_ajouter_famille->addItem(query.value(0).toString());

                }
            }
}





void Dialog::on_ajouter_famille_clicked()
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
    msg.setText("add succ");
    msg.exec();

    }else{
        msg.setText("failed to add");
        msg.exec();
    }
}
//supprimer famille
void Dialog::on_supprimer_famille_2_clicked()
{QMessageBox msg;
    famille f;
    int matricule =ui->matricule_supprimer_famille->text().toInt();

    if(f.supprimer(matricule)){
ui->table_famille->setModel(tmp2.afficher());
msg.setText("famille deleted succ");
        msg.exec();

    }else {
        msg.setText("failed to delete");
        msg.exec();
    }

}
//modifier famille


void Dialog::on_modifier_famille_clicked()
{QMessageBox msg;


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

}else{
    msg.setText("failed to update");
    msg.exec();
}

}
//---------------------------les metiers--------------------------------//

//trier don
void Dialog::on_afficher_don_trier_clicked()
{


if(ui->matricule_trie->isChecked()){

    ui->tableDon->setModel(tmp1.afficherMatricule());
}else if(ui->type_trie->isChecked()){

    ui->tableDon->setModel(tmp1.afficherType());
}else {
    ui->tableDon->setModel(tmp1.afficher());
}


}
//trier famille
void Dialog::on_afficher_famille_clicked()
{
    if(ui->besoin_trie_famille->isChecked()){
        ui->table_famille->setModel(tmp2.afficherBesoin());

    }else if(ui->nbr_trie_famille->isChecked()){

        ui->table_famille->setModel(tmp2.afficherNBR());
    }else {
        ui->table_famille->setModel(tmp2.afficher());
    }

}
//recherche par nom
void Dialog::on_lineEdit_textChanged(const QString &arg1)
{
    ui->table_famille->setModel(tmp2.rechercheDynamic(arg1));
}

void Dialog::on_pushButton_clicked()
{
    QSqlQuery query;

    //nombre de dons
            QString nb_don="";
            query.prepare("SELECT COUNT(*) FROM MYRIAM.DON");
            query.exec();
            while(query.next()){
            nb_don= query.value(0).toString();}

     //nombre de famille

            QString nb_famille="";
            query.prepare("SELECT COUNT(*) FROM MYRIAM.FAMILLES");
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

                /*QValueAxis *axisY = new QValueAxis();
                axisY->setRange(0,qt_besoin.toInt()+10);
                chart->addAxis(axisY, Qt::AlignLeft);
                series->attachAxis(axisY);*/

                chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);

                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->setParent(ui->horizontalFrame);

}
//statistique
void Dialog::afficherStatistique(){


    QSqlQuery query;

    //nombre de dons
            QString nb_don="";
            query.prepare("SELECT COUNT(*) FROM MYRIAM.DON");
            query.exec();
            while(query.next()){
            nb_don= query.value(0).toString();}

     //nombre de famille

            QString nb_famille="";
            query.prepare("SELECT COUNT(*) FROM MYRIAM.FAMILLES");
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

                /*QValueAxis *axisY = new QValueAxis();
                axisY->setRange(0,qt_besoin.toInt()+10);
                chart->addAxis(axisY, Qt::AlignLeft);
                series->attachAxis(axisY);*/

                chart->legend()->setVisible(true);
                    chart->legend()->setAlignment(Qt::AlignBottom);

                    QChartView *chartView = new QChartView(chart);
                    chartView->setRenderHint(QPainter::Antialiasing);
                    chartView->setParent(ui->horizontalFrame);
}


