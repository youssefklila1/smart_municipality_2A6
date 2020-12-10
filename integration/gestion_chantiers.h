#ifndef GESTION_CHANTIERS_H
#define GESTION_CHANTIERS_H

#include <QDialog>

namespace Ui {
class gestion_chantiers;
}

class gestion_chantiers : public QDialog
{
    Q_OBJECT

public:
    explicit gestion_chantiers(QWidget *parent = nullptr);
    ~gestion_chantiers();

private:
    Ui::gestion_chantiers *ui;
};

#endif // GESTION_CHANTIERS_H
