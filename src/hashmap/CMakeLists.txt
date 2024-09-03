add_executable(contains_duplicate2 contains_duplicate2.cpp)
set_target_properties(
  contains_duplicate2 PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                 ${CMAKE_BINARY_DIR}/hashmap)

add_executable(group_anagrams group_anagrams.cpp)
set_target_properties(group_anagrams PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                ${CMAKE_BINARY_DIR}/hashmap)

add_executable(happy_number happy_number.cpp)
set_target_properties(happy_number PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/hashmap)

add_executable(isomorphic_strings isomorphic_strings.cpp)
set_target_properties(isomorphic_strings PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                    ${CMAKE_BINARY_DIR}/hashmap)

add_executable(longest_consecutive_sequence longest_consecutive_sequence.cpp)
set_target_properties(
  longest_consecutive_sequence PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                          ${CMAKE_BINARY_DIR}/hashmap)

add_executable(ransom_note ransom_note.cpp)
set_target_properties(ransom_note PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                             ${CMAKE_BINARY_DIR}/hashmap)

add_executable(two_sum two_sum.cpp)
set_target_properties(two_sum PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                             ${CMAKE_BINARY_DIR}/hashmap)

add_executable(valid_anagram valid_anagram.cpp)
set_target_properties(valid_anagram PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                               ${CMAKE_BINARY_DIR}/hashmap)

add_executable(word_pattern word_pattern.cpp)
set_target_properties(word_pattern PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                              ${CMAKE_BINARY_DIR}/hashmap)
