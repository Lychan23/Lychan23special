cmake_minimum_required(VERSION 3.21)
project(DelayVST VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src
)

add_executable(delayvst WIN32 src/main.cpp src/BaseWindow.cpp src/MyWindow.cpp)

find_package(fmt REQUIRED)
find_package(range-v3 REQUIRED)
find_package(cxxopts REQUIRED)
find_package(Catch2 REQUIRED)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
