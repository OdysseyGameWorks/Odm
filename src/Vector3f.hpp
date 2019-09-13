#pragma once

/*
 Author - Odyssey.
 Specially developed maths library of game development.
 Heavily commented for the user to be able to understand easily.
 */

#include "MathUtil.hpp"
#include "Vector2f.hpp"

#ifndef _VEC3_H
#define _VEC3_H

namespace odm
{

	struct Vector3f
	{
	public:
		union
		{
			struct
			{
				float x,
					y,
					z;
			};

			struct
			{
				float fVal[3];
			};
		};


		/**
		 * Constructs a vector.
		 * Inializes all coords to 0.
		*/
		__forceinline Vector3f();


		/**
		 * Constructs from anther vector.
		 * @param v Takes in another vector to copy coords value.
		*/
		__forceinline Vector3f(const Vector3f& v);


		/**
		 * Constructs from three float arguments.
		 * @param x Initial value for X coord.
		 * @param y Initial value for Y coord.
		 * @param z Initial value for Z coord.
		*/
		__forceinline Vector3f(float x, float y, float z);


		/**
		 * Constructs from single float argument.
		 * @param f Initial value for X-Y-Z coord.
		*/
		__forceinline explicit Vector3f(float f);


		/**
		 * Constructs from a Vector2 and float.
		 * @param v Vector2 from which the vector3 is to be constructed.
		 * @param z Initial value for z-coord.
		*/
		__forceinline Vector3f(const Vector2f& v, float z);


		/**
		 * Constructs from a Vector2
		 * Sets the z-coord to 1
		 * @param v Vector2 from which the vector3 is to be constructed.
		*/
		__forceinline Vector3f(const Vector2f& v);


		/** dtor */
		__forceinline ~Vector3f() = default;


		// -------- METHODS -----------

		/**
		 * Calculates the absolute value of the vector coords.
		 * @return Abs value of this Vector.
		*/
		__forceinline Vector3f Abs() const;

		/**
		 * Returns the length of the vector
		*/
		__forceinline float Length() const;

		/**
		 * Calculates the distance between two vectors.
		 * @param v Vector from which distance will be calculated.
		 * @return distance between two vectors in float.
		*/
		__forceinline float Distance(const Vector3f& v) const;

		/**
		 * Calculates the distance between two vectors.
		 * @param v1 Vector from which distance will be calculated.
		 * @param v2 Vector from which distance will be compared.
		 * @return distance between two vectors in float.
		*/
		__forceinline static float Distance(const Vector3f& v1, const Vector3f& v2);

		/**
		 * Calculates the dot product two vectors.
		 * @param v Vector which would be dot multiplied.
		 * @return dot product between two vectors in Vector3.
		*/
		__forceinline float Dot(const Vector3f& v) const;

		/**
		 * Calculates the dot product two vectors.
		 * @param v Vector which would be dot multiplied.
		 * @param v2 Vector which would be dot multiplied with the vector v.
		 * @return dot product between two vectors in Vector3.
		*/
		__forceinline static float Dot(const Vector3f& v1, const Vector3f& v2);

		/**
		 * Calculates the cross product two vectors.
		 * @param v1 First vector from v2 will be cross multiplied.
		 * @param v2 Second vector from v1 will be cross multiplied.
		 * @return distace between two vectors in Vector3.
		*/
		__forceinline static Vector3f Cross(const Vector3f& v1, const Vector3f& v2);

		/**
		 * Calculates the cross product two vectors.
		 * @param v Vector which would be cross multiplied.
		 * @return distace between two vectors in Vector3.
		*/
		__forceinline Vector3f Cross(const Vector3f& v) const;


		/** Returns the normalized vector. */
		__forceinline Vector3f Normalize() const;

		/** 
		 * Returns the normalized vector.
		 * @param v Vector to be normalized
		*/
		static Vector3f Normalize(const Vector3f& v) { return v.Normalize(); }

	public:
		// --- SETTERS ---

		/**
		 * Sets the x coord of the vector.
		 * @param value to be set to the coord.
		*/
		__forceinline void SetX(float val) { x = val; }

		/**
		 * Sets the x coord of the vector.
		 * @param value to be set to the coord.
		*/
		__forceinline void SetY(float val) { y = val; }

		/**
		 * Sets the x coord of the vector.
		 * @param value to be set to the coord.
		*/
		__forceinline void SetZ(float val) { z = val; }

	public:

		// --- GETTERS ---

		/** Gets the value x coord of the vector. */
		__forceinline float GetX() { return x; }

		/** Gets the value x coord of the vector. */
		__forceinline float GetY() { return y; }

		/** Gets the value x coord of the vector. */
		__forceinline float GetZ() { return z; }

	public:
		// --- OPERATORS ---

		__forceinline void operator=(const Vector3f& vec);

		/**
		 * Checks if two vectors are equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline bool operator==(const Vector3f& v) const;

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline bool operator!=(const Vector3f& v) const;

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline Vector3f operator+(const Vector3f& v);

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline const Vector3f operator-(const Vector3f& v) const;

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline Vector3f operator*(const Vector3f& v);

		/**
		 * Checks if two vectors are not equal.
		 * @param v float to be compared with.
		*/
		__forceinline const Vector3f operator*(float f) const;

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline Vector3f operator/(const Vector3f& v) const;

