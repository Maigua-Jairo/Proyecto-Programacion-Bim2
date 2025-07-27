#ifndef PERSONAS_H
#define PERSONAS_H
#include "contacto.h"
#include <QDialog>

namespace Ui {
class Personas;
}

class Personas : public QDialog
{
    Q_OBJECT

public:
    explicit Personas(QWidget *parent = nullptr);
    Contacto obtenerContacto() const;

    ~Personas();

private slots:
    void on_BtnGuardar_accepted();

    void on_BtnGuardar_rejected();

private:
    Ui::Personas *ui;
    QList<Contacto> listaContactos;
};

#endif // PERSONAS_H
