#ifndef ELIMINAR_H
#define ELIMINAR_H

#include <QDialog>

namespace Ui {
class Eliminar;
}

class Eliminar : public QDialog
{
    Q_OBJECT

public:
    explicit Eliminar(QWidget *parent = nullptr);
    ~Eliminar();

private slots:
    void on_ConfEliminar_accepted();

    void on_ConfEliminar_rejected();

private:
    Ui::Eliminar *ui;
};

#endif // ELIMINAR_H
