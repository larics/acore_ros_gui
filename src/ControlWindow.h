//
// Created by developer on 5/24/21.
//

#ifndef CONTROL_WINDOW_H
#define CONTROL_WINDOW_H
#include <QtWidgets>
#include <QString>
#include <QWidget>
#include <QPushButton>
#include "RobotThread.h"

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


private:

    Ui::Widget *ui;

    bool m_GUI = false;

    RobotThread m_RobotThread;

};// end class ControlWindow
}// end namespace
#endif //CONTROL_WINDOW_H
