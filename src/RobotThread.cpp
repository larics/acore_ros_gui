#include "RobotThread.h"


RobotThread::RobotThread(int argc, char** pArgv)
    : m_Init_argc(argc),
    m_pInit_argv(pArgv)
{ 
 /** Constructor for the robot thread **/ 
QSettings settings(QString("/home/developer/moveit_ws/src/acore_ros_gui/config/config.ini"), QSettings::IniFormat);
loadSettings(&settings);

QSettings settings2(QString("/home/developer/moveit_ws/src/acore_ros_gui/config/uav_config.ini"), QSettings::IniFormat);
loadSettings2(&settings2);
}

RobotThread::~RobotThread()
{
    if(ros::isStarted())
    {
        ros::shutdown();
        ros::waitForShutdown();
    }
    m_pThread->wait();
} // destructor

bool RobotThread::init()
{
    m_pThread = new QThread();
    this->moveToThread(m_pThread);
    connect(m_pThread, &QThread::started, this, &RobotThread::run);
    ros::init(m_Init_argc, m_pInit_argv, "gui_command");

    ROS_INFO("Initializing RobotThread");

    if(!ros::master::check())
        return false;
    ros::start();
    ros::Time::init();
    ros::NodeHandle nh;

    //kreiranje QSettings-a za ARM
    QSettings settings(QString("/home/developer/moveit_ws/src/acore_ros_gui/configconfig.ini"), QSettings::IniFormat);

    //kreiranje QSettings-a za UAV
    QSettings settings2(QString("/home/developer/moveit_ws/src/acore_ros_gui/configuav_config.ini"), QSettings::IniFormat);

    // Services, publishers and subscribers for Arm
    ee_position_listener = nh.subscribe(m_ee_position_topic_name, 10, &RobotThread::eePoseCallback, this);
    state_listener = nh.subscribe(m_joint_states_listener_name, 10, &RobotThread::jointStates, this);

    groupPublisher = nh.advertise<std_msgs::Float64MultiArray>(m_joint_group_publisher_name, 100);

    EEpublisher = nh.advertise<geometry_msgs::Pose>(m_ee_publisher_name, 100);

    joystickpub1 = nh.advertise<std_msgs::Float64>(m_joint1_publisher_name, 100);
    joystickpub2 = nh.advertise<std_msgs::Float64>(m_joint2_publisher_name, 100);
    joystickpub3 = nh.advertise<std_msgs::Float64>(m_joint3_publisher_name, 100);
    joystickpub4 = nh.advertise<std_msgs::Float64>(m_joint4_publisher_name, 100);
    joystickpub5 = nh.advertise<std_msgs::Float64>(m_joint5_publisher_name, 100);
    joystickpub6 = nh.advertise<std_msgs::Float64>(m_joint6_publisher_name, 100);

    startJoystickControlService = nh.serviceClient<std_srvs::Trigger>(m_joystick_control_service_name);
    startToolControlService = nh.serviceClient<std_srvs::Trigger>(m_tool_control_service_name);
    startJointControlService = nh.serviceClient<std_srvs::Trigger>(m_joint_control_service_name);
    
    //Services, publishers and subscribers for UAV

    pointPublisher = nh.advertise<geometry_msgs::Pose>(m_point_publisher_name,100);
    uav_position_sub = nh.subscribe(m_uav_position_sub_name, 10, &RobotThread::uavPositions, this);
    rpyPublisher = nh.advertise<geometry_msgs::Vector3>(m_rpy_publisher_name, 100);


    //getting rosparam

    ros::NodeHandle nh1;
    float joint1_max_position;
    float joint2_max_position;

    float joint3_max_position;
    float joint4_max_position;

    float joint5_max_position;
    float joint6_max_position;

    float joint1_min_position;
    float joint2_min_position;

    float joint3_min_position;
    float joint4_min_position;

    float joint5_min_position;
    float joint6_min_position;

    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint1/max_velocity", joint1_max_position, 2.947);
    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint1/min_position", joint1_min_position, -2.947);

    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint2/max_position", joint2_max_position, 2.08);
    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint2/min_position", joint2_min_position, -2.08);

    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint3/max_position", joint3_max_position, 2.694);
    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint3/min_position", joint3_min_position, -2.694);

    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint4/max_position", joint4_max_position, 2.08);
    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint4/min_position", joint4_min_position, -2.08);

    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint5/max_position", joint5_max_position, 2.947);
    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint5/min_position", joint5_min_position, -2.947);

    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint6/max_position", joint6_max_position, 2.08);
    nh1.param<float>("/robot_description_planning/joint_limits/lwa4p_joint6/min_position", joint6_min_position, -2.08);

    Q_EMIT loadparameters(joint1_max_position, joint1_min_position, joint2_max_position, joint2_min_position, joint3_max_position, joint3_min_position,
    joint4_max_position, joint4_min_position, joint5_max_position, joint5_min_position, joint6_max_position, joint6_min_position);
    

    m_pThread->start();
    return true;
}


