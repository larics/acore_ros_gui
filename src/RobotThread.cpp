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
    state_listener = nh.subscribe("/lwa4p/joint_states", 10, &RobotThread::jointStates, this);

    positioner1 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_1_position_controller/command", 100);
    positioner2 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_2_position_controller/command", 100);
    positioner3 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_3_position_controller/command", 100);
    positioner4 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_4_position_controller/command", 100);
    positioner5 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_5_position_controller/command", 100);
    positioner6 = nh.advertise<std_msgs::Float64>("/lwa4p/joint_6_position_controller/command", 100);

    EEpublisher = nh.advertise<geometry_msgs::Pose>("/control_arm_node/arm/command/pose", 100);

    

    startPositionControllerClient = nh.serviceClient<std_srvs::Trigger>("/control_arm_node/controllers/start_position_controllers");
    startPositionControllerClient1 = nh.serviceClient<std_srvs::Trigger>("/control_arm_node/controllers/start_joint_trajectory_controller");
    startPositionControllerClient2 = nh.serviceClient<std_srvs::Trigger>("/control_arm_node/controllers/start_joint_group_position_controller");
    

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
    QMutex * pMutex;
    while( ros::ok())
    {
        pMutex = new QMutex();

        // std_msgs::Float64 msg1;
        geometry_msgs::Pose EEmsg;

        pMutex->lock();

        // if(manualInfo){
        //     msg1.data = newdata;
        // }else{
        //     msg1.data = data;
        // }

        EEmsg.position.x = positionx;
        EEmsg.position.y = positiony;
        EEmsg.position.z = positionz;
        EEmsg.orientation.x = orientationx;
        EEmsg.orientation.y = orientationy;
        EEmsg.orientation.z = orientationz;
        EEmsg.orientation.w = orientationw;

        pMutex->unlock();

        EEpublisher.publish(EEmsg);
        
        ros::spinOnce();
        ROS_INFO("[RobotThread] Running...");
        loop_rate.sleep();
        delete pMutex;
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
    std_msgs::Float64 msg1;

    pMutex->lock();
    data = x;
    msg1.data = data;
    positioner1.publish(msg1);
    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition2(double x){
    QMutex * pMutex = new QMutex();
    std_msgs::Float64 msg2;

    pMutex->lock();
    data = x;
    msg2.data = data;
    positioner2.publish(msg2);
    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition3(double x){
    QMutex * pMutex = new QMutex();
    std_msgs::Float64 msg3;

    pMutex->lock();
    data = x;
    msg3.data = data;
    positioner3.publish(msg3);
    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition4(double x){
    QMutex * pMutex = new QMutex();
    std_msgs::Float64 msg4;

    pMutex->lock();
    data = x;
    msg4.data = data;
    positioner4.publish(msg4);
    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition5(double x){
    QMutex * pMutex = new QMutex();
    std_msgs::Float64 msg5;

    pMutex->lock();
    data = x;
    msg5.data = data;
    positioner5.publish(msg5);
    pMutex->unlock();

    delete pMutex;
}

void RobotThread::setPosition6(double x){
    QMutex * pMutex = new QMutex();
    std_msgs::Float64 msg6;

    pMutex->lock();
    data = x;
    msg6.data = data;
    positioner6.publish(msg6);
    pMutex->unlock();

    delete pMutex;
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
    startPositionControllerClient.call(srv);
}

void RobotThread::setToolCtrl(){
    std_srvs::Trigger srv;
    startPositionControllerClient1.call(srv);
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
