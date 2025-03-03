cmake_minimum_required(VERSION 3.15.0)
project(workermanager)
 
file(GLOB ALL_SOURCES "./source/*.cpp" "./source/*.h")
#aux_source_directory("./source" ALL_SOURCES)
add_executable(${PROJECT_NAME} ${ALL_SOURCES})