//
// Created by developer on 5/24/21.
//

#ifndef CONTROL_WINDOW_H
#define CONTROL_WINDOW_H
#include <QtWidgets>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include <QComboBox>
#include "RobotThread.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {class Widget; }
QT_END_NAMESPACE


namespace server{
#define PI 3.14159265359

class ControlWindow : public QWidget
{
    Q_OBJECT

public:
    ControlWindow(int argc, char** argv, QWidget * parent = 0);

    Q_SLOT void startGUI();
    Q_SLOT void updateEEStateDisplay(double x, double y, double z, double yaw, double pitch, double roll);
    Q_SLOT void updateJointStateDisplay(double a, double b, double c, double x, double y, double z);

    Q_SLOT void getPosition1();
    Q_SLOT void getPosition2();
    Q_SLOT void getPosition3();
    Q_SLOT void getPosition4();
    Q_SLOT void getPosition5();
    Q_SLOT void getPosition6();
    Q_SLOT void getPositions();
    Q_SLOT void setToolControl();
    Q_SLOT void setJointControl();
    Q_SLOT void setJoystickControl();
    Q_SLOT void setServoControl();
    Q_SLOT void getEEstate();
    Q_SLOT void sliderinit1();
    Q_SLOT void sliderinit2();
    Q_SLOT void sliderinit3();
    Q_SLOT void sliderinit4();
    Q_SLOT void sliderinit5();
    Q_SLOT void sliderinit6();
    Q_SLOT void getSliderValue();

    // Q_SLOT void getJointNumber();
    // Q_SLOT void sendJointInfo();
    Q_SLOT void plusPose();
    Q_SLOT void minusPose();
    // Q_SLOT void startManual();
    // Q_SLOT void stopManual();


private:

    Ui::Widget *ui;

    bool m_GUI = false;
    // bool manual = false;

    RobotThread m_RobotThread;

    QString pos1;
    double pos1f;
    
    QString pos2;
    double pos2f;

    QString pos3;
    double pos3f;

    QString pos4;
    double pos4f;

    QString pos5;
    double pos5f;

    QString pos6;
    double pos6f;

    double  slider_value;
    int radio_value;

    int radioServo;

    // QString number;

    double xf;
    double yf;
    double zf;
    double orixf;
    double oriyf;
    double orizf;
    double oriwf;

};// end class ControlWindow
}// end namespace
#endif //CONTROL_WINDOW_H
