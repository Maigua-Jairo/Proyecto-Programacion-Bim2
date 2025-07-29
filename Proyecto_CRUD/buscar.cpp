#include "buscar.h"
#include "ui_buscar.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include "contacto.h"
Buscar::Buscar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Buscar)
{
    ui->setupUi(this);
}

Buscar::~Buscar()
{
    delete ui;
}

void Buscar::on_BtnSearch_accepted()
{
    accepted();
}


void Buscar::on_BtnSearch_rejected()
{
    reject();
}

