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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *armTab;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *trajectoryCtlLayout;
    QPushButton *trajCtlEnableButton;
    QHBoxLayout *trajectoryHorizontalLayout;
    QVBoxLayout *trajectoryVerticalLayout2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *trajectoryVerticalLayout1;
    QLineEdit *trajCtlLineEditX;
    QLineEdit *trajCtlLineEditY;
    QLineEdit *trajCtlLineEditZ;
    QLineEdit *trajCtlLineEditqX;
    QLineEdit *trajCtlLineEditqY;
    QLineEdit *trajCtlLineEditqZ;
    QLineEdit *trajCtlLineEditqW;
    QPushButton *trajSendCmdButton;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *jointCtlLayout;
    QHBoxLayout *hLayoutJointCtl0;
    QPushButton *jointCtlEnableButton;
    QHBoxLayout *hLayoutJointCtl1;
    QLabel *label_19;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *q1CmdLineEdit;
    QPushButton *q1SendCmdButton;
    QHBoxLayout *hLayoutJointCtl2;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *q2LineEdit;
    QPushButton *q2SendCmdButton;
    QHBoxLayout *hLayoutJointCtl3;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *q3LineEdit;
    QPushButton *q3SendCmdButton;
    QHBoxLayout *hLayoutJointCtl4;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *q4LineEdit;
    QPushButton *q4SendCmdButton;
    QHBoxLayout *hLayoutJointCtl5;
    QLabel *label_20;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *q5LineEdit;
    QPushButton *q5SendCmdButton;
    QHBoxLayout *hLayoutJointCtl6;
    QLabel *label_21;
    QSpacerItem *horizontalSpacer_7;
    QLineEdit *q6LineEdit;
    QPushButton *q6SendCmdButton;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *joyCtlLayout;
    QPushButton *joyCtlButton;
    QHBoxLayout *radioButtonJointLayout;
    QRadioButton *q1RadioButton;
    QRadioButton *q3RadioButton;
    QRadioButton *q2RadioButton;
    QRadioButton *q6RadioButton;
    QRadioButton *q5RadioButton;
    QRadioButton *q4RadioButton;
    QHBoxLayout *horizontalSliderLayout;
    QLabel *horizontalSliderMinLabel;
    QSlider *horizontalSlider;
    QLabel *horizontalSliderMaxLabel;
    QPushButton *joyCtlPublishButton;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *servoCtlLayout;
    QPushButton *servoToolCtlButton;
    QHBoxLayout *radioButtonAxisLayout;
    QRadioButton *radioButtonX;
    QRadioButton *radioButtonY;
    QRadioButton *radioButtonZ;
    QPushButton *servoToolCtlDownButton;
    QPushButton *servoToolCtlUpButton;
    QLabel *currentChoosenAxisPositionLabel;
    QPushButton *servoToolCtlButtonPublish;
    QWidget *horizontalLayoutWidget_12;
    QHBoxLayout *guiCtlStatusLayout;
    QLabel *ctlModeLabel;
    QLabel *guiModeLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *enableGUIButton;
    QWidget *horizontalLayoutWidget_13;
    QHBoxLayout *armInfoLayout;
    QVBoxLayout *toolPoseLayout;
    QLabel *xPositionLabel;
    QLabel *yPositionLabel;
    QLabel *zPositionLabel;
    QLabel *rollOrientationLabel;
    QLabel *pitchOrientationLabel;
    QLabel *yawOrientationLabel;
    QVBoxLayout *jointConfigurationLayout;
    QLabel *q1PositionLabel;
    QLabel *q2PositionLabel;
    QLabel *q3PositionLabel;
    QLabel *q4PositionLabel;
    QLabel *q5PositionLabel;
    QLabel *q6PositionLabel;
    QWidget *canTab;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(936, 600);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 20, 891, 551));
        armTab = new QWidget();
        armTab->setObjectName(QStringLiteral("armTab"));
        verticalLayoutWidget_5 = new QWidget(armTab);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(20, 20, 221, 279));
        trajectoryCtlLayout = new QVBoxLayout(verticalLayoutWidget_5);
        trajectoryCtlLayout->setObjectName(QStringLiteral("trajectoryCtlLayout"));
        trajectoryCtlLayout->setContentsMargins(0, 0, 0, 0);
        trajCtlEnableButton = new QPushButton(verticalLayoutWidget_5);
        trajCtlEnableButton->setObjectName(QStringLiteral("trajCtlEnableButton"));

        trajectoryCtlLayout->addWidget(trajCtlEnableButton);

        trajectoryHorizontalLayout = new QHBoxLayout();
        trajectoryHorizontalLayout->setObjectName(QStringLiteral("trajectoryHorizontalLayout"));
        trajectoryVerticalLayout2 = new QVBoxLayout();
        trajectoryVerticalLayout2->setObjectName(QStringLiteral("trajectoryVerticalLayout2"));
        label = new QLabel(verticalLayoutWidget_5);
        label->setObjectName(QStringLiteral("label"));

        trajectoryVerticalLayout2->addWidget(label);

        label_2 = new QLabel(verticalLayoutWidget_5);
        label_2->setObjectName(QStringLiteral("label_2"));

        trajectoryVerticalLayout2->addWidget(label_2);

        label_3 = new QLabel(verticalLayoutWidget_5);
        label_3->setObjectName(QStringLiteral("label_3"));

        trajectoryVerticalLayout2->addWidget(label_3);

        label_4 = new QLabel(verticalLayoutWidget_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        trajectoryVerticalLayout2->addWidget(label_4);

        label_5 = new QLabel(verticalLayoutWidget_5);
        label_5->setObjectName(QStringLiteral("label_5"));

        trajectoryVerticalLayout2->addWidget(label_5);

        label_6 = new QLabel(verticalLayoutWidget_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        trajectoryVerticalLayout2->addWidget(label_6);

        label_7 = new QLabel(verticalLayoutWidget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        trajectoryVerticalLayout2->addWidget(label_7);


        trajectoryHorizontalLayout->addLayout(trajectoryVerticalLayout2);

        trajectoryVerticalLayout1 = new QVBoxLayout();
        trajectoryVerticalLayout1->setObjectName(QStringLiteral("trajectoryVerticalLayout1"));
        trajCtlLineEditX = new QLineEdit(verticalLayoutWidget_5);
        trajCtlLineEditX->setObjectName(QStringLiteral("trajCtlLineEditX"));

        trajectoryVerticalLayout1->addWidget(trajCtlLineEditX);

        trajCtlLineEditY = new QLineEdit(verticalLayoutWidget_5);
        trajCtlLineEditY->setObjectName(QStringLiteral("trajCtlLineEditY"));

        trajectoryVerticalLayout1->addWidget(trajCtlLineEditY);

        trajCtlLineEditZ = new QLineEdit(verticalLayoutWidget_5);
        trajCtlLineEditZ->setObjectName(QStringLiteral("trajCtlLineEditZ"));

        trajectoryVerticalLayout1->addWidget(trajCtlLineEditZ);

        trajCtlLineEditqX = new QLineEdit(verticalLayoutWidget_5);
        trajCtlLineEditqX->setObjectName(QStringLiteral("trajCtlLineEditqX"));

        trajectoryVerticalLayout1->addWidget(trajCtlLineEditqX);

        trajCtlLineEditqY = new QLineEdit(verticalLayoutWidget_5);
        trajCtlLineEditqY->setObjectName(QStringLiteral("trajCtlLineEditqY"));

        trajectoryVerticalLayout1->addWidget(trajCtlLineEditqY);

        trajCtlLineEditqZ = new QLineEdit(verticalLayoutWidget_5);
        trajCtlLineEditqZ->setObjectName(QStringLiteral("trajCtlLineEditqZ"));

        trajectoryVerticalLayout1->addWidget(trajCtlLineEditqZ);

        trajCtlLineEditqW = new QLineEdit(verticalLayoutWidget_5);
        trajCtlLineEditqW->setObjectName(QStringLiteral("trajCtlLineEditqW"));

        trajectoryVerticalLayout1->addWidget(trajCtlLineEditqW);


        trajectoryHorizontalLayout->addLayout(trajectoryVerticalLayout1);


        trajectoryCtlLayout->addLayout(trajectoryHorizontalLayout);

        trajSendCmdButton = new QPushButton(verticalLayoutWidget_5);
        trajSendCmdButton->setObjectName(QStringLiteral("trajSendCmdButton"));

        trajectoryCtlLayout->addWidget(trajSendCmdButton);

        verticalLayoutWidget_6 = new QWidget(armTab);
        verticalLayoutWidget_6->setObjectName(QStringLiteral("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(260, 20, 261, 413));
        jointCtlLayout = new QVBoxLayout(verticalLayoutWidget_6);
        jointCtlLayout->setObjectName(QStringLiteral("jointCtlLayout"));
        jointCtlLayout->setContentsMargins(0, 0, 0, 0);
        hLayoutJointCtl0 = new QHBoxLayout();
        hLayoutJointCtl0->setObjectName(QStringLiteral("hLayoutJointCtl0"));
        jointCtlEnableButton = new QPushButton(verticalLayoutWidget_6);
        jointCtlEnableButton->setObjectName(QStringLiteral("jointCtlEnableButton"));

        hLayoutJointCtl0->addWidget(jointCtlEnableButton);


        jointCtlLayout->addLayout(hLayoutJointCtl0);

        hLayoutJointCtl1 = new QHBoxLayout();
        hLayoutJointCtl1->setObjectName(QStringLiteral("hLayoutJointCtl1"));
        label_19 = new QLabel(verticalLayoutWidget_6);
        label_19->setObjectName(QStringLiteral("label_19"));

        hLayoutJointCtl1->addWidget(label_19);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutJointCtl1->addItem(horizontalSpacer_2);

        q1CmdLineEdit = new QLineEdit(verticalLayoutWidget_6);
        q1CmdLineEdit->setObjectName(QStringLiteral("q1CmdLineEdit"));

        hLayoutJointCtl1->addWidget(q1CmdLineEdit);


        jointCtlLayout->addLayout(hLayoutJointCtl1);

        q1SendCmdButton = new QPushButton(verticalLayoutWidget_6);
        q1SendCmdButton->setObjectName(QStringLiteral("q1SendCmdButton"));

        jointCtlLayout->addWidget(q1SendCmdButton);

        hLayoutJointCtl2 = new QHBoxLayout();
        hLayoutJointCtl2->setObjectName(QStringLiteral("hLayoutJointCtl2"));
        label_17 = new QLabel(verticalLayoutWidget_6);
        label_17->setObjectName(QStringLiteral("label_17"));

        hLayoutJointCtl2->addWidget(label_17);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutJointCtl2->addItem(horizontalSpacer_3);

        q2LineEdit = new QLineEdit(verticalLayoutWidget_6);
        q2LineEdit->setObjectName(QStringLiteral("q2LineEdit"));

        hLayoutJointCtl2->addWidget(q2LineEdit);


        jointCtlLayout->addLayout(hLayoutJointCtl2);

        q2SendCmdButton = new QPushButton(verticalLayoutWidget_6);
        q2SendCmdButton->setObjectName(QStringLiteral("q2SendCmdButton"));

        jointCtlLayout->addWidget(q2SendCmdButton);

        hLayoutJointCtl3 = new QHBoxLayout();
        hLayoutJointCtl3->setObjectName(QStringLiteral("hLayoutJointCtl3"));
        label_18 = new QLabel(verticalLayoutWidget_6);
        label_18->setObjectName(QStringLiteral("label_18"));

        hLayoutJointCtl3->addWidget(label_18);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutJointCtl3->addItem(horizontalSpacer_4);

        q3LineEdit = new QLineEdit(verticalLayoutWidget_6);
        q3LineEdit->setObjectName(QStringLiteral("q3LineEdit"));

        hLayoutJointCtl3->addWidget(q3LineEdit);


        jointCtlLayout->addLayout(hLayoutJointCtl3);

        q3SendCmdButton = new QPushButton(verticalLayoutWidget_6);
        q3SendCmdButton->setObjectName(QStringLiteral("q3SendCmdButton"));

        jointCtlLayout->addWidget(q3SendCmdButton);

        hLayoutJointCtl4 = new QHBoxLayout();
        hLayoutJointCtl4->setObjectName(QStringLiteral("hLayoutJointCtl4"));
        label_16 = new QLabel(verticalLayoutWidget_6);
        label_16->setObjectName(QStringLiteral("label_16"));

        hLayoutJointCtl4->addWidget(label_16);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutJointCtl4->addItem(horizontalSpacer_5);

        q4LineEdit = new QLineEdit(verticalLayoutWidget_6);
        q4LineEdit->setObjectName(QStringLiteral("q4LineEdit"));

        hLayoutJointCtl4->addWidget(q4LineEdit);


        jointCtlLayout->addLayout(hLayoutJointCtl4);

        q4SendCmdButton = new QPushButton(verticalLayoutWidget_6);
        q4SendCmdButton->setObjectName(QStringLiteral("q4SendCmdButton"));

        jointCtlLayout->addWidget(q4SendCmdButton);

        hLayoutJointCtl5 = new QHBoxLayout();
        hLayoutJointCtl5->setObjectName(QStringLiteral("hLayoutJointCtl5"));
        label_20 = new QLabel(verticalLayoutWidget_6);
        label_20->setObjectName(QStringLiteral("label_20"));

        hLayoutJointCtl5->addWidget(label_20);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutJointCtl5->addItem(horizontalSpacer_6);

        q5LineEdit = new QLineEdit(verticalLayoutWidget_6);
        q5LineEdit->setObjectName(QStringLiteral("q5LineEdit"));

        hLayoutJointCtl5->addWidget(q5LineEdit);


        jointCtlLayout->addLayout(hLayoutJointCtl5);

        q5SendCmdButton = new QPushButton(verticalLayoutWidget_6);
        q5SendCmdButton->setObjectName(QStringLiteral("q5SendCmdButton"));

        jointCtlLayout->addWidget(q5SendCmdButton);

        hLayoutJointCtl6 = new QHBoxLayout();
        hLayoutJointCtl6->setObjectName(QStringLiteral("hLayoutJointCtl6"));
        label_21 = new QLabel(verticalLayoutWidget_6);
        label_21->setObjectName(QStringLiteral("label_21"));

        hLayoutJointCtl6->addWidget(label_21);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hLayoutJointCtl6->addItem(horizontalSpacer_7);

        q6LineEdit = new QLineEdit(verticalLayoutWidget_6);
        q6LineEdit->setObjectName(QStringLiteral("q6LineEdit"));

        hLayoutJointCtl6->addWidget(q6LineEdit);


        jointCtlLayout->addLayout(hLayoutJointCtl6);

        q6SendCmdButton = new QPushButton(verticalLayoutWidget_6);
        q6SendCmdButton->setObjectName(QStringLiteral("q6SendCmdButton"));

        jointCtlLayout->addWidget(q6SendCmdButton);

        verticalLayoutWidget_7 = new QWidget(armTab);
        verticalLayoutWidget_7->setObjectName(QStringLiteral("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(540, 20, 331, 211));
        joyCtlLayout = new QVBoxLayout(verticalLayoutWidget_7);
        joyCtlLayout->setObjectName(QStringLiteral("joyCtlLayout"));
        joyCtlLayout->setContentsMargins(0, 0, 0, 0);
        joyCtlButton = new QPushButton(verticalLayoutWidget_7);
        joyCtlButton->setObjectName(QStringLiteral("joyCtlButton"));

        joyCtlLayout->addWidget(joyCtlButton);

        radioButtonJointLayout = new QHBoxLayout();
        radioButtonJointLayout->setObjectName(QStringLiteral("radioButtonJointLayout"));
        q1RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q1RadioButton->setObjectName(QStringLiteral("q1RadioButton"));

        radioButtonJointLayout->addWidget(q1RadioButton);

        q3RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q3RadioButton->setObjectName(QStringLiteral("q3RadioButton"));

        radioButtonJointLayout->addWidget(q3RadioButton);

        q2RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q2RadioButton->setObjectName(QStringLiteral("q2RadioButton"));

        radioButtonJointLayout->addWidget(q2RadioButton);

        q6RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q6RadioButton->setObjectName(QStringLiteral("q6RadioButton"));

        radioButtonJointLayout->addWidget(q6RadioButton);

        q5RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q5RadioButton->setObjectName(QStringLiteral("q5RadioButton"));

        radioButtonJointLayout->addWidget(q5RadioButton);

        q4RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q4RadioButton->setObjectName(QStringLiteral("q4RadioButton"));

        radioButtonJointLayout->addWidget(q4RadioButton);


        joyCtlLayout->addLayout(radioButtonJointLayout);

        horizontalSliderLayout = new QHBoxLayout();
        horizontalSliderLayout->setObjectName(QStringLiteral("horizontalSliderLayout"));
        horizontalSliderMinLabel = new QLabel(verticalLayoutWidget_7);
        horizontalSliderMinLabel->setObjectName(QStringLiteral("horizontalSliderMinLabel"));

        horizontalSliderLayout->addWidget(horizontalSliderMinLabel);

        horizontalSlider = new QSlider(verticalLayoutWidget_7);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(10);

        horizontalSliderLayout->addWidget(horizontalSlider);

        horizontalSliderMaxLabel = new QLabel(verticalLayoutWidget_7);
        horizontalSliderMaxLabel->setObjectName(QStringLiteral("horizontalSliderMaxLabel"));

        horizontalSliderLayout->addWidget(horizontalSliderMaxLabel);


        joyCtlLayout->addLayout(horizontalSliderLayout);

        joyCtlPublishButton = new QPushButton(verticalLayoutWidget_7);
        joyCtlPublishButton->setObjectName(QStringLiteral("joyCtlPublishButton"));

        joyCtlLayout->addWidget(joyCtlPublishButton);

        verticalLayoutWidget_8 = new QWidget(armTab);
        verticalLayoutWidget_8->setObjectName(QStringLiteral("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(540, 240, 331, 191));
        servoCtlLayout = new QVBoxLayout(verticalLayoutWidget_8);
        servoCtlLayout->setObjectName(QStringLiteral("servoCtlLayout"));
        servoCtlLayout->setContentsMargins(0, 0, 0, 0);
        servoToolCtlButton = new QPushButton(verticalLayoutWidget_8);
        servoToolCtlButton->setObjectName(QStringLiteral("servoToolCtlButton"));

        servoCtlLayout->addWidget(servoToolCtlButton);

        radioButtonAxisLayout = new QHBoxLayout();
        radioButtonAxisLayout->setObjectName(QStringLiteral("radioButtonAxisLayout"));
        radioButtonX = new QRadioButton(verticalLayoutWidget_8);
        radioButtonX->setObjectName(QStringLiteral("radioButtonX"));

        radioButtonAxisLayout->addWidget(radioButtonX);

        radioButtonY = new QRadioButton(verticalLayoutWidget_8);
        radioButtonY->setObjectName(QStringLiteral("radioButtonY"));

        radioButtonAxisLayout->addWidget(radioButtonY);

        radioButtonZ = new QRadioButton(verticalLayoutWidget_8);
        radioButtonZ->setObjectName(QStringLiteral("radioButtonZ"));

        radioButtonAxisLayout->addWidget(radioButtonZ);


        servoCtlLayout->addLayout(radioButtonAxisLayout);

        servoToolCtlDownButton = new QPushButton(verticalLayoutWidget_8);
        servoToolCtlDownButton->setObjectName(QStringLiteral("servoToolCtlDownButton"));

        servoCtlLayout->addWidget(servoToolCtlDownButton);

        servoToolCtlUpButton = new QPushButton(verticalLayoutWidget_8);
        servoToolCtlUpButton->setObjectName(QStringLiteral("servoToolCtlUpButton"));

        servoCtlLayout->addWidget(servoToolCtlUpButton);

        currentChoosenAxisPositionLabel = new QLabel(verticalLayoutWidget_8);
        currentChoosenAxisPositionLabel->setObjectName(QStringLiteral("currentChoosenAxisPositionLabel"));

        servoCtlLayout->addWidget(currentChoosenAxisPositionLabel);

        servoToolCtlButtonPublish = new QPushButton(verticalLayoutWidget_8);
        servoToolCtlButtonPublish->setObjectName(QStringLiteral("servoToolCtlButtonPublish"));

        servoCtlLayout->addWidget(servoToolCtlButtonPublish);

        horizontalLayoutWidget_12 = new QWidget(armTab);
        horizontalLayoutWidget_12->setObjectName(QStringLiteral("horizontalLayoutWidget_12"));
        horizontalLayoutWidget_12->setGeometry(QRect(20, 450, 851, 52));
        guiCtlStatusLayout = new QHBoxLayout(horizontalLayoutWidget_12);
        guiCtlStatusLayout->setObjectName(QStringLiteral("guiCtlStatusLayout"));
        guiCtlStatusLayout->setContentsMargins(0, 0, 0, 0);
        ctlModeLabel = new QLabel(horizontalLayoutWidget_12);
        ctlModeLabel->setObjectName(QStringLiteral("ctlModeLabel"));

        guiCtlStatusLayout->addWidget(ctlModeLabel);

        guiModeLabel = new QLabel(horizontalLayoutWidget_12);
        guiModeLabel->setObjectName(QStringLiteral("guiModeLabel"));

        guiCtlStatusLayout->addWidget(guiModeLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        guiCtlStatusLayout->addItem(horizontalSpacer);

        enableGUIButton = new QPushButton(horizontalLayoutWidget_12);
        enableGUIButton->setObjectName(QStringLiteral("enableGUIButton"));

        guiCtlStatusLayout->addWidget(enableGUIButton);

        horizontalLayoutWidget_13 = new QWidget(armTab);
        horizontalLayoutWidget_13->setObjectName(QStringLiteral("horizontalLayoutWidget_13"));
        horizontalLayoutWidget_13->setGeometry(QRect(20, 310, 221, 121));
        armInfoLayout = new QHBoxLayout(horizontalLayoutWidget_13);
        armInfoLayout->setObjectName(QStringLiteral("armInfoLayout"));
        armInfoLayout->setContentsMargins(0, 0, 0, 0);
        toolPoseLayout = new QVBoxLayout();
        toolPoseLayout->setObjectName(QStringLiteral("toolPoseLayout"));
        xPositionLabel = new QLabel(horizontalLayoutWidget_13);
        xPositionLabel->setObjectName(QStringLiteral("xPositionLabel"));

        toolPoseLayout->addWidget(xPositionLabel);

        yPositionLabel = new QLabel(horizontalLayoutWidget_13);
        yPositionLabel->setObjectName(QStringLiteral("yPositionLabel"));

        toolPoseLayout->addWidget(yPositionLabel);

        zPositionLabel = new QLabel(horizontalLayoutWidget_13);
        zPositionLabel->setObjectName(QStringLiteral("zPositionLabel"));

        toolPoseLayout->addWidget(zPositionLabel);

        rollOrientationLabel = new QLabel(horizontalLayoutWidget_13);
        rollOrientationLabel->setObjectName(QStringLiteral("rollOrientationLabel"));

        toolPoseLayout->addWidget(rollOrientationLabel);

        pitchOrientationLabel = new QLabel(horizontalLayoutWidget_13);
        pitchOrientationLabel->setObjectName(QStringLiteral("pitchOrientationLabel"));

        toolPoseLayout->addWidget(pitchOrientationLabel);

        yawOrientationLabel = new QLabel(horizontalLayoutWidget_13);
        yawOrientationLabel->setObjectName(QStringLiteral("yawOrientationLabel"));

        toolPoseLayout->addWidget(yawOrientationLabel);


        armInfoLayout->addLayout(toolPoseLayout);

        jointConfigurationLayout = new QVBoxLayout();
        jointConfigurationLayout->setObjectName(QStringLiteral("jointConfigurationLayout"));
        q1PositionLabel = new QLabel(horizontalLayoutWidget_13);
        q1PositionLabel->setObjectName(QStringLiteral("q1PositionLabel"));

        jointConfigurationLayout->addWidget(q1PositionLabel);

        q2PositionLabel = new QLabel(horizontalLayoutWidget_13);
        q2PositionLabel->setObjectName(QStringLiteral("q2PositionLabel"));

        jointConfigurationLayout->addWidget(q2PositionLabel);

        q3PositionLabel = new QLabel(horizontalLayoutWidget_13);
        q3PositionLabel->setObjectName(QStringLiteral("q3PositionLabel"));

        jointConfigurationLayout->addWidget(q3PositionLabel);

        q4PositionLabel = new QLabel(horizontalLayoutWidget_13);
        q4PositionLabel->setObjectName(QStringLiteral("q4PositionLabel"));

        jointConfigurationLayout->addWidget(q4PositionLabel);

        q5PositionLabel = new QLabel(horizontalLayoutWidget_13);
        q5PositionLabel->setObjectName(QStringLiteral("q5PositionLabel"));

        jointConfigurationLayout->addWidget(q5PositionLabel);

        q6PositionLabel = new QLabel(horizontalLayoutWidget_13);
        q6PositionLabel->setObjectName(QStringLiteral("q6PositionLabel"));

        jointConfigurationLayout->addWidget(q6PositionLabel);


        armInfoLayout->addLayout(jointConfigurationLayout);

        tabWidget->addTab(armTab, QString());
        canTab = new QWidget();
        canTab->setObjectName(QStringLiteral("canTab"));
        tabWidget->addTab(canTab, QString());

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        trajCtlEnableButton->setText(QApplication::translate("Widget", "Trajectory Control", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "X                ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "Y ", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "Z ", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "qX ", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "qY", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "qZ", Q_NULLPTR));
        label_7->setText(QApplication::translate("Widget", "qW", Q_NULLPTR));
        trajSendCmdButton->setText(QApplication::translate("Widget", "Publish Trajectory", Q_NULLPTR));
        jointCtlEnableButton->setText(QApplication::translate("Widget", "Joint Control", Q_NULLPTR));
        label_19->setText(QApplication::translate("Widget", "Q1", Q_NULLPTR));
        q1SendCmdButton->setText(QApplication::translate("Widget", "Publish Q1 command", Q_NULLPTR));
        label_17->setText(QApplication::translate("Widget", "Q2", Q_NULLPTR));
        q2SendCmdButton->setText(QApplication::translate("Widget", "Publish Q2 command", Q_NULLPTR));
        label_18->setText(QApplication::translate("Widget", "Q3", Q_NULLPTR));
        q3SendCmdButton->setText(QApplication::translate("Widget", "Publish Q3 command", Q_NULLPTR));
        label_16->setText(QApplication::translate("Widget", "Q4", Q_NULLPTR));
        q4SendCmdButton->setText(QApplication::translate("Widget", "Publish Q4 command", Q_NULLPTR));
        label_20->setText(QApplication::translate("Widget", "Q5", Q_NULLPTR));
        q5SendCmdButton->setText(QApplication::translate("Widget", "Publish Q5 command", Q_NULLPTR));
        label_21->setText(QApplication::translate("Widget", "Q6", Q_NULLPTR));
        q6SendCmdButton->setText(QApplication::translate("Widget", "Publish Q6 command", Q_NULLPTR));
        joyCtlButton->setText(QApplication::translate("Widget", "Joystick control", Q_NULLPTR));
        q1RadioButton->setText(QApplication::translate("Widget", "Q1", Q_NULLPTR));
        q3RadioButton->setText(QApplication::translate("Widget", "Q2", Q_NULLPTR));
        q2RadioButton->setText(QApplication::translate("Widget", "Q3", Q_NULLPTR));
        q6RadioButton->setText(QApplication::translate("Widget", "Q4", Q_NULLPTR));
        q5RadioButton->setText(QApplication::translate("Widget", "Q5", Q_NULLPTR));
        q4RadioButton->setText(QApplication::translate("Widget", "Q6", Q_NULLPTR));
        horizontalSliderMinLabel->setText(QApplication::translate("Widget", "q_min", Q_NULLPTR));
        horizontalSliderMaxLabel->setText(QApplication::translate("Widget", "q_max", Q_NULLPTR));
        joyCtlPublishButton->setText(QApplication::translate("Widget", "Publish command", Q_NULLPTR));
        servoToolCtlButton->setText(QApplication::translate("Widget", "Servo tool control", Q_NULLPTR));
        radioButtonX->setText(QApplication::translate("Widget", "X", Q_NULLPTR));
        radioButtonY->setText(QApplication::translate("Widget", "Y", Q_NULLPTR));
        radioButtonZ->setText(QApplication::translate("Widget", "Z", Q_NULLPTR));
        servoToolCtlDownButton->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        servoToolCtlUpButton->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
        currentChoosenAxisPositionLabel->setText(QApplication::translate("Widget", "Print axis value", Q_NULLPTR));
        servoToolCtlButtonPublish->setText(QApplication::translate("Widget", "Publish command", Q_NULLPTR));
        ctlModeLabel->setText(QApplication::translate("Widget", "CONTROL MODE:                                                        ", Q_NULLPTR));
        guiModeLabel->setText(QApplication::translate("Widget", "GUI:                            ", Q_NULLPTR));
        enableGUIButton->setText(QApplication::translate("Widget", "Start GUI", Q_NULLPTR));
        xPositionLabel->setText(QApplication::translate("Widget", "X", Q_NULLPTR));
        yPositionLabel->setText(QApplication::translate("Widget", "Y", Q_NULLPTR));
        zPositionLabel->setText(QApplication::translate("Widget", "Z", Q_NULLPTR));
        rollOrientationLabel->setText(QApplication::translate("Widget", "Roll", Q_NULLPTR));
        pitchOrientationLabel->setText(QApplication::translate("Widget", "Pitch", Q_NULLPTR));
        yawOrientationLabel->setText(QApplication::translate("Widget", "Yaw", Q_NULLPTR));
        q1PositionLabel->setText(QApplication::translate("Widget", "q1", Q_NULLPTR));
        q2PositionLabel->setText(QApplication::translate("Widget", "q2", Q_NULLPTR));
        q3PositionLabel->setText(QApplication::translate("Widget", "q3", Q_NULLPTR));
        q4PositionLabel->setText(QApplication::translate("Widget", "q4", Q_NULLPTR));
        q5PositionLabel->setText(QApplication::translate("Widget", "q5", Q_NULLPTR));
        q6PositionLabel->setText(QApplication::translate("Widget", "q6", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(armTab), QApplication::translate("Widget", "Arm Control", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(canTab), QApplication::translate("Widget", "CAN Communication", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
