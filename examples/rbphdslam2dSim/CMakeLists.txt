PROJECT(rbphdslam2dSim)

add_executable(rbphdslam2dSim rbphdslam2dSim.cpp)
target_link_libraries(rbphdslam2dSim PRIVATE rfsslam)
target_link_libraries(rbphdslam2dSim PRIVATE Boost::filesystem Boost::program_options)
