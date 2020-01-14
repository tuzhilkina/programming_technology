cmake_minimum_required(VERSION 3.15)
project(vktracker LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET(CMAKE_INSTALL_PREFIX $<TARGET_FILE_DIR:${PROJECT_NAME}> CACHE PATH "Initial cahe" FORCE)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets)
find_package(Qt5 REQUIRED COMPONENTS QuickWidgets)
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

set(project_qrc
src.qrc
)

qt5_wrap_ui(project_headers_wrapped ${project_ui})
qt5_wrap_cpp(project_sources_moc ${project_headers})
qt5_add_resources(project_resources ${project_qrc})

add_executable(${PROJECT_NAME}
${project_headers}
${project_sources}
${project_sources_moc}
${project_headers_wrapped}
${project_resources})

target_link_libraries(${PROJECT_NAME}
PUBLIC
Qt5::Core
Qt5::Network
Qt5::WebEngineWidgets
Qt5::Widgets
Qt5::Multimedia
)

install(FILES $<TARGET_FILE:Qt5::Core> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Gui> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Multimedia> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Network> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Positioning> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::PrintSupport> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Qml> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Quick> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::QuickWidgets> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::WebChannel> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::WebEngineCore> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::WebEngineWidgets> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)
install(FILES $<TARGET_FILE:Qt5::Widgets> DESTINATION $<TARGET_FILE_DIR:${PROJECT_NAME}>)

