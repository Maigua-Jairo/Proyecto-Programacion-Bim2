/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *BtnEliminar;
    QPushButton *BtnActualizar;
    QPushButton *BtnMostrar;
    QTableWidget *lista_contactos;
    QPushButton *BtnAgregar;
    QPushButton *BtnSalir;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(483, 294);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        BtnEliminar = new QPushButton(centralwidget);
        BtnEliminar->setObjectName("BtnEliminar");
        BtnEliminar->setGeometry(QRect(120, 230, 71, 21));
        BtnActualizar = new QPushButton(centralwidget);
        BtnActualizar->setObjectName("BtnActualizar");
        BtnActualizar->setGeometry(QRect(290, 230, 81, 21));
        BtnMostrar = new QPushButton(centralwidget);
        BtnMostrar->setObjectName("BtnMostrar");
        BtnMostrar->setGeometry(QRect(200, 230, 81, 21));
        lista_contactos = new QTableWidget(centralwidget);
        lista_contactos->setObjectName("lista_contactos");
        lista_contactos->setGeometry(QRect(30, 40, 431, 171));
        BtnAgregar = new QPushButton(centralwidget);
        BtnAgregar->setObjectName("BtnAgregar");
        BtnAgregar->setGeometry(QRect(20, 230, 81, 21));
        BtnSalir = new QPushButton(centralwidget);
        BtnSalir->setObjectName("BtnSalir");
        BtnSalir->setGeometry(QRect(380, 230, 71, 21));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(180, 10, 111, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 483, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        BtnEliminar->setText(QCoreApplication::translate("MainWindow", "Eliminar", nullptr));
        BtnActualizar->setText(QCoreApplication::translate("MainWindow", "Actualizar", nullptr));
        BtnMostrar->setText(QCoreApplication::translate("MainWindow", "Mostrar", nullptr));
        BtnAgregar->setText(QCoreApplication::translate("MainWindow", "Agregar", nullptr));
        BtnSalir->setText(QCoreApplication::translate("MainWindow", "Salir", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-weight:700;\">Lista de Contactos</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
