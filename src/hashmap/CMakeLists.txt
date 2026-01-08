file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

foreach(source_file IN LISTS SOURCES)
  # Get filename without directory and extension
  get_filename_component(target_name ${source_file} NAME_WE)

  add_executable(${target_name} ${source_file})
  set_target_properties(${target_name} PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                  ${CMAKE_BINARY_DIR}/hashmap)
endforeach()
