add_executable(valid_parentheses valid_parentheses.cpp)
set_target_properties(
  valid_parentheses PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                       ${CMAKE_BINARY_DIR}/stack)

