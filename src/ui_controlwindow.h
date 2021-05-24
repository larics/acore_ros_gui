/********************************************************************************
** Form generated from reading UI file 'controlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWINDOW_H
#define UI_CONTROLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *startButton;
    QLabel *label;
    QLabel *ee_XLabel;
    QLabel *ee_YLabel;
    QLabel *ee_ZLabel;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        startButton = new QPushButton(Widget);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(40, 20, 89, 25));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 60, 151, 17));
        ee_XLabel = new QLabel(Widget);
        ee_XLabel->setObjectName(QStringLiteral("ee_XLabel"));
        ee_XLabel->setGeometry(QRect(40, 100, 67, 17));
        ee_YLabel = new QLabel(Widget);
        ee_YLabel->setObjectName(QStringLiteral("ee_YLabel"));
        ee_YLabel->setGeometry(QRect(40, 130, 67, 17));
        ee_ZLabel = new QLabel(Widget);
        ee_ZLabel->setObjectName(QStringLiteral("ee_ZLabel"));
        ee_ZLabel->setGeometry(QRect(40, 160, 67, 17));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        startButton->setText(QApplication::translate("Widget", "Start GUI", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "End effector position", Q_NULLPTR));
        ee_XLabel->setText(QApplication::translate("Widget", "X = ", Q_NULLPTR));
        ee_YLabel->setText(QApplication::translate("Widget", "Y = ", Q_NULLPTR));
        ee_ZLabel->setText(QApplication::translate("Widget", "Z = ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
