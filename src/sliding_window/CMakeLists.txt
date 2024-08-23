add_executable(longest_substring_without_repeating_characters
               longest_substring_without_repeating_characters.cpp)

set_target_properties(
  longest_substring_without_repeating_characters
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/sliding_window)

add_executable(minimum_size_subarray_sum minimum_size_subarray_sum.cpp)

set_target_properties(
  minimum_size_subarray_sum PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                       ${CMAKE_BINARY_DIR}/sliding_window)

add_executable(minimum_window_substring minimum_window_substring.cpp)

set_target_properties(
  minimum_window_substring PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                      ${CMAKE_BINARY_DIR}/sliding_window)

add_executable(substring_with_concatenation_of_all_words
               substring_with_concatenation_of_all_words.cpp)

set_target_properties(
  substring_with_concatenation_of_all_words
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/sliding_window)
