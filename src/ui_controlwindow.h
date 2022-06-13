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
    QPushButton *publishAll;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *joyCtlLayout;
    QPushButton *joyCtlButton;
    QHBoxLayout *radioButtonJointLayout;
    QRadioButton *q1RadioButton;
    QRadioButton *q2RadioButton;
    QRadioButton *q3RadioButton;
    QRadioButton *q4RadioButton;
    QRadioButton *q5RadioButton;
    QRadioButton *q6RadioButton;
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
    QPushButton *servoToolCtlUpButton;
    QPushButton *servoToolCtlDownButton;
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
    QWidget *uavTab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_22;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_23;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_15;
    QLabel *uav_positionx_value;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_22;
    QLabel *uav_positiony_value;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_23;
    QLabel *uav_positionz_value;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_24;
    QLabel *label_27;
    QSpacerItem *horizontalSpacer_25;
    QLabel *uav_roll_disp;
    QSpacerItem *horizontalSpacer_26;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *horizontalSpacer_27;
    QLabel *label_28;
    QSpacerItem *horizontalSpacer_28;
    QLabel *uav_pitch_disp;
    QSpacerItem *horizontalSpacer_29;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_30;
    QLabel *label_29;
    QSpacerItem *horizontalSpacer_31;
    QLabel *uav_yaw_disp;
    QSpacerItem *horizontalSpacer_32;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QPushButton *uav_position_control;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_17;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_8;
    QLineEdit *uav_position_x;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_18;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *uav_position_y;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_19;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_10;
    QLineEdit *uav_position_z;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_20;
    QLabel *label_33;
    QSpacerItem *horizontalSpacer_11;
    QLineEdit *uav_position_yaw;
    QPushButton *uav_publish_position;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_16;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer_12;
    QLineEdit *uav_angular_roll;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_15;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_13;
    QLineEdit *uav_angular_pitch;
    QHBoxLayout *horizontalLayout_12;
    QSpacerItem *horizontalSpacer_21;
    QLabel *label_13;
    QSpacerItem *horizontalSpacer_14;
    QLineEdit *uav_angular_yaw;
    QPushButton *uav_angular_publish;
    QWidget *cam;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(936, 600);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(30, 20, 891, 561));
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
        verticalLayoutWidget_6->setGeometry(QRect(260, 20, 261, 416));
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

        publishAll = new QPushButton(verticalLayoutWidget_6);
        publishAll->setObjectName(QStringLiteral("publishAll"));

        jointCtlLayout->addWidget(publishAll);

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

        q2RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q2RadioButton->setObjectName(QStringLiteral("q2RadioButton"));

        radioButtonJointLayout->addWidget(q2RadioButton);

        q3RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q3RadioButton->setObjectName(QStringLiteral("q3RadioButton"));

        radioButtonJointLayout->addWidget(q3RadioButton);

        q4RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q4RadioButton->setObjectName(QStringLiteral("q4RadioButton"));

        radioButtonJointLayout->addWidget(q4RadioButton);

        q5RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q5RadioButton->setObjectName(QStringLiteral("q5RadioButton"));

        radioButtonJointLayout->addWidget(q5RadioButton);

        q6RadioButton = new QRadioButton(verticalLayoutWidget_7);
        q6RadioButton->setObjectName(QStringLiteral("q6RadioButton"));

        radioButtonJointLayout->addWidget(q6RadioButton);


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

        servoToolCtlUpButton = new QPushButton(verticalLayoutWidget_8);
        servoToolCtlUpButton->setObjectName(QStringLiteral("servoToolCtlUpButton"));

        servoCtlLayout->addWidget(servoToolCtlUpButton);

        servoToolCtlDownButton = new QPushButton(verticalLayoutWidget_8);
        servoToolCtlDownButton->setObjectName(QStringLiteral("servoToolCtlDownButton"));

        servoCtlLayout->addWidget(servoToolCtlDownButton);

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
        horizontalLayoutWidget_13->setGeometry(QRect(20, 310, 221, 124));
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
        uavTab = new QWidget();
        uavTab->setObjectName(QStringLiteral("uavTab"));
        layoutWidget = new QWidget(uavTab);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 310, 281, 68));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_22);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_4->addWidget(label_14);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_23);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_15 = new QLabel(layoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        verticalLayout_7->addWidget(label_15);

        uav_positionx_value = new QLabel(layoutWidget);
        uav_positionx_value->setObjectName(QStringLiteral("uav_positionx_value"));

        verticalLayout_7->addWidget(uav_positionx_value);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_22 = new QLabel(layoutWidget);
        label_22->setObjectName(QStringLiteral("label_22"));

        verticalLayout_8->addWidget(label_22);

        uav_positiony_value = new QLabel(layoutWidget);
        uav_positiony_value->setObjectName(QStringLiteral("uav_positiony_value"));

        verticalLayout_8->addWidget(uav_positiony_value);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_23 = new QLabel(layoutWidget);
        label_23->setObjectName(QStringLiteral("label_23"));

        verticalLayout_9->addWidget(label_23);

        uav_positionz_value = new QLabel(layoutWidget);
        uav_positionz_value->setObjectName(QStringLiteral("uav_positionz_value"));

        verticalLayout_9->addWidget(uav_positionz_value);


        horizontalLayout_3->addLayout(verticalLayout_9);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        layoutWidget1 = new QWidget(uavTab);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 380, 281, 101));
        verticalLayout_10 = new QVBoxLayout(layoutWidget1);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_24);

        label_27 = new QLabel(layoutWidget1);
        label_27->setObjectName(QStringLiteral("label_27"));

        horizontalLayout_5->addWidget(label_27);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_25);

        uav_roll_disp = new QLabel(layoutWidget1);
        uav_roll_disp->setObjectName(QStringLiteral("uav_roll_disp"));

        horizontalLayout_5->addWidget(uav_roll_disp);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_26);


        verticalLayout_10->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalSpacer_27 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_27);

        label_28 = new QLabel(layoutWidget1);
        label_28->setObjectName(QStringLiteral("label_28"));

        horizontalLayout_6->addWidget(label_28);

        horizontalSpacer_28 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_28);

        uav_pitch_disp = new QLabel(layoutWidget1);
        uav_pitch_disp->setObjectName(QStringLiteral("uav_pitch_disp"));

        horizontalLayout_6->addWidget(uav_pitch_disp);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_29);


        verticalLayout_10->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_30);

        label_29 = new QLabel(layoutWidget1);
        label_29->setObjectName(QStringLiteral("label_29"));

        horizontalLayout_7->addWidget(label_29);

        horizontalSpacer_31 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_31);

        uav_yaw_disp = new QLabel(layoutWidget1);
        uav_yaw_disp->setObjectName(QStringLiteral("uav_yaw_disp"));

        horizontalLayout_7->addWidget(uav_yaw_disp);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_32);


        verticalLayout_10->addLayout(horizontalLayout_7);

        layoutWidget2 = new QWidget(uavTab);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 41, 281, 261));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        uav_position_control = new QPushButton(layoutWidget2);
        uav_position_control->setObjectName(QStringLiteral("uav_position_control"));

        verticalLayout->addWidget(uav_position_control);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_17);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout->addWidget(label_8);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_8);

        uav_position_x = new QLineEdit(layoutWidget2);
        uav_position_x->setObjectName(QStringLiteral("uav_position_x"));

        horizontalLayout->addWidget(uav_position_x);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_18);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_8->addWidget(label_9);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        uav_position_y = new QLineEdit(layoutWidget2);
        uav_position_y->setObjectName(QStringLiteral("uav_position_y"));

        horizontalLayout_8->addWidget(uav_position_y);


        verticalLayout->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_19);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_9->addWidget(label_10);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_10);

        uav_position_z = new QLineEdit(layoutWidget2);
        uav_position_z->setObjectName(QStringLiteral("uav_position_z"));

        horizontalLayout_9->addWidget(uav_position_z);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_20);

        label_33 = new QLabel(layoutWidget2);
        label_33->setObjectName(QStringLiteral("label_33"));

        horizontalLayout_10->addWidget(label_33);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_11);

        uav_position_yaw = new QLineEdit(layoutWidget2);
        uav_position_yaw->setObjectName(QStringLiteral("uav_position_yaw"));

        horizontalLayout_10->addWidget(uav_position_yaw);


        verticalLayout->addLayout(horizontalLayout_10);

        uav_publish_position = new QPushButton(layoutWidget2);
        uav_publish_position->setObjectName(QStringLiteral("uav_publish_position"));

        verticalLayout->addWidget(uav_publish_position);

        layoutWidget3 = new QWidget(uavTab);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(328, 41, 291, 261));
        verticalLayout_2 = new QVBoxLayout(layoutWidget3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout_2->addWidget(pushButton_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_16);

        label_11 = new QLabel(layoutWidget3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_2->addWidget(label_11);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_12);

        uav_angular_roll = new QLineEdit(layoutWidget3);
        uav_angular_roll->setObjectName(QStringLiteral("uav_angular_roll"));

        horizontalLayout_2->addWidget(uav_angular_roll);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_15);

        label_12 = new QLabel(layoutWidget3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_11->addWidget(label_12);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_13);

        uav_angular_pitch = new QLineEdit(layoutWidget3);
        uav_angular_pitch->setObjectName(QStringLiteral("uav_angular_pitch"));

        horizontalLayout_11->addWidget(uav_angular_pitch);


        verticalLayout_2->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalSpacer_21 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_21);

        label_13 = new QLabel(layoutWidget3);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_12->addWidget(label_13);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_14);

        uav_angular_yaw = new QLineEdit(layoutWidget3);
        uav_angular_yaw->setObjectName(QStringLiteral("uav_angular_yaw"));

        horizontalLayout_12->addWidget(uav_angular_yaw);


        verticalLayout_2->addLayout(horizontalLayout_12);

        uav_angular_publish = new QPushButton(layoutWidget3);
        uav_angular_publish->setObjectName(QStringLiteral("uav_angular_publish"));

        verticalLayout_2->addWidget(uav_angular_publish);

        tabWidget->addTab(uavTab, QString());
        cam = new QWidget();
        cam->setObjectName(QStringLiteral("cam"));
        tabWidget->addTab(cam, QString());

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(1);


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
        publishAll->setText(QApplication::translate("Widget", "Publish All", Q_NULLPTR));
        joyCtlButton->setText(QApplication::translate("Widget", "Joystick control", Q_NULLPTR));
        q1RadioButton->setText(QApplication::translate("Widget", "Q1", Q_NULLPTR));
        q2RadioButton->setText(QApplication::translate("Widget", "Q2", Q_NULLPTR));
        q3RadioButton->setText(QApplication::translate("Widget", "Q3", Q_NULLPTR));
        q4RadioButton->setText(QApplication::translate("Widget", "Q4", Q_NULLPTR));
        q5RadioButton->setText(QApplication::translate("Widget", "Q5", Q_NULLPTR));
        q6RadioButton->setText(QApplication::translate("Widget", "Q6", Q_NULLPTR));
        horizontalSliderMinLabel->setText(QApplication::translate("Widget", "q_min", Q_NULLPTR));
        horizontalSliderMaxLabel->setText(QApplication::translate("Widget", "q_max", Q_NULLPTR));
        joyCtlPublishButton->setText(QApplication::translate("Widget", "Publish command", Q_NULLPTR));
        servoToolCtlButton->setText(QApplication::translate("Widget", "Servo tool control", Q_NULLPTR));
        radioButtonX->setText(QApplication::translate("Widget", "X", Q_NULLPTR));
        radioButtonY->setText(QApplication::translate("Widget", "Y", Q_NULLPTR));
        radioButtonZ->setText(QApplication::translate("Widget", "Z", Q_NULLPTR));
        servoToolCtlUpButton->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        servoToolCtlDownButton->setText(QApplication::translate("Widget", "-", Q_NULLPTR));
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
        label_14->setText(QApplication::translate("Widget", "position", Q_NULLPTR));
        label_15->setText(QApplication::translate("Widget", "   x", Q_NULLPTR));
        uav_positionx_value->setText(QApplication::translate("Widget", "xvalue", Q_NULLPTR));
        label_22->setText(QApplication::translate("Widget", "    y", Q_NULLPTR));
        uav_positiony_value->setText(QApplication::translate("Widget", "yvalue", Q_NULLPTR));
        label_23->setText(QApplication::translate("Widget", "    z", Q_NULLPTR));
        uav_positionz_value->setText(QApplication::translate("Widget", "zvalue", Q_NULLPTR));
        label_27->setText(QApplication::translate("Widget", "roll:", Q_NULLPTR));
        uav_roll_disp->setText(QApplication::translate("Widget", "roll_value", Q_NULLPTR));
        label_28->setText(QApplication::translate("Widget", "pitch:", Q_NULLPTR));
        uav_pitch_disp->setText(QApplication::translate("Widget", "pitch_value", Q_NULLPTR));
        label_29->setText(QApplication::translate("Widget", "yaw:", Q_NULLPTR));
        uav_yaw_disp->setText(QApplication::translate("Widget", "yaw_value", Q_NULLPTR));
        uav_position_control->setText(QApplication::translate("Widget", "position control", Q_NULLPTR));
        label_8->setText(QApplication::translate("Widget", "     x:     ", Q_NULLPTR));
        label_9->setText(QApplication::translate("Widget", "     y:    ", Q_NULLPTR));
        label_10->setText(QApplication::translate("Widget", "     z:    ", Q_NULLPTR));
        label_33->setText(QApplication::translate("Widget", "  yaw:", Q_NULLPTR));
        uav_publish_position->setText(QApplication::translate("Widget", "publish position", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("Widget", "angular position control", Q_NULLPTR));
        label_11->setText(QApplication::translate("Widget", "roll:", Q_NULLPTR));
        label_12->setText(QApplication::translate("Widget", "pitch:", Q_NULLPTR));
        label_13->setText(QApplication::translate("Widget", "yaw:", Q_NULLPTR));
        uav_angular_publish->setText(QApplication::translate("Widget", "publish angular rotation", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(uavTab), QApplication::translate("Widget", "UAV Control", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(cam), QApplication::translate("Widget", "CAM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROLWINDOW_H
