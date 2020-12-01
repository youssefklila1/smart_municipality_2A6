#ifndef DIALOG_H
#define DIALOG_H
#include "don.h"
#include <QDialog>
#include "don.h"
#include "famille.h"
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
    void on_afficher_table_don_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_modifier_don_clicked();

    void afficherLesDons();
    void on_ajouter_famille_clicked();

    void on_supprimer_famille_2_clicked();

    void on_modifier_famille_clicked();

    void on_afficher_don_trier_clicked();

    void on_afficher_famille_clicked();

private:
    Ui::Dialog *ui;
    Don tmp1;

    famille tmp2;

};

#endif // DIALOG_H
