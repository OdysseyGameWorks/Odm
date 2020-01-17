#pragma once

#ifndef _MAT4_H
#define _MAT4_H

#include <cassert>
#include "Vector4f.h"

namespace odm
{
	struct Matrix4x4
	{
		union {
			Vector4f m[4];
			float elem[4 * 4];
		};
	
		/**
		 * Constructs a 4x4 matrix.
		 * Initializes all the elements to 0.
		 */
		inline Matrix4x4();
	
		/**
		 * Constructs a 4x4 matrix.
		 * @param InX Sets the values of first col elements.
		 * @param InY Sets the values of second col elements.
		 * @param InZ Sets the values of third col elements.
		 * @param InW Sets the values of fourth col elements.
		 */
		inline Matrix4x4(const Vector3f &InX, const Vector3f &InY, const Vector3f &InZ, const Vector3f &InW);
	
		/**
		 * Constructs by copying 4x4 matrix.
		 * @param mat The matrix from which the value is to be copied
		 */
		inline Matrix4x4(const Matrix4x4 &mat);
	
		/**
		 * Constructs by copying 4x4 matrix.
		 * @param f sets the diagonal values to f
		 */
		inline Matrix4x4(float f);
	
		/**
		 * Constructs a 4x4 matrix.
		 * Initializes all the elements according to arguments.
		 */
		inline Matrix4x4(
			float x0, float y0, float z0, float w0,
			float x1, float y1, float z1, float w1,
			float x2, float y2, float z2, float w2,
			float x3, float y3, float z3, float w3);
	
		/** Default Destructor. */
		~Matrix4x4() = default;
	
	
		inline void SetIdentity();
		inline Matrix4x4 Transpose() const;
		inline static Matrix4x4 Transpose(const Matrix4x4 &mat);
		inline Matrix4x4 Inverse();
			
		inline Vector4f &operator[](int colIndex);
		inline Vector4f operator[](int colIndex) const;
	
		inline Matrix4x4 operator*(const Matrix4x4 &mat) const;
		inline Matrix4x4& operator*=(const Matrix4x4 &mat);

		inline vec3 operator*(const vec3 &v) const;
		inline vec4 operator*(const vec4 &v) const;
		
		inline void operator=(const Matrix4x4 &mat);

	};

	
	using mat4 = Matrix4x4;
	using mat4x4 = Matrix4x4;

	inline Vector4f &Matrix4x4::operator[](int colIndex)
	{
		assert(colIndex >= 0 && colIndex < 4);
		return m[colIndex];
	}
	
	inline Vector4f Matrix4x4::operator[](int colIndex) const
	{
		assert(colIndex >= 0 && colIndex < 4);
		return m[colIndex];
	}
	
	inline void Matrix4x4::operator=(const Matrix4x4 &mat)
	{
		m[0] = vec4(mat[0]);
		m[1] = vec4(mat[1]);
		m[2] = vec4(mat[2]);
		m[3] = vec4(mat[3]);
	}

} // namespace odm

#else
#error Matrix4x4 header had already been included
#endif

#include "Mat4x4.inl"
