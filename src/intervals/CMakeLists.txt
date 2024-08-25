add_executable(insert_interval insert_interval.cpp)
set_target_properties(insert_interval PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                 ${CMAKE_BINARY_DIR}/intervals)

add_executable(merge_intervals merge_intervals.cpp)
set_target_properties(merge_intervals PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                 ${CMAKE_BINARY_DIR}/intervals)

add_executable(minimum_number_of_arrows_to_burst_ballons
               minimum_number_of_arrows_to_burst_ballons.cpp)
set_target_properties(
  minimum_number_of_arrows_to_burst_ballons
  PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/intervals)

add_executable(summary_ranges summary_ranges.cpp)
set_target_properties(summary_ranges PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                ${CMAKE_BINARY_DIR}/intervals)
