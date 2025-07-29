/********************************************************************************
** Form generated from reading UI file 'eliminar.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ELIMINAR_H
#define UI_ELIMINAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Eliminar
{
public:
    QLabel *label;
    QLineEdit *EliminarNombre;
    QLabel *label_2;
    QLineEdit *EliminarApellido;
    QDialogButtonBox *ConfEliminar;

    void setupUi(QDialog *Eliminar)
    {
        if (Eliminar->objectName().isEmpty())
            Eliminar->setObjectName("Eliminar");
        Eliminar->resize(400, 123);
        label = new QLabel(Eliminar);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 91, 16));
        EliminarNombre = new QLineEdit(Eliminar);
        EliminarNombre->setObjectName("EliminarNombre");
        EliminarNombre->setGeometry(QRect(150, 20, 113, 24));
        label_2 = new QLabel(Eliminar);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 60, 51, 16));
        EliminarApellido = new QLineEdit(Eliminar);
        EliminarApellido->setObjectName("EliminarApellido");
        EliminarApellido->setGeometry(QRect(150, 60, 113, 24));
        ConfEliminar = new QDialogButtonBox(Eliminar);
        ConfEliminar->setObjectName("ConfEliminar");
        ConfEliminar->setGeometry(QRect(230, 90, 166, 24));
        ConfEliminar->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        retranslateUi(Eliminar);

        QMetaObject::connectSlotsByName(Eliminar);
    } // setupUi

    void retranslateUi(QDialog *Eliminar)
    {
        Eliminar->setWindowTitle(QCoreApplication::translate("Eliminar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Eliminar", "Prmer Nombre: ", nullptr));
        label_2->setText(QCoreApplication::translate("Eliminar", "Apellido:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Eliminar: public Ui_Eliminar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ELIMINAR_H
