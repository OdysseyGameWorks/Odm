#pragma once

#ifndef _VEC3_H
#define _VEC3_H

#include <cassert>
#include "MathUtil.h"

namespace odm
{
	struct Vector2f;

	struct Vector3f
	{
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float FElement[3];
		};


		/**
		 * Constructs a vector.
		 * Initializes all coordinates to 0.
		 */
		Vector3f();

		/**
		 * Constructs from anther vector.
		 * @param v Takes in another vector to copy coordinate values.
		 */
		Vector3f(const Vector3f& v) = default;

		/**
		 * Constructs from three float arguments.
		 * @param x Initial value for X coordinate.
		 * @param y Initial value for Y coordinate.
		 * @param z Initial value for Z coordinate.
		 */
		Vector3f(float x, float y, float z);

		/**
		 * Constructs from single float argument.
		 * @param f Initial value for X-Y-Z coordinate.
		 */
		explicit Vector3f(float f);

		/**
		 * Constructs from a Vector2 and float.
		 * @param v Vector2 from which the vector3 is to be constructed.
		 * @param z Initial value for z-coordinate.
		 */
		Vector3f(const Vector2f& v, float z);

		/**
		 * Constructs from a Vector2
		 * Sets the z-coordinate to 1
		 * @param v Vector2 from which the vector3 is to be constructed.
		 */
		Vector3f(const Vector2f& v);


		/** Default Destructor */
		~Vector3f() = default;


		/**
		 * Calculates the absolute value of the vector coordinates.
		 * @return Abs value of this Vector.
		 */
		Vector3f Abs() const;

		/**
		 * Returns the length of the vector
		*/
		float Length() const;

		/**
		 * Calculates the distance between two vectors.
		 * @param v Vector from which distance will be calculated.
		 * @return distance between two vectors in float.
		 */
		[[nodiscard]] float Distance(const Vector3f& v) const;

		/**
		 * Calculates the distance between two vectors.
		 * @param v1 Vector from which distance will be calculated.
		 * @param v2 Vector from which distance will be compared.
		 * @return distance between two vectors in float.
		 */
		static float Distance(const Vector3f& v1, const Vector3f& v2);

		/**
		 * Calculates the dot product two vectors.
		 * @param v Vector which would be dot multiplied.
		 * @return dot product between two vectors in Vector3.
		 */
		[[nodiscard]] float Dot(const Vector3f& v) const;

		/**
		 * Calculates the dot product two vectors.
		 * @param v1 Vector which would be dot multiplied.
		 * @param v2 Vector which would be dot multiplied with the vector v.
		 * @return dot product between two vectors in Vector3.
		 */
		static float Dot(const Vector3f& v1, const Vector3f& v2);

		/**
		 * Calculates the cross product two vectors.
		 * @param lhs First vector from v2 will be cross multiplied.
		 * @param rhs Second vector from v1 will be cross multiplied.
		 * @return distance between two vectors in Vector3.
		 */
		static Vector3f Cross(const Vector3f& lhs, const Vector3f& rhs);

		/**
		 * Calculates the cross product two vectors.
		 * @param v Vector which would be cross multiplied.
		 * @return distance between two vectors in Vector3.
		 */
		[[nodiscard]] Vector3f __cdecl Cross(const Vector3f& v) const;


		/** Returns the normalized vector. */
		[[nodiscard]] Vector3f __cdecl Normalize() const;

		/** 
		 * Returns the normalized vector.
		 * @param v Vector to be normalized
		 */
		static Vector3f Normalize(const Vector3f& v) { return v.Normalize(); }

		/** Finds the angle between two Vectors. */
		static float Angle(const Vector3f& a, const Vector3f& b);

		Vector3f& operator=(const Vector3f& vec);
		Vector3f operator^(const Vector3f& v) const;

		bool operator==(const Vector3f& v) const;
		bool operator!=(const Vector3f& v) const;

