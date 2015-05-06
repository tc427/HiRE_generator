include_directories(${opep_cpp_BINARY_DIR})

file(GLOB inout_SOURCES *.cpp)
add_library(inout ${inout_SOURCES})
add_dependencies(inout mainlib)
target_link_libraries(inout mainlib)

