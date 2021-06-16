#ifndef ___ROBOTTHREAD_H___
#define ___ROBOTTHREAD_H___

#include <QtCore>
#include <QThread>
#include <QStringList>
#include <stdlib.h>
#include <QString>
#include <QMutex>
#include <iostream>
#include "assert.h"
#include <QChar>

#include <cmath>

#include <ros/ros.h>
#include <ros/network.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>
#include <std_srvs/Trigger.h>

class RobotThread:public QObject {
    Q_OBJECT
public:
    RobotThread(int argc, char **pArgv);
    virtual ~RobotThread();

    bool init();

    // Subscriber callback methods
    void eePoseCallback(const geometry_msgs::Pose & msg);
    void jointStates(const sensor_msgs::JointState &msg);

    Q_SLOT void run();

    Q_SIGNAL void newEEPose(double,double,double,double,double,double);
    Q_SIGNAL void newJointPose(double, double, double, double, double, double);

    Q_SLOT void setPosition1(double x);
    Q_SLOT void setPosition2(double x);
    Q_SLOT void setPosition3(double x);
    Q_SLOT void setPosition4(double x);
    Q_SLOT void setPosition5(double x);
    Q_SLOT void setPosition6(double x);


    // Q_SLOT void setJoint(QString number);

    Q_SLOT void setJointCtrl();
    Q_SLOT void setToolCtrl();

    Q_SLOT void setEEstates(double, double, double, double, double, double, double);

    // Q_SLOT void jointUp();
    // Q_SLOT void jointDown();
    // Q_SLOT void manualinfo(bool);

    // double getData();

private:
    int m_Init_argc;
    char** m_pInit_argv;

    QThread * m_pThread;

    ros::Subscriber ee_position_listener;
    ros::Subscriber state_listener;
    ros::Publisher positioner1;
    ros::Publisher positioner2;
    ros::Publisher positioner3;
    ros::Publisher positioner4;
    ros::Publisher positioner5;
    ros::Publisher positioner6;
    ros::ServiceClient startPositionControllerClient;
    ros::ServiceClient startPositionControllerClient1;
    ros::ServiceClient startPositionControllerClient2;
    ros::Publisher EEpublisher;

    std::string ee_position_topic_name = "/control_arm_node/tool/current_pose";

    double m_eeXPos; double m_eeYPos; double m_eeZPos;
    double m_eeXOri; double m_eeYOri; double m_eeZOri; double m_eeWOri;

    double roll; double yaw; double pitch;

    double state1; double state2; double state3;
    double state4; double state5; double state6;

    std_msgs::Float64 msg1;
    std_msgs::Float64 msg2;
    std_msgs::Float64 msg3;
    std_msgs::Float64 msg4;
    std_msgs::Float64 msg5;
    std_msgs::Float64 msg6;
    double data;
    // QString joint_number;

    geometry_msgs::Pose EEmsg;
    double positionx;
    double positiony;
    double positionz;
    double orientationx;
    double orientationy;
    double orientationz;
    double orientationw;

    // double newdata;
    // bool manualInfo;

};
#endif //ACORE_ROS_GUI_ROBOTTHREAD_H