void RobotThread::eePoseCallback(const geometry_msgs::Pose &msg)
{
    QMutex * pMutex = new QMutex();

    pMutex->lock();
    m_eeXPos = msg.position.x;
    m_eeYPos = msg.position.y;
    m_eeZPos = msg.position.z;
    m_eeXOri = msg.orientation.x;
    m_eeYOri = msg.orientation.y;
    m_eeZOri = msg.orientation.z;
    m_eeWOri = msg.orientation.w;

    roll = atan2(2.0*(m_eeXOri*m_eeYOri + m_eeWOri*m_eeZOri), m_eeWOri*m_eeWOri + m_eeXOri*m_eeXOri - m_eeYOri*m_eeYOri - m_eeZOri*m_eeZOri);
    pitch = asin(-2.0*(m_eeXOri*m_eeZOri - m_eeWOri*m_eeYOri));
    yaw = atan2(2.0*(m_eeYOri*m_eeZOri + m_eeWOri*m_eeXOri), m_eeWOri*m_eeWOri - m_eeXOri*m_eeXOri - m_eeYOri*m_eeYOri + m_eeZOri*m_eeZOri);
    pMutex->unlock();

    delete pMutex;
    Q_EMIT newEEPose(m_eeXPos, m_eeYPos, m_eeZPos, yaw, pitch, roll);
}

