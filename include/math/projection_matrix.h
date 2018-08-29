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

    static void CalculateOrthographic(Mat4& matrix, float width, float height);

    static void CalculatePerspective(Mat4& matrix, float aspect, float fov, float near, float far);
};

#endif
