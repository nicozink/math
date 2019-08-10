// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <math/projection_matrix.h>

// Library Includes
#include <reflection/register_class.h>

REGISTER_CLASS(ProjectionMatrix)
{
	register_constructor();
	register_static_method("CalculateOrthographic", &ProjectionMatrix::CalculateOrthographic);
	register_static_method("CalculatePerspective", &ProjectionMatrix::CalculatePerspective);
}

void ProjectionMatrix::CalculateOrthographic(Mat4& matrix, float width, float height)
{
    const float n = -1.0f;
	const float f = 1.0f;

	const float l = 0.0f;
	const float r = width;

	const float b = 0.0f;
	const float t = height;
	
	matrix(0, 0) = 2.0f / (r - l);
	matrix(0, 1) = 0.0f;
	matrix(0, 2) = 0.0f;
	matrix(0, 3) = 0.0f;

	matrix(1, 0) = 0.0f;
	matrix(1, 1) = 2.0f / (t - b);
	matrix(1, 2) = 0.0f;
	matrix(1, 3) = 0.0f;

	matrix(2, 0) = 0.0f;
	matrix(2, 1) = 0.0f;
	matrix(2, 2) = -2.0f / (f - n);
	matrix(2, 3) = 0.0f;

	matrix(3, 0) = -(r + l) / (r - l);
	matrix(3, 1) = -(t + b) / (t - b);
	matrix(3, 2) = -(f + n) / (f - n);
	matrix(3, 3) = 1.0f;
}

void ProjectionMatrix::CalculatePerspective(Mat4& matrix, float aspect, float fov, float near, float far)
{
    const float width = near * std::tanf(fov / 2.0f) * aspect;

	const float l = -width;
	const float r = width;

	const float height = width / aspect;

	const float t = height;
	const float b = -height;

	matrix = Mat4{
		//1.0, 0.0, 0.0, 0.0,
		//0.0, 1.0, 0.0, 0.0,
		//0.0, 0.0, 1.0, 0.0,
		//0.0, 0.0, 0.0, 1.0

		2.0f * near / (r - l), 0.0, 0.0, 0.0,
		0.0, 2.0f * near / (t - b), 0.0, 0.0,
		(r + l) / (r - l), (t + b) / (t - b), -(far + near) / (far - near), -1.0,
		0.0, 0.0, -2.0f * far * near / (far - near), 0.0
	};
}
