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
        connect(ui->enableGUIButton, &QPushButton::clicked, this, &ControlWindow::startGUI);

        //publishanje joint state GOTOVO
        connect(ui->q1SendCmdButton, &QPushButton::clicked, this, &ControlWindow::getPosition1);
        connect(ui->q2SendCmdButton, &QPushButton::clicked, this, &ControlWindow::getPosition2);
        connect(ui->q3SendCmdButton, &QPushButton::clicked, this, &ControlWindow::getPosition3);
        connect(ui->q4SendCmdButton, &QPushButton::clicked, this, &ControlWindow::getPosition4);
        connect(ui->q5SendCmdButton, &QPushButton::clicked, this, &ControlWindow::getPosition5);
        connect(ui->q6SendCmdButton, &QPushButton::clicked, this, &ControlWindow::getPosition6);
        
        connect(&m_RobotThread, &RobotThread::newEEPose, this, &ControlWindow::updateEEStateDisplay);
        connect(&m_RobotThread, &RobotThread::newJointPose, this, &ControlWindow::updateJointStateDisplay);

        //na koji nacin kontroliramo manipulator GOTOVO (možda jedino promjeniti lavel u koji se posta)
        connect(ui->trajCtlEnableButton, &QPushButton::clicked, this, &ControlWindow::setToolControl);
        connect(ui->jointCtlEnableButton, &QPushButton::clicked, this, &ControlWindow::setJointControl);

        //publishanje ee GOTOVO
        connect(ui->trajSendCmdButton, &QPushButton::clicked, this, &ControlWindow::getEEstate);

        // connect(ui->up, &QPushButton::pressed, this, &ControlWindow::upJoint);
        // connect(ui->down, &QPushButton::pressed, this, &ControlWindow::downJoint);
        // connect(ui->manualOn, &QPushButton::clicked, this, &ControlWindow::startManual);
        // connect(ui->manualOff, &QPushButton::clicked, this, &ControlWindow::stopManual);

        // ui->up->setAutoRepeat(true);
        // ui->down->setAutoRepeat(true);

        m_RobotThread.init();

    } // end contstructor

    void ControlWindow::startGUI(){
        m_GUI = true;
    }

    // void ControlWindow::startManual(){
    //     manual = true;
    //     ui->onoff->setText("ON");
    //     m_RobotThread.manualinfo(manual);
    // }

    // void ControlWindow::stopManual(){
    //     manual = false;
    //     ui->onoff->setText("OFF");
    //     m_RobotThread.manualinfo(manual);
    // }

    void ControlWindow::updateEEStateDisplay(double x, double y, double z, double yaw, double pitch, double roll) {
        QString xPosition, yPosition, zPosition, yaws, pitchs, rolls;
        QString connectionWarning("start GUI.");
        xPosition.setNum(x, 'f', 2); yPosition.setNum(y, 'f', 2); zPosition.setNum(z, 'f', 2);
        yaws.setNum(yaw, 'f', 2); rolls.setNum(roll, 'f', 2); pitchs.setNum(pitch, 'f', 2);
        if (m_GUI)
        {
            ui->xPositionLabel->setText(xPosition);
            ui->yPositionLabel->setText(yPosition);
            ui->zPositionLabel->setText(zPosition);
            ui->rollOrientationLabel->setText(rolls);
            ui->pitchOrientationLabel->setText(pitchs);
            ui->yawOrientationLabel->setText(yaws);
        }
        else{
            ui->xPositionLabel->setText(connectionWarning);
            ui->yPositionLabel->setText(connectionWarning);
            ui->zPositionLabel->setText(connectionWarning);
            ui->rollOrientationLabel->setText(connectionWarning);
            ui->pitchOrientationLabel->setText(connectionWarning);
            ui->yawOrientationLabel->setText(connectionWarning);
        }

    }


    void ControlWindow::updateJointStateDisplay(double a, double b, double c, double x, double y, double z){

        QString state1disp, state2disp, state3disp, state4disp, state5disp, state6disp;
        state1disp.setNum(a, 'f', 2); state2disp.setNum(b, 'f', 2); state3disp.setNum(c, 'f', 2);
        state4disp.setNum(x, 'f', 2); state5disp.setNum(y, 'f', 2); state6disp.setNum(z, 'f', 2);
        QString connectionWarning("Start GUI");

        if(m_GUI){
            ui->q1PositionLabel->setText(state1disp);
            ui->q2PositionLabel->setText(state2disp);
            ui->q3PositionLabel->setText(state3disp);
            ui->q4PositionLabel->setText(state4disp);
            ui->q5PositionLabel->setText(state5disp);
            ui->q6PositionLabel->setText(state6disp);
        }else{
            ui->q1PositionLabel->setText(connectionWarning);
            ui->q2PositionLabel->setText(connectionWarning);
            ui->q3PositionLabel->setText(connectionWarning);
            ui->q4PositionLabel->setText(connectionWarning);
            ui->q5PositionLabel->setText(connectionWarning);
            ui->q6PositionLabel->setText(connectionWarning);
        }

    }
    
    // reading from lineEdits and sending info to RobotThread

    void ControlWindow::getEEstate(){
        QString x, y, z, orix, oriy, oriz, oriw;
        x = ui->trajCtlLineEditX->text();
        y = ui->trajCtlLineEditY->text();
        z = ui->trajCtlLineEditZ->text();
        orix = ui->trajCtlLineEditqX->text();
        oriy = ui->trajCtlLineEditqY->text();
        oriz = ui->trajCtlLineEditqZ->text();
        oriw = ui->trajCtlLineEditqW->text();
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

    // void ControlWindow::sendJointInfo(){m_RobotThread.setJoint(number);}

    void ControlWindow::setJointControl(){
        m_RobotThread.setJointCtrl();
        ui->ctlModeLabel->setText("Joint control running...");
    }
    void ControlWindow::setToolControl(){
        m_RobotThread.setToolCtrl();
        ui->ctlModeLabel->setText("Tool control running...");
    }

    // //arrows
    // void ControlWindow::upJoint(){m_RobotThread.jointUp();}
    // void ControlWindow::downJoint(){m_RobotThread.jointDown();}

    // NOVE FUNKCIJE OVE KOJE KORISTIMO ZA GUI 2.0

    void ControlWindow::getPosition1(){
        QString pos1;
        pos1 = ui->q1CmdLineEdit->text();
        pos1f = pos1.toFloat();
        if(pos1f>PI || pos1f<-PI){
            QMessageBox::warning(this, "Radian input","Position must be in radians");
        }
        else{
            m_RobotThread.setPosition1(pos1f);
        }
    }

    void ControlWindow::getPosition2(){
        QString pos2;
        pos2 = ui->q2LineEdit->text();
        pos2f = pos2.toFloat();
        if(pos2f>PI || pos2f<-PI){
            QMessageBox::warning(this, "Radian input","Position must be in radians");
        }
        else{
            m_RobotThread.setPosition2(pos2f);
        }
    }

    void ControlWindow::getPosition3(){
        QString pos3;
        pos3 = ui->q3LineEdit->text();
        pos3f = pos3.toFloat();
        if(pos3f>PI || pos3f<-PI){
            QMessageBox::warning(this, "Radian input","Position must be in radians");
        }
        else{
            m_RobotThread.setPosition3(pos3f);
        }
    }

    void ControlWindow::getPosition4(){
        QString pos4;
        pos4 = ui->q4LineEdit->text();
        pos4f = pos4.toFloat();
        if(pos4f>PI || pos4f<-PI){
            QMessageBox::warning(this, "Radian input","Position must be in radians");
        }
        else{
            m_RobotThread.setPosition4(pos4f);
        }
    }

    void ControlWindow::getPosition5(){
        QString pos5;
        pos5 = ui->q5LineEdit->text();
        pos5f = pos5.toFloat();
        if(pos5f>PI || pos5f<-PI){
            QMessageBox::warning(this, "Radian input","Position must be in radians");
        }
        else{
            m_RobotThread.setPosition5(pos5f);
        }
    }

    void ControlWindow::getPosition6(){
        QString pos6;
        pos6 = ui->q6LineEdit->text();
        pos6f = pos6.toFloat();
        if(pos6f>PI || pos6f<-PI){
            QMessageBox::warning(this, "Radian input","Position must be in radians");
        }
        else{
            m_RobotThread.setPosition6(pos6f);
        }
    }

}
