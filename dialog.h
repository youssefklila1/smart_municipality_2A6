#ifndef DIALOG_H
#define DIALOG_H

#include "materiauxPoss.h"
#include "materiauxmanq.h"
#include "matmaint.h"
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

    void on_ajouterposs_clicked();
    void on_supp_mat_poss1_clicked();

    void on_ajoutermateriauxmanq_clicked();
    void on_supprimermatmanq1_clicked();

    void on_ajouter_mat_maintenace_clicked();
    void on_supprimer_mat_maintenace1_clicked();






    void on_pushButton_4_clicked();

private:
    Ui::Dialog *ui;
    Materiauxposs tempmatposs;
    Materiauxmanq tempmatmanq;
    Matmaint tempmatmaint;



};

#endif // DIALOG_H
