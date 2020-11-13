cmake_minimum_required (VERSION 3.7)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall)
add_compile_options(-Werror)
add_compile_options(-O2)

include_directories(${CMAKE_CURRENT_LIST_DIR}/../vendor/onikiri2/lib)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../vendor/onikiri2/src)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../vendor/onikiri2/src/pch)

project (loader)

add_executable(
  loader
  src/main.cpp
  ../vendor/onikiri2/src/Emu/Utility/System/Loader/ELF32.cpp
  ../vendor/onikiri2/src/Emu/Utility/System/Loader/ELF64.cpp
  ../vendor/onikiri2/src/Emu/Utility/System/Loader/Elf32Reader.cpp
  ../vendor/onikiri2/src/Emu/Utility/System/Loader/Elf64Reader.cpp
)

target_link_libraries(
  loader
  "-lboost_system"
)