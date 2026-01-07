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
