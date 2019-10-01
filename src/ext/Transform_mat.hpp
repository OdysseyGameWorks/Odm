#pragma once

// Author - Odyssey.
// Specially developed maths library of game development.
// Heavily commented for the user to be able to understand easily.

#include "../Mat4x4.hpp"

namespace odm
{
	/**
	 * Builds a translation 4x4 matrix created from vector of 3 components.
	 * @param m Input matrix multiplied by this translation matrix.
	 * @parma v Coords of a translation Vector.
	*/
	__forceinline Matrix4x4 translate(const Matrix4x4& m, const Vector3f& v);

	/**
	 * Builds a rotation 4x4 matrix created from vector of 3 components.
	 * @param m Input matrix multiplied by this rotation matrix.
	 * @parma angle Rotation angle expressed in radians.
	 * @param v Rotation axis recommended to be normalized.
	*/
	__forceinline Matrix4x4 rotate(const Matrix4x4& m, const float angle, const Vector3f& v);


	/**
	 * Builds a scale 4x4 matrix created from vector of 3 scalars.
	 * @param m Input matrix multiplied by this scale matrix.
	 * @parma v Ratio of scaling for each axis.
	*/
	__forceinline Matrix4x4 scale(const Matrix4x4& m, const Vector3f& v);

	/**
	 * Builds a look at view matrix based on the default handedness.
	 * @param eye Position of the camera
	 * @param center Position where the camera is looking at
	 * @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
	*/
	__forceinline Matrix4x4 lookAt(const Vector3f& eye, const Vector3f& center, const Vector3f& up = Vector3f::Up);

	[[nodiscard]] __forceinline Vector3f getPosition(const Matrix4x4& transform);
}

#include "Transform_mat.inl"
