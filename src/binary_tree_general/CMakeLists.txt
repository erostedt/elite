add_executable(maximum_depth_of_binary_tree maximum_depth_of_binary_tree.cpp)
set_target_properties(maximum_depth_of_binary_tree PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(same_tree same_tree.cpp)
set_target_properties(same_tree PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/binary_tree_general)
