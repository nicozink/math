// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef math_matrix_h
#define math_matrix_h

// Local Includes

// Project Includes
#include <cpp_util/debug/assert.h>

// External Includes
#include <algorithm>
#include <array>
#include <initializer_list>

// Referenced classes.

// Stores a matrix of the specified type and dimensions.
// @type TType The type of the object stored in the matrix.
// @type TSize The size of the matrix.
template <typename TType, int TSize>
class Matrix
{
  public:
    
    //
    // Constructors
    //
    
    // Creates a new instance of the Matrix class.
    Matrix()
    {
      
    }

    // Creates a new instance of the Matrix class.
    // @param values The values.
    Matrix(TType values[TSize * TSize])
    {
      for (int i = 0; i < TSize * TSize; ++i)
      {
        this->values[i] = values[i];
      }
    }

    // Creates a new instance of the Matrix class.
    // @param values The values.
    Matrix(std::array<TType, TSize * TSize> values)
      : values{ values }
    {
      
    }

    // Creates a new instance of the Matrix class.
    // @param list The list of arguments.
    Matrix(std::initializer_list<TType> list)
    {
      Assert(list.size() == TSize * TSize,
        "The argument list did not match the vector size.");
      
      int c = 0;
      
      for(auto elem : list)
      {
        this->values[c] = elem;
        
        ++c;
      }
    }
    
    // Destroys this instance of the Matrix class.
    virtual ~Matrix()
    {
    
    }
    
    //
    // Operators
    //
    
    // Returns the value stored in the given row and column.
    // @param r The row.
    // @param c The column.
    // @returns The value.
    TType& operator () (int r, int c)
    {
      return values[c * TSize + r];
    }
    
    // Returns the value stored in the given index.
    // @param i The index.
    // @returns The value.
    const std::array<TType, TSize * TSize>& operator * () const
    {
      return values;
    }
    
    //
    // Public Methods
    //
    
    // Returns the value stored in the given row and column.
    // @param r The row.
    // @param c The column.
    // @returns The value.
    TType Get(int r, int c)
    {
      return values[c * TSize + r];
    }
    
    // Gets the values stored in the array.
    // @returns The values.
    std::array<TType, TSize * TSize>& GetArray()
    {
      return values;
    }
    
    // Sets the rows and columns of the matrix to form an
    // identity matrix.
    void Identity()
    {
      for (int i = 0; i < TSize; ++i)
      {
        for (int j = 0; j < TSize; ++j)
        {
          if (i == j)
          {
            (*this)(i, j) = 1;
          }
          else
          {
            (*this)(i, j) = 0;
          }
        }
      }
    }

    // Multiplies the provided matrix with this instance.
    void LeftMultiply(Matrix<TType, TSize>& matrix)
    {
      TType arrcopy[TSize * TSize];

      std::copy(std::begin(values), std::end(values), std::begin(arrcopy));

      for (int i = 0; i < TSize; ++i)
      {
        for (int j = 0; j < TSize; ++j)
        {
          TType val = 0;

          for (int k = 0; k < TSize; ++k)
          {
            val += matrix.Get(i, k) * GetArrayValue(arrcopy, k, j);
          }

          (*this)(i, j) = val;
        }
      }
    }

    // Sets the value at the given row and column.
    // @param r The row.
    // @param c The column.
    // @param v The value.
    void Set(int r, int c, TType v)
    {
      values[c * TSize + r] = v;
    }
    
  private:
  
    //
    // Private Variables
    //
    
    // Contains the values stored in the matrix.
    std::array<TType, TSize * TSize> values;

    //
    // Private Methods
    //

    // Gets the value of the array at the speicified position.
    TType& GetArrayValue(TType (&values)[TSize * TSize], int c, int r)
    {
      return values[c * TSize + r];
    }
};

#endif
