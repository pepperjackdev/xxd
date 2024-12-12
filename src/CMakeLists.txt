add_library(xxdlib xxdlib.c)

target_include_directories(xxdlib PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(xxd main.c)

target_link_libraries(xxd PRIVATE xxdlib)