void RobotThread::loadSettings(QSettings* settings){
    //load subscriber topics
    m_ee_position_topic_name = settings->value("subscribers/ee_position_topic_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_joint_states_listener_name = settings->value("subscribers/joint_states_listener_name", "Error/topic didn't load").toString().toUtf8().constData();
    //load publisher topics
    m_joint_group_publisher_name = settings->value("publishers/joint_group_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_ee_publisher_name = settings->value("publishers/ee_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_joint1_publisher_name = settings->value("publishers/joint1_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_joint2_publisher_name = settings->value("publishers/joint2_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_joint3_publisher_name = settings->value("publishers/joint3_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_joint4_publisher_name = settings->value("publishers/joint4_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_joint5_publisher_name = settings->value("publishers/joint5_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_joint6_publisher_name = settings->value("publishers/joint6_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    //load service topics
    m_joystick_control_service_name = settings->value("services/joystick_control_service_name", "Error, service didn't load").toString().toUtf8().constData();
    m_tool_control_service_name = settings->value("services/tool_control_service_name", "Error, service didn't load").toString().toUtf8().constData();
    m_joint_control_service_name = settings->value("services/joint_control_service_name", "Error, service didn't load").toString().toUtf8().constData();

}

void RobotThread::loadSettings2(QSettings* settings2){

    //load uav subscriber topics
    m_uav_position_sub_name = settings2->value("subscribers/uav_position_sub_name", "Error/topic didn't load").toString().toUtf8().constData();

    //load uav publisher topics
    m_rpy_publisher_name = settings2->value("publishers/rpy_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
    m_point_publisher_name = settings2->value("publishers/point_publisher_name", "Error/topic didn't load").toString().toUtf8().constData();
}


void RobotThread::jointStates(const sensor_msgs::JointState &msg){

    QMutex * pMutex = new QMutex();

    pMutex->lock();
    state1 = msg.position[0];
    state2 = msg.position[1];
    state3 = msg.position[2];
    state4 = msg.position[3];
    state5 = msg.position[4];
    state6 = msg.position[5];
    pMutex->unlock();

    delete pMutex;
    Q_EMIT newJointPose(state1, state2, state3, state4, state5, state6);

}

void RobotThread::run()
{
    ros::Rate loop_rate(1);
    // QMutex * pMutex;
    while( ros::ok())
    {
        // pMutex = new QMutex();

        // geometry_msgs::Pose EEmsg;

        // pMutex->lock();

        // EEmsg.position.x = positionx;
        // EEmsg.position.y = positiony;
        // EEmsg.position.z = positionz;
        // EEmsg.orientation.x = orientationx;
        // EEmsg.orientation.y = orientationy;
        // EEmsg.orientation.z = orientationz;
        // EEmsg.orientation.w = orientationw;

        // pMutex->unlock();

        // // EEpublisher.publish(EEmsg);
        
        ros::spinOnce();
        ROS_INFO("[RobotThread] Running...");
        loop_rate.sleep();
        // delete pMutex;
    }
}

// void RobotThread::setPositions(double x){

//     QMutex * pMutex = new QMutex();
//     std_msgs::Float64 msg1;

//     pMutex->lock();

//     data = x;
//     msg1.data = data;


//     if(joint_number=="q1"){
//         positioner1.publish(msg1);
//     }else if(joint_number=="q2"){
//         positioner2.publish(msg1);
//     }else if(joint_number=="q3"){
//         positioner3.publish(msg1);
//     }else if(joint_number=="q4"){
//         positioner4.publish(msg1);
//     }else if(joint_number=="q5"){
//         positioner5.publish(msg1);
//     }else if(joint_number=="q6"){
//         positioner6.publish(msg1);
//     }
//     pMutex->unlock();

//     delete pMutex;
// }

void RobotThread::setPosition1(double x){
    QMutex * pMutex = new QMutex();

    pMutex->lock();

    data = x;
    std::vector<double> vec1 = { data, state2, state3, state4, state5, state6};
    std_msgs::Float64MultiArray msg;

    msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
    msg.layout.dim[0].size = vec1.size();
    msg.layout.dim[0].stride = 1;
    msg.layout.dim[0].label = "x";

    msg.data.clear();
    msg.data.insert(msg.data.end(), vec1.begin(), vec1.end());
    groupPublisher.publish(msg);

    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition2(double x){
    QMutex * pMutex = new QMutex();

    pMutex->lock();

    data = x;
    std::vector<double> vec1 = { state1, data, state3, state4, state5, state6};
    std_msgs::Float64MultiArray msg;

    msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
    msg.layout.dim[0].size = vec1.size();
    msg.layout.dim[0].stride = 1;
    msg.layout.dim[0].label = "x";

    msg.data.clear();
    msg.data.insert(msg.data.end(), vec1.begin(), vec1.end());
    groupPublisher.publish(msg);

    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition3(double x){
    QMutex * pMutex = new QMutex();

    pMutex->lock();

    data = x;
    std::vector<double> vec1 = { state1, state2, data, state4, state5, state6};
    std_msgs::Float64MultiArray msg;

    msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
    msg.layout.dim[0].size = vec1.size();
    msg.layout.dim[0].stride = 1;
    msg.layout.dim[0].label = "x";

    msg.data.clear();
    msg.data.insert(msg.data.end(), vec1.begin(), vec1.end());
    groupPublisher.publish(msg);

    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition4(double x){
    QMutex * pMutex = new QMutex();

    pMutex->lock();

    data = x;
    std::vector<double> vec1 = { state1, state2, state3, data, state5, state6};
    std_msgs::Float64MultiArray msg;

    msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
    msg.layout.dim[0].size = vec1.size();
    msg.layout.dim[0].stride = 1;
    msg.layout.dim[0].label = "x";

    msg.data.clear();
    msg.data.insert(msg.data.end(), vec1.begin(), vec1.end());
    groupPublisher.publish(msg);

    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition5(double x){
    QMutex * pMutex = new QMutex();

    pMutex->lock();

    data = x;
    std::vector<double> vec1 = { state1, state2, state3, state4, data, state6};
    std_msgs::Float64MultiArray msg;

    msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
    msg.layout.dim[0].size = vec1.size();
    msg.layout.dim[0].stride = 1;
    msg.layout.dim[0].label = "x";

    msg.data.clear();
    msg.data.insert(msg.data.end(), vec1.begin(), vec1.end());
    groupPublisher.publish(msg);

    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition6(double x){
    QMutex * pMutex = new QMutex();

    pMutex->lock();

    data = x;
    std::vector<double> vec1 = { state1, state2, state3, state4, state5, data};
    std_msgs::Float64MultiArray msg;

    msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
    msg.layout.dim[0].size = vec1.size();
    msg.layout.dim[0].stride = 1;
    msg.layout.dim[0].label = "x";

    msg.data.clear();
    msg.data.insert(msg.data.end(), vec1.begin(), vec1.end());
    groupPublisher.publish(msg);

    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPositions(double q1, double q2, double q3, double q4, double q5, double q6){
    // QMutex * pMutex = new QMutex();
    // std_msgs::Float64MultiArray msgAll;
    // std::vector<float> poses;

    // pMutex->lock();
    data1 = q1;
    data2 = q2;
    data3 = q3;
    data4 = q4;
    data5 = q5;
    data6 = q6;
    // // poses.push_back(data1);
    // // poses.push_back(data2);
    // // poses.push_back(data3);
    // // poses.push_back(data4);
    // // poses.push_back(data5);
    // // poses.push_back(data6);
    // // msgAll.data[0] = data1;
    // // msgAll.data[1] = data2;
    // // msgAll.data[2] = data3;
    // // msgAll.data[3] = data4;
    // // msgAll.data[4] = data5;
    // // msgAll.data[5] = data6;
    // // msgAll.data = poses;
    // msgAll.data = {data1, data2, data3, data4, data5, data6};
    // groupPublisher.publish(msgAll);
    // pMutex->unlock();
    // delete pMutex;

    //dodavanje u multiarray
    std::vector<double> vec1 = { data1, data2, data3, data4, data5, data6};
    std_msgs::Float64MultiArray msg;

    // set up dimensions
    msg.layout.dim.push_back(std_msgs::MultiArrayDimension());
    msg.layout.dim[0].size = vec1.size();
    msg.layout.dim[0].stride = 1;
    msg.layout.dim[0].label = "x"; // or whatever name you typically use to index vec1

    // copy in the data
    msg.data.clear();
    msg.data.insert(msg.data.end(), vec1.begin(), vec1.end());
    groupPublisher.publish(msg);
}

// void RobotThread::setJoint(QString number){
//     QMutex * pMutex = new QMutex();
//     pMutex->lock();
//     joint_number = number;

//     pMutex->unlock();
//     delete pMutex;
// }

void RobotThread::setJointCtrl(){

    std_srvs::Trigger srv;
    startJointControlService.call(srv);
}

void RobotThread::setToolCtrl(){
    std_srvs::Trigger srv;
    startToolControlService.call(srv);
}

void RobotThread::setJoystickCtrl(){
    std_srvs::Trigger srv;
    startJoystickControlService.call(srv);
}

void RobotThread::setEEstates(double x, double y, double z, double ox, double oy, double oz, double ow){

    QMutex * pMutex = new QMutex();
    pMutex->lock();

    positionx = x;
    positiony = y;
    positionz = z;
    orientationx = ox;
    orientationy = oy;
    orientationz = oz;
    orientationw = ow;

    geometry_msgs::Pose EEmsg;

    EEmsg.position.x = positionx;
    EEmsg.position.y = positiony;
    EEmsg.position.z = positionz;
    EEmsg.orientation.x = orientationx;
    EEmsg.orientation.y = orientationy;
    EEmsg.orientation.z = orientationz;
    EEmsg.orientation.w = orientationw;

    EEpublisher.publish(EEmsg);

    pMutex->unlock();
    delete pMutex;

}

void RobotThread::setSliderValue(double x, int y){
    QMutex * pMutex = new QMutex();
    std_msgs::Float64 msg;
    pMutex->lock();
    radio = y;
    switch(radio){
        case 1:
            slider = x;
            msg.data = slider;
            joystickpub1.publish(msg);
            break;
        case 2:
            slider = x;
            msg.data = slider;
            joystickpub2.publish(msg);
            break;
        case 3:
            slider = x;
            msg.data = slider;
            joystickpub3.publish(msg);
            break;
        case 4:
            slider = x;
            msg.data = slider;
            joystickpub4.publish(msg);
            break;
        case 5:
            slider = x;
            msg.data = slider;
            joystickpub5.publish(msg);
            break;
        case 6:
            slider = x;
            msg.data = slider;
            joystickpub6.publish(msg);
            break;
            
    }
    pMutex->unlock();
    delete pMutex;
}

void RobotThread::posePlus(int radioServo){

    QMutex * pMutex = new QMutex();
    pMutex->lock();

    geometry_msgs::Pose newplusEEmsg;
    switch(radioServo){
        case 1:
            newplusEEmsg.position.x = m_eeXPos + 0.01;
            newplusEEmsg.position.y = m_eeYPos;
            newplusEEmsg.position.z = m_eeZPos;
            break;
        case 2:
            newplusEEmsg.position.y = m_eeYPos + 0.01;
            newplusEEmsg.position.x = m_eeXPos;
            newplusEEmsg.position.z = m_eeZPos;
            break;
        case 3:
            newplusEEmsg.position.z = m_eeZPos + 0.01;
            newplusEEmsg.position.x = m_eeXPos;
            newplusEEmsg.position.y = m_eeYPos;
            break;
    }
    newplusEEmsg.orientation.x = m_eeXOri;
    newplusEEmsg.orientation.y = m_eeYOri;
    newplusEEmsg.orientation.z = m_eeZOri;
    newplusEEmsg.orientation.w = m_eeWOri;

    EEpublisher.publish(newplusEEmsg);

    pMutex->unlock();
    delete pMutex;
}

void RobotThread::poseMinus(int radioServo){
    QMutex * pMutex = new QMutex();
    pMutex->lock();

    geometry_msgs::Pose newminusEEmsg;
    switch(radioServo){
        case 1:
            newminusEEmsg.position.x = m_eeXPos - 0.01;
            newminusEEmsg.position.y = m_eeYPos;
            newminusEEmsg.position.z = m_eeZPos;
            break;
        case 2:
            newminusEEmsg.position.y = m_eeYPos - 0.01;
            newminusEEmsg.position.x = m_eeXPos;
            newminusEEmsg.position.z = m_eeZPos;
            break;
        case 3:
            newminusEEmsg.position.z = m_eeZPos - 0.01;
            newminusEEmsg.position.x = m_eeXPos;
            newminusEEmsg.position.y = m_eeYPos;
            break;
    }
    newminusEEmsg.orientation.x = m_eeXOri;
    newminusEEmsg.orientation.y = m_eeYOri;
    newminusEEmsg.orientation.z = m_eeZOri;
    newminusEEmsg.orientation.w = m_eeWOri;

    EEpublisher.publish(newminusEEmsg);

    pMutex->unlock();
    delete pMutex;
}

//DIO KOJI SE ODNOSI NA UAV-UPRAVLJANJE ------------------------------------------------------------------------------------------

//setUavPointPosition - treba dodati odgovarajuci publisher

void RobotThread::setUavPointPosition(double x, double y, double z, double yaw){
    QMutex * pMutex = new QMutex();
    pMutex->lock();

    uav_positionx = x;
    uav_positiony = y;
    uav_positionz = z;
    
    geometry_msgs::Pose uavPoint_msg;

    uav_roll = 0;
    uav_pitch = 0;

    uav_qx = sin(roll/2) * cos(pitch/2) * cos(yaw/2) - cos(roll/2) * sin(pitch/2) * sin(yaw/2);
    uav_qy = cos(roll/2) * sin(pitch/2) * cos(yaw/2) + sin(roll/2) * cos(pitch/2) * sin(yaw/2);
    uav_qz = cos(roll/2) * cos(pitch/2) * sin(yaw/2) - sin(roll/2) * sin(pitch/2) * cos(yaw/2);
    uav_qw = cos(roll/2) * cos(pitch/2) * cos(yaw/2) + sin(roll/2) * sin(pitch/2) * sin(yaw/2);

    uavPoint_msg.position.x = uav_positionx;
    uavPoint_msg.position.y = uav_positiony;
    uavPoint_msg.position.z = uav_positionz;

    uavPoint_msg.orientation.x = uav_qx;
    uavPoint_msg.orientation.y = uav_qy;
    uavPoint_msg.orientation.z = uav_qz;
    uavPoint_msg.orientation.w = uav_qw;
    

    pointPublisher.publish(uavPoint_msg);

    pMutex->unlock();
    delete pMutex;
}

void RobotThread::uavPositions(const geometry_msgs::PoseStamped &msg){

    QMutex * pMutex = new QMutex();

    pMutex->lock();
    uav_x_state = msg.pose.position.x;
    uav_y_state = msg.pose.position.y;
    uav_z_state = msg.pose.position.z;

    uav_x_ori = msg.pose.orientation.x;
    uav_y_ori = msg.pose.orientation.y;
    uav_z_ori = msg.pose.orientation.z;
    uav_w_ori = msg.pose.orientation.w;

    disp_yaw = atan2(2.0*(uav_x_ori*uav_y_ori + uav_w_ori*uav_z_ori), uav_w_ori*uav_w_ori + uav_x_ori*uav_x_ori - uav_y_ori*uav_y_ori - uav_z_ori*uav_z_ori);
    disp_pitch = asin(-2.0*(uav_x_ori*uav_z_ori - uav_w_ori*m_eeYOri));
    disp_roll = atan2(2.0*(uav_y_ori*uav_z_ori + uav_w_ori*uav_x_ori), uav_w_ori*uav_w_ori - uav_x_ori*uav_x_ori - uav_y_ori*uav_y_ori + uav_z_ori*uav_z_ori);

    pMutex->unlock();

    delete pMutex;
    Q_EMIT uavSubPosition(uav_x_state, uav_y_state, uav_z_state, disp_roll, disp_pitch, disp_yaw);

}

void RobotThread::setUavRPY(double roll, double pitch, double yaw){
    QMutex * pMutex = new QMutex();
    pMutex->lock();

    uav_roll = roll;
    uav_pitch = pitch;
    uav_yaw = yaw;
    
    geometry_msgs::Vector3 uavRPY;

    uavRPY.x = uav_roll;
    uavRPY.y = uav_pitch;
    uavRPY.z = uav_yaw;
    
    rpyPublisher.publish(uavRPY);

    pMutex->unlock();
    delete pMutex;
}









// void RobotThread::jointUp(){
//     QMutex * pMutex = new QMutex();
//     std_msgs::Float64 msg1;

//     if(manualInfo){
//         pMutex->lock();
//         if(joint_number=="q1"){
//             newdata = state1 + 0.01;
//             msg1.data = newdata;
//             positioner1.publish(msg1);
//         }else if(joint_number=="q2"){
//             newdata = state2 + 0.01;
//             msg1.data = newdata;
//             positioner2.publish(msg1);
//         }else if(joint_number=="q3"){
//             newdata = state3 + 0.01;
//             msg1.data = newdata;
//             positioner3.publish(msg1);
//         }else if(joint_number=="q4"){
//             newdata = state4 + 0.01;
//             msg1.data = newdata;
//             positioner4.publish(msg1);
//         }else if(joint_number=="q5"){
//             newdata = state5 + 0.01;
//             msg1.data = newdata;
//             positioner5.publish(msg1);
//         }else if(joint_number=="q6"){
//             newdata = state6 + 0.01;
//             msg1.data = newdata;
//             positioner6.publish(msg1);
//         }
//         pMutex->unlock();
//     }
//     delete pMutex;
// }

// void RobotThread::jointDown(){
//     QMutex * pMutex = new QMutex();
//     std_msgs::Float64 msg1;


//     if(manualInfo){
//         pMutex->lock();
//         if(joint_number=="q1"){
//             newdata = state1 - 0.01;
//             msg1.data = newdata;
//             positioner1.publish(msg1);
//         }else if(joint_number=="q2"){
//             newdata = state2 - 0.01;
//             msg1.data = newdata;
//             positioner2.publish(msg1);
//         }else if(joint_number=="q3"){
//             newdata = state3 - 0.01;
//             msg1.data = newdata;
//             positioner3.publish(msg1);
//         }else if(joint_number=="q4"){
//             newdata = state4 - 0.01;
//             msg1.data = newdata;
//             positioner4.publish(msg1);
//         }else if(joint_number=="q5"){
//             newdata = state5 - 0.01;
//             msg1.data = newdata;
//             positioner5.publish(msg1);
//         }else if(joint_number=="q6"){
//             newdata = state6 - 0.01;
//             msg1.data = newdata;
//             positioner6.publish(msg1);
//         }
//         pMutex->unlock();
//     }

//     delete pMutex;
// }

// void RobotThread::manualinfo(bool manual){
//     QMutex * pMutex = new QMutex();
//     pMutex->lock();
//     manualInfo = manual;
//     pMutex->unlock();
//     delete pMutex;
// }

// double RobotThread::getData(){return data;}
