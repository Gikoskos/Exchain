cmake_minimum_required(VERSION 3.2)
project(Exchain VERSION 0.1.0 LANGUAGES CXX)

set(projectSources
    main.cpp
    randgen.cpp
    mchain.cpp
    tests.cpp
)

add_executable(Exchain
    ${projectSources}
)

set_target_properties(Exchain PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
