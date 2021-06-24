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
        connect(ui->publishAll, &QPushButton::clicked, this, &ControlWindow::getPositions);
        
        connect(&m_RobotThread, &RobotThread::newEEPose, this, &ControlWindow::updateEEStateDisplay);
        connect(&m_RobotThread, &RobotThread::newJointPose, this, &ControlWindow::updateJointStateDisplay);

        //na koji nacin kontroliramo manipulator GOTOVO (možda jedino promjeniti lavel u koji se posta)
        connect(ui->trajCtlEnableButton, &QPushButton::clicked, this, &ControlWindow::setToolControl);
        connect(ui->jointCtlEnableButton, &QPushButton::clicked, this, &ControlWindow::setJointControl);
        connect(ui->joyCtlButton, &QPushButton::clicked, this, &ControlWindow::setJoystickControl);
        connect(ui->servoToolCtlButton, &QPushButton::clicked, this, &ControlWindow::setServoControl);

        //publishanje ee GOTOVO
        connect(ui->trajSendCmdButton, &QPushButton::clicked, this, &ControlWindow::getEEstate);

        //inicijalizacija slidera za svaki zglob posebno
        connect(ui->q1RadioButton, &QRadioButton::clicked, this, &ControlWindow::sliderinit1);
        connect(ui->q2RadioButton, &QRadioButton::clicked, this, &ControlWindow::sliderinit2);
        connect(ui->q3RadioButton, &QRadioButton::clicked, this, &ControlWindow::sliderinit3);
        connect(ui->q4RadioButton, &QRadioButton::clicked, this, &ControlWindow::sliderinit4);
        connect(ui->q5RadioButton, &QRadioButton::clicked, this, &ControlWindow::sliderinit5);
        connect(ui->q6RadioButton, &QRadioButton::clicked, this, &ControlWindow::sliderinit6);

        //publishanje sa sliderom
        connect(ui->joyCtlPublishButton, &QPushButton::clicked, this, &ControlWindow::getSliderValue);

        connect(ui->servoToolCtlUpButton, &QPushButton::pressed, this, &ControlWindow::plusPose);
        connect(ui->servoToolCtlDownButton, &QPushButton::pressed, this, &ControlWindow::minusPose);
        ui->servoToolCtlUpButton->setAutoRepeat(true);
        ui->servoToolCtlDownButton->setAutoRepeat(true);

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
        ui->guiModeLabel->setText("Joint control running...");
    }
    void ControlWindow::setToolControl(){
        m_RobotThread.setToolCtrl();
        ui->guiModeLabel->setText("Tool control running...");
    }

    void ControlWindow::setJoystickControl(){
        m_RobotThread.setJoystickCtrl();
        ui->guiModeLabel->setText("Joystick control running...");
    }

    void ControlWindow::setServoControl(){
        m_RobotThread.setToolCtrl();
        ui->guiModeLabel->setText("Servo control running...");
    }

    // +/-
    void ControlWindow::plusPose(){
        if(ui->radioButtonX->isChecked()){
            radioServo = 1;
        }else if(ui->radioButtonY->isChecked()){
            radioServo = 2;
        }else if(ui->radioButtonZ->isChecked()){
            radioServo = 3;
        }
        m_RobotThread.posePlus(radioServo);
    }
    void ControlWindow::minusPose(){
        if(ui->radioButtonX->isChecked()){
            radioServo = 1;
        }else if(ui->radioButtonY->isChecked()){
            radioServo = 2;
        }else if(ui->radioButtonZ->isChecked()){
            radioServo = 3;
        }
        m_RobotThread.poseMinus(radioServo);
    }

    // NOVE FUNKCIJE OVE KOJE KORISTIMO ZA GUI 2.0

    void ControlWindow::getPositions(){
        QString pos1; QString pos2; QString pos3;
        QString pos4; QString pos5; QString pos6;
        pos1 = ui->q1CmdLineEdit->text();
        pos2 = ui->q2LineEdit->text();
        pos3 = ui->q3LineEdit->text();
        pos4 = ui->q4LineEdit->text();
        pos5 = ui->q5LineEdit->text();
        pos6 = ui->q6LineEdit->text();
        pos1f = pos1.toFloat();
        pos2f = pos2.toFloat();
        pos3f = pos3.toFloat();
        pos4f = pos4.toFloat();
        pos5f = pos5.toFloat();
        pos6f = pos6.toFloat();
        if(pos1f>PI || pos1f<-PI || pos2f>PI || pos2f<-PI || pos3f>PI || pos3f<-PI || pos4f>PI || pos4f<-PI || pos5f>PI || pos5f<-PI || pos6f>PI || pos6f<-PI){
            QMessageBox::warning(this, "Radian input","Position must be in radians");
        }
        else{
            m_RobotThread.setPositions(pos1f, pos2f, pos3f, pos4f, pos5f, pos6f);
        }
    }

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

    void ControlWindow::sliderinit1(){
        radio_value = 1;
        ui->horizontalSlider->setMinimum(-100);
        ui->horizontalSlider->setMaximum(120);
        ui->horizontalSliderMinLabel->setText("-1.0");
        ui->horizontalSliderMaxLabel->setText("1.2");
    }

    void ControlWindow::sliderinit2(){
        radio_value = 2;
        ui->horizontalSlider->setMinimum(-200);
        ui->horizontalSlider->setMaximum(200);
        ui->horizontalSliderMinLabel->setText("-2.0");
        ui->horizontalSliderMaxLabel->setText("2.0");
    }

    void ControlWindow::sliderinit3(){
        radio_value = 3;
        ui->horizontalSlider->setMinimum(-300);
        ui->horizontalSlider->setMaximum(300);
        ui->horizontalSliderMinLabel->setText("-3.0");
        ui->horizontalSliderMaxLabel->setText("3.0");
    }

    void ControlWindow::sliderinit4(){
        radio_value = 4;
        ui->horizontalSlider->setMinimum(-1);
        ui->horizontalSlider->setMaximum(1.2);
        ui->horizontalSliderMinLabel->setText("-1");
        ui->horizontalSliderMaxLabel->setText("1.2");
    }

    void ControlWindow::sliderinit5(){
        radio_value = 5;
        ui->horizontalSlider->setMinimum(-1);
        ui->horizontalSlider->setMaximum(1.2);
        ui->horizontalSliderMinLabel->setText("-1");
        ui->horizontalSliderMaxLabel->setText("1.2");
    }

    void ControlWindow::sliderinit6(){
        radio_value = 6;
        ui->horizontalSlider->setMinimum(-1);
        ui->horizontalSlider->setMaximum(1.2);
        ui->horizontalSliderMinLabel->setText("-1");
        ui->horizontalSliderMaxLabel->setText("1.2");
    }

    void ControlWindow::getSliderValue(){
        slider_value = ui->horizontalSlider->value()/100.0;
        m_RobotThread.setSliderValue(slider_value, radio_value);
    }

}
