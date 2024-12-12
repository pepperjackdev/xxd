cmake_minimum_required(VERSION 3.15)
project(xxd VERSION 1.0 LANGUAGES C)

# source
add_subdirectory(src)

# custom target to build and run the project
add_custom_target(run
    COMMAND xxd
    DEPENDS xxd
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Building and running xxd..."
)