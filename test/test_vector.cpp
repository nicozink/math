/*
Copyright © 2012, Nico Zink
All rights reserved.
*/

// Local Includes

// Project Includes
#include <math/Vector.h>
#include <unittest/test.h>

// External Includes
#include <cstdlib>

// Tests constructing a vector by verifying the underlying values.
TEST(Matrix, ConstructVector)
{
  Vector<float, 2> vector({ 1.0, 2.0 });
  
  auto& results = vector.get_array();

  ASSERT_EQ(results[0], 1.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[1], 2.0) << "An incorrect value was returned.";
}

// Tests getting vector values.
TEST(Vector, TestGetter)
{
  float array[4] = { 1.0, 2.0 };
  
  Vector<float, 2> vector(array);
  
  ASSERT_EQ(vector.get(0), 1.0) << "An incorrect value was returned.";
  ASSERT_EQ(vector.get(1), 2.0) << "An incorrect value was returned.";
}

// Tests getting vector values.
TEST(Vector, TestOperatorGetter)
{
  float array[4] = { 1.0, 2.0 };
  
  Vector<float, 2> vector(array);
  
  ASSERT_EQ(vector(0), 1.0) << "An incorrect value was returned.";
  ASSERT_EQ(vector(1), 2.0) << "An incorrect value was returned.";
}

// Tests setting vector values.
TEST(Vector, TestSetter)
{
  float array[4] = { 1.0, 2.0 };
  
  Vector<float, 2> vector(array);
  
  vector.set(0, 5.0);
  vector.set(1, 6.0);
  
  auto& results = vector.get_array();

  ASSERT_EQ(results[0], 5.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[1], 6.0) << "An incorrect value was returned.";
}

// Tests setting vector values.
TEST(Vector, TestOperatorSetter)
{
  float array[4] = { 1.0, 2.0, 3.0, 4.0 };
  
  Vector<float, 2> vector(array);
  
  vector(0) = 5.0;
  vector(1) = 6.0;
  
  auto& results = vector.get_array();

  ASSERT_EQ(results[0], 5.0) << "An incorrect value was returned.";
  ASSERT_EQ(results[1], 6.0) << "An incorrect value was returned.";
}
