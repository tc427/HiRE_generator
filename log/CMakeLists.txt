include_directories(${opep_cpp_BINARY_DIR})

file(GLOB log_SOURCES *.cpp)
add_library(log ${log_SOURCES})
add_dependencies(log mainlib)

