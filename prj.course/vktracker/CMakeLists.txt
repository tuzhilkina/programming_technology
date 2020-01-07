cmake_minimum_required(VERSION 3.15)
project(vktracker LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Qt5_DIR "C:/Qt/5.12.6/msvc2017_64/lib/cmake/Qt5" CACHE PATH "Initial cahe" FORCE)

SET(CMAKE_INSTALL_PREFIX $<TARGET_FILE_DIR:${PROJECT_NAME}> CACHE PATH "Initial cahe" FORCE)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt5 REQUIRED COMPONENTS Network)
find_package(Qt5 REQUIRED COMPONENTS WebEngineWidgets)
find_package(Qt5 REQUIRED COMPONENTS Multimedia)

get_target_property(QtCore_location Qt5::Core LOCATION)

set(project_headers
vktracker.h
login.h
followed.h
vk.h
notification.h
)

set(project_sources
main.cpp
vktracker.cpp
login.cpp
followed.cpp
vk.cpp
notification.cpp
)

set(project_ui
vktracker.ui
login.ui
followed.ui
notification.ui
)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})

add_executable(${PROJECT_NAME} ${project_headers} ${project_sources}
${project_sources_moc} ${project_headers_wrapped})
add_executable(CMAKE_AUTORCC main.cpp)
target_link_libraries(${PROJECT_NAME}
PUBLIC
Qt5::Core
Qt5::Network
Qt5::WebEngineWidgets
Qt5::Widgets
Qt5::Multimedia
)