include_directories(${opep_cpp_BINARY_DIR})

file(GLOB param_SOURCES *.cpp)
add_library(param ${param_SOURCES})
add_dependencies(param mainlib)

