PROJECT(analysis2dSim)

add_executable(analysis2dSim analysis2dSim.cpp)
target_link_libraries(analysis2dSim PRIVATE rfsslam)
target_link_libraries(analysis2dSim PRIVATE Boost::filesystem)
