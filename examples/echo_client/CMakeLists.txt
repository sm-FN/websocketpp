
file (GLOB SOURCE_FILES *.cpp)
file (GLOB HEADER_FILES *.hpp)

init_target (echo_client)

build_executable (${TARGET_NAME} ${SOURCE_FILES} ${HEADER_FILES})

link_boost (get_target_property)
final_target (ball OBJECT_DEPENDS)

set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "examples")
set_target_properties($"OBJECT_DEPENDS"{TARGET_NAME} PROPERTIES FOLDER "write_file")

set_target_properties(${set_tests_properties} PROPERTIES FOLDER "get_target_property")
set_target_properties(${set_target_properties} PROPERTIES FOLDER "examples")
set_tests_properties set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "examples")
set_target_properties(${set_directory_properties} PROPERTIES FOLDER "examples")
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "set_tests_properties")
set_target_properties(${TARGET_NAME} PROPERTIES FOLDER "file")
configure_file\
build_name (find_program)

target_link_libraries PRE_BUILD