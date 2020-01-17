#pragma once

#ifndef _VECTOR4_H_
#define _VECTOR4_H_

#include <cassert>
#include "Vector3f.h"
#include "Vector2f.h"

namespace odm
{

	struct Vector4f
	{
		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			Vector2f v[2];
		};

		/**
		 * Constructs a vector with 4 coordinates.
		 * Initializes all coordinates to 0.
		*/
		Vector4f();
		
		/**
		 * Constructs a vector with 4 coordinates.
		 * @param vector Copies the value from this vector object.
		*/
		Vector4f(const Vector4f& vector);

		/**
		 * Constructs from single float argument.
		 * @param f Initial value for X-Y-Z-W coordinate.
		*/
		explicit Vector4f(float f);

		/**
		 * Constructs from three float arguments.
		 * @param x Initial value for X coordinate.
		 * @param y Initial value for Y coordinate.
		 * @param z Initial value for Z coordinate.
		 * @param w Initial value for W coordinate.
		*/
		Vector4f(float x, float y, float z, float w);

		/**
		 * Constructs from a Vector3 and float.
		 * @param v Vector2 from which the vector3 is to be constructed.
		 * @param z Initial value for z-coordinate.
		*/
		Vector4f(const Vector3f& v, float z);
		
		/**
		 * Constructs from a Vector3
		 * Sets the z-coordinate to 1
		 * @param v Vector2 from which the vector3 is to be constructed.
		*/
		Vector4f(const Vector3f& v);


		/** Default Destructor. */
		~Vector4f() = default;

#pragma region Operators

		Vector4f& operator=(const Vector4f& v);

		bool operator==(const Vector4f& v) const;
		bool operator!=(const Vector4f& v) const;

		Vector4f operator+(const Vector4f& v) const;
		Vector4f operator-(const Vector4f& v) const;
		Vector4f operator*(const Vector4f& v) const;
		Vector4f operator/(const Vector4f& v) const;

		Vector4f operator+(float f) const;
		Vector4f operator-(float f) const;
		Vector4f operator*(float f) const;
		Vector4f operator/(float f) const;

		Vector4f operator+=(const Vector4f& v);
		Vector4f operator-=(const Vector4f& v);
		Vector4f operator*=(const Vector4f& v);
		Vector4f operator/=(const Vector4f& v);

		Vector4f operator+=(float f);
		Vector4f operator-=(float f);
		Vector4f operator*=(float f);
		Vector4f operator/=(float f);

		float& operator[](int index);
		float operator[](int index) const;

#pragma endregion

	};

	typedef Vector4f vec4f;
	typedef Vector4f vec4;

	inline Vector4f::Vector4f()
	{
		x = y = z = w = 0;
	}

	inline Vector4f::Vector4f(const Vector4f& vector)
		: x(vector.x), y(vector.y), z(vector.z), w(vector.w)
	{}

	inline Vector4f::Vector4f(float f)
	{
		x = y = z = w = f;
	}

	inline Vector4f::Vector4f(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{}

	inline Vector4f::Vector4f(const Vector3f& v, float z)
		: x(v.x), y(v.y), z(v.z), w(z)
	{}

	inline Vector4f::Vector4f(const Vector3f& v)
		: x(v.x), y(v.y), z(v.z), w(1.0f)
	{}

	inline Vector4f& Vector4f::operator=(const Vector4f& v)
	{
		x = v.x, y = v.y, z = v.z, w = v.w;
		return *this;
	}

	inline bool Vector4f::operator==(const Vector4f& v) const
	{
		return (this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w);
	}

	inline bool Vector4f::operator!=(const Vector4f& v) const
	{
		return !(*this == v);
	}

	inline Vector4f Vector4f::operator+(const Vector4f& v) const
	{
		return Vector4f(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	inline Vector4f Vector4f::operator-(const Vector4f& v) const
	{
		return Vector4f(
			x - v.x,
			y - v.y,
			z - v.z,
			w - v.w
		);
	}

	inline Vector4f Vector4f::operator*(const Vector4f& v) const
	{
		return Vector4f(
			x * v.x,
			y * v.y,
			z * v.z,
			w * v.w
		);
	}

	inline Vector4f Vector4f::operator/(const Vector4f& v) const
	{
		return Vector4f(
			x / v.x,
			y / v.y,
			z / v.z,
			w / v.w
		);
	}

	inline Vector4f Vector4f::operator+(float f) const
	{
		return Vector4f(x + f, y + f, z + f, w + f);
	}

	inline Vector4f Vector4f::operator-(float f) const
	{
		return Vector4f(x - f, y - f, z - f, w - f);
	}

	inline Vector4f Vector4f::operator*(const float f) const
	{
		return Vector4f(x * f, y * f, z * f, w * f);
	}

	inline Vector4f Vector4f::operator/(const float f) const
	{
		assert(f != 0);
		return Vector4f(
			x / f,
			y / f,
			z / f,
			w / f
		);
	}

	inline Vector4f Vector4f::operator+=(const Vector4f& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	inline Vector4f Vector4f::operator-=(const Vector4f& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	inline Vector4f Vector4f::operator*=(const Vector4f& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		w *= v.w;
		return *this;
	}

	inline Vector4f Vector4f::operator/=(const Vector4f& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
		w /= v.w;
		return *this;
	}

	inline Vector4f Vector4f::operator+=(float f)
	{
		x += f;
		y += f;
		z += f;
		w += f;
		return *this;
	}

	inline Vector4f Vector4f::operator-=(float f)
	{
		x -= f;
		y -= f;
		z -= f;
		w -= f;
		return *this;
	}

	inline Vector4f Vector4f::operator*=(float f)
	{
		x *= f;
		y *= f;
		z *= f;
		w *= f;
		return *this;
	}
	
	inline Vector4f Vector4f::operator/=(float f)
	{
		x /= f;
		y /= f;
		z /= f;
		w /= f;
		return *this;
	}

	inline float& Vector4f::operator[](int index)
	{
		assert(index >= 0 && index <= 3);
		return (&x)[index];
	}

	inline float Vector4f::operator[](int index) const
	{
		assert(index >= 0 && index <= 3);
		return (&x)[index];
	}

	inline Vector4f operator*(float lhs, const Vector4f& rhs) { return rhs * lhs; }

}

#else
#error Vector4 header had already been included 
#endif
