#pragma once

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

	Matrix4x4 perspective(float fov, float aspectRatio, float nearPlane, float farPlane)
	{
		Matrix4x4 Result(0.0f);
		float const tanHalfFovy = tan(fov / static_cast<float>(2));
		Result[0][0] = static_cast<float>(1) / (aspectRatio * tanHalfFovy);
		Result[1][1] = static_cast<float>(1) / (tanHalfFovy);
		Result[2][2] = -(farPlane + nearPlane) / (farPlane - nearPlane);
		Result[2][3] = -static_cast<float>(1);
		Result[3][2] = -(static_cast<float>(2) * farPlane * nearPlane) / (farPlane - nearPlane);
		return Result;
	}
}
