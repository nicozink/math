// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#include <math/vec3.h>

// Library Includes
#include <reflection/register_class.h>

REGISTER_CLASS(Vec3)
{
	register_constructor<float, float, float>();
	register_method("get", &Vec3::get);
	register_method("set", &Vec3::set);
}
