#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "contacto.h"
#include <QTextStream>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lista_contactos->setColumnCount(4);
    ui->lista_contactos->setHorizontalHeaderLabels({"Nombre", "Teléfono", "Email", "Dirección"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnGuardar_clicked()
{
    QFile file("contactos.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const Contacto &c : listaContactos) {
            out << c.nombre << "|" << c.telefono << "|" << c.email << "|" << c.pais << "\n";
        }
        file.close();
        QMessageBox::information(this, "Guardado", "Contactos guardados exitosamente.");
    }
}


void MainWindow::on_BtnAgregar_clicked()
{
    Contacto c;
    c.nombre = ui->Name->text();
    c.telefono = ui->Phone->text();
    c.email = ui->email->text();
    c.pais = ui->country->text();
    listaContactos.append(c);
    QMessageBox::information(this, "Agregado", "Contacto agreado correctamente");
}

