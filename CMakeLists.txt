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