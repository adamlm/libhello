cmake_minimum_required(VERSION 3.20 FATAL_ERROR)
project(libhello VERSION 0.1.0)

include(options.cmake)
include(dependencies.cmake)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set(CMAKE_EXPORT_COMPILE_COMMANDS ${libhello_EXPORT_COMPILE_COMMANDS})

add_subdirectory(src)

if(libhello_BUILD_TESTS)
  enable_testing()
  add_subdirectory(test)
endif()

if(libhello_BUILD_EXAMPLES)
  add_subdirectory(examples)
endif()

if(libhello_BUILD_DOCS)
  add_subdirectory(docs)
endif()

if(libhello_BUILD_PACKAGING)
  add_subdirectory(packaging)
endif()
