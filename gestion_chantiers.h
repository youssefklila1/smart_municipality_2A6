#ifndef GESTION_CHANTIERS_H
#define GESTION_CHANTIERS_H
#include "societes.h"
#include "chantiers.h"
#include <QDialog>
#include <QMainWindow>
#include <QWidget>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QRegularExpression>
#include <QTableWidgetItem>
#include <QDebug>
#include <QSqlTableModel>
#include <QAbstractItemView>
#include <QRegExp>
#include <QFileDialog>
#include <QPrinter>
#include<QPrintDialog>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>



namespace Ui {
class gestion_chantiers;
}

class gestion_chantiers : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_chantiers(QWidget *parent = nullptr);
    ~gestion_chantiers();

private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_tabWidget_2_tabBarClicked(int index);

    void on_tabWidget_3_tabBarClicked(int index);

    void on_Affichage_4_clicked(const QModelIndex &index);

    void on_commandLinkButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

    void on_lineEdit_17_textChanged(const QString &arg1);

    void on_lineEdit_18_textChanged(const QString &arg1);

    void on_imprimer_clicked();

private:
    Ui::gestion_chantiers *ui;
        Societes tmpsocietes;
        Chantiers tmpchantiers;

};

#endif // GESTION_CHANTIERS_H
