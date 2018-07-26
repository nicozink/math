// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#include <math/mat4.h>

// Local Includes

// Project Includes

// System Includes
#include <cmath>

// Creates a new instance of the Matrix class.
Mat4::Mat4()
{

}

// Creates a new instance of the Matrix class.
// @param values The values.
Mat4::Mat4(float values[16])
: Matrix(values)
{

}

// Creates a new instance of the Matrix class.
// @param list The list of arguments.
Mat4::Mat4(std::initializer_list<float> list)
: Matrix(list)
{

}

// Destroys this instance of the Matrix class.
Mat4::~Mat4()
{

}

// Sets the rotation of the object around each euler axis.
// The rotation is applied in the order of yxz.
// @param x The x axis.
// @param y The y axis.
// @param z The z axis.
void Mat4::RotateEuler(float x, float y, float z)
{
  (*this)(0, 0) = cos(z) * cos(y) - sin(z) * sin(x) * sin(y);
  (*this)(1, 0) = sin(z) * cos(y) + cos(z) * sin(x) * sin(y);
  (*this)(2, 0) = -cos(x) * sin(y);
  (*this)(3, 0) = 0;

  (*this)(0, 1) = -sin(z) * cos(x);
  (*this)(1, 1) = cos(z) * cos(x);
  (*this)(2, 1) = sin(x);
  (*this)(3, 1) = 0;

  (*this)(0, 2) = cos(z) * sin(y) + sin(z) * sin(x) * cos(y);
  (*this)(1, 2) = sin(z) * sin(y) - cos(z) * sin(x) * cos(y);
  (*this)(2, 2) = cos(x) * cos(y);
  (*this)(3, 2) = 0;

  (*this)(0, 3) = 0;
  (*this)(1, 3) = 0;
  (*this)(2, 3) = 0;
  (*this)(3, 3) = 1;
}

// Sets the scale of the object.
// @param scale The scale.
void Mat4::Scale(float scale)
{
  Identity();

  (*this)(0, 0) = scale;
  (*this)(1, 1) = scale;
  (*this)(2, 2) = scale;
}

// Sets the scale of the object.
// @param scalex The x scale.
// @param scaley The y scale.
// @param scalez The z scale.
void Mat4::ScaleXYZ(float scalex, float scaley, float scalez)
{
  Identity();

  (*this)(0, 0) = scalex;
  (*this)(1, 1) = scaley;
  (*this)(2, 2) = scalez;
}

// Creates a new translation matrix.
// @param x The x coordinate.
// @param y The y coordinate.
// @param z The z coordinate.
// 2returns The matrix.
void Mat4::Translate(float x, float y, float z)
{
  Identity();

  (*this)(0, 3) = x;
  (*this)(1, 3) = y;
  (*this)(2, 3) = z;
}
