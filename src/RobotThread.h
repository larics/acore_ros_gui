#ifndef ___ROBOTTHREAD_H___
#define ___ROBOTTHREAD_H___

#include <QtCore>
#include <QThread>
#include <QStringList>
#include <stdlib.h>
#include <QMutex>
#include <iostream>
#include "assert.h"

#include <ros/ros.h>
#include <ros/network.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>

class RobotThread:public QObject {
    Q_OBJECT
public:
    RobotThread(int argc, char **pArgv);
    virtual ~RobotThread();

    bool init();

    // Subscriber callback methods
    void eePoseCallback(const geometry_msgs::Pose & msg);

    Q_SLOT void run();

    Q_SIGNAL void newEEPose(double,double,double,double,double,double,double);

private:
    int m_Init_argc;
    char** m_pInit_argv;

    QThread * m_pThread;

    ros::Subscriber ee_position_listener;
    std::string ee_position_topic_name = "/control_arm_node/tool/current_pose";

    double m_eeXPos; double m_eeYPos; double m_eeZPos;
    double m_eeXOri; double m_eeYOri; double m_eeZOri; double m_eeWOri;

};
#endif //ACORE_ROS_GUI_ROBOTTHREAD_H
