cmake_minimum_required(VERSION 3.12)
project(myproject)
set(CMAKE_CXX_STANDARD 14)
set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ../bin )
set (Boost_USE_STATIC_LIBS ON)
set (Boost_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)
FIND_PACKAGE( Boost 1.68 COMPONENTS serialization REQUIRED)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
link_directories(../3thparty)
add_executable(myproject source/main.cpp source/Package/Package.cpp source/Package/Package.h source/Package/PackageController.cpp source/Package/PackageController.h)
TARGET_LINK_LIBRARIES( myproject LINK_PUBLIC ${Boost_LIBRARIES} )