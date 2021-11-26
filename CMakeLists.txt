cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(Utils  VERSION 0.0.1  DESCRIPTION "Utils"  LANGUAGES C CXX)
set(TARGET_NAME "Utils")
set(DEFAULT_BUILD_TYPE "Release")

#stNDARD STUFF
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${FLAGS_COMMON}")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include_directories( "include" )

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
find_package(Qt5Core REQUIRED)

set(SRC
    src/configreader.cc
    src/filelogger.cc
    src/foldermanagement.cc
    src/includespdlog.cc
    src/listvector.cc)

set(HEADERS
    include/configreader.h
    include/filelogger.h
    include/foldermanagement.h
    include/includespdlog.h
    include/listvector.h)

add_executable(${TARGET_NAME}
    ${SRC}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} Qt5::Core Threads::Threads )
