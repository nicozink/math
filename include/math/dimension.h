// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef math_dimension_h
#define math_dimension_h

// This stores a 3d dimension, consisting of width and height.
class Dimension
{
public:

	//
	// Constructors
	//

	// Creates a new instance of the Dimension class.
	Dimension(int width, int height);

	//
	// Public Methods
	//

	// Gets the width.
	// @returns The width.
	int get_width();

	// Gets the height.
	// @returns The height.
	int get_height();

private:

	//
	// Private Variables
	//

	int m_width;

	int m_height;
};

#endif
