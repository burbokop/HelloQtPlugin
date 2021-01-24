cmake_minimum_required(VERSION 3.10)



# Remove when sharing with others.
list(APPEND CMAKE_PREFIX_PATH "/home/viktor/Qt/Tools/QtCreator/dev/lib/cmake/QtCreator")

project(Hello)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 20)



find_package(QtCreator COMPONENTS Core ProjectExplorer REQUIRED)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets QuickWidgets REQUIRED)
set(QtX Qt${QT_VERSION_MAJOR})

add_qtc_plugin(Hello
  PLUGIN_DEPENDS
    QtCreator::Core
    QtCreator::ProjectExplorer
  DEPENDS
    ${QtX}::Widgets
    ${QtX}::QuickWidgets
    QtCreator::ExtensionSystem
    QtCreator::Utils
  SOURCES
    .github/workflows/build_cmake.yml
    .github/workflows/README.md
    README.md
    resources.qrc
    src/hello.cpp
    src/hello.h
    src/hello_global.h
    src/helloconstants.h
    src/jprojproject.cpp
    src/jprojproject.h
    src/jprojprojectimporter.cpp
    src/jprojprojectimporter.h
    src/buildsystem.cpp
    src/buildsystem.h
    src/jprojfileparser.cpp
    src/jprojfileparser.h
    src/runconfiguration.cpp
    src/runconfiguration.h
)

target_link_libraries(Hello

    )
