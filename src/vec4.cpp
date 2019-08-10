// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <math/vec4.h>

// Library Includes
#include <reflection/register_class.h>

REGISTER_CLASS(Vec4)
{
	register_constructor<float, float, float, float>();
	register_method("get", &Vec4::get);
	register_method("set", &Vec4::set);
}
