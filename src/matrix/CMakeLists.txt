add_executable(valid_sudoku valid_sudoku.cpp)

set_target_properties(valid_sudoku PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/matrix)
