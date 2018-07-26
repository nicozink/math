// Copyright (c) Nico Zink
// https://github.com/nicozink/darkentity.git
// Licensed under GNU General Public License 3.0 or later.

#pragma once

#ifndef math_vector_h
#define math_vector_h

// Local Includes

// Project Includes
#include <cpp_util/debug/assert.h>

// External Includes
#include <array>
#include <cstdarg>
#include <initializer_list>

// Referenced classes.

// Stores a vector of the specified type and dimensions.
// @type TType The type of the object stored in the vector.
// @type TSize The size of the vector.
template <typename TType, int TSize>
class Vector
{
public:
    
	//
	// Constructors
	//
    
	// Creates a new instance of the Vector class.
	Vector()
	{
      
	}

	// Creates a new instance of the Vector class.
	// @param values The values.
	Vector(TType values[TSize])
	{
		for (int i = 0; i < TSize; ++i)
		{
			this->values[i] = values[i];
		}
	}
    
	// Creates a new instance of the Vector class.
	// @param list The list of arguments.
	Vector(std::initializer_list<TType> list)
	{
		Assert(list.size() == TSize, "The argument list did not match the vector size.");
      
		int c = 0;
      
		for(auto elem : list)
		{
			this->values[c] = elem;
        
			++c;
		}
	}
    
	// Creates a new instance of the Vector class.
	template<typename... Args>
	Vector(Args... args)
	: Vector({ args... })
	{

	}

	// Destroys this instance of the Vector class.
	virtual ~Vector()
	{
    
	}
    
	//
	// Public Methods
	//
    
	template <typename TReturn = Vector<TType, TSize>>
	auto cross(Vector<TType, TSize>& other)
		-> std::enable_if_t<(TSize == 3), TReturn>
	{
		Vector<TType, TSize> to_return;

		to_return[0] = values[1] * other[2] - values[2] * other[1];
		to_return[1] = values[2] * other[0] - values[0] * other[2];
		to_return[2] = values[0] * other[2] - values[1] * other[0];

		return to_return;
	}

	TType dot(Vector<TType, TSize>& other)
	{
		TType to_return{};

		for (int i = 0; i < TSize; ++i)
		{
			to_return += values[i] * other[i];
		}

		return to_return;
	}

	// Returns the value stored in the given index.
	// @param i The index.
	// @returns The value.
	TType get(int i)
	{
		return values[i];
	}
    
	// Gets the values stored in the array.
	// @returns The values.
	std::array<TType, TSize>& get_array()
	{
		return values;
	}
    
	// Calculates the length of the vector.
	TType length()
	{
		TType length{};

		for (int i = 0; i < TSize; ++i)
		{
			length += values[i] * values[i];
		}

		return sqrt(length);
	}

	// Normalises the vector.
	Vector<TType, TSize> normalise()
	{
		return (*this) / length();
	}

	// Sets the value stored in the given index.
	// @param i The index.
	// @param value The value.
	void set(int i, TType value)
	{
		values[i] = value;
	}

	//
	// Operators
	//

	// Returns the value stored in the given index.
	// @param i The index.
	// @returns The value.
	TType& operator () (int i)
	{
		return values[i];
	}

	// Returns the value stored in the given index.
	// @param i The index.
	// @returns The value.
	TType& operator [] (int i)
	{
		return values[i];
	}

	// Returns the value stored in the given index.
	// @param i The index.
	// @returns The value.
	TType operator [] (int i) const
	{
		return values[i];
	}

	// Returns the value stored in the given index.
	// @param i The index.
	// @returns The value.
	const std::array<TType, TSize>& operator * () const
	{
		return values;
	}

	// Returns the value stored in the given index.
	// @param i The index.
	// @returns The value.
	Vector<TType, TSize> operator - () const
	{
		Vector<TType, TSize> to_return;

		for (int i = 0; i < TSize; ++i)
		{
			to_return[i] = -values[i];
		}

		return to_return;
	}

	Vector<TType, TSize> operator+(const Vector<TType, TSize>& other)
	{
		Vector<TType, TSize> to_return;

		for (int i = 0; i < TSize; ++i)
		{
			to_return[i] = values[i] + other[i];
		}

		return to_return;
	}

	Vector<TType, TSize> operator-(const Vector<TType, TSize>& other)
	{
		Vector<TType, TSize> to_return;

		for (int i = 0; i < TSize; ++i)
		{
			to_return[i] = values[i] - other[i];
		}

		return to_return;
	}

	Vector<TType, TSize> operator/(TType value)
	{
		Vector<TType, TSize> to_return;

		for (int i = 0; i < TSize; ++i)
		{
			to_return[i] = values[i] / value;
		}

		return to_return;
	}

private:
  
	//
	// Protected Variables
	//
    
	// Contains the values stored in the vector.
	std::array<TType, TSize> values;
};

#endif
