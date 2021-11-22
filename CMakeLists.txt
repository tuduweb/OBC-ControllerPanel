cmake_minimum_required(VERSION 3.14)

project(ControllerPanel CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

IF (APPLE)
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/usr/local/opt/qt5/lib/cmake")
ENDIF()


set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)


file(GLOB_RECURSE SOURCES  src/* )


set(CONTROLLERPANEL_SOURCES
    examples/basic/main.cpp
    ${SOURCES}
)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Widgets SerialPort Quick WebSockets Network NetLinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Widgets SerialPort Quick WebSockets Network LinguistTools REQUIRED)

add_library(obc_controlPanel_baselib STATIC
    ${SOURCES}
)

add_executable(ControllerPanel
    ${CONTROLLERPANEL_SOURCES}
)

# obc-foundation
include(./3rdparty/obc-foundation/OBCFoundation.cmake)

# public not private, so other exe can link them ?
target_link_libraries(obc_controlPanel_baselib
    PUBLIC Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::SerialPort
    Qt${QT_VERSION_MAJOR}::Quick
    Qt${QT_VERSION_MAJOR}::WebSockets
    Qt${QT_VERSION_MAJOR}::Network

    obc_fondation
)

### add extra qt library
target_link_libraries(ControllerPanel
    PRIVATE obc_controlPanel_baselib
)

add_subdirectory(./examples)
