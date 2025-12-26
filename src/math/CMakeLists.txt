add_executable(palindrome_number palindrome_number.cpp)
set_target_properties(palindrome_number PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/math)

add_executable(pow pow.cpp)
set_target_properties(pow PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/math)
