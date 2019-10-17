#include "Mat4x4.hpp"
#pragma once

namespace odm
{
	// --- Constructors ---

	__forceinline Matrix4x4::Matrix4x4()
	{
		SetIdentity();
	}

	__forceinline Matrix4x4::Matrix4x4(const Matrix4x4& mat)
	{
		m[0] = Vector4f(mat[0]);
		m[1] = Vector4f(mat[1]);
		m[2] = Vector4f(mat[2]);
		m[3] = Vector4f(mat[3]);
	}

	__forceinline Matrix4x4::Matrix4x4(const float f)
	{
		m[0] = Vector4f(f, 0, 0, 0);
		m[1] = Vector4f(0, f, 0, 0);
		m[2] = Vector4f(0, 0, f, 0);
		m[3] = Vector4f(0, 0, 0, f);
	}

	__forceinline Matrix4x4::Matrix4x4(const Vector3f& InX, const Vector3f& InY, const Vector3f& InZ, const Vector3f& InW)
	{

	}


	__forceinline Matrix4x4::Matrix4x4(
		float x0, float y0, float z0, float w0,
		float x1, float y1, float z1, float w1,
		float x2, float y2, float z2, float w2,
		float x3, float y3, float z3, float w3)
	{
		m[0] = Vector4f(x0, x1, x2, x3);
		m[1] = Vector4f(y0, y1, y2, y3);
		m[2] = Vector4f(z0, z1, z2, z3);
		m[3] = Vector4f(z0, z1, z2, z3);
	}

	// --- Methods ---

	__forceinline void Matrix4x4::SetIdentity()
	{
		m[0] = Vector4f(1, 0, 0, 0);
		m[1] = Vector4f(0, 1, 0, 0);
		m[2] = Vector4f(0, 0, 1, 0);
		m[3] = Vector4f(0, 0, 0, 1);
	}

	__forceinline Matrix4x4 Matrix4x4::Transpose() const
	{
		Matrix4x4 result;

		for (int col = 0; col < 3; ++col){
			for (int row = 0; row < 3; ++row)
			{
				result[col][row] = m[row][col];
			}
		}
		return result;
	}

	__forceinline Matrix4x4 Matrix4x4::Transpose(const Matrix4x4& mat)
	{
		return mat.Transpose();
	}
	
	__forceinline Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat) const
	{
		vec4 const SrcA0 = m[0];
		vec4 const SrcA1 = m[1];
		vec4 const SrcA2 = m[2];
		vec4 const SrcA3 = m[3];

		vec4 const SrcB0 = mat[0];
		vec4 const SrcB1 = mat[1];
		vec4 const SrcB2 = mat[2];
		vec4 const SrcB3 = mat[3];

		Matrix4x4 Result;
		Result[0] = SrcA0 * SrcB0[0] + SrcA1 * SrcB0[1] + SrcA2 * SrcB0[2] + SrcA3 * SrcB0[3];
		Result[1] = SrcA0 * SrcB1[0] + SrcA1 * SrcB1[1] + SrcA2 * SrcB1[2] + SrcA3 * SrcB1[3];
		Result[2] = SrcA0 * SrcB2[0] + SrcA1 * SrcB2[1] + SrcA2 * SrcB2[2] + SrcA3 * SrcB2[3];
		Result[3] = SrcA0 * SrcB3[0] + SrcA1 * SrcB3[1] + SrcA2 * SrcB3[2] + SrcA3 * SrcB3[3];
		return Result;
	}

}