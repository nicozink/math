// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <math/dimension.h>

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
