#ifndef DIALOG_H
#define DIALOG_H
#include "don.h"
#include <QDialog>
#include "don.h"
#include "famille.h"

#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:


    void on_pushButton_2_clicked();


    void on_modifier_don_clicked();
//remplir combo boc avec les dons
    void afficherLesDons();
    //statistique
    void afficherStatistique();
    void on_ajouter_famille_clicked();

    void on_supprimer_famille_2_clicked();

    void on_modifier_famille_clicked();

    void on_afficher_don_trier_clicked();

    void on_afficher_famille_clicked();
//recherche dynamique
    void on_lineEdit_textChanged(const QString &arg1);


    void on_supprimer_don_clicked();

private:
    Ui::Dialog *ui;

    Don tmp1;
    famille tmp2;

};

#endif // DIALOG_H
