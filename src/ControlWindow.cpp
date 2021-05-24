#include "ControlWindow.h"
#include "ui_controlwindow.h"

namespace server{
    ControlWindow::ControlWindow(int argc, char** argv, QWidget *parent)
        :QWidget(parent),
        ui(new Ui::Widget),
        m_RobotThread(argc, argv)
    {
        // SetupUI


        show();
        setWindowTitle(tr("ControlWindow"));

        // TODO: Add signal to connect robot thread with cb method
        m_RobotThread.init();

    }
}