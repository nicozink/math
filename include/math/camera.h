// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef camera_camera_h
#define camera_camera_h

// Project Includes
#include <math/mat4.h>
#include <math/vec3.h>

class Camera
{
public:
	
	Camera();

	void calculate();

	Mat4& get_matrix();
	
	Vec3& get_position();

	Vec3& get_direction();

	Vec3& get_right();

	Vec3& get_up();

	Vec3& get_world_up();

	void set_direction(Vec3 direction);

	void set_position(Vec3 position);

	void set_world_up(Vec3 up);

private:

	Mat4 camera_transform;

	Vec3 direction;

	Vec3 position;
	
	Vec3 right;

	Vec3 up;

	Vec3 world_up;
};

#endif
