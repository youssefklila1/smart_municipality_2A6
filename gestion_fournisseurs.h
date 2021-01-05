#ifndef GESTION_FOURNISSEURS_H
#define GESTION_FOURNISSEURS_H
#include "fournisseurs.h"
#include "bondescommandes.h"
#include "produit.h"

#include <QDialog>

namespace Ui {
class gestion_fournisseurs;
}

class gestion_fournisseurs : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_fournisseurs(QWidget *parent = nullptr);
    ~gestion_fournisseurs();

private slots:
    void on_ajouter_fournisseur_clicked();

    void on_afficher_fournisseur_clicked();

    void on_pushButton_clicked();

    void on_rechercher_fournisseur_clicked();

    void on_modifier_fournisseur_clicked();

    void on_ajouterbon_clicked();

    void on_afficher_don_clicked();

    void on_supprimer_bon_clicked();

    void on_rechercher_bon_clicked();

    void on_pushButton_2_clicked();

    void on_ajouter_pro_clicked();

    void on_supprimer_pro_clicked();

    void on_afficher_pro_clicked();

    void on_chercher_pro_clicked();

    void on_modifier_pro_clicked();

    void on_tri_bon_clicked();

    void on_tri_four_clicked();

    void on_tri_pro_clicked();

    void on_pushButton_3_clicked();

    void on_retour_2_clicked();

    void on_retour_3_clicked();

    void on_retour_4_clicked();

private:
    Ui::gestion_fournisseurs *ui;
        Fournisseurs tempfour;
        Bondescommandes tempband ;
        produit tempprod ;

};

#endif // GESTION_FOURNISSEURS_H
