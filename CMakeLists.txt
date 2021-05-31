cmake_minimum_required(VERSION 3.10)
project(composition-cpp)

# Executing CMakeLists.txt in subdirs
add_subdirectory(include)
add_subdirectory(src)

# Adding executable binary with sources and headers from subdirs
add_executable(composition_cpp ${SOURCES} ${HEADERS})
# Linking Math.h binary library (I don't know if it's necessary, but let it be :D)
target_link_libraries(composition_cpp m)
# Including headers dirs for #include <CMatrix.h> (not #include <../include/CMatrix.h>)
target_include_directories(composition_cpp PRIVATE include)