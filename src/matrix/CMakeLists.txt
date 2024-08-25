add_executable(game_of_life game_of_life.cpp)
set_target_properties(game_of_life PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/matrix)

add_executable(rotate_image rotate_image.cpp)
set_target_properties(rotate_image PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/matrix)

add_executable(set_matrix_zeros set_matrix_zeros.cpp)
set_target_properties(set_matrix_zeros PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                  ${CMAKE_BINARY_DIR}/matrix)

add_executable(spiral_matrix spiral_matrix.cpp)
set_target_properties(spiral_matrix PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                               ${CMAKE_BINARY_DIR}/matrix)

add_executable(valid_sudoku valid_sudoku.cpp)
set_target_properties(valid_sudoku PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/matrix)
