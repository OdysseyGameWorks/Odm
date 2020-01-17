#pragma once

#include <cassert>
#include "Vector3f.h"

namespace odm
{
	struct Vector2f
	{
		union
		{
			struct
			{
				float x;
				float y;
			};
			float fVal[2]{};
		};


		/**
		 * Constructs a 2D vector.
		 * Initializes all coord to 0.
		*/
		Vector2f();

		/**
		 * Constructs from another vector.
		 * @param v Takes in another vector to copy coords value.
		*/
		Vector2f(const Vector2f& v);

		/**
		 * Constructs from single float argument.
		 * @param f Initial value for XYZ coord.
		*/
		Vector2f(float f);

		/**
		 * Constructs from two float arguments.
		 * @param x Initial value for X coord.
		 * @param y Initial value for Y coord.
		*/
		Vector2f(float x, float y);

		/**
		 * Constructs from a 3D vector.
		 * @param v Takes in another vector to copy coords value.
		*/
		Vector2f(const Vector3f& v);

		/** Default Destructor. */
		~Vector2f() = default;



		bool operator==(const Vector2f& v) const;
		bool operator!=(const Vector2f& v) const;
		bool operator<(const Vector2f& v) const;
		bool operator>(const Vector2f& v) const;
		bool operator>=(const Vector2f& v) const;
		bool operator<=(const Vector2f& v) const;
		bool operator<(float f) const;
		bool operator>(float f) const;
		bool operator>=(float f) const;
		bool operator<=(float f) const;

		Vector2f operator+(const Vector2f& v) const;
		Vector2f operator-(const Vector2f& v) const;
		Vector2f operator*(const Vector2f& v) const;
		Vector2f operator/(const Vector2f& v) const;

		Vector2f operator+(float f) const;
		Vector2f operator-(float f) const;
		Vector2f operator*(float f) const;
		Vector2f operator/(float f) const;
		
		void operator-();
	};

	typedef Vector2f vec2;
	typedef Vector2f vec2f;

	inline Vector2f::Vector2f() {
		x = y = 0;
	}

	inline Vector2f::Vector2f(const Vector2f& v)
		: x(v.x), y(v.y)
	{}

	inline Vector2f::Vector2f(float f)
		: x(f), y(f)
	{}

	inline Vector2f::Vector2f(float x, float y)
		: x(x), y(y)
	{}

	inline Vector2f::Vector2f(const Vector3f & v)
		: x(v.x), y(v.y)
	{}

	inline bool Vector2f::operator==(const Vector2f& v) const
	{
		return (x == v.x && y == v.y);
	}

	inline bool Vector2f::operator!=(const Vector2f& v) const
	{
		return !(*this == v);
	}

	inline bool Vector2f::operator<(const Vector2f& v) const
	{
		return (x < v.x && 
				y < v.y);
	}

	inline bool Vector2f::operator>(const Vector2f& v) const
	{
		return (x > v.x &&
				y > v.y);
	}

	inline bool Vector2f::operator>=(const Vector2f& v) const
	{
		return (x >= v.x &&
				y >= v.y);
	}

	inline bool Vector2f::operator<=(const Vector2f& v) const
	{
		return (x <= v.x &&
				y <= v.y);
	}

	inline bool Vector2f::operator<(float f) const
	{
		return (x < f &&
				y < f);
	}

	inline bool Vector2f::operator>(float f) const
	{
		return (x > f &&
				y > f);
	}

	inline bool Vector2f::operator>=(float f) const
	{
		return (x >= f &&
				y >= f);
	}

	inline bool Vector2f::operator<=(float f) const
	{
		return (x <= f &&
				y <= f);
	}

	inline Vector2f Vector2f::operator+(const Vector2f& v) const
	{
		return Vector2f(
			x + v.x,
			y + v.y
		);
	}

	inline Vector2f Vector2f::operator-(const Vector2f& v) const
	{
		return Vector2f(
			x - v.x,
			y - v.y
		);
	}

	inline Vector2f Vector2f::operator*(const Vector2f& v) const
	{
		return Vector2f(
			x * v.x,
			y * v.y
		);
	}

	inline Vector2f Vector2f::operator/(const Vector2f& v) const
	{
		return Vector2f(
			x / v.x,
			y / v.y
		);
	}

	inline Vector2f Vector2f::operator+(const float f) const
	{
		return Vector2f(
			x + f,
			y + f
		);
	}

	inline Vector2f Vector2f::operator-(const float f) const
	{
		return Vector2f(
			x - f,
			y - f
		);
	}

	inline Vector2f Vector2f::operator*(const float f) const
	{
		return Vector2f(
			x * f,
			y * f
		);
	}

	inline Vector2f Vector2f::operator/(const float f) const
	{
		assert(f != 0);
		return Vector2f(
			x / f,
			y / f
		);
	}
}