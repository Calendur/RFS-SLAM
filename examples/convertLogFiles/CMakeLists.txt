PROJECT(convertLogFiles)

add_executable(convertLogFiles convertLogFiles.cpp)
target_link_libraries(convertLogFiles PRIVATE Boost::filesystem)
