cmake_minimum_required(VERSION 3.15)
project(MYARRAY)

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

include_directories(${PROJECT_SOURCE_DIR}/include)
file(GLOB MAIN_SRC ${PROJECT_SOURCE_DIR}/src/*.cpp)

add_executable(main ${MAIN_SRC})