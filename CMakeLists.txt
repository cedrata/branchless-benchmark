cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME "BranchlessBenchmark")

project(${PROJECT_NAME} VERSION 0.1)
add_executable("${PROJECT_NAME}" Tests/branched.cpp Tests/branchless.cpp)
set(SourceFiles Source/main.cpp Source/branched.h Source/branched.cpp Source/branchless.h Source/branched.cpp)

target_sources("${PROJECT_NAME}" PRIVATE ${SourceFiles})

Include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_PROGRESS TRUE
    GIT_SHALLOW TRUE
    GIT_TAG v3.1.0)
FetchContent_MakeAvailable(Catch2) # find_package equivalent

add_executable(Tests Tests/branched.cpp Tests/branchless.cpp)
target_compile_features(Tests PRIVATE cxx_std_20)

target_include_directories(Tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/Source)