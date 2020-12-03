#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include "salles.h"
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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();
    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_comboBox_2_activated(const QString &arg1);

    void on_pushButton_modifier_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_rechercher_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_modifier_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_rechercherNOM_clicked();

    void on_pushButton_rechercherPRENOM_clicked();

    void on_pushButton_rechercherREF_clicked();

    void on_pushButton_rechercherLIEU_clicked();

    void on_pushButton_rechercherDATE_clicked();
    bool verif();
    bool verifS();



private:
    Ui::MainWindow *ui;
    Client tmpclient;
    salles tmpsalles;
};
#endif // MAINWINDOW_H
