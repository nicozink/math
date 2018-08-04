// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef math_projection_matrix_h
#define math_projection_matrix_h

#include <math/projection_matrix.h>

// Library Includes
#include <reflection/register_class.h>

REGISTER_CLASS(ProjectionMatrix)
{
	register_constructor();
	register_static_method("CalculateOrthographic", &ProjectionMatrix::CalculateOrthographic);
	register_static_method("CalculatePerspective", &ProjectionMatrix::CalculatePerspective);
}

Mat4 ProjectionMatrix::CalculateOrthographic(float width, float height)
{
    Mat4 projection;

	const float n = -1.0f;
	const float f = 1.0f;

	const float l = 0.0f;
	const float r = width;

	const float b = 0.0f;
	const float t = height;
	
	projection(0, 0) = 2.0f / (r - l);
	projection(0, 1) = 0.0f;
	projection(0, 2) = 0.0f;
	projection(0, 3) = -(r + l) / (r - l);

	projection(1, 0) = 0.0f;
	projection(1, 1) = 2.0f / (t - b);
	projection(1, 2) = 0.0f;
	projection(1, 3) = (t + b) / (t - b);

	projection(2, 0) = 0.0f;
	projection(2, 1) = 0.0f;
	projection(2, 2) = -2.0f / (f - n);
	projection(2, 3) = -(f + n) / (f - n);

	projection(3, 0) = 0.0f;
	projection(3, 1) = 0.0f;
	projection(3, 2) = 0.0f;
	projection(3, 3) = 1.0f;

	return projection;
}

Mat4 ProjectionMatrix::CalculatePerspective(float aspect, float fov, float near, float far)
{
    Mat4 projection;

	const float width = near * std::tanf(fov / 2.0f) * aspect;

	const float l = -width;
	const float r = width;

	const float height = width / aspect;

	const float t = height;
	const float b = -height;

	projection(0, 0) = 2.0*near / (r - l);
	projection(0, 1) = 0.0;
	projection(0, 2) = (r + l) / (r - l);
	projection(0, 3) = 0.0;

	projection(1, 0) = 0.0;
	projection(1, 1) = 2.0*near / (t - b);
	projection(1, 2) = (t + b) / (t - b);
	projection(1, 3) = 0.0;

	projection(2, 0) = 0.0;
	projection(2, 1) = 0.0;
	projection(2, 2) = (far + near) / (near - far);
	projection(2, 3) = 2.0*far*near / (near - far);

	projection(3, 0) = 0.0;
	projection(3, 1) = 0.0;
	projection(3, 2) = -1.0;
	projection(3, 3) = 0.0;

	return projection;
}

#endif
