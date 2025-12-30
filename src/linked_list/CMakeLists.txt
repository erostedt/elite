add_executable(cycle cycle.cpp)
set_target_properties(cycle PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/linked_list)

add_executable(add_two_numbers add_two_numbers.cpp)
set_target_properties(add_two_numbers PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/linked_list)

