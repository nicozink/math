// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef math_projection_h
#define math_projection_h

// Local Includes
#include "mat4.h"

class ProjectionMatrix
{
public:

    static Mat4 CalculateOrthographic(float width, float height);

    static Mat4 CalculatePerspective(float aspect, float fov, float near, float far);
};

#endif
