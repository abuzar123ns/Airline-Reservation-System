cmake_minimum_required(VERSION 3.16)

project(uni6 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        welcomewindow.cpp
        welcomewindow.h
        welcomewindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(uni6
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        res.qrc
        loginwindow.h loginwindow.cpp loginwindow.ui
        mainscreen.h mainscreen.cpp mainscreen.ui
        bookflightwindow.h bookflightwindow.cpp bookflightwindow.ui
        flightdetailwindow.h flightdetailwindow.cpp flightdetailwindow.ui
        lodgecomplaintwindow.h lodgecomplaintwindow.cpp lodgecomplaintwindow.ui
        bill.h bill.cpp bill.ui
        adminlogin.h adminlogin.cpp adminlogin.ui
        adminportal.h adminportal.cpp adminportal.ui
        viewcomplaintswindow.h viewcomplaintswindow.cpp viewcomplaintswindow.ui
        viewflightdetail.h viewflightdetail.cpp viewflightdetail.ui
        updateticket.h updateticket.cpp updateticket.ui

    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET uni6 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(uni6 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(uni6
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(uni6 PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.uni6)
endif()
set_target_properties(uni6 PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS uni6
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(uni6)
endif()
