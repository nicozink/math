cmake_minimum_required(VERSION 3.0)

PROJECT(input VERSION 1.0.0)

enable_testing()

if (EXISTS libraries/cpp_util/CMakeLists.txt)
	add_subdirectory(libraries/cpp_util)
endif()

set(SRC_MAIN
	${CMAKE_CURRENT_SOURCE_DIR}/src/dimension.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/mat4.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/projection_matrix.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/transform.cpp)

set(SRC_INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/dimension.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/mat4.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/matrix.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/projection_matrix.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/transform.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/vec3.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/vec4.h
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/vector.h)

set(SRC_TEST
	${CMAKE_CURRENT_SOURCE_DIR}/test/test_matrix.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/test_vector.cpp)

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}/")

foreach(_source IN ITEMS ${SRC_MAIN} ${SRC_INTERFACE} ${SRC_TEST})
	get_filename_component(_source_path "${_source}" PATH)
	file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
	string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
	source_group("${_group_path}" FILES "${_source}")
endforeach()

add_library(math ${SRC_MAIN} ${SRC_INTERFACE})

target_include_directories(math
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(math cpp_util)

add_library(math_tests ${SRC_TEST})
set_target_properties(math_tests PROPERTIES FOLDER "tests")

target_link_libraries(math_tests math unittest)

add_executable(math_test ${SRC_TEST})
set_target_properties(math_test PROPERTIES FOLDER "executable")

target_link_libraries(math_test math unittest)

add_test(NAME math_test
	COMMAND math_test)