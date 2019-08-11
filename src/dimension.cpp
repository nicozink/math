// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <math/dimension.h>

// Library Includes
#include <reflection/register_class.h>

REGISTER_CLASS(Dimension)
{
	register_constructor<float, float>();
	register_method("get_width", &Dimension::get_width);
	register_method("get_height", &Dimension::get_height);
}

//
// Constructors
//

Dimension::Dimension(float width, float height)
{
	m_width = width;
	m_height = height;
}

//
// Public Methods
//

float Dimension::get_width()
{
	return m_width;
}

float Dimension::get_height()
{
	return m_height;
}
