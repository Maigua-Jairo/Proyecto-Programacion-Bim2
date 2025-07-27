/********************************************************************************
** Form generated from reading UI file 'personas.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSONAS_H
#define UI_PERSONAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Personas
{
public:
    QDialogButtonBox *BtnGuardar;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Name;
    QLineEdit *LastName;
    QLineEdit *Phone;
    QLineEdit *Correo;

    void setupUi(QDialog *Personas)
    {
        if (Personas->objectName().isEmpty())
            Personas->setObjectName("Personas");
        Personas->resize(400, 300);
        BtnGuardar = new QDialogButtonBox(Personas);
        BtnGuardar->setObjectName("BtnGuardar");
        BtnGuardar->setGeometry(QRect(230, 270, 166, 24));
        BtnGuardar->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(Personas);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 30, 91, 21));
        label_2 = new QLabel(Personas);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 110, 61, 21));
        label_3 = new QLabel(Personas);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(90, 150, 49, 16));
        label_4 = new QLabel(Personas);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 70, 61, 21));
        Name = new QLineEdit(Personas);
        Name->setObjectName("Name");
        Name->setGeometry(QRect(140, 30, 131, 24));
        LastName = new QLineEdit(Personas);
        LastName->setObjectName("LastName");
        LastName->setGeometry(QRect(140, 70, 131, 24));
        Phone = new QLineEdit(Personas);
        Phone->setObjectName("Phone");
        Phone->setGeometry(QRect(140, 110, 131, 24));
        Correo = new QLineEdit(Personas);
        Correo->setObjectName("Correo");
        Correo->setGeometry(QRect(140, 150, 131, 24));

        retranslateUi(Personas);

        QMetaObject::connectSlotsByName(Personas);
    } // setupUi

    void retranslateUi(QDialog *Personas)
    {
        Personas->setWindowTitle(QCoreApplication::translate("Personas", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Personas", "Primer Nombre:", nullptr));
        label_2->setText(QCoreApplication::translate("Personas", "Tel\303\251fono:", nullptr));
        label_3->setText(QCoreApplication::translate("Personas", "Email:", nullptr));
        label_4->setText(QCoreApplication::translate("Personas", "Apellido: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Personas: public Ui_Personas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSONAS_H
