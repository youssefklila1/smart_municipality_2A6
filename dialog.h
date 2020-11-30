#ifndef DIALOG_H
#define DIALOG_H
#include "don.h"
#include <QDialog>
#include "don.h"

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

private:
    Ui::Dialog *ui;
    Don tmp1;

};

#endif // DIALOG_H
