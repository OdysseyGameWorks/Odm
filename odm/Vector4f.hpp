#pragma once

/*
 Author - Odyssey.
 Specially developed maths library of game development.
 Heavily commented for the user to be able to understand easily.
 */

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include <array>
#include <assert.h>
#include "Vector3f.hpp"
#include "Vector2f.hpp"

namespace odm
{

	struct Vector4f
	{
	public:
		union
		{
			struct
			{
				float x,
					y,
					z,
					w;
			};

			struct
			{
				Vector2f v[2];
			};
		};

		/**
		 * Constructs a vector with 4 coords.
		 * Inializes all coords to 0.
		*/
		__forceinline Vector4f();

		/**
		 * Constructs a vector with 4 coords.
		 * @param vector Copies the value from this vector object.
		*/
		__forceinline Vector4f(const Vector4f& vector);

		/**
		 * Constructs from single float argument.
		 * @param f Initial value for X-Y-Z-W coord.
		*/
		__forceinline explicit Vector4f(float f);

		/**
		 * Constructs from three float arguments.
		 * @param x Initial value for X coord.
		 * @param y Initial value for Y coord.
		 * @param z Initial value for Z coord.
		 * @param w Initial value for W coord.
		*/
		__forceinline Vector4f(float x, float y, float z, float w);

		/**
		 * Constructs from a Vector3 and float.
		 * @param v Vector2 from which the vector3 is to be constructed.
		 * @param z Initial value for z-coord.
		*/
		__forceinline Vector4f(const Vector3f& v, float f);


		/**
		 * Constructs from a Vector3
		 * Sets the z-coord to 1
		 * @param v Vector2 from which the vector3 is to be constructed.
		*/
		__forceinline Vector4f(const Vector3f& v);


		/** dtor */
		__forceinline ~Vector4f() = default;


	public:

		// --- OPERATORS ---

		__forceinline void operator=(const Vector4f& v);

		__forceinline bool operator==(const Vector4f& v);

		__forceinline bool operator!=(const Vector4f& v);

		__forceinline Vector4f operator+(const Vector4f& v) const;

		__forceinline Vector4f operator-(const Vector4f& v) const;

		__forceinline Vector4f operator*(const Vector4f& v) const;

		__forceinline Vector4f operator/(const Vector4f& v) const;

		__forceinline Vector4f operator*(const float f) const;

		__forceinline Vector4f operator/(const float f) const;

		__forceinline float& operator[](int index);

		__forceinline float operator[](int index) const;

	};

	typedef Vector4f vec4f;
	typedef Vector4f vec4;

	__forceinline Vector4f::Vector4f()
	{
		x = y = z = w = 0;
	}

	__forceinline Vector4f::Vector4f(const Vector4f& vector)
		: x(vector.x), y(vector.y), z(vector.z), w(vector.w)
	{}

	__forceinline Vector4f::Vector4f(float f)
	{
		x = y = z = w = f;
	}

	__forceinline Vector4f::Vector4f(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{}

	__forceinline Vector4f::Vector4f(const Vector3f& v, float f)
		: x(v.x), y(v.y), z(v.z), w(f)
	{}

	__forceinline Vector4f::Vector4f(const Vector3f& v)
		: x(v.x), y(v.y), z(v.z), w(1.0f)
	{}

	__forceinline void Vector4f::operator=(const Vector4f& v)
	{
		x = v.x, y = v.y, z = v.z, w = v.w;
	}

	__forceinline bool Vector4f::operator==(const Vector4f& v)
	{
		return (this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w);
	}

	__forceinline bool Vector4f::operator!=(const Vector4f& v)
	{
		return !(*this == v);
	}

	__forceinline Vector4f Vector4f::operator+(const Vector4f& v) const
	{
		return Vector4f(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	__forceinline Vector4f Vector4f::operator-(const Vector4f& v) const
	{
		return Vector4f(
			x - v.x,
			y - v.y,
			z - v.z,
			w - v.w
		);
	}

	__forceinline Vector4f Vector4f::operator*(const Vector4f& v) const
	{
		return Vector4f(
			x * v.x,
			y * v.y,
			z * v.z,
			w * v.w
		);
	}

	__forceinline Vector4f Vector4f::operator/(const Vector4f& v) const
	{
		return Vector4f(
			x / v.x,
			y / v.y,
			z / v.z,
			w / v.w
		);
	}

	__forceinline Vector4f Vector4f::operator*(const float f) const
	{
		return Vector4f(x * f, y * f, z * f, w * f);
	}

	__forceinline Vector4f Vector4f::operator/(const float f) const
	{
		assert(f != 0);
		return Vector4f(
			x / f,
			y / f,
			z / f,
			w / f
		);
	}

	__forceinline float& Vector4f::operator[](int index)
	{
		assert(index >= 0 && index <= 3);
		switch (index)
		{
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		default:
			break;
		}
	}

	__forceinline float Vector4f::operator[](int index) const
	{
		assert(index >= 0 && index <= 3);
		switch (index)
		{
		case 0:
			return x;
			break;
		case 1:
			return y;
			break;
		case 2:
			return z;
			break;
		case 3:
			return w;
			break;
		default:
			break;
		}
	}

	__forceinline Vector4f operator*(float lhs, const Vector4f& rhs) { return rhs * lhs; }

}

#else
#error Vector4 header had already been included 
#endif
