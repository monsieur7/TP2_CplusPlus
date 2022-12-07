cmake_minimum_required(VERSION 3.0.0)
project(ENIGMA VERSION 0.1.0)

include(CTest)
enable_testing()
set(SOURCES main.cpp Encrypt.cpp Enigma.cpp)
add_executable(ENIGMA ${SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
