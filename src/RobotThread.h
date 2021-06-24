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
#include <vector>

#include <ros/ros.h>
#include <ros/network.h>
#include <geometry_msgs/Pose.h>
#include <nav_msgs/Odometry.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>
#include <std_srvs/Trigger.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/MultiArrayLayout.h>
#include <std_msgs/MultiArrayDimension.h>

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
    Q_SLOT void setPositions(double q1, double q2, double q3, double q4, double q5, double q6);

    Q_SLOT void setSliderValue(double x, int y);

    Q_SLOT void posePlus(int radioServo);
    Q_SLOT void poseMinus(int radioServo);

    // Q_SLOT void setJoint(QString number);

    Q_SLOT void setJointCtrl();
    Q_SLOT void setToolCtrl();
    Q_SLOT void setJoystickCtrl();

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
    // ros::Publisher positioner1;
    // ros::Publisher positioner2;
    // ros::Publisher positioner3;
    // ros::Publisher positioner4;
    // ros::Publisher positioner5;
    // ros::Publisher positioner6;
    ros::Publisher groupPublisher;
    ros::ServiceClient startJoystickControlService;
    ros::ServiceClient startJointControlService;
    ros::ServiceClient startToolControlService;
    ros::Publisher EEpublisher;

    ros::Publisher joystickpub1;
    ros::Publisher joystickpub2;
    ros::Publisher joystickpub3;
    ros::Publisher joystickpub4;
    ros::Publisher joystickpub5;
    ros::Publisher joystickpub6;
    double slider;
    int radio;

    std::string ee_position_topic_name = "/control_arm_node/tool/current_pose";
    std::string joint_states_listener_name = "/lwa4p/joint_states";
    std::string joint_group_publisher_name = "/lwa4p/joint_group_position_controller/command";
    std::string ee_publisher_name = "/control_arm_node/arm/command/pose";
    std::string joint1_publisher_name = "/lwa4p/joint_1_position_controller/command";
    std::string joint2_publisher_name = "/lwa4p/joint_2_position_controller/command";
    std::string joint3_publisher_name = "/lwa4p/joint_3_position_controller/command";
    std::string joint4_publisher_name = "/lwa4p/joint_4_position_controller/command";
    std::string joint5_publisher_name = "/lwa4p/joint_5_position_controller/command";
    std::string joint6_publisher_name = "/lwa4p/joint_6_position_controller/command";
    std::string joystick_control_service_name = "/control_arm_node/controllers/start_position_controllers";
    std::string tool_control_service_name = "/control_arm_node/controllers/start_joint_trajectory_controller";
    std::string joint_control_service_name = "/control_arm_node/controllers/start_joint_group_position_controller";

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

    double data1;
    double data2;
    double data3;
    double data4;
    double data5;
    double data6;

};
#endif //ACORE_ROS_GUI_ROBOTTHREAD_H
