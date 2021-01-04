#ifndef GESTION_EVENEMENT_H
#define GESTION_EVENEMENT_H
#include "client.h"
#include "salles.h"

#include <QDialog>

namespace Ui {
class gestion_evenement;
}

class gestion_evenement : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_evenement(QWidget *parent = nullptr);
    ~gestion_evenement();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pb_ajouter_clicked();

    bool verif();
    bool verifS();

    void on_pb_supprimer_clicked();

    void on_pushButton_modifier_clicked();

    void on_tri_cin_clicked();

    void on_tri_nom_clicked();

    void on_pushButton_rechercher_cin_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_4_clicked();

    void on_pushButton_rechercherREF_clicked();

    void on_pushButton_rechercherLIEU_clicked();

    void on_pushButton_rechercherDATE_clicked();

    void on_pushButton_rechercherPRENOM_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_rechercherNOM_clicked();

private:
    Ui::gestion_evenement *ui;
        Client tmpclient;
        salles tmpsalles;

};

#endif // GESTION_EVENEMENT_H
