#pragma once

#include "Vector2f.hpp"
#include "Vector3f.hpp"
#include "Vector4f.hpp"
#include "Mat4x4.hpp"

namespace odm
{
	__forceinline static const float* value_ptr(const Vector2f& v);
	__forceinline static const float* value_ptr(const Vector3f& v);
	__forceinline static const float* value_ptr(const Vector4f& v);
	__forceinline static const float* value_ptr(const Matrix4x4& m);
}

#include "value_ptr.inl"