// mainwindow.cpp
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "personas.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "buscar.h"
#include "eliminar.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Agenda de Contactos");
    ui->lista_contactos->setColumnCount(4);
    ui->lista_contactos->setHorizontalHeaderLabels({"Nombre", "Apellido", "Teléfono", "Email"});
    ui->lista_contactos->setRowCount(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_BtnAgregar_clicked()
{
    Personas p(this);
    p.setWindowTitle("Agregar Contacto");

    if (p.exec() == QDialog::Accepted) {
        Contacto c = p.obtenerContacto();

        QFile file("C://listaContactos//contactos.txt");
        if (file.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&file);
            out << "Nombre: " << c.nombre << "\n";
            out << "Apellido: " << c.apellido << "\n";
            out << "Teléfono: " << c.telefono << "\n";
            out << "Correo: " << c.email << "\n";
            out << "---------------------------\n";
            file.close();
            QMessageBox::information(this, "Guardado", "Contacto guardado correctamente.");
        } else {
            QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        }

    }
}

<<<<<<< Updated upstream
void MainWindow::on_btnActualizar_clicked()
{
    QString nuevoNombre = ui->lineEditNombre->text().trimmed();
    QString nuevoTelefono = ui->lineEditTelefono->text().trimmed();
    QString nuevoCorreo = ui->lineEditCorreo->text().trimmed();
    QString nuevaDireccion = ui->lineEditDireccion->text().trimmed();

    if (nuevoNombre.isEmpty()) {
        QMessageBox::warning(this, "Error", "Debe ingresar un nombre válido.");
        return;
    }

    QString nuevaLinea = nuevoNombre + ";" + nuevoTelefono + ";" + nuevoCorreo + ";" + nuevaDireccion;

    QFile archivo("contactos.txt");
    if (!archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escribir.");
        return;
    }

    QTextStream out(&archivo);
    for (const QString &linea : contactosSinModificar) {
        out << linea << "\n";
    }

    out << nuevaLinea << "\n";
    archivo.close();

    QMessageBox::information(this, "Actualizado", "El contacto se actualizó correctamente.");

    // Limpiar campos
    ui->lineEditBuscar->clear();
    ui->lineEditNombre->clear();
    ui->lineEditTelefono->clear();
    ui->lineEditCorreo->clear();
    ui->lineEditDireccion->clear();
}

void MainWindow::on_BtnEliminar_clicked()
{
    QString nombreaEliminar = ui->lineEditBuscar->text().trimmed();
    if (nombreaEliminar.isEmpty()){
        QMessageBox::warning(this, "Error", "Ingrese el nomrbe del contacto a eliminar");
        return;
    }
    QFile archivo("contactos.txt");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        return;
    }
=======
void MainWindow::on_BtnEliminar_clicked()
{
    Eliminar d(this);
    d.exec();
}

void MainWindow::on_BtnMostrar_clicked()
{
}
void MainWindow::on_BtnActualizar_clicked()
{
>>>>>>> Stashed changes

    QTextStream in(&archivo);
    QStringList nuevasLineas;
    bool eliminado = false;

    // Leemos el archivo y omitimos el contacto a eliminar
    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        QStringList campos = linea.split(";");

        if (campos.size() == 4 && campos[0] == nombreaEliminar) {
            eliminado = true;
            continue; // no guardamos esta línea
        }
        nuevasLineas << linea;
    }
    archivo.close();

    if (!eliminado) {
        QMessageBox::information(this, "No encontrado", "El contacto no fue encontrado.");
        return;
    }

    // Sobrescribimos el archivo con los contactos restantes
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QTextStream out(&archivo);
        for (const QString &linea : nuevasLineas) {
            out << linea << "\n";
        }
        archivo.close();
        QMessageBox::information(this, "Eliminado", "El contacto fue eliminado con éxito.");
    } else {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo para escribir.");
    }

    //Limpiar los campos 
    ui->lineEditBuscar->clear();
    ui->lineEditNombre->clear();
    ui->lineEditTelefono->clear();
    ui->lineEditCorreo->clear();
    ui->lineEditDireccion->clear();
}
<<<<<<< Updated upstream
=======

void MainWindow::actualizarTabla()
{
    ui->lista_contactos->setRowCount(listaContactos.size());
    for (int i = 0; i < listaContactos.size(); ++i) {
        ui->lista_contactos->setItem(i, 0, new QTableWidgetItem(listaContactos[i].nombre));
        ui->lista_contactos->setItem(i, 1, new QTableWidgetItem(listaContactos[i].apellido));
         ui->lista_contactos->setItem(i, 2, new QTableWidgetItem(listaContactos[i].telefono));
        ui->lista_contactos->setItem(i, 3, new QTableWidgetItem(listaContactos[i].email));
    }
}


void MainWindow::on_BtnSalir_clicked()
{
    QMessageBox:: warning(this, "ADVERTENCIA", "El programa ha finalizado");
    close();
}

>>>>>>> Stashed changes
