#pragma once

#include "../Mat4x4.hpp"
#include "View_mat.hpp"

namespace odm
{
	Matrix4x4 orthographic(float left, float right, float top, float bottom, float nearPlane, float farPlane)
	{
		Matrix4x4 result(1);

		result[0][0] = 2.0f / (right - left);
		result[1][1] = 2.0f / (top - bottom);
		result[2][2] = -2.0f / (farPlane - nearPlane);
		result[3][0] = -(right + left) / (right - left);
		result[3][1] = -(top + bottom) / (top - bottom);
		result[3][2] = -(farPlane + nearPlane) / (farPlane - nearPlane);

		return result;
	}

	Matrix4x4 perspective(float fovy, float aspect, float zNear, float zFar)
	{
		Matrix4x4 Result(0.0f);

		float const tanHalfFovy = tan(fovy / static_cast<float>(2));
		Result[0][0] = static_cast<float>(1) / (aspect * tanHalfFovy);
		Result[1][1] = static_cast<float>(1) / (tanHalfFovy);
		Result[2][2] = -(zFar + zNear) / (zFar - zNear);
		Result[2][3] = -static_cast<float>(1);
		Result[3][2] = -(static_cast<float>(2) * zFar * zNear) / (zFar - zNear);
		
		return Result;
	}
}