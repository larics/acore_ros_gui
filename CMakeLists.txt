cmake_minimum_required(VERSION 2.8.9)
project(acore_ros_gui)
find_package(catkin REQUIRED COMPONENTS roscpp)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Core REQUIRED)

catkin_package(
        CATKIN_DEPENDS roscpp geometry_msgs
        DEPENDS system-lib
)

#qt5_add_resources(QT_RESOURCES_CPP qt_resources/arrows.qrc)
qt5_wrap_cpp(QT_MOC_HPP src/ControlWindow.h
        src/RobotThread.h)

include_directories(src ${catkin_INCLUDE_DIRS})
include_directories(${Qt5Widgets_INCLUDE_DIRS})

add_executable(acore_gui_ros_ctl src/ControlWindow.cpp
        src/RobotThread.cpp
        src/main.cpp
        ${QT_MOC_HPP})

target_link_libraries(acore_gui_ros_ctl ${QT_LIBRARIES}
        ${catkin_LIBRARIES} Qt5::Widgets)

install(TARGETS acore_gui_ros_ctl
        RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
        )