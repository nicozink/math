// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef math_mat4_h
#define math_mat4_h

// Local Includes
#include "Matrix.h"

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
	// @param values The values.
	Mat4(float values[16]);

	// Creates a new instance of the Matrix class.
	// @param list The list of arguments.
	Mat4(std::initializer_list<float> list);

	// Destroys this instance of the Matrix class.
	virtual ~Mat4();

	//
	// Public Methods
	//

	// Sets the rotation of the object around each euler axis.
	// @param x The x axis.
	// @param y The y axis.
	// @param z The z axis.
	void RotateEuler(float x, float y, float z);

	// Sets the scale of the object.
	// @param scale The scale.
	void Scale(float scale);
    
	// Sets the scale of the object.
	// @param scalex The x scale.
	// @param scaley The y scale.
	// @param scalez The z scale.
	void ScaleXYZ(float scalex, float scaley, float scalez);
    
	// Creates a new translation matrix.
	// @param x The x coordinate.
	// @param y The y coordinate.
	// @param z The z coordinate.
	// 2returns The matrix.
	void Translate(float x, float y, float z);
};

#endif
