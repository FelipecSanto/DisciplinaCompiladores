project(miniC-llvm)

cmake_minimum_required(VERSION 3.10)

set(CMAKE_C_STANDARD 11)

include_directories(src/include)

file(GLOB_RECURSE SOURCES
    src/*.c
    src/parser/*.c
    src/llvm/*.c
    src/utils/*.c
)

add_executable(miniC-llvm ${SOURCES})

find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

set(LLVM_LINK_COMPONENTS
    core
    irreader
    analysis
    executionengine
    native
)

llvm_map_components_to_libnames(llvm_libs ${LLVM_LINK_COMPONENTS})

target_link_libraries(miniC-llvm ${llvm_libs})