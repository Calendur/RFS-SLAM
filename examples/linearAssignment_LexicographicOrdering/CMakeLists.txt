PROJECT(linearAssignment_LexicographicOrdering)

add_executable(${PROJECT_NAME} linearAssignment_LexicographicOrdering.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE rfsslam)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::boost)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/examples")
