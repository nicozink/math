/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

// Local Includes
#include "mat4.h"

// Project Includes

// External Includes

// Class definitions
class TransformSystem;

class Transform
{
  friend class TransformSystem;

  public:
  
    //
    // Constructors
    //
    
    // Initialises a new instance of the Transform class.
    Transform();

    // Initialises a new instance of the transform class.
    Transform(const Transform& other);

    // Initialises a new instance of the transform class.
    void operator=(const Transform& other);

    // Destroys this new instance of the Transform class.
    ~Transform();

    //
    // Public Methods
    //
    
    // Calculates the transform.
    void Calculate();

    // Gets the transformation matrix.
    // @returns The transform matrix.
    Mat4& GetTransform();

    // Sets the rotation of the object around each euler axis.
    // @param x The x axis.
    // @param y The y axis.
    // @param z The z axis.
    void RotateEuler(float x, float y, float z);

    // Sets the scale of the transform.
    // @param scale The scale.
    void Scale(float scale);

    // Sets the scale of the transform.
    // @param scalex The x scale.
    // @param scaley The y scale.
    // @param scalez The z scale.
    void ScaleXYZ(float scalex, float scaley, float scalez);

    // Sets the matrix of this transform.
    // @param matrix The matrix.
    void SetMatrix(Mat4& matrix);

    // Sets the matrix of this transform.
    // @param matrix The matrix.
    void SetMatrix(Mat4&& matrix);

    // Sets the parent of this transform.
    // @param parent The parent transform.
    void SetParent(Transform* parent);

    // Sets the scale of the transform.
    // @param scale The scale.
    void Translate(float x, float y, float z);

  protected:

    //
    // Private Variables
    //

    // Stores the matrix containing the full transformation.
    Mat4 rotationMatrix;

    // Stores the scaling factor.
    Mat4 scaleMatrix;

    // Stores the matrix containing the full transformation.
    Mat4 translationMatrix;

    // Stores the matrix containing the full transformation.
    Mat4 fullMatrix;
};

#endif
