#pragma once

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

#include "Transform_mat.hpp"

namespace odm
{
	/**
	 * Builds a translation 4x4 matrix created from vector of 3 components.
	 * @parma v Coords of a translation Vector.
	*/
	__forceinline static Matrix4x4 translate(const Vector3f& v);


	/**
	 * Builds a rotation 4x4 matrix created from vector of 3 components.
	 * @parma angle Rotation angle expressed in radians.
	 * @param axis Rotation axis recommended to be normalized.
	*/
	__forceinline static Matrix4x4 rotate(float angle, const Vector3f& v);


	/**
	 * Builds a scale 4x4 matrix created from vector of 3 scalars.
	 * @parma v Ratio of scaling for each axis.
	*/
	__forceinline static Matrix4x4 scale(const Vector3f& v);

}

#else
#error Transform header had already been included
#endif

#include "Transform.inl"
