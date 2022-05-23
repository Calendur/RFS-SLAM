PROJECT(fastslam2dSim)

add_executable(fastslam2dSim fastslam2dSim.cpp)
target_link_libraries(fastslam2dSim PRIVATE rfsslam)
target_link_libraries(fastslam2dSim PRIVATE Boost::filesystem Boost::program_options)
