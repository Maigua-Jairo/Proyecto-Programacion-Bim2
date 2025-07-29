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
    QString nombre = ui->EliminarNombre->text().trimmed();
    QString apellido = ui->EliminarApellido->text().trimmed();

    if (nombre.isEmpty() || apellido.isEmpty()) {
        QMessageBox::warning(this, "Campos vacíos", "Debes llenar nombre y apellido.");
        return;
    }

    QFile archivo("C://listaContactos//contactos.txt");
    if (!archivo.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error", "No se pudo abrir el archivo.");
        return;
    }

    QTextStream in(&archivo);
    QStringList nuevosDatos;
    QString nombreActual, apellidoActual;
    bool eliminado = false;
    QStringList buffer;

    while (!in.atEnd()) {
        QString linea = in.readLine().trimmed();

        if (linea.startsWith("Nombre: ")) {
            nombreActual = linea.mid(8);
        } else if (linea.startsWith("Apellido: ")) {
            apellidoActual = linea.mid(10);
        }

        buffer << linea;

        if (linea.startsWith("----------------")) {
            if (nombreActual == nombre && apellidoActual == apellido) {
                eliminado = true;
                buffer.clear();  // Descarta este bloque
            } else {
                nuevosDatos << buffer;
                buffer.clear();
            }
        }
    }

    archivo.close();

    if (!eliminado) {
        QMessageBox::information(this, "No encontrado", "Contacto no encontrado.");
        return;
    }

    // Reescribimos el archivo sin el contacto eliminado
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&archivo);
        for (const QString &linea : nuevosDatos) {
            out << linea << "\n";
        }
        archivo.close();
        QMessageBox::information(this, "Eliminado", "Contacto eliminado correctamente.");
        accept();
    } else {
        QMessageBox::warning(this, "Error", "No se pudo escribir el archivo.");
    }
}

void Eliminar:: on_ConfEliminar_rejected()
{
    reject();
}

