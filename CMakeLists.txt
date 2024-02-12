cmake_minimum_required(VERSION 3.0.0)
project(canopen-master VERSION 0.1.0 LANGUAGES C CXX)
# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(CLI11 CONFIG REQUIRED)
find_package(Protobuf REQUIRED)
find_package(eCAL REQUIRED)

#set(dualshock_proto
#    ${CMAKE_CURRENT_SOURCE_DIR}/protobuf/dualshock.proto  
#)

#PROTOBUF_TARGET_CPP(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/protobuf ${dualshock_proto})


add_executable(canopen-master main.cpp hid-interface/hid_dualshock.cpp)
target_include_directories(canopen-master PRIVATE hid-interface)
target_link_libraries(canopen-master 
	hidapi-libusb
	eCAL::core
	protobuf::libprotobuf
	)

install(TARGETS canopen-master DESTINATION bin)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
