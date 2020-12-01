#ifndef DIALOG_H
#define DIALOG_H
#include"employe.h"
#include"conges.h"
#include"tache.h"
#include <QDialog>

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
    void on_pushButton_clicked();

    void on_supprimer_employe_2_clicked();

    void on_Ajouter_clicked();

    void on_supprimer_conge_clicked();

    void on_AJOUTER_TACHE_clicked();

    void on_supprimer_tache_clicked();

    void on_modifier_employe_clicked();

    void on_rechercher_employe_clicked();

    void on_Trier_employe_clicked();

    void on_imprimer_conge_clicked();

    void on_modifier_conge_clicked();

    void on_modifier_tache_clicked();

private:
    Ui::Dialog *ui;
     employe tempemploye;
     Conges tempconge;
     tache temptache;
};

#endif // DIALOG_H
