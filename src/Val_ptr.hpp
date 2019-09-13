#pragma once

#include "Vector2f.hpp"
#include "Vector3f.hpp"
#include "Vector4f.hpp"
#include "Mat4x4.hpp"

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
