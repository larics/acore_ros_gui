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

    if(!ros::master::check())
        return false;
    ros::start();
    ros::Time::init();
    ros::NodeHandle nh;

    m_pThread->start();
    return true;
}

void RobotThread::run()
{
    ros::Rate loop_rate(100);
    QMutex * pMutex;
    while( ros::ok())
    {
        pMutex = new QMutex();

        //ros::LOGINFO("Running...")
        ros::spinOnce();
        loop_rate.sleep();
        delete pMutex;
    }
}