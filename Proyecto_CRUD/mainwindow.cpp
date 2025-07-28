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
void MainWindow::on_btnBuscar_clicked()
{
    QString nombreBuscado = ui->lineEditBuscar->text().trimmed();
    QFile archivo("contactos.txt");

    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        return;
    }

    QTextStream in(&archivo);
    QString contactoEncontrado;
    QStringList lineas;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();
        QStringList campos = linea.split(";");

        if (campos.size() == 4 && campos[0] == nombreBuscado) {
            contactoEncontrado = linea;
            ui->lineEditNombre->setText(campos[0]);
            ui->lineEditTelefono->setText(campos[1]);
            ui->lineEditCorreo->setText(campos[2]);
            ui->lineEditDireccion->setText(campos[3]);
        } else {
            lineas << linea;
        }
    }

    archivo.close();

    if (contactoEncontrado.isEmpty()) {
        QMessageBox::information(this, "No encontrado", "El contacto no existe.");
    } else {
        contactosSinModificar = lineas;
    }
}

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

    // Limpiar los campos
    ui->lineEditBuscar->clear();
    ui->lineEditNombre->clear();
    ui->lineEditTelefono->clear();
    ui->lineEditCorreo->clear();
    ui->lineEditDireccion->clear();
}
