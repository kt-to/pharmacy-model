cmake_minimum_required(VERSION 3.25)
project(pharmacy_model)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

set(CMAKE_CXX_STANDARD 20)

add_executable(pharmacy_model
        main.cpp
        mainwindow.h
        modeling.h
        Animation.h
        person.h back.h ill.cpp medicament.h person.cpp back.cpp notification.h medicament.cpp notification.cpp
        notification_list.h
        modeling.cpp)
target_link_libraries(pharmacy_model
        Qt::Core
        Qt::Gui
        Qt::Widgets
)
