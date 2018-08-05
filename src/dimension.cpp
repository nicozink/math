// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <math/dimension.h>

// Library Includes
#include <reflection/register_class.h>

REGISTER_CLASS(Dimension)
{
	register_constructor<int, int>();
	register_method("get_width", &Dimension::get_width);
	register_method("get_height", &Dimension::get_height);
}

Dimension::Dimension(int width, int height)
{
	this->width = width;
	this->height = height;
}

int Dimension::get_width()
{
	return width;
}

int Dimension::get_height()
{
	return height;
}
