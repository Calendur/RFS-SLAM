PROJECT(rfsslam)
SET(RFSSLAM_MAJOR_VERSION 1)
SET(RFSSLAM_MINOR_VERSION 1)
SET(RFSSLAM_PATCH_VERSION 0)
SET(RFSSLAM_VERSION ${RFSSLAM_MAJOR_VERSION}.${RFSSLAM_MINOR_VERSION}.${RFSSLAM_PATCH_VERSION})
message(STATUS "RFSSLAM Version ${RFSSLAM_VERSION}")

add_library(rfsslam)
target_include_directories(rfsslam PUBLIC ${EIGEN_INCLUDE_DIRS})
target_include_directories(rfsslam PUBLIC ../include)
target_sources(rfsslam PRIVATE
  ../include/TimeStamp.hpp
  ../include/Timer.hpp
  ../include/Frame.hpp
  ../include/ProcessModel_Odometry1D.hpp 
  ../include/ProcessModel_Odometry2D.hpp
  ../include/ProcessModel_Ackerman2D.hpp
  ../include/MeasurementModel_Rng1D.hpp
  ../include/MeasurementModel_RngBrg.hpp
  ../include/MeasurementModel_XY.hpp
  ../include/MeasurementModel_VictoriaPark.hpp
  ../include/KalmanFilter_RngBrg.hpp
  ../include/HungarianMethod.hpp
  ../include/MurtyAlgorithm.hpp
  ../include/BruteForceAssignment.hpp
  ../include/CostMatrix.hpp
  ../include/PermutationLexicographic.hpp
  ../include/MatrixPermanent.hpp
  ../include/RandomNumber.hpp
  ../include/misc/MemProfile.hpp
  TimeStamp.cpp 
  Timer.cpp
  Frame.cpp
  ProcessModel_Odometry1D.cpp 
  ProcessModel_Odometry2D.cpp
  ProcessModel_Ackerman2D.cpp
  MeasurementModel_Rng1D.cpp
  MeasurementModel_RngBrg.cpp
  MeasurementModel_XY.cpp
  MeasurementModel_VictoriaPark.cpp
  KalmanFilter_RngBrg.cpp
  HungarianMethod.cpp
  MurtyAlgorithm.cpp
  BruteForceAssignment.cpp
  CostMatrix.cpp
  PermutationLexicographic.cpp
  MatrixPermanent.cpp
  RandomNumber.cpp
  misc/memProfile.cpp
  )
target_link_libraries(rfsslam PUBLIC Boost::boost Boost::timer Boost::graph)

# Installation
#INSTALL(TARGETS rfsslam
#  DESTINATION /usr/local/lib/rfsslam
#  PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ
#  EXPORT rfsslam-targets)
#INSTALL(EXPORT rfsslam-targets DESTINATION /usr/local/lib/rfsslam)
#CONFIGURE_FILE(rfsslam-config.cmake.in "rfsslam-config.cmake" @ONLY)
#CONFIGURE_FILE(rfsslam-config-version.cmake.in "rfsslam-config-version.cmake" @ONLY)
#INSTALL(FILES ${CMAKE_BINARY_DIR}/rfsslam-config.cmake ${CMAKE_BINARY_DIR}/rfsslam-config-version.cmake
#  DESTINATION /usr/local/lib/rfsslam)
#
#FILE(GLOB headerFiles "include/*.hpp")
#INSTALL(FILES ${headerFiles}
#  DESTINATION /usr/local/include/rfsslam
#  PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ)
