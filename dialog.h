#ifndef DIALOG_H
#define DIALOG_H
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
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_11_clicked();

    void on_comboBox_3_currentIndexChanged(const QString &arg1);

    void on_radioButton_11_clicked();

    void on_checkBox_clicked();

    void on_checkBox_2_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_Affichage_4_clicked(const QModelIndex &index);

    void on_tabWidget_3_currentChanged(int index);

    void on_tabWidget_2_currentChanged(int index);

    void on_Affichage_4_activated(const QModelIndex &index);

    void on_commandLinkButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Dialog *ui;
    Societes tmpsocietes;
    Chantiers tmpchantiers;
};

#endif // DIALOG_H
