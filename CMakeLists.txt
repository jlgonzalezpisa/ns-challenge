#
# File: CMakeLists.txt
#
# Author: jose.pisa
# Date: Thu Jun 4 2020
#
CMAKE_MINIMUM_REQUIRED (VERSION 3.6)
PROJECT (challenge CXX C)

SET (CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
SET (PROJECT_VERSION "0.0.1")

# Get the target architecture platform.
SET (APP_NAME challenge)

SET (CMAKE_CXX_STANDARD 14)

SET (CMAKE_INSTALL_BINDIR  "${CMAKE_INSTALL_PREFIX}/bin")
SET (CMAKE_INSTALL_LIBDIR  "${CMAKE_INSTALL_PREFIX}/lib")
SET (CMAKE_INSTALL_MANDIR  "${CMAKE_INSTALL_PREFIX}/man")

# Print variables to stdout
MESSAGE (STATUS "################################################################")
MESSAGE (STATUS "Building challenge.")
MESSAGE (STATUS "################################################################")

FILE (GLOB_RECURSE SOURCE_FILES src/*.cpp  include/*.h)

INCLUDE_DIRECTORIES (SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES (SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add projects
ADD_EXECUTABLE (${APP_NAME} ${SOURCE_FILES} src/Adder.cpp include/Adder.h include/AddOverflowException.h src/LargestSumFinder.cpp include/LargestSumFinder.h)