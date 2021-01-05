#ifndef GESTION_DONS_H
#define GESTION_DONS_H
#include "don.h"
#include <QDialog>
#include "don.h"
#include "famille.h"
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include "smtp.h"
#include <QDialog>

namespace Ui {
class gestion_dons;
}

class gestion_dons : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_dons(QWidget *parent = nullptr);
    ~gestion_dons();

private slots:
    void on_ajoute_don_clicked();

    void on_supprimer_don_clicked();

    void on_modifier_don_clicked();

    void on_ajouter_famille_clicked();

    void on_supprimer_famille_clicked();

    void on_modifier_famille_clicked();

    void on_afficher_don_trier_clicked();

    void on_afficher_tri_famille_clicked();

    void on_recherche_dynamique_famille_textChanged(const QString &arg1);
    void afficherStatistique();

    void on_imprimer_clicked();

    void sendMail();
    void mailSent(QString);
    void browse();


    void on_retour_2_clicked();

    void on_retour_3_clicked();

private:
    Ui::gestion_dons *ui;
        Don tmp1;
        famille tmp2;
        QStringList files ;

};

#endif // GESTION_DONS_H
