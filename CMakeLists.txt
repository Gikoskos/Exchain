cmake_minimum_required(VERSION 3.1.3)
project(Exchain VERSION 0.1.0 LANGUAGES C CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")

include(AddSourcesToTarget)
include(CMakePrintHelpers)


add_executable(Exchain)

#################
# external deps
#################

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)
target_include_directories(Exchain PRIVATE external/glfw/include)
target_link_libraries(Exchain glfw)

# GLAD
target_include_directories(Exchain PRIVATE external/glad/include)
target_sources(Exchain PRIVATE external/glad/src/glad.c)

# KHR
target_include_directories(Exchain PRIVATE external/KHR/include)

##################
# project source
##################
add_subdirectory(include)
add_subdirectory(src)
target_include_directories(Exchain PRIVATE include)


####################
# compiler options
####################
set_target_properties(Exchain PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
