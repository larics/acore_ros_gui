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
#include <geometry_msgs/Twist.h> // TODO: Swap this with ROS geometry method
#include <nav_msgs/Odometry.h>

class RobotThread:public QObject {
    Q_OBJECT
public:
    RobotThread(int argc, char **pArgv);
    virtual ~RobotThread();

    bool init();

    Q_SLOT void run();

private:
    int m_Init_argc;
    char** m_pInit_argv;

    QThread * m_pThread;

    ros::Subscriber joint_listener;

};
#endif //ACORE_ROS_GUI_ROBOTTHREAD_H
