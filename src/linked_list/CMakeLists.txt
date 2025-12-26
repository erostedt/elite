add_executable(cycle cycle.cpp)
set_target_properties(cycle PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/linked_list)

