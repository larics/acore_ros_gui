#include "ControlWindow.h"
#include "ui_controlwindow.h"

namespace server{
    ControlWindow::ControlWindow(int argc, char** argv, QWidget *parent)
        :QWidget(parent),
        ui(new Ui::Widget),
        m_RobotThread(argc, argv)
    {
        // SetupUI

        ui->setupUi(this);
        //show();
        setWindowTitle(tr("ControlWindow"));

        // Connecting eePositionFetchButton with updateEEDisplay method, every other button should have same connection
        connect(ui->startButton, &QPushButton::clicked, this, &ControlWindow::startGUI);
        connect(&m_RobotThread, &RobotThread::newEEPose, this, &ControlWindow::updateEEStateDisplay);
        m_RobotThread.init();

    } // end contstructor

    void ControlWindow::startGUI(){
        m_GUI = true;
    }

    void ControlWindow::updateEEStateDisplay(double x, double y, double z) {
        QString xPosition, yPosition, zPosition;
        QString connectionWarning("start GUI.");
        xPosition.setNum(x); yPosition.setNum(y); zPosition.setNum(z);
        if (m_GUI)
        {
            ui->ee_XLabel->setText(xPosition);
            ui->ee_YLabel->setText(yPosition);
            ui->ee_ZLabel->setText(zPosition);
        }
        else{
            ui->ee_XLabel->setText(connectionWarning);
            ui->ee_YLabel->setText(connectionWarning);
            ui->ee_ZLabel->setText(connectionWarning);
        }

    }
}