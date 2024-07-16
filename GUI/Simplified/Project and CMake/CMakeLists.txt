cmake_minimum_required(VERSION 3.16)

project(TCP VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.2 COMPONENTS Quick REQUIRED)

qt_add_executable(appTCP
    main.cpp
)

qt_add_qml_module(appTCP
    URI TCP
    VERSION 1.0
    QML_FILES main.qml
    SOURCES CommunicationController.h CommunicationController.cpp
    RESOURCES Images/bedroom.jpg
    RESOURCES Images/air-conditioner.png
    RESOURCES Images/brightness.png Images/fan.png
    RESOURCES Images/door-bell.png
    RESOURCES Images/gate.png
    RESOURCES Images/spotify.png
    RESOURCES Images/backward.png Images/forward.png Images/pause.png Images/play.png
    RESOURCES Images/minus.png Images/plus.png
    RESOURCES Images/0.png Images/1.png Images/2.png Images/3.png
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appTCP PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appTCP
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appTCP
    PRIVATE Qt6::Quick)

include(GNUInstallDirs)
install(TARGETS appTCP
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
