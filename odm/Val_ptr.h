#pragma once

#include "Vector2f.h"
#include "Vector3f.h"
#include "Vector4f.h"
#include "Mat4x4.h"

namespace odm
{
	/**
	 * Pointer to the vector 2 value
	 * @param v The vector whose value is to be pointed
	 * @return Float pointer to the vector elem
	*/
	__forceinline static const float* value_ptr(const Vector2f& v);
	
	/**
	 * Pointer to the vector 3 value
	 * @param v The vector whose value is to be pointed
	 * @return Float pointer to the vector elem
	*/
	__forceinline static const float* value_ptr(const Vector3f& v);
	
	/**
	 * Pointer to the vector 4 value
	 * @param v The vector whose value is to be pointed
	 * @return Float pointer to the vector elem
	*/
	__forceinline static const float* value_ptr(const Vector4f& v);
	
	/**
	 * Pointer to the matrix 4x4 value
	 * @param v The vector whose value is to be pointed
	 * @return Float pointer to the vector elem
	*/
	__forceinline static const float* value_ptr(const Matrix4x4& m);
}

#include "value_ptr.inl"
