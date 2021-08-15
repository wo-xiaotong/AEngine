cmake_minimum_required(VERSION 3.1)
set (CMAKE_C_STANDARD 11)
set (CMAKE_CXX_STANDARD 11)

project(AEngine)
set(AEngine_Build_Root ${PROJECT_SOURCE_DIR})

add_subdirectory(engine)  #子目录工程
add_subdirectory(client)  #子目录工程
add_subdirectory(test)  #子目录工程