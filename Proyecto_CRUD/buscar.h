#ifndef BUSCAR_H
#define BUSCAR_H

#include <QDialog>

namespace Ui {
class Buscar;
}

class Buscar : public QDialog
{
    Q_OBJECT

public:
    explicit Buscar(QWidget *parent = nullptr);
    ~Buscar();

private slots:
    void on_BtnSearch_accepted();

    void on_BtnSearch_rejected();

private:
    Ui::Buscar *ui;
};

#endif // BUSCAR_H
