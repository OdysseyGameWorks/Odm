#pragma once

#ifndef _VIEW_MAT_H_
#define _VIEW_MAT_H_

#include "../Mat4x4.h"

namespace odm
{
	/**
	 * Creates a perspective view matrix.
	 * @param fov Takes in the field of view of the perspective.
	 * @param aspectRatio Takes in the aspect ratio of the screen.
	 * @param nearPlane Takes in the near plane of the perspective frustum.
	 * @param farPlane Takes in the far plane of the perspective frustum.
	 * @return Perspective matrix.
	 */
	inline Matrix4x4 perspective(float fov, float aspectRatio, float nearPlane = 100.0f, float farPlane = 0.1f);

	/**
	 * Creates a orthographic view matrix.
	 * @param left Takes in the normalized left side of the orthographic view.
	 * @param right Takes in the normalized right side of the orthographic view.
	 * @param top Takes in the normalized top side of the orthographic view.
	 * @param bottom Takes in the normalized bottom side of the orthographic view.
	 * @param nearPlane Takes in the normalized near plane of the orthographic frustum.
	 * @param farPlane Takes in the normalized far plane of the orthographic frustum.
	 * @return Perspective matrix.
	 */
	inline Matrix4x4 orthographic(float left, float right, float top, float bottom, float nearPlane, float farPlane);

}

#else
#error View Matrix header had already been included.
#endif

#include "View_mat.inl"
