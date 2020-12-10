#include "gestion_chantiers.h"
#include "ui_gestion_chantiers.h"

gestion_chantiers::gestion_chantiers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_chantiers)
{
    ui->setupUi(this);
}

gestion_chantiers::~gestion_chantiers()
{
    delete ui;
}