		/**
		 * Divides the vector.
		 * @param f Float value to divide the vector with.
		*/
		__forceinline Vector3f operator/(float f);

		/**
		 * Index Operator
		 * @param index Index of the vector component.
		*/
		__forceinline const float operator[](int index) const;

		__forceinline const Vector3f operator-() const;


	public:

		/** A zero vector (0, 0, 0) */
		static const Vector3f Zero;

		/** One vector (1, 1, 1) */
		static const Vector3f One;

		/** Up vector (0, 1, 0) */
		static const Vector3f Up;

		/** Down vector (0, -1, 0) */
		static const Vector3f Down;

		/** Forward vector (0, 0, 1) */
		static const Vector3f Forward;

		/** Backward vector (0, 0, -1) */
		static const Vector3f Back;

		/** Left vector (-1, 0, 0) */
		static const Vector3f Left;

		/** Right vector (1, 0, 0) */
		static const Vector3f Right;

	};

	typedef Vector3f vec3;
	typedef Vector3f vec3f;


	__forceinline Vector3f::Vector3f()
	{
		x = y = z = 0;
	}

	__forceinline Vector3f::Vector3f(float f)
	{
		x = y = z = f;
	}

	__forceinline Vector3f::Vector3f(const Vector2f& v, float z)
		: x(v.x), y(v.y), z(z)
	{}

	__forceinline Vector3f::Vector3f(const Vector2f& v)
		: x(v.x), y(v.y), z(1.0f)
	{}

	__forceinline Vector3f::Vector3f(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	__forceinline Vector3f::Vector3f(const Vector3f& v)
		: x(v.x), y(v.y), z(v.z)
	{}

	__forceinline vec3 Vector3f::Abs() const
	{
		return vec3(abs(x), abs(y), abs(z));
	}

	__forceinline float Vector3f::Length() const
	{
		return (sqrt(x * x + y * y + z * z));
	}

	__forceinline float Vector3f::Distance(const Vector3f& v) const
	{
		return sqrt((x - v.x * x - v.x) + (y - v.y * y - v.y) + (z - v.z * z - v.z));
	}

	__forceinline float Vector3f::Distance(const Vector3f & v1, const Vector3f & v2)
	{
		v1.Distance(v2);
	}

	__forceinline float Vector3f::Dot(const Vector3f& v) const
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	__forceinline float Vector3f::Dot(const Vector3f& v1, const Vector3f& v2)
	{
		return v1.Dot(v2);
	}

	__forceinline Vector3f Vector3f::Cross(const Vector3f& lhs, const Vector3f& rhs)
	{
		Vector3f result;

		result.x = lhs.y * rhs.z - lhs.z * rhs.y;
		result.y = lhs.z * rhs.x - lhs.x * rhs.z;
		result.z = lhs.x * rhs.y - lhs.y * rhs.x;

		return result;
	}

	__forceinline Vector3f Vector3f::Cross(const Vector3f& v) const
	{
		return Cross(*this, v);
	}

	__forceinline Vector3f Vector3f::Normalize() const
	{
		auto length_squared = Length() * Length();
		if (!(length_squared == 1.0f) && length_squared > 0.0f)
		{
			return (*this) * (1.0f / sqrt(length_squared));
		}
		else
			return *this;
	}

	__forceinline void Vector3f::operator=(const Vector3f& vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}

	__forceinline bool Vector3f::operator==(const Vector3f & v) const
	{
		return (x == v.x && y == v.y && z == v.z);
	}

	__forceinline bool Vector3f::operator!=(const Vector3f& v) const
	{
		return !(*this == v);
	}

	__forceinline Vector3f Vector3f::operator+(const Vector3f& v)
	{
		return Vector3f(
			x + v.x,
			y + v.y,
			z + v.z
		);
	}

	__forceinline const Vector3f Vector3f::operator-(const Vector3f& v) const
	{
		return Vector3f(
			x - v.x,
			y - v.y,
			z - v.z
		);
	}

	__forceinline Vector3f Vector3f::operator*(const Vector3f& v)
	{
		return Vector3f(
			x * v.x,
			y * v.y,
			z * v.z
		);
	}

	__forceinline const Vector3f Vector3f::operator*(float f) const
	{
		return Vector3f(
			x * f, y * f, z * f
		);
	}

	inline Vector3f Vector3f::operator/(const Vector3f& v) const
	{
		return Vector3f(
			x / v.x,
			y / v.y,
			z / v.z
		);
	}

	__forceinline Vector3f Vector3f::operator/(float f)
	{
		return Vector3f(
			x / f,
			y / f,
			z / f
		);
	}

	__forceinline const float Vector3f::operator[](int index) const
	{
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
		default:
			break;
		}
	}

	__forceinline const Vector3f Vector3f::operator-() const
	{
		return Vector3f(-x, -y, -z);
	}

	__forceinline Vector3f operator*(float lhs, const Vector3f& rhs) { return rhs * lhs; }

}

#else
#error Vector3 header had already been included
#endif

