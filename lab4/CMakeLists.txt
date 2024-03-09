cmake_minimum_required(VERSION 3.10)
project(lab_04)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(GTest REQUIRED)
include_directories(${INCLUDE_DIR})

add_executable(main main.cpp ${INCLUDE_DIR})

enable_testing()

add_executable(tests test1.cpp ${INCLUDE_DIR})
target_link_libraries(tests ${GTEST_LIBRARIES} -lpthread)

add_test(NAME BASIC COMMAND tests)
