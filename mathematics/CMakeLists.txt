include_directories(${opep_cpp_BINARY_DIR})

file(GLOB mathematics_SOURCES *.cpp)
add_library(mathematics ${mathematics_SOURCES})
add_dependencies(mathematics mainlib)

