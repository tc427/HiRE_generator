include_directories(${opep_cpp_BINARY_DIR})

file(GLOB geometry_SOURCES *.cpp)
add_library(geometry ${geometry_SOURCES})
add_dependencies(geometry mainlib)
add_dependencies(geometry entities)

