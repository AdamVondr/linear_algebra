cmake_minimum_required(VERSION 3.20)

project(Linear_Algebra)



# Library
add_library(linear_algebra STATIC)

target_sources( linear_algebra
    PRIVATE
        src/vector.c
    PRIVATE
        src/matrix.c
)

target_include_directories( linear_algebra
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Examples to compile
add_subdirectory(examples)