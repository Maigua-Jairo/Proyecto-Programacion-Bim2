#include "personas.h"
#include "ui_personas.h"
#include "contacto.h"
#include <QFile>
#include <QMessageBox>
#include "mainwindow.h"

Personas::Personas(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Personas)
{
    ui->setupUi(this);
}

Personas::~Personas()
{
    delete ui;
}

Contacto Personas::obtenerContacto() const
{
    Contacto c;
    c.nombre = ui->Name->text();
    c.telefono = ui->Phone->text();
    c.email = ui->Correo->text();
    c.apellido = ui->LastName->text();
    return c;
}


void Personas::on_BtnGuardar_accepted()
{

    accept();  // Cierra la ventana y notifica éxito
}



void Personas::on_BtnGuardar_rejected()
{
    reject();
}

