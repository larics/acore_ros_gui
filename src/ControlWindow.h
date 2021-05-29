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
    Q_SLOT void updateEEStateDisplay(double x, double y, double z);
    Q_SLOT void updateJointStateDisplay(double a, double b, double c, double x, double y, double z);
    Q_SLOT void getPositions();
    Q_SLOT void getJointNumber();
    // Q_SLOT void sendPositions();
    Q_SLOT void sendJointInfo();
    Q_SLOT void setToolControl();
    Q_SLOT void setJointControl();
    Q_SLOT void getEEstate();


private:

    Ui::Widget *ui;

    bool m_GUI = false;

    RobotThread m_RobotThread;

    QString pos1;
    double pos1f;
    
    QString number;

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
