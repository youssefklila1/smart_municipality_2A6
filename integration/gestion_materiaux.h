#ifndef GESTION_MATERIAUX_H
#define GESTION_MATERIAUX_H
#include "materiauxposs.h"
#include "materiauxmanq.h"
#include "matmaint.h"

#include <QDialog>

namespace Ui {
class gestion_materiaux;
}

class gestion_materiaux : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_materiaux(QWidget *parent = nullptr);
    ~gestion_materiaux();

private slots:
    void on_ajouterposs_clicked();

    void on_Modifier_materiel_possession_clicked();

    void on_supp_mat_poss1_clicked();

    void on_combo_box_recherche_poss_activated(int index);

    void on_comboBox_trier_poss_activated(int index);

    void on_supprimer_mat_poss_tab_clicked();

    void on_imprimer_mat_poss_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_ajoutermateriauxmanq_clicked();

    void on_modifier_materiel_manquant_clicked();

    void on_supprimermatmanq1_clicked();



    void on_comboBox_tri_ma_manq_activated(int index);

    void on_supprimer_mat_manq_tab_clicked();

    void on_comboBox_rechercher_mat_manq_activated(int index);

    void on_ajouter_mat_maintenace_clicked();

    void on_supprimer_mat_maintenace1_clicked();

    void on_modifier_materiaux_maintenance_clicked();

    void on_comboBox_tri_mat_maint_activated(int index);

    void on_supprimer_mat_maint_tab_clicked();

    void on_comboBox_rechercher_mat_maint_activated(int index);

private:
    Ui::gestion_materiaux *ui;
    Materiauxposs tempmatposs;
    Materiauxmanq tempmatmanq;
    Matmaint tempmatmaint;

};

#endif // GESTION_MATERIAUX_H
