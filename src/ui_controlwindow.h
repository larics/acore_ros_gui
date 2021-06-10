/********************************************************************************
** Form generated from reading UI file 'controlwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROLWINDOW_H
#define UI_CONTROLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *publishButton;
    QComboBox *comboBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *ee_XLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *ee_YLabel;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *ee_ZLabel;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *joint1_value;
    QLabel *joint2_value;
    QLabel *joint3_value;
    QLabel *joint4_value;
    QLabel *joint5_value;
    QLabel *joint6_value;
    QLabel *label_11;
    QLabel *label_20;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_19;
    QHBoxLayout *horizontalLayout_5;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QVBoxLayout *verticalLayout_4;
    QLineEdit *posex;
    QLineEdit *posey;
    QLineEdit *posez;
    QLineEdit *orientationx;
    QLineEdit *orientationy;
    QLineEdit *orientationz;
    QLineEdit *orientationw;
    QPushButton *pushButton;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *manualOn;
    QPushButton *manualOff;
    QVBoxLayout *verticalLayout_7;
    QPushButton *up;
    QPushButton *down;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_23;
    QLabel *onoff;
    QLabel *controlstatus;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *startButton;
    QPushButton *toolControl;
    QPushButton *jointControl;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1032, 600);
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 380, 201, 17));
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(460, 210, 113, 23));
        publishButton = new QPushButton(Widget);
        publishButton->setObjectName(QStringLiteral("publishButton"));
        publishButton->setGeometry(QRect(570, 210, 111, 23));
        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(460, 180, 111, 23));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(70, 410, 131, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        ee_XLabel = new QLabel(layoutWidget);
        ee_XLabel->setObjectName(QStringLiteral("ee_XLabel"));

        horizontalLayout->addWidget(ee_XLabel);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_2->addWidget(label_3);

        ee_YLabel = new QLabel(layoutWidget);
        ee_YLabel->setObjectName(QStringLiteral("ee_YLabel"));

        horizontalLayout_2->addWidget(ee_YLabel);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        ee_ZLabel = new QLabel(layoutWidget);
        ee_ZLabel->setObjectName(QStringLiteral("ee_ZLabel"));

        horizontalLayout_3->addWidget(ee_ZLabel);


        verticalLayout->addLayout(horizontalLayout_3);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(460, 360, 98, 191));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        verticalLayout_2->addWidget(label_9);

        label_10 = new QLabel(layoutWidget1);
        label_10->setObjectName(QStringLiteral("label_10"));

        verticalLayout_2->addWidget(label_10);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(570, 360, 91, 191));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        joint1_value = new QLabel(layoutWidget2);
        joint1_value->setObjectName(QStringLiteral("joint1_value"));

        verticalLayout_3->addWidget(joint1_value);

        joint2_value = new QLabel(layoutWidget2);
        joint2_value->setObjectName(QStringLiteral("joint2_value"));

        verticalLayout_3->addWidget(joint2_value);

        joint3_value = new QLabel(layoutWidget2);
        joint3_value->setObjectName(QStringLiteral("joint3_value"));

        verticalLayout_3->addWidget(joint3_value);

        joint4_value = new QLabel(layoutWidget2);
        joint4_value->setObjectName(QStringLiteral("joint4_value"));

        verticalLayout_3->addWidget(joint4_value);

        joint5_value = new QLabel(layoutWidget2);
        joint5_value->setObjectName(QStringLiteral("joint5_value"));

        verticalLayout_3->addWidget(joint5_value);

        joint6_value = new QLabel(layoutWidget2);
        joint6_value->setObjectName(QStringLiteral("joint6_value"));

        verticalLayout_3->addWidget(joint6_value);

        label_11 = new QLabel(Widget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(460, 330, 171, 16));
        label_20 = new QLabel(Widget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(460, 150, 121, 16));
        layoutWidget3 = new QWidget(Widget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(61, 80, 236, 253));
        verticalLayout_6 = new QVBoxLayout(layoutWidget3);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label_19 = new QLabel(layoutWidget3);
        label_19->setObjectName(QStringLiteral("label_19"));

        verticalLayout_6->addWidget(label_19);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        label_12 = new QLabel(layoutWidget3);
        label_12->setObjectName(QStringLiteral("label_12"));

        verticalLayout_5->addWidget(label_12);

        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QStringLiteral("label_13"));

        verticalLayout_5->addWidget(label_13);

        label_14 = new QLabel(layoutWidget3);
        label_14->setObjectName(QStringLiteral("label_14"));

        verticalLayout_5->addWidget(label_14);

        label_15 = new QLabel(layoutWidget3);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_5->addWidget(label_15);

        label_16 = new QLabel(layoutWidget3);
        label_16->setObjectName(QStringLiteral("label_16"));

        verticalLayout_5->addWidget(label_16);

        label_17 = new QLabel(layoutWidget3);
        label_17->setObjectName(QStringLiteral("label_17"));

        verticalLayout_5->addWidget(label_17);

        label_18 = new QLabel(layoutWidget3);
        label_18->setObjectName(QStringLiteral("label_18"));

        verticalLayout_5->addWidget(label_18);


        horizontalLayout_5->addLayout(verticalLayout_5);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        posex = new QLineEdit(layoutWidget3);
        posex->setObjectName(QStringLiteral("posex"));

        verticalLayout_4->addWidget(posex);

        posey = new QLineEdit(layoutWidget3);
        posey->setObjectName(QStringLiteral("posey"));

        verticalLayout_4->addWidget(posey);

        posez = new QLineEdit(layoutWidget3);
        posez->setObjectName(QStringLiteral("posez"));

        verticalLayout_4->addWidget(posez);

        orientationx = new QLineEdit(layoutWidget3);
        orientationx->setObjectName(QStringLiteral("orientationx"));

        verticalLayout_4->addWidget(orientationx);

        orientationy = new QLineEdit(layoutWidget3);
        orientationy->setObjectName(QStringLiteral("orientationy"));

        verticalLayout_4->addWidget(orientationy);

        orientationz = new QLineEdit(layoutWidget3);
        orientationz->setObjectName(QStringLiteral("orientationz"));

        verticalLayout_4->addWidget(orientationz);

        orientationw = new QLineEdit(layoutWidget3);
        orientationw->setObjectName(QStringLiteral("orientationw"));

        verticalLayout_4->addWidget(orientationw);


        horizontalLayout_5->addLayout(verticalLayout_4);


        verticalLayout_6->addLayout(horizontalLayout_5);

        pushButton = new QPushButton(layoutWidget3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_6->addWidget(pushButton);

        layoutWidget4 = new QWidget(Widget);
        layoutWidget4->setObjectName(QStringLiteral("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(780, 210, 211, 121));
        verticalLayout_8 = new QVBoxLayout(layoutWidget4);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        manualOn = new QPushButton(layoutWidget4);
        manualOn->setObjectName(QStringLiteral("manualOn"));

        horizontalLayout_6->addWidget(manualOn);

        manualOff = new QPushButton(layoutWidget4);
        manualOff->setObjectName(QStringLiteral("manualOff"));

        horizontalLayout_6->addWidget(manualOff);


        verticalLayout_8->addLayout(horizontalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        up = new QPushButton(layoutWidget4);
        up->setObjectName(QStringLiteral("up"));

        verticalLayout_7->addWidget(up);

        down = new QPushButton(layoutWidget4);
        down->setObjectName(QStringLiteral("down"));

        verticalLayout_7->addWidget(down);


        verticalLayout_8->addLayout(verticalLayout_7);

        layoutWidget5 = new QWidget(Widget);
        layoutWidget5->setObjectName(QStringLiteral("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(840, 180, 131, 17));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        label_23 = new QLabel(layoutWidget5);
        label_23->setObjectName(QStringLiteral("label_23"));

        horizontalLayout_7->addWidget(label_23);

        onoff = new QLabel(layoutWidget5);
        onoff->setObjectName(QStringLiteral("onoff"));

        horizontalLayout_7->addWidget(onoff);

        controlstatus = new QLabel(Widget);
        controlstatus->setObjectName(QStringLiteral("controlstatus"));
        controlstatus->setGeometry(QRect(660, 30, 241, 23));
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(393, 32, 254, 25));
        horizontalLayout_4 = new QHBoxLayout(widget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        startButton = new QPushButton(widget);
        startButton->setObjectName(QStringLiteral("startButton"));

        horizontalLayout_4->addWidget(startButton);

        toolControl = new QPushButton(widget);
        toolControl->setObjectName(QStringLiteral("toolControl"));

        horizontalLayout_4->addWidget(toolControl);

        jointControl = new QPushButton(widget);
        jointControl->setObjectName(QStringLiteral("jointControl"));

        horizontalLayout_4->addWidget(jointControl);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "<b>End effector position display", Q_NULLPTR));
        publishButton->setText(QApplication::translate("Widget", "publish joint state", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Widget", "q1", Q_NULLPTR)
         << QApplication::translate("Widget", "q2", Q_NULLPTR)
         << QApplication::translate("Widget", "q3", Q_NULLPTR)
         << QApplication::translate("Widget", "q4", Q_NULLPTR)
         << QApplication::translate("Widget", "q5", Q_NULLPTR)
         << QApplication::translate("Widget", "q6", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("Widget", "x =", Q_NULLPTR));
        ee_XLabel->setText(QApplication::translate("Widget", "x value", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "y =", Q_NULLPTR));
        ee_YLabel->setText(QApplication::translate("Widget", "y value", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "z =", Q_NULLPTR));
        ee_ZLabel->setText(QApplication::translate("Widget", "z value", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "joint1_position :", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "joint2_position :", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "joint3_position :", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "joint4_position :", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "joint5_position :", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "joint6_position :", Q_NULLPTR));
        joint1_value->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        joint2_value->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        joint3_value->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        joint4_value->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        joint5_value->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        joint6_value->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "<b>Joint positions display", Q_NULLPTR));
        label_20->setText(QApplication::translate("Widget", "<b>Joint positions", Q_NULLPTR));
        label_19->setText(QApplication::translate("Widget", "<b>End effector position", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "                   x =", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "                   y =", Q_NULLPTR));
        label_14->setText(QApplication::translate("Widget", "                   z = ", Q_NULLPTR));
        label_15->setText(QApplication::translate("Widget", "quaternion x = ", Q_NULLPTR));
        label_16->setText(QApplication::translate("Widget", "quaternion y =", Q_NULLPTR));
        label_17->setText(QApplication::translate("Widget", "quaternion z = ", Q_NULLPTR));
        label_18->setText(QApplication::translate("Widget", "quaternion w = ", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "publish pose", Q_NULLPTR));
        manualOn->setText(QApplication::translate("Widget", "manual on ", Q_NULLPTR));
        manualOff->setText(QApplication::translate("Widget", "manual off", Q_NULLPTR));
        up->setText(QApplication::translate("Widget", "up", Q_NULLPTR));
        down->setText(QApplication::translate("Widget", "down", Q_NULLPTR));
        label_23->setText(QApplication::translate("Widget", "<b> status:", Q_NULLPTR));
        onoff->setText(QApplication::translate("Widget", "on/off", Q_NULLPTR));
        controlstatus->setText(QApplication::translate("Widget", "control status", Q_NULLPTR));
        startButton->setText(QApplication::translate("Widget", "Start GUI", Q_NULLPTR));
        toolControl->setText(QApplication::translate("Widget", "tool control", Q_NULLPTR));
        jointControl->setText(QApplication::translate("Widget", "joint control", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
