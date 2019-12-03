cmake_minimum_required(VERSION 3.15)
project(vktracker LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets Sql)

set(project_headers
mainwindow.h)

set(project_sources
main.cpp
mainwindow.cpp)

set(project_ui
mainwindow.ui)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})

add_executable(${PROJECT_NAME} ${project_headers} ${project_sources}
${project_sources_moc} ${project_headers_wrapped})
add_executable(CMAKE_AUTORCC main.cpp)
target_link_libraries(${PROJECT_NAME}
PUBLIC
Qt5::Core
Qt5::Widgets)