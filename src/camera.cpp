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
	m_position = Vec3(0.0f, 0.0f, 0.0f);
	m_direction = Vec3(0.0f, 0.0f, 1.0f);
	m_world_up = Vec3(0.0f, 1.0f, 0.0f);
}

void Camera::calculate()
{
	m_camera_transform = Mat4{
		m_right[0], m_up[0], -m_direction[0], 0.0f,
		m_right[1], m_up[1], -m_direction[1], 0.0f,
		m_right[2], m_up[2], -m_direction[2], 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
	};

	Mat4 transform_matrix{
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		-m_position[0], -m_position[1], -m_position[2], 1.0f,
	};

	m_camera_transform.RightMultiply(transform_matrix);
}

Mat4& Camera::get_matrix()
{
	return m_camera_transform;
}

Vec3& Camera::get_position()
{
	return m_position;
}

Vec3& Camera::get_direction()
{
	return m_direction;
}

Vec3& Camera::get_right()
{
	return m_right;
}

Vec3& Camera::get_up()
{
	return m_up;
}

Vec3& Camera::get_world_up()
{
	return m_world_up;
}

void Camera::set_direction(Vec3 direction)
{
	m_direction = direction.normalise();

	m_right = m_direction.cross(m_world_up).normalise();
	m_up = m_right.cross(m_direction);
}

void Camera::set_position(Vec3 position)
{
	m_position = position;
}

void Camera::set_world_up(Vec3 world_up)
{
	m_world_up = world_up;

	m_right = m_direction.cross(world_up).normalise();
	m_up = m_right.cross(m_direction);
}