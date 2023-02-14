cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "comparason")
project(${PROJECT_NAME} VERSION 0.1)

set(SourceFiles Source/branched.h Source/branched.cpp Source/branchless.h)
add_library("${PROJECT_NAME}" STATIC ${SourceFiles})
target_compile_features("${PROJECT_NAME}" PRIVATE cxx_std_20)

add_executable(main Source/main.cpp)
target_link_libraries("${PROJECT_NAME}")
target_compile_features(main PRIVATE cxx_std_20)

# Include(FetchContent)

# FetchContent_Declare(
#   Catch2
#   GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#   GIT_TAG        v3.1.0
# )

# FetchContent_MakeAvailable(Catch2)

# add_executable(tests Tests/test.cpp)
# target_compile_features(tests PRIVATE cxx_std_20)

# target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source)
# target_link_libraries(tests PRIVATE Catch2::Catch2WithMain "MainLib")
# include(${Catch2_SOURCE_DIR}/extras/Catch.cmake "${PROJECT_NAME}")

# catch_discover_tests(tests)