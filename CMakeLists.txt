cmake_minimum_required(VERSION 3.0.0)
project(canopen-master VERSION 0.1.0 LANGUAGES C CXX)
# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(canopen-master main.cpp hid-interface/hid_dualshock.cpp)
target_include_directories(canopen-master PRIVATE hid-interface)
target_link_libraries(canopen-master hidapi-libusb)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
