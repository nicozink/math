/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#include <math/transform.h>

// Library Includes
#include <reflection/register_class.h>

REGISTER_CLASS(Transform)
{
	register_constructor();
	register_method("Calculate", &Transform::Calculate);
	register_method("RotateEuler", &Transform::RotateEuler);
	register_method("Scale", &Transform::Scale);
	register_method("Translate", &Transform::Translate);
}

//
// Constructors
//

// Initialises a new instance of the transform class.
Transform::Transform()
{
  rotationMatrix.Identity();
  scaleMatrix.Identity();
  translationMatrix.Identity();
  fullMatrix.Identity();
}

// Initialises a new instance of the transform class.
Transform::Transform(const Transform& other)
{
  this->rotationMatrix = other.rotationMatrix;
  this->scaleMatrix = other.rotationMatrix;
  this->translationMatrix = other.translationMatrix;
  this->fullMatrix = other.fullMatrix;
}

// Initialises a new instance of the transform class.
void Transform::operator=(const Transform& other)
{
  this->rotationMatrix = other.rotationMatrix;
  this->scaleMatrix = other.rotationMatrix;
  this->translationMatrix = other.translationMatrix;
  this->fullMatrix = other.fullMatrix;
}

// Destroys this new instance of the Transform class.
Transform::~Transform()
{

}

//
// Public Methods
//

// Calculates the transform.
void Transform::Calculate()
{
  fullMatrix.Identity();

  fullMatrix.LeftMultiply(scaleMatrix);
  fullMatrix.LeftMultiply(rotationMatrix);
  fullMatrix.LeftMultiply(translationMatrix);
}

// Gets the transformation matrix.
// @returns The transform matrix.
Mat4& Transform::GetTransform()
{
  return fullMatrix;
}

// Sets the rotation of the object around each euler axis.
// @param x The x axis.
// @param y The y axis.
// @param z The z axis.
void Transform::RotateEuler(float x, float y, float z)
{
  rotationMatrix.RotateEuler(x, y, z);
}

// Sets the scale of the transform.
// @param scale The scale.
void Transform::Scale(float scale)
{
  scaleMatrix.Scale(scale);
}

// Sets the scale of the transform.
// @param scalex The x scale.
// @param scaley The y scale.
// @param scalez The z scale.
void Transform::ScaleXYZ(float scalex, float scaley, float scalez)
{
  scaleMatrix.ScaleXYZ(scalex, scaley, scalez);
}

// Sets the matrix of this transform.
// @param matrix The matrix.
void Transform::SetMatrix(Mat4& matrix)
{
  fullMatrix = matrix;
}

// Sets the matrix of this transform.
// @param matrix The matrix.
void Transform::SetMatrix(Mat4&& matrix)
{
  fullMatrix = matrix;
}

// Sets the scale of the transform.
// @param scale The scale.
void Transform::Translate(float x, float y, float z)
{
  translationMatrix.Translate(x, y, z);
}
