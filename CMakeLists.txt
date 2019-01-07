cmake_minimum_required(VERSION 3.1.3)
project(Exchain VERSION 0.1.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(AddSourcesToTarget)
include(CMakePrintHelpers)


add_executable(Exchain)

target_include_directories(Exchain PRIVATE include)

add_subdirectory(include)
add_subdirectory(src)


set_target_properties(Exchain PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
