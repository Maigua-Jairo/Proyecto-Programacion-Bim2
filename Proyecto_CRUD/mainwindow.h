#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "contacto.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_BtnAgregar_clicked();

    void on_BtnMostrar_clicked();

    void on_BtnActualizar_clicked();

    void on_BtnSalir_clicked();

    void on_BtnEliminar_clicked();

private:
    void actualizarTabla();
    void cargarDesdeArchivo();

    Ui::MainWindow *ui;
    QList<Contacto> listaContactos;
};
#endif //MainWindow_H
