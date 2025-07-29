#include "eliminar.h"
#include "ui_eliminar.h"
#include "personas.h"
#include "contacto.h"
#include "buscar.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

Eliminar::Eliminar(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Eliminar)
{
    ui->setupUi(this);
    setWindowTitle("Eliminar Contacto");
}

Eliminar::~Eliminar()
{
    delete ui;
}

void Eliminar::on_ConfEliminar_accepted()
{

}

void Eliminar:: on_ConfEliminar_rejected()
{
    reject();
}

