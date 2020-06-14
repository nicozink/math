// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef math_mat4_h
#define math_mat4_h

// Local Includes
#include "matrix.h"
#include "vec3.h"

// Project Includes

// External Includes

// This declares a matrix containing floats in four rows and columns.
class Mat4 : public Matrix<float, 4>
{
public:

	//
	// Constructors
	//

	// Creates a new instance of the Matrix class.
	Mat4();

	// Creates a new instance of the Matrix class.
	// @param identity_value The initial value.
	Mat4(float identity_value);

	// Creates a new instance of the Matrix class.
	// @param values The values.
	Mat4(float values[16]);

	// Creates a new instance of the Matrix class.
	// @param list The list of arguments.
	Mat4(std::initializer_list<float> list);

	// Destroys this instance of the Matrix class.
	virtual ~Mat4();

	//
	// Public Static Methods
	//

	// Sets the rotation of the object around each euler axis.
	// @param matrix The matrix.
	// @param vec The rotation vector.
	// @param delta The z axis.
	static void Identity(Mat4& matrix);

	// Sets the rotation of the object around each euler axis.
	// @param matrix The matrix.
	// @param vec The rotation vector.
	// @param delta The z axis.
	static void Rotate(Mat4& matrix, Vec3 vec, float delta);

	// Sets the rotation of the object around each euler axis.
	// @param matrix The matrix.
	// @param x The rotation around the x axis.
	// @param y The rotation around the y axis.
	// @param z The rotation around the z axis.
	static void RotateEuler(Mat4& matrix, float x, float y, float z);

	// Sets the rotation of the object around each euler axis.
	// @param matrix The matrix.
	// @param delta The rotation around the x axis.
	static void RotateX(Mat4& matrix, float delta);

	// Sets the rotation of the object around each euler axis.
	// @param matrix The matrix.
	// @param delta The rotation around the y axis.
	static void RotateY(Mat4& matrix, float delta);
	
	// Sets the rotation of the object around each euler axis.
	// @param matrix The matrix.
	// @param delta The rotation around the z axis.
	static void RotateZ(Mat4& matrix, float delta);

	// Sets the scale of the object.
	// @param matrix The matrix.
	// @param scale The scale factor.
	static void Scale(Mat4& matrix, float scale);
    
	// Sets the scale of the object.
	// @param matrix The matrix.
	// @param vec The scale vector.
	static void ScaleXYZ(Mat4& matrix, Vec3 vec);
    
	// Creates a new translation matrix.
	// @param matrix The matrix.
	// @param vec The translation vector.
	static void Translate(Mat4& matrix, Vec3 vec);
};

#endif
