include_directories(${opep_cpp_BINARY_DIR})

file(GLOB entities_SOURCES *.cpp)
add_library(entities ${entities_SOURCES})
add_dependencies(entities mainlib)

