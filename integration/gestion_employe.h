#ifndef GESTION_EMPLOYE_H
#define GESTION_EMPLOYE_H
#include"employe.h"
#include"conges.h"
#include"tache.h"
#include <QDialog>

namespace Ui {
class gestion_employe;
}

class gestion_employe : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_employe(QWidget *parent = nullptr);
    ~gestion_employe();

private slots:
    void on_ajoute_employe_clicked();

    void on_supprimer_employe_clicked();

    void on_modifier_employe_clicked();

    void on_rechercher_employe_clicked();

    void on_Trier_employe_clicked();

    void on_ajouter_conge_clicked();

    void on_supprimer_conge_clicked();

    void on_modifier_conge_clicked();

    void on_recherche_dynamique_employe_textChanged(const QString &arg1);

    void on_ajouter_tache_clicked();

    void on_supprimer_tache_clicked();

    void on_modifier_tache_clicked();

    void on_recherche_dynamique_textChanged(const QString &arg1);

    void on_rechercher_statique_taches_clicked();

    void on_pushButton_clicked();

private:
    Ui::gestion_employe *ui;
         employe tempemploye;
         Conges tempconge;
         tache temptache;

};

#endif // GESTION_EMPLOYE_H
