#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_connection_clicked();

    void on_gestion_materiaux_clicked();

    void on_gestion_employe_clicked();

    void on_gestion_dons_clicked();



    void on_gestion_evenement_clicked();

    void on_gestion_fournisseurs_clicked();

    void on_gestion_chantiers_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
