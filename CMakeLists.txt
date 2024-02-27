cmake_minimum_required(VERSION 3.22)

project(DSA)

set(SOURCES src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC ${PROJECT_SOURCE_DIR}/include/data_structures
  PUBLIC ${PROJECT_SOURCE_DIR}/googletest/googletest/include)

enable_testing()
add_subdirectory(googletest)
add_executable(test_project test/main.cc test/data_structures/list.cc
                            test/data_structures/stack.cc)
target_link_libraries(test_project GTest::gtest_main)
target_include_directories(test_project
                           PUBLIC ${PROJECT_SOURCE_DIR}/include/data_structures)

include(GoogleTest)
gtest_discover_tests(test_project)
