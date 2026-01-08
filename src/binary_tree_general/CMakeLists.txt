add_executable(maximum_depth_of_binary_tree maximum_depth_of_binary_tree.cpp)
set_target_properties(
  maximum_depth_of_binary_tree
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(same_tree same_tree.cpp)
set_target_properties(
  same_tree PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                       ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(symmetric_tree symmetric_tree.cpp)
set_target_properties(
  symmetric_tree PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                            ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(invert_binary_tree invert_binary_tree.cpp)
set_target_properties(
  invert_binary_tree PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(flatten_binary_tree_to_linked_list
               flatten_binary_tree_to_linked_list.cpp)
set_target_properties(
  flatten_binary_tree_to_linked_list
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(construct_binary_tree_from_inorder_and_postorder_traversal
               construct_binary_tree_from_inorder_and_postorder_traversal.cpp)
set_target_properties(
  construct_binary_tree_from_inorder_and_postorder_traversal
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(construct_binary_tree_from_preorder_and_inorder_traversal
               construct_binary_tree_from_preorder_and_inorder_traversal.cpp)
set_target_properties(
  construct_binary_tree_from_preorder_and_inorder_traversal
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(path_sum path_sum.cpp)
set_target_properties(
  path_sum PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                      ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(sum_root_to_leaf_numbers sum_root_to_leaf_numbers.cpp)
set_target_properties(
  sum_root_to_leaf_numbers PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                      ${CMAKE_BINARY_DIR}/binary_tree_general)

add_executable(binary_tree_maximum_path_sum binary_tree_maximum_path_sum.cpp)
set_target_properties(
  binary_tree_maximum_path_sum
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/binary_tree_general)
