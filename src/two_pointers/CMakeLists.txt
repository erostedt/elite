add_executable(container_with_most_water container_with_most_water.cpp)
set_target_properties(
  container_with_most_water PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                       ${CMAKE_BINARY_DIR}/two_pointers)

add_executable(is_subsequence is_subsequence.cpp)
set_target_properties(
  is_subsequence PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                            ${CMAKE_BINARY_DIR}/two_pointers)

add_executable(three_sum three_sum.cpp)
set_target_properties(three_sum PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                           ${CMAKE_BINARY_DIR}/two_pointers)

add_executable(two_sum2 two_sum2.cpp)
set_target_properties(two_sum2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                          ${CMAKE_BINARY_DIR}/two_pointers)

add_executable(valid_palindrome valid_palindrome.cpp)
set_target_properties(
  valid_palindrome PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                              ${CMAKE_BINARY_DIR}/two_pointers)
