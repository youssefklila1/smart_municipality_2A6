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

}

Dialog::~Dialog()
{
    delete ui;
}
// afficher les donnees sur la table don
void Dialog::on_afficher_table_don_clicked()
{    ui->tableDon->setModel(tmp1.afficher());


}



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
