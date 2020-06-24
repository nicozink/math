cmake_minimum_required(VERSION 3.0)

include(${LIBRARY_FOLDER}/build_tools/cmake/cmake_utils.cmake)

PROJECT(math VERSION 1.0.0)

enable_testing()

import_library(cpp_util)
import_library(reflection)
import_library(unittest)

set(SRC_MAIN
	${CMAKE_CURRENT_SOURCE_DIR}/src/camera.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/dimension.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/mat4.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/projection_matrix.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/transform.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/vec3.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/vec4.cpp)

set(SRC_INTERFACE
	${CMAKE_CURRENT_SOURCE_DIR}/include/math/camera.h
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
	${CMAKE_CURRENT_SOURCE_DIR}/test/test_matrix_glm.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/test/test_vector.cpp)

set(_src_root_path "${CMAKE_CURRENT_SOURCE_DIR}/")

foreach(_source IN ITEMS ${SRC_MAIN} ${SRC_INTERFACE} ${SRC_TEST})
	get_filename_component(_source_path "${_source}" PATH)
	file(RELATIVE_PATH _source_path_rel "${_src_root_path}" "${_source_path}")
	string(REPLACE "/" "\\" _group_path "${_source_path_rel}")
	source_group("${_group_path}" FILES "${_source}")
endforeach()

create_library(math library ${SRC_MAIN} ${SRC_INTERFACE})

target_include_directories(math
	PUBLIC
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
	PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_libraries(math cpp_util reflection)

# We actually do have a dependency on glm.
# There seems to be a vcpkg bug finding it
# for Emscripten - and things happen to
# compile without it.
#find_package(glm CONFIG REQUIRED)

create_library(math_tests tests ${SRC_TEST})

target_link_libraries(math_tests build_tools math unittest)

create_executable(math_test test ${SRC_TEST})

target_link_libraries(math_test build_tools math unittest)

if (${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
	add_test(NAME math_test COMMAND ${NODE_JS} "${CMAKE_CURRENT_BINARY_DIR}/math_test.js")
else ()
	add_test(NAME math_test COMMAND math_test)
endif ()