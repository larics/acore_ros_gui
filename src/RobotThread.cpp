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
}

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
    pMutex->unlock();

    delete pMutex;
    Q_EMIT newEEPose(m_eeXPos, m_eeYPos, m_eeZPos, m_eeXOri, m_eeYOri, m_eeZOri, m_eeWOri);
}

void RobotThread::run()
{
    ros::Rate loop_rate(1);
    QMutex * pMutex;
    while( ros::ok())
    {
        pMutex = new QMutex();

        ros::spinOnce();
        ROS_INFO("[RobotThread] Running...");
        loop_rate.sleep();
        delete pMutex;
    }
}