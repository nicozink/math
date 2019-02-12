// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

// Project Includes
#include <math/Matrix.h>
#include <math/projection_matrix.h>
#include <unittest/test.h>

// Thirdparty Includes
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// Tests constructing a matrix.
TEST(MatrixGLM, ConstructMatrix)
{
	glm::mat4 glm_matrix = glm::perspective(glm::radians(45.f), 1.33f, 0.1f, 10.f);
	float* matrix_values = glm::value_ptr(glm_matrix);

	Mat4 matrix;
	ProjectionMatrix::CalculatePerspective(matrix, 1.33f, glm::radians(45.0), 0.1, 10.0);

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

	Mat4 matrix;
	matrix.Translate(1.0f, 2.0f, 3.0f);

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

	Mat4 matrix;
	matrix.Scale(2.0f);

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

	Mat4 matrix;
	matrix.RotateEuler(glm::radians(90.0f), 0.0f, 0.0f);

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - matrix.GetArray()[i]) < std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}

// Tests constructing a matrix.
TEST(MatrixGLM, Multiply)
{
	glm::mat4 glm_matrix1 = glm::mat4(1.0f);
	glm_matrix1 = glm::rotate(glm_matrix1, glm::radians(45.0f), glm::vec3(1.0f, 0.0f, 0.0f));

	glm::mat4 glm_matrix2 = glm::mat4(1.0f);
	glm_matrix2 = glm::rotate(glm_matrix2, glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	glm::mat4 glm_result = glm_matrix1 * glm_matrix2;

	float* matrix_values = glm::value_ptr(glm_result);

	Mat4 matrix1;
	matrix1.RotateEuler(glm::radians(45.0f), 0.0f, 0.0f);

	Mat4 matrix2;
	matrix2.RotateEuler(0.0f, glm::radians(45.0f), 0.0f);

	matrix1.RightMultiply(matrix2);

	for (int i = 0; i < 16; ++i)
	{
		ASSERT(fabsf(matrix_values[i] - matrix1.GetArray()[i]) <= std::numeric_limits<float>::epsilon()) << "An incorrect value was returned.";
	}
}
