/********************************************************************************
** Form generated from reading UI file 'buscar.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUSCAR_H
#define UI_BUSCAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Buscar
{
public:
    QLabel *label;
    QLineEdit *ActNombre;
    QDialogButtonBox *BtnSearch;
    QLineEdit *NuevoTelefono;
    QLineEdit *NuevoCorreo;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *ActApellido;

    void setupUi(QDialog *Buscar)
    {
        if (Buscar->objectName().isEmpty())
            Buscar->setObjectName("Buscar");
        Buscar->resize(477, 254);
        label = new QLabel(Buscar);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 91, 21));
        ActNombre = new QLineEdit(Buscar);
        ActNombre->setObjectName("ActNombre");
        ActNombre->setGeometry(QRect(170, 20, 141, 24));
        BtnSearch = new QDialogButtonBox(Buscar);
        BtnSearch->setObjectName("BtnSearch");
        BtnSearch->setGeometry(QRect(290, 220, 166, 24));
        BtnSearch->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        NuevoTelefono = new QLineEdit(Buscar);
        NuevoTelefono->setObjectName("NuevoTelefono");
        NuevoTelefono->setGeometry(QRect(100, 120, 111, 24));
        NuevoCorreo = new QLineEdit(Buscar);
        NuevoCorreo->setObjectName("NuevoCorreo");
        NuevoCorreo->setGeometry(QRect(310, 120, 121, 24));
        label_3 = new QLabel(Buscar);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(190, 80, 151, 31));
        label_5 = new QLabel(Buscar);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(50, 120, 61, 21));
        label_6 = new QLabel(Buscar);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(260, 120, 51, 21));
        label_7 = new QLabel(Buscar);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(110, 50, 61, 21));
        ActApellido = new QLineEdit(Buscar);
        ActApellido->setObjectName("ActApellido");
        ActApellido->setGeometry(QRect(170, 50, 141, 24));

        retranslateUi(Buscar);

        QMetaObject::connectSlotsByName(Buscar);
    } // setupUi

    void retranslateUi(QDialog *Buscar)
    {
        Buscar->setWindowTitle(QCoreApplication::translate("Buscar", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Buscar", "Primer Nombre:", nullptr));
        label_3->setText(QCoreApplication::translate("Buscar", "<html><head/><body><p><span style=\" font-size:12pt; font-weight:700;\">Nuevos Datos</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Buscar", "Tel\303\251fono:", nullptr));
        label_6->setText(QCoreApplication::translate("Buscar", "Correo:", nullptr));
        label_7->setText(QCoreApplication::translate("Buscar", "Apellido:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Buscar: public Ui_Buscar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUSCAR_H
