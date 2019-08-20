// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

// Project Includes
#include <math/camera.h>
#include <math/Matrix.h>
#include <math/projection_matrix.h>
#include <math/Transform.h>
#include <unittest/test.h>

// Thirdparty Includes
#pragma warning(push, 0)
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#pragma warning(pop)

// Tests constructing a matrix.
TEST(MatrixGLM, ConstructPerspective)
{
	glm::mat4 glm_matrix = glm::perspective(glm::radians(45.f), 1.33f, 0.1f, 10.f);
	float* matrix_values = glm::value_ptr(glm_matrix);

	Mat4 matrix;
	ProjectionMatrix::CalculatePerspective(matrix, 1.33f, (float)glm::radians(45.0), 0.1f, 10.0f);

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - matrix.GetArray()[i]) <= std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, ConstructOrthographic)
{
	glm::mat4 glm_matrix = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
	float* matrix_values = glm::value_ptr(glm_matrix);

	Mat4 matrix;
	ProjectionMatrix::CalculateOrthographic(matrix, 800.0f, 600.0f);

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - matrix.GetArray()[i]) <= std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, ConstructTranslate)
{
	glm::mat4 glm_matrix = glm::mat4(1.0f);
	glm_matrix = glm::translate(glm_matrix, glm::vec3(1.0f, 2.0f, 3.0f));
	float* matrix_values = glm::value_ptr(glm_matrix);

	Mat4 matrix(1.0f);
	Mat4::Translate(matrix, Vec3(1.0f, 2.0f, 3.0f));

	for (int i = 0; i < 16; ++i)
	{
		ASSERT_EQ(matrix_values[i], matrix.GetArray()[i]) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, ConstructScale)
{
	glm::mat4 glm_matrix = glm::mat4(1.0f);
	glm_matrix = glm::scale(glm_matrix, glm::vec3(2.0f, 2.0f, 2.0f));
	float* matrix_values = glm::value_ptr(glm_matrix);

	Mat4 matrix(1.0f);
	Mat4::Scale(matrix, 2.0f);

	for (int i = 0; i < 16; ++i)
	{
		ASSERT_EQ(matrix_values[i], matrix.GetArray()[i]) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, ConstructRotate)
{
	glm::mat4 glm_matrix = glm::mat4(1.0f);
	glm_matrix = glm::rotate(glm_matrix, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	float* matrix_values = glm::value_ptr(glm_matrix);

	Mat4 matrix(1.0f);
	Mat4::RotateEuler(matrix, glm::radians(90.0f), 0.0f, 0.0f);

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - matrix.GetArray()[i]) < std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, MultiplyLeft)
{
	glm::mat4 glm_matrix1 = glm::mat4(1.0f);
	glm_matrix1 = glm::rotate(glm_matrix1, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 glm_matrix2 = glm::mat4(1.0f);
	glm_matrix2 = glm::rotate(glm_matrix2, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 glm_result = glm_matrix2 * glm_matrix1;

	float* matrix_values = glm::value_ptr(glm_result);

	Mat4 matrix1(1.0f);
	Mat4::RotateEuler(matrix1, glm::radians(45.0f), 0.0f, 0.0f);

	Mat4 matrix2(1.0f);
	Mat4::RotateEuler(matrix2, 0.0f, glm::radians(45.0f), 0.0f);

	matrix1.LeftMultiply(matrix2);

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - matrix1.GetArray()[i]) <= std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, MultiplyRight)
{
	glm::mat4 glm_matrix1 = glm::mat4(1.0f);
	glm_matrix1 = glm::rotate(glm_matrix1, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 glm_matrix2 = glm::mat4(1.0f);
	glm_matrix2 = glm::rotate(glm_matrix2, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 glm_result = glm_matrix1 * glm_matrix2;

	float* matrix_values = glm::value_ptr(glm_result);

	Mat4 matrix1(1.0f);
	Mat4::RotateEuler(matrix1, glm::radians(45.0f), 0.0f, 0.0f);

	Mat4 matrix2(1.0f);
	Mat4::RotateEuler(matrix2, 0.0f, glm::radians(45.0f), 0.0f);

	matrix1.RightMultiply(matrix2);

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - matrix1.GetArray()[i]) <= std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, Transform)
{
	glm::mat4 translate_matrix = glm::mat4(1.0f);
	translate_matrix = glm::translate(translate_matrix, glm::vec3(3.0f, 2.0f, 1.0f));

	glm::mat4 scale_matrix = glm::mat4(1.0f);
	scale_matrix = glm::scale(scale_matrix, glm::vec3(1.0f, 2.0f, 3.0f));

	glm::mat4 rotate_matrix = glm::mat4(1.0f);
	rotate_matrix = glm::rotate(rotate_matrix, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 glm_result = translate_matrix * rotate_matrix * scale_matrix;

	float* matrix_values = glm::value_ptr(glm_result);

	Transform transform;
	transform.RotateEuler(glm::radians(45.0f), 0.0f, 0.0f);
	transform.ScaleXYZ(1.0f, 2.0f, 3.0f);
	transform.Translate(3.0f, 2.0f, 1.0f);
	transform.Calculate();

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - transform.GetTransform().GetArray()[i]) <= std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, Camera)
{
	glm::vec3 eye = glm::vec3(0.1f, 0.5f, 0.3f);
	glm::vec3 center = glm::vec3(0.3f, 0.2f, 0.1f);
	glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 glm_camera = glm::lookAt(eye, center, up);
	
	float* matrix_values = glm::value_ptr(glm_camera);

	Camera camera;
	camera.set_position(Vec3(0.1f, 0.5f, 0.3f));
	camera.set_direction(Vec3(0.2f, -0.3f, -0.2f));
	camera.set_world_up(Vec3(0.0f, 1.0f, 0.0f));
	camera.calculate();

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - camera.get_matrix().GetArray()[i]) <= std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}
