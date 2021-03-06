#pragma once

#include "../Mat4x4.h"

namespace odm
{
	/**
	 * Builds a translation 4x4 matrix created from vector of 3 components.
	 * @param m Input matrix multiplied by this translation matrix.
	 * @param v Coordinates of a translation Vector.
	*/
	NODISCARD inline Matrix4x4 translate(const Matrix4x4 &m, const Vector3f &v);

	/**
	 * Builds a rotation 4x4 matrix created from vector of 3 components.
	 * @param m Input matrix multiplied by this rotation matrix.
	 * @param angle Rotation angle expressed in radians.
	 * @param v Rotation axis recommended to be normalized.
	 */
	NODISCARD inline Matrix4x4 rotate(const Matrix4x4 &m, float angle, const Vector3f &v);

	/**
	 * Builds a scale 4x4 matrix created from vector of 3 scalars.
	 * @param m Input matrix multiplied by this scale matrix.
	 * @param v Ratio of scaling for each axis.
	 */
	NODISCARD inline Matrix4x4 scale(const Matrix4x4& m, const Vector3f& v);

	/**
	 * Builds a look at view matrix based on the default handedness.
	 * @param eye Position of the camera
	 * @param center Position where the camera is looking at
	 * @param up Normalized up vector, how the camera is oriented. Typically (0, 0, 1)
	 */
	NODISCARD inline Matrix4x4 lookAt(const Vector3f &eye, const Vector3f &center, const Vector3f &up = Vector3f::Up);

	/**
	 * Gets the position vector from the Transformation matrix.
	 * @param mat Input matrix multiplied by this position matrix.
	 * @param position Position to be applied to matrix.
	 */
	NODISCARD inline Matrix4x4 setPosition(const Matrix4x4 &mat, const vec3f &position);

	/**
	 * Gets the position vector from the Transformation matrix.
	 * @param transform Takes the transform matrix.
	 * @returns Vector3 position form the transform matrix.
	 */
	NODISCARD inline Vector3f getPosition(const Matrix4x4 &transform);
}

#include "Transform_mat.inl"
