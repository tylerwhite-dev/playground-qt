cmake_minimum_required(VERSION 3.16)

project(playground-qt VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.8)

qt_add_executable(appplayground-qt main.cpp)

qt_add_qml_module(appplayground-qt
    URI playground-qt
    VERSION 1.0
    QML_FILES
        Main.qml

    SOURCES
    mainviewmodel.h mainviewmodel.cpp
)

target_link_libraries(appplayground-qt
    PRIVATE
    Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appplayground-qt
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
