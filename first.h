#ifndef FIRST_H
#define FIRST_H

#include <QDialog>

namespace Ui {
class first;
}

class first : public QDialog
{
    Q_OBJECT

public:
    explicit first(QWidget *parent = nullptr);
    ~first();

private slots:
    void on_connection_clicked();

    void on_gestion_materiaux_clicked();

    void on_gestion_employe_clicked();

    void on_gestion_dons_clicked();



    void on_gestion_evenement_clicked();

    void on_gestion_fournisseurs_clicked();

    void on_gestion_chantiers_clicked();

private:
    Ui::first *ui;

};

#endif // FIRST_H
