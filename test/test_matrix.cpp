/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <math/matrix.h>
#include <unittest/test.h>

// External Includes
#include <cstdlib>

// Tests constructing a matrix.
TEST(Matrix, ConstructMatrix)
{
  float array[4] = { 1.0, 2.0, 3.0, 4.0 };
  
  Matrix<float, 2> matrix(array);
  
  auto results = matrix.GetArray();

  ASSERT_EQ(results[0], 1.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[1], 2.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[2], 3.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[3], 4.0) << "An incorrect value was returned.";
}

// Tests getting matrix values.
TEST(Matrix, TestGetter)
{
  float array[4] = { 1.0, 2.0, 3.0, 4.0 };
  
  Matrix<float, 2> matrix(array);
  
  ASSERT_EQ(matrix.Get(0, 0), 1.0) << "An incorrect value was returned.";
  ASSERT_EQ(matrix.Get(1, 0), 3.0) << "An incorrect value was returned.";
  ASSERT_EQ(matrix.Get(0, 1), 2.0) << "An incorrect value was returned.";
  ASSERT_EQ(matrix.Get(1, 1), 4.0) << "An incorrect value was returned.";
}

// Tests getting matrix values.
TEST(Matrix, TestOperatorGetter)
{
  float array[4] = { 1.0, 2.0, 3.0, 4.0 };
  
  Matrix<float, 2> matrix(array);
  
  ASSERT_EQ(matrix(0, 0), 1.0) << "An incorrect value was returned.";
  ASSERT_EQ(matrix(1, 0), 3.0) << "An incorrect value was returned.";
  ASSERT_EQ(matrix(0, 1), 2.0) << "An incorrect value was returned.";
  ASSERT_EQ(matrix(1, 1), 4.0) << "An incorrect value was returned.";
}

// Tests setting matrix values.
TEST(Matrix, TestSetter)
{
  float array[4] = { 1.0, 2.0, 3.0, 4.0 };
  
  Matrix<float, 2> matrix(array);
  
  matrix.Set(0, 0, 5.0);
  matrix.Set(1, 0, 6.0);
  matrix.Set(0, 1, 7.0);
  matrix.Set(1, 1, 8.0);
  
  auto results = matrix.GetArray();

  ASSERT_EQ(results[0], 5.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[1], 7.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[2], 6.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[3], 8.0) << "An incorrect value was returned.";
}

// Tests setting matrix values.
TEST(Matrix, TestOperatorSetter)
{
  float array[4] = { 1.0, 2.0, 3.0, 4.0 };
  
  Matrix<float, 2> matrix(array);
  
  matrix(0, 0) = 5.0;
  matrix(1, 0) = 6.0;
  matrix(0, 1) = 7.0;
  matrix(1, 1) = 8.0;
  
  auto results = matrix.GetArray();

  ASSERT_EQ(results[0], 5.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[1], 7.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[2], 6.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[3], 8.0) << "An incorrect value was returned.";
}
