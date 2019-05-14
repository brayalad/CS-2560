cmake_minimum_required(VERSION 3.14)
project(SpaceRace)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # static library
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib) # dynamic library
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin) # executables
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/modules" ${CMAKE_MODULE_PATH})


set(SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/SFML-2.5.1/lib/cmake/SFML")

#add_subdirectory(lib/SFML/SFML-2.5.1)
#add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/SFML-2.5.1)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/SFML-2.5.1/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib/SFML/SFML-2.5.1/lib)
#include_directories(lib/SFML)


#Include where to find headers
include_directories(./src)
include_directories(./src/headers)

# Do a GLOB search, and add them to executable
set(EXECUTABLE_NAME "SPACE_RACE")
file(GLOB SRC_FILES
        "src/headers/*.h"
        "src/*.cpp"
        )

find_package(SFML 2.5 COMPONENTS graphics audio network window system REQUIRED)

add_executable(${EXECUTABLE_NAME} ${SRC_FILES})

target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-network sfml-audio sfml-window sfml-system)