		bool operator>(const Vector3f& v) const;
		bool operator<(const Vector3f& v) const;
		bool operator<=(const Vector3f& v) const;
		bool operator>=(const Vector3f& v) const;
		
		bool operator>(float f) const;
		bool operator<(float f) const;
		bool operator<=(float f) const;
		bool operator>=(float f) const;

		Vector3f operator+(const Vector3f& v) const;
		Vector3f operator-(const Vector3f& v) const;
		Vector3f operator*(const Vector3f& v) const;
		Vector3f operator/(const Vector3f& v) const;

		Vector3f operator+(float f) const;
		Vector3f operator-(float f) const;
		Vector3f operator*(float f) const;
		Vector3f operator/(float f) const;

		Vector3f operator+=(const odm::Vector3f& other);
		Vector3f operator-=(const odm::Vector3f& other);
		Vector3f operator*=(const odm::Vector3f& other);
		Vector3f operator/=(const odm::Vector3f& other);

		Vector3f operator+=(float f);
		Vector3f operator-=(float f);
		Vector3f operator*=(float f);
		Vector3f operator/=(float f);

		float& operator[](int index);
		float operator[](int index) const;
		Vector3f operator-() const;


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

	static Vector3f operator*(float f, const Vector3f& v) { return v * f; }
	static Vector3f operator+(float f, const Vector3f& v) { return v + f; }

	typedef Vector3f vec3;
	typedef Vector3f vec3f;


	inline Vector3f::Vector3f()
	{
		x = y = z = 0;
	}

	inline Vector3f::Vector3f(float f)
	{
		x = y = z = f;
	}

	inline Vector3f::Vector3f(float x, float y, float z)
		: x(x), y(y), z(z)
	{}

	inline vec3 Vector3f::Abs() const
	{
		return vec3(abs(x), abs(y), abs(z));
	}

	inline float Vector3f::Length() const
	{
		return (sqrt(x * x + y * y + z * z));
	}

	inline float Vector3f::Distance(const Vector3f& v) const
	{
		return sqrt((x - v.x * x - v.x) + (y - v.y * y - v.y) + (z - v.z * z - v.z));
	}

	inline float Vector3f::Distance(const Vector3f & v1, const Vector3f & v2)
	{
		return v1.Distance(v2);
	}

	inline float Vector3f::Dot(const Vector3f& v) const
	{
		return (x * v.x + y * v.y + z * v.z);
	}

	inline float Vector3f::Dot(const Vector3f& v1, const Vector3f& v2)
	{
		return v1.Dot(v2);
	}

	inline Vector3f Vector3f::Cross(const Vector3f& lhs, const Vector3f& rhs)
	{
		Vector3f result;

		result.x = lhs.y * rhs.z - rhs.y * lhs.z;
		result.y = lhs.z * rhs.x - rhs.z * lhs.x;
		result.z = lhs.x * rhs.y - rhs.x * lhs.y;

		return result;
	}

	inline Vector3f Vector3f::Cross(const Vector3f& v) const
	{
		return Cross(*this, v);
	}

	inline Vector3f Vector3f::Normalize() const
	{
		const auto length_squared = Length() * Length();
		if (!(length_squared == 1.0f) && length_squared > 0.0f) {
			return (*this) * (1.0f / sqrt(length_squared));
		} return *this;
	}

	inline float Vector3f::Angle(const Vector3f& a, const Vector3f& b)
	{
		return acosf((Dot(a, b) / (a.Length() / b.Length())));
	}

	inline Vector3f& Vector3f::operator=(const Vector3f& vec)
	{
		this->x = vec.x;
		this->y = vec.y;
		this->z = vec.z;
		return *this;
	}

	inline Vector3f Vector3f::operator^(const Vector3f& v) const
	{
		return this->Cross(v);
	}

	inline bool Vector3f::operator==(const Vector3f & v) const
	{
		return (x == v.x && y == v.y && z == v.z);
	}

