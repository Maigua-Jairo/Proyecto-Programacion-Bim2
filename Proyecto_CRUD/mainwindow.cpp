#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "contacto.h"
#include <QTextStream>
#include <QFile>
#include "personas.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Agenda de Contactos"); //Funcion para cambiar el titulo de la ventana
    ui->lista_contactos->setColumnCount(4);
    ui->lista_contactos->setHorizontalHeaderLabels({"Nombre", "Teléfono", "Email", "Dirección"});
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnAgregar_clicked()
{
    Personas p(this);
    p.setWindowTitle("Agregar Nuevo Contacto");
    if (p.exec() == QDialog::Accepted) {
        Contacto c = p.obtenerContacto(); // Obtenemos los datos reales

        QFile file("C://ListaContactos//contactos.txt"); // Usa doble barra si es necesario

        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            int numero = listaContactos.size() + 1;
            out << "Contacto #" << numero << "\n";
            out << "Nombre: " << c.nombre << "\n";
            out << "Teléfono: " << c.telefono << "\n";
            out << "Correo: " << c.email << "\n";
            out << "---------------------------\n";
            file.close();
            QMessageBox::information(this, "Guardado", "Contacto guardado correctamente.");

        } else {
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        }
         listaContactos.append(c);
    }

 }

void MainWindow::on_BtnEliminar_clicked()
{

}

