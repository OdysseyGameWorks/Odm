#pragma once

/*
 Author - Odyssey.
 Specially developed maths library of game development.
 Heavily commented for the user to be able to understand easily.
 */

#include <assert.h>

namespace odm
{
	struct Vector2f
	{
	public:
		union
		{
			struct
			{
				float x,
					y;
			};

			struct
			{
				float fVal[2];
			};
		};


		/**
		 * Ctor.
		 * Inializes all coord to 0.
		*/
		__forceinline Vector2f();


		/**
		 * Constructs from anther vector.
		 * @param v Takes in another vector to copy coords value.
		*/
		__forceinline Vector2f(const Vector2f& v);


		/**
		 * Constructs from single float argument.
		 * @param f Initial value for XYZ coord.
		*/
		__forceinline explicit Vector2f(float f);


		/**
		 * Constructs from three float arguments.
		 * @param x Initial value for X coord.
		 * @param y Initial value for Y coord.
		 * @param z Initial value for Z coord.
		*/
		__forceinline explicit Vector2f(float x, float y);

		/** dtor */
		__forceinline ~Vector2f() = default;

	public:
		// --- SETTERS ---

		/**
		 * Sets the x coord of the vector.
		 * @param value to be set to the coord.
		*/
		__forceinline void SetX(float value) { x = value; }


		/**
		 * Sets the x coord of the vector.
		 * @param value to be set to the coord.
		*/
		__forceinline void SetY(float value) { y = value; }

	public:
		// --- GETTERS ---

		/** Gets the value x coord of the vector. */
		__forceinline float GetX() { return x; }

		/** Gets the value x coord of the vector. */
		__forceinline float GetY() { return y; }

	public:
		// --- OPERATORS ---

		/**
		 * Checks if two vectors are equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline bool operator==(const Vector2f& v) const;

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline bool operator!=(const Vector2f& v) const;

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline Vector2f operator+(const Vector2f& v);

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline Vector2f operator-(const Vector2f& v);

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline Vector2f operator*(const Vector2f& v);

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline Vector2f operator/(const Vector2f& v);

		__forceinline Vector2f operator+(const float f);
		__forceinline Vector2f operator-(const float f);
		__forceinline Vector2f operator*(const float f);

		/**
		 * Checks if two vectors are not equal.
		 * @param v Vector to be compared with.
		*/
		__forceinline Vector2f operator/(const float f);

	};

	typedef Vector2f vec2;
	typedef Vector2f vec2f;

	__forceinline Vector2f::Vector2f()
	{
		x = y = 0;
	}

	__forceinline Vector2f::Vector2f(const Vector2f& v)
		: x(v.x), y(v.y)
	{}

	__forceinline Vector2f::Vector2f(float f)
		: x(f), y(f)
	{}

	__forceinline Vector2f::Vector2f(float x, float y)
		: x(x), y(y)
	{}

	__forceinline bool Vector2f::operator==(const Vector2f& v) const
	{
		return (x == v.x && y == v.y);
	}

	__forceinline bool Vector2f::operator!=(const Vector2f& v) const
	{
		return !(*this == v);
	}

	__forceinline Vector2f Vector2f::operator+(const Vector2f& v)
	{
		return Vector2f(
			x + v.x,
			y + v.y
		);
	}

	__forceinline Vector2f Vector2f::operator-(const Vector2f& v)
	{
		return Vector2f(
			x - v.x,
			y - v.y
		);
	}

	__forceinline Vector2f Vector2f::operator*(const Vector2f& v)
	{
		return Vector2f(
			x * v.x,
			y * v.y
		);
	}

	__forceinline Vector2f Vector2f::operator/(const Vector2f& v)
	{
		return Vector2f(
			x / v.x,
			y / v.y
		);
	}

	__forceinline Vector2f Vector2f::operator+(const float f)
	{
		return Vector2f(
			x + f,
			y + f
		);
	}

	__forceinline Vector2f Vector2f::operator-(const float f)
	{
		return Vector2f(
			x - f,
			y - f
		);
	}

	__forceinline Vector2f Vector2f::operator*(const float f)
	{
		return Vector2f(
			x * f,
			y * f
		);
	}

	__forceinline Vector2f Vector2f::operator/(const float f)
	{
		assert(f != 0);
		return Vector2f(
			x / f,
			y / f
		);
	}
}