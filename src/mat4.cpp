// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <math/mat4.h>

// System Includes
#include <cmath>

//
// Reflection
//

#include <reflection/register_class.h>

namespace
{

}

REGISTER_CLASS(Mat4)
{
	register_constructor();
	register_method<float (Mat4::*)(int, int)>("Get", &Mat4::Get);
	register_method<void (Mat4::*)(int, int, float)>("Set", &Mat4::Set);
}

// Creates a new instance of the Matrix class.
Mat4::Mat4()
{

}

// Creates a new instance of the Matrix class.
// @param values The values.
Mat4::Mat4(float values[16])
: Matrix(values)
{

}

Mat4::Mat4(float identity_value)
	: Matrix({ identity_value, 0.0f, 0.0f, 0.0f,
		0.0f, identity_value, 0.0f, 0.0f,
		0.0f, 0.0f, identity_value, 0.0f,
		0.0f, 0.0f, 0.0f, identity_value, })
{

}

// Creates a new instance of the Matrix class.
// @param list The list of arguments.
Mat4::Mat4(std::initializer_list<float> list)
: Matrix(list)
{

}

// Destroys this instance of the Matrix class.
Mat4::~Mat4()
{

}

void Mat4::Identity(Mat4& matrix)
{
	matrix(0, 0) = 1.0f;
	matrix(0, 1) = 0.0f;
	matrix(0, 2) = 0.0f;
	matrix(0, 3) = 0.0f;

	matrix(1, 0) = 0.0f;
	matrix(1, 1) = 1.0f;
	matrix(1, 2) = 0.0f;
	matrix(1, 3) = 0.0f;

	matrix(2, 0) = 0.0f;
	matrix(2, 1) = 0.0f;
	matrix(2, 2) = 1.0f;
	matrix(2, 3) = 0.0f;

	matrix(3, 0) = 0.0f;
	matrix(3, 1) = 0.0f;
	matrix(3, 2) = 0.0f;
	matrix(3, 3) = 1.0f;
}

void Mat4::Rotate(Mat4& matrix, Vec3 vec, float delta)
{
	Mat4 rotate_matrix;

	float cos_d = cos(delta);
	float sin_d = sin(delta);

	float r_x = vec[0];
	float r_y = vec[1];
	float r_z = vec[2];

	rotate_matrix(0, 0) = cos_d + pow(r_x, 2.0f) * (1.0f - cos_d);
	rotate_matrix(0, 1) = r_y * vec[0] * (1.0f - cos_d) + r_z * sin_d;
	rotate_matrix(0, 2) = r_z * r_x * (1.0f - cos_d) - r_y * sin_d;
	rotate_matrix(0, 3) = 0;

	rotate_matrix(1, 0) = r_x * r_y * (1.0f - cos_d) - r_z * sin_d;
	rotate_matrix(1, 1) = cos_d + pow(r_y, 2.0f) * (1.0f - cos_d);
	rotate_matrix(1, 2) = r_z * r_y * (1.0f - cos_d) + r_x * sin_d;
	rotate_matrix(1, 3) = 0;

	rotate_matrix(2, 0) = r_x * r_z * (1.0f - cos_d) + r_y * sin_d;
	rotate_matrix(2, 1) = r_y * r_z * (1.0f - cos_d) - r_x * sin_d;
	rotate_matrix(2, 2) = cos_d + pow(r_z, 2.0f) * (1.0f - cos_d);
	rotate_matrix(2, 3) = 0;

	rotate_matrix(3, 0) = 0;
	rotate_matrix(3, 1) = 0;
	rotate_matrix(3, 2) = 0;
	rotate_matrix(3, 3) = 1;

	matrix.RightMultiply(rotate_matrix);
}

void Mat4::RotateEuler(Mat4& matrix, float x, float y, float z)
{
	RotateX(matrix, x);
	RotateY(matrix, y);
	RotateZ(matrix, z);
}

void Mat4::RotateX(Mat4& matrix, float delta)
{
	Rotate(matrix, Vec3(1.0f, 0.0f, 0.0f), delta);
}

void Mat4::RotateY(Mat4& matrix, float delta)
{
	Rotate(matrix, Vec3(0.0f, 1.0f, 0.0f), delta);
}

void Mat4::RotateZ(Mat4& matrix, float delta)
{
	Rotate(matrix, Vec3(0.0f, 0.0f, 1.0f), delta);
}

void Mat4::Scale(Mat4& matrix, float scale)
{
	Mat4 scale_matrix;
	Mat4::Identity(scale_matrix);

	scale_matrix(0, 0) = scale;
	scale_matrix(1, 1) = scale;
	scale_matrix(2, 2) = scale;

	matrix.RightMultiply(scale_matrix);
}

void Mat4::ScaleXYZ(Mat4& matrix, Vec3 vec)
{
	Mat4 scale_matrix;
	Mat4::Identity(scale_matrix);

	scale_matrix(0, 0) = vec[0];
	scale_matrix(1, 1) = vec[1];
	scale_matrix(2, 2) = vec[2];

	matrix.RightMultiply(scale_matrix);
}

void Mat4::Translate(Mat4& matrix, Vec3 vec)
{
	Mat4 translate_matrix;
	Mat4::Identity(translate_matrix);

	translate_matrix(3, 0) = vec[0];
	translate_matrix(3, 1) = vec[1];
	translate_matrix(3, 2) = vec[2];

	matrix.RightMultiply(translate_matrix);
}
