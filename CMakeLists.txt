cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "comparason")

project(${PROJECT_NAME} VERSION 0.1)

# add_executable(tests Tests/branched.cpp Tests/branchless.cpp)
set(SourceFiles Source/main.cpp Source/branched.h Source/branched.cpp Source/branchless.h Source/branched.cpp)
add_executable("${PROJECT_NAME}" ${SourceFiles})
target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_20)

# target_sources("${PROJECT_NAME}" PRIVATE ${SourceFiles})

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.1.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests Tests/branched.cpp Tests/branchless.cpp)
target_compile_features(tests PRIVATE cxx_std_20)

target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
include(${Catch2_SOURCE_DIR}/extras/Catch.cmake "${PROJECT_NAME}")

catch_discover_tests(tests)