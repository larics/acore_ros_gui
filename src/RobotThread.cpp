#include "RobotThread.h"


RobotThread::RobotThread(int argc, char** pArgv)
    : m_Init_argc(argc),
    m_pInit_argv(pArgv)
{   /** Constructor for the robot thread **/  }

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

    // TODO: Add corresponding subscribers and publishers
    ee_position_listener = nh.subscribe(ee_position_topic_name, 10, &RobotThread::eePoseCallback, this);
    state_listener = nh.subscribe(joint_states_listener_name, 10, &RobotThread::jointStates, this);

    // positioner1 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_1_position_controller/command", 100);
    // positioner2 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_2_position_controller/command", 100);
    // positioner3 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_3_position_controller/command", 100);
    // positioner4 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_4_position_controller/command", 100);
    // positioner5 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_5_position_controller/command", 100);
    // positioner6 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_6_position_controller/command", 100);
    groupPublisher = nh.advertise<std_msgs::Float64MultiArray>(joint_group_publisher_name, 100);

    EEpublisher = nh.advertise<geometry_msgs::Pose>(ee_publisher_name, 100);

    joystickpub1 = nh.advertise<std_msgs::Float64>(joint1_publisher_name, 100);
    joystickpub2 = nh.advertise<std_msgs::Float64>(joint2_publisher_name, 100);
    joystickpub3 = nh.advertise<std_msgs::Float64>(joint3_publisher_name, 100);
    joystickpub4 = nh.advertise<std_msgs::Float64>(joint4_publisher_name, 100);
    joystickpub5 = nh.advertise<std_msgs::Float64>(joint5_publisher_name, 100);
    joystickpub6 = nh.advertise<std_msgs::Float64>(joint6_publisher_name, 100);

    

    startJoystickControlService = nh.serviceClient<std_srvs::Trigger>(joystick_control_service_name);
    startToolControlService = nh.serviceClient<std_srvs::Trigger>(tool_control_service_name);
    startJointControlService = nh.serviceClient<std_srvs::Trigger>(joint_control_service_name);
    

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
            joystickpub2.publish(msg);
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
