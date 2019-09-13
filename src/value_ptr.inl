#include "Val_ptr.hpp"
#pragma once

namespace odm
{
	static const float* value_ptr(const Vector2f& v)
	{
		return &(v.x);
	}

	static const float* value_ptr(const Vector3f& v)
	{
		return &(v.x);
	}

	static const float* value_ptr(const Vector4f& v)
	{
		return &(v.x);
	}

	static const float* value_ptr(const Matrix4x4& mat)
	{
		const float* fl = &(mat.m[0].x);
		return fl;
	}
}