	inline bool Vector3f::operator!=(const Vector3f& v) const
	{
		return !(*this == v);
	}

	inline bool Vector3f::operator>(const Vector3f& v) const
	{
		return (x > v.x && y > v.y && z > v.z);
	}

	inline bool Vector3f::operator<(const Vector3f& v) const
	{
		return (x < v.x && y < v.y && z < v.z);
	}

	inline bool Vector3f::operator<=(const Vector3f& v) const
	{
		return (x <= v.x && y <= v.y && z <= v.z);
	}

	inline bool Vector3f::operator>=(const Vector3f& v) const
	{
		return (x >= v.x && y >= v.y && z >= v.z);
	}

	inline bool Vector3f::operator>(float f) const
	{
		return (x > f && y > f && z > f);
	}

	inline bool Vector3f::operator<(float f) const
	{
		return (x < f && y < f && z < f);
	}

	inline bool Vector3f::operator<=(float f) const
	{
		return (x <= f && y <= f && z <= f);
	}

	inline bool Vector3f::operator>=(float f) const
	{
		return (x >= f && y >= f && z >= f);
	}

	inline Vector3f Vector3f::operator+(const Vector3f& v) const
	{
		return Vector3f(
			x + v.x,
			y + v.y,
			z + v.z
		);
	}

	inline Vector3f Vector3f::operator-(const Vector3f& v) const
	{
		return Vector3f(
			x - v.x,
			y - v.y,
			z - v.z
		);
	}

	inline Vector3f Vector3f::operator*(const Vector3f& v) const
	{
		return Vector3f(
			x * v.x,
			y * v.y,
			z * v.z
		);
	}

	inline Vector3f Vector3f::operator+(float f) const
	{
		return Vector3f(
			x + f,
			y + f,
			z + f
		);
	}

	inline Vector3f Vector3f::operator-(float f) const
	{
		return Vector3f(
			x - f,
			y - f,
			z - f
		);
	}

	inline Vector3f Vector3f::operator*(float f) const
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

	inline Vector3f Vector3f::operator/(float f) const
	{
		return Vector3f(
			x / f,
			y / f,
			z / f
		);
	}

	inline Vector3f Vector3f::operator+=(const odm::Vector3f& other)
	{
		this->x += other.x;
		this->y += other.y;
		this->z += other.z;
		return *this;
	}

	inline Vector3f Vector3f::operator-=(const odm::Vector3f& other)
	{
		this->x -= other.x;
		this->y -= other.y;
		this->z -= other.z;
		return *this;
	}
	
	inline Vector3f Vector3f::operator*=(const odm::Vector3f& other)
	{
		this->x *= other.x;
		this->y *= other.y;
		this->z *= other.z;
		return *this;
	}

	inline Vector3f Vector3f::operator/=(const odm::Vector3f& other)
	{
		this->x /= other.x;
		this->y /= other.y;
		this->z /= other.z;
		return *this;
	}

	inline Vector3f Vector3f::operator+=(float f)
	{
		this->x += f;
		this->y += f;
		this->z += f;
		return *this;
	}

	inline Vector3f Vector3f::operator-=(float f)
	{
		this->x -= f;
		this->y -= f;
		this->z -= f;
		return *this;
	}

	inline Vector3f Vector3f::operator*=(float f)
	{
		this->x *= f;
		this->y *= f;
		this->z *= f;
		return *this;
	}

	inline Vector3f Vector3f::operator/=(float f)
	{
		this->x /= f;
		this->y /= f;
		this->z /= f;
		return *this;
	}
	
	inline float& Vector3f::operator[](int index)
	{
		assert(index >= 0 && index < 3);
		return (&x)[index];
	}

	inline float Vector3f::operator[](int index) const
	{
		assert(index >= 0 && index < 3);
		return (&x)[index];
	}

	inline Vector3f Vector3f::operator-() const
	{
		return Vector3f(-x, -y, -z);
	}

}

#else
#error Vector3 header had already been included
#endif

