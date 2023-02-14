cmake_minimum_required(VERSION 3.0)
project(bless LANGUAGES CXX)


add_library(comparason INTERFACE)
target_sources(comparason INTERFACE
    FILE_SET HEADERS
    BASE_DIRS ${PROJECT_SOURCE_DIR}/src
    FILES src/main.cpp
)
add_subdirectory("src/comparason")

add_executable(main)
target_sources(main PRIVATE "src/main.cpp")
target_link_libraries(main PRIVATE comparason)
target_compile_features(main PRIVATE cxx_std_20)

install(TARGETS comparason FILE_SET HEADERS)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.1.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests)
target_sources(tests PRIVATE "tests/test.cpp")
target_compile_features(tests PRIVATE cxx_std_20)

# target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain comparason)
include(${Catch2_SOURCE_DIR}/extras/Catch.cmake bless)

catch_discover_tests(tests)