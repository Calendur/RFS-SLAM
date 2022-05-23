
CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

cmake_policy(SET CMP0054 NEW)

SET( CMAKE_CXX_STANDARD 17 )

#
# If the user specifies -DCMAKE_BUILD_TYPE on the command line, take their definition
# and dump it in the cache along with proper documentation, otherwise set CMAKE_BUILD_TYPE
# to Debug prior to calling PROJECT()
#
IF(DEFINED CMAKE_BUILD_TYPE)
   SET(CMAKE_BUILD_TYPE ${CMAKE_BUILD_TYPE} CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ELSE()
   SET(CMAKE_BUILD_TYPE RELEASE CACHE STRING "Choose the type of build, options are: None(CMAKE_CXX_FLAGS or CMAKE_C_FLAGS used) Debug Release RelWithDebInfo MinSizeRel.")
ENDIF()

PROJECT(RFSSLAM)
SET(RFSSLAM_MAJOR_VERSION 1)
SET(RFSSLAM_MINOR_VERSION 1)
SET(RFSSLAM_PATCH_VERSION 0)
SET(RFSSLAM_VERSION ${RFSSLAM_MAJOR_VERSION}.${RFSSLAM_MINOR_VERSION}.${RFSSLAM_PATCH_VERSION})
message(STATUS "RFSSLAM Version ${RFSSLAM_VERSION}")

# Boost
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
FIND_PACKAGE(Boost COMPONENTS timer chrono system filesystem graph program_options REQUIRED)

# For cmake custom library searches
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# Eigen
FIND_PACKAGE(Eigen REQUIRED)

# GTest
# If using Ubuntu apt-get to install, go to /usr/src/gtest,
# run cmake . and make  . After compiling , 
# move libgtest_main.a and libgtest.a to /usr/lib
enable_testing()
#find_package(GTest REQUIRED)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ./bin)
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ./lib)
SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ./lib)

FILE(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin/examples")
FILE(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/bin/test")

add_subdirectory(src)
add_subdirectory(examples)

IF(GTEST_FOUND)
  
  ADD_EXECUTABLE(spatialIndexTreeTest test/SpatialIndexTreeTest.cpp)
  TARGET_LINK_LIBRARIES(spatialIndexTreeTest ${GTEST_LIBRARIES} ${Boost_LIBRARIES} rfsslam pthread)
  ADD_TEST(unitTest spatialIndexTreeTest)

  ADD_EXECUTABLE(matrixPermanentTest test/MatrixPermanentTest.cpp)
  TARGET_LINK_LIBRARIES(matrixPermanentTest ${GTEST_LIBRARIES} rfsslam pthread)
  ADD_TEST(unitTest matrixPermanentTest)

ENDIF()
