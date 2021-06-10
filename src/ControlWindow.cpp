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
        // connect(ui->loaButton, &QPushButton::clicked, this, &ControlWindow::getPositions);
        // connect(ui->loaButton, &QPushButton::clicked, this, &ControlWindow::getJointNumber);

        connect(ui->publishButton, &QPushButton::clicked, this, &ControlWindow::getPositions);
        connect(ui->publishButton, &QPushButton::clicked, this, &ControlWindow::getJointNumber);
        // connect(ui->publishButton, &QPushButton::clicked, this, &ControlWindow::sendPositions);
        connect(ui->publishButton, &QPushButton::clicked, this, &ControlWindow::sendJointInfo);
        
        connect(&m_RobotThread, &RobotThread::newEEPose, this, &ControlWindow::updateEEStateDisplay);
        connect(&m_RobotThread, &RobotThread::newJointPose, this, &ControlWindow::updateJointStateDisplay);

        connect(ui->toolControl, &QPushButton::clicked, this, &ControlWindow::setToolControl);
        connect(ui->jointControl, &QPushButton::clicked, this, &ControlWindow::setJointControl);

        connect(ui->pushButton, &QPushButton::clicked, this, &ControlWindow::getEEstate);

        connect(ui->up, &QPushButton::pressed, this, &ControlWindow::upJoint);
        connect(ui->down, &QPushButton::pressed, this, &ControlWindow::downJoint);
        connect(ui->manualOn, &QPushButton::clicked, this, &ControlWindow::startManual);
        connect(ui->manualOff, &QPushButton::clicked, this, &ControlWindow::stopManual);

        ui->up->setAutoRepeat(true);
        ui->down->setAutoRepeat(true);

        m_RobotThread.init();

    } // end contstructor

    void ControlWindow::startGUI(){
        m_GUI = true;
    }

    void ControlWindow::startManual(){
        manual = true;
        ui->onoff->setText("ON");
        m_RobotThread.manualinfo(manual);
    }

    void ControlWindow::stopManual(){
        manual = false;
        ui->onoff->setText("OFF");
        m_RobotThread.manualinfo(manual);
    }

    void ControlWindow::updateEEStateDisplay(double x, double y, double z) {
        QString xPosition, yPosition, zPosition;
        QString connectionWarning("start GUI.");
        xPosition.setNum(x, 'f', 2); yPosition.setNum(y, 'f', 2); zPosition.setNum(z, 'f', 2);
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


    void ControlWindow::updateJointStateDisplay(double a, double b, double c, double x, double y, double z){

        QString state1disp, state2disp, state3disp, state4disp, state5disp, state6disp;
        state1disp.setNum(a, 'f', 2); state2disp.setNum(b, 'f', 2); state3disp.setNum(c, 'f', 2);
        state4disp.setNum(x, 'f', 2); state5disp.setNum(y, 'f', 2); state6disp.setNum(z, 'f', 2);
        QString connectionWarning("Start GUI");

        if(m_GUI){
            ui->joint1_value->setText(state1disp);
            ui->joint2_value->setText(state2disp);
            ui->joint3_value->setText(state3disp);
            ui->joint4_value->setText(state4disp);
            ui->joint5_value->setText(state5disp);
            ui->joint6_value->setText(state6disp);
        }else{
            ui->joint1_value->setText(connectionWarning);
            ui->joint2_value->setText(connectionWarning);
            ui->joint3_value->setText(connectionWarning);
            ui->joint4_value->setText(connectionWarning);
            ui->joint5_value->setText(connectionWarning);
            ui->joint6_value->setText(connectionWarning);
        }

    }
    
    // reading from lineEdits and sending info to RobotThread
    void ControlWindow::getPositions(){
        QString pos1;
        pos1 = ui->lineEdit->text();
        pos1f = pos1.toFloat();
        if(pos1f>3.14 || pos1f<-3.14){
            QMessageBox::warning(this, "Radian input","Position must be in radians");
        }
        else{
            m_RobotThread.setPositions(pos1f);
        }
    }

    void ControlWindow::getJointNumber(){
        // QString number;
        number = ui->comboBox->currentText();
    }

    void ControlWindow::getEEstate(){
        QString x, y, z, orix, oriy, oriz, oriw;
        x = ui->posex->text();
        y = ui->posey->text();
        z = ui->posez->text();
        orix = ui->orientationx->text();
        oriy = ui->orientationy->text();
        oriz = ui->orientationz->text();
        oriw = ui->orientationw->text();
        xf = x.toFloat();
        yf = y.toFloat();
        zf = z.toFloat();
        orixf = orix.toFloat();
        oriyf = oriy.toFloat();
        orizf = oriz.toFloat();
        oriwf = oriw.toFloat();

        if(xf<-0.5 || xf>0.5 || yf<-0.5 || yf>0.5 || zf<0.7 || zf>1.29){
            QMessageBox::warning(this, "ERROR", "Wrong inputs!");
        }else{
            m_RobotThread.setEEstates(xf, yf, zf, orixf, oriyf, orizf, oriwf);
        }

    }

    void ControlWindow::sendJointInfo(){m_RobotThread.setJoint(number);}

    void ControlWindow::setJointControl(){
        m_RobotThread.setJointCtrl();
        ui->controlstatus->setText("Joint control running...");
    }
    void ControlWindow::setToolControl(){
        m_RobotThread.setToolCtrl();
        ui->controlstatus->setText("Tool control running...");
    }

    // //arrows
    void ControlWindow::upJoint(){m_RobotThread.jointUp();}
    void ControlWindow::downJoint(){m_RobotThread.jointDown();}

}
