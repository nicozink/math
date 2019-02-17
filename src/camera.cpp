// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <math/camera.h>

// Library Includes
#include <cpp_util/log/logger.h>
#include <reflection/register_class.h>

REGISTER_CLASS(Camera)
{
	register_constructor();
	register_method("get_matrix", &Camera::get_matrix);
	register_method("calculate", &Camera::calculate);
	register_method("set_direction", &Camera::set_direction);
	register_method("set_position", &Camera::set_position);
	register_method("set_world_up", &Camera::set_world_up);
	register_method("get_direction", &Camera::get_direction);
	register_method("get_position", &Camera::get_position);
}

Camera::Camera()
{
	position = Vec3(0.0f, 0.0f, 0.0f);
	direction = Vec3(0.0f, 0.0f, 1.0f);
	world_up = Vec3(0.0f, 1.0f, 0.0f);
}

void Camera::calculate()
{
	camera_transform = Mat4{
		right[0], up[0], -direction[0], 0.0f,
		right[1], up[1], -direction[1], 0.0f,
		right[2], up[2], -direction[2], 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	Mat4 transform_matrix{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		-position[0], -position[1], -position[2], 1.0f,
	};

	camera_transform.RightMultiply(transform_matrix);
}

Mat4& Camera::get_matrix()
{
	return camera_transform;
}

Vec3& Camera::get_position()
{
	return position;
}

Vec3& Camera::get_direction()
{
	return direction;
}

Vec3& Camera::get_right()
{
	return right;
}

Vec3& Camera::get_up()
{
	return up;
}

Vec3& Camera::get_world_up()
{
	return world_up;
}

void Camera::set_direction(Vec3 direction)
{
	this->direction = direction.normalise();

	right = this->direction.cross(world_up).normalise();
	up = right.cross(this->direction);
}

void Camera::set_position(Vec3 position)
{
	this->position = position;
}

void Camera::set_world_up(Vec3 world_up)
{
	this->world_up = world_up;

	right = direction.cross(world_up).normalise();
	up = right.cross(direction);
}