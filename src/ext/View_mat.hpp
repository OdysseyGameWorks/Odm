#pragma once

/*
 Author - Odyssey.
 Specially developed maths library of game development.
 Heavily commented for the user to be able to understand easily.
 */


#ifndef _VIEW_MAT_H_
#define _VIEW_MAT_H_

#include "../Mat4x4.hpp"

namespace odm
{
	/**
	 * Creates a perspective view matrix.
	 * @param _fov Takes in the field of view of the perspective.
	 * @param aspectRatio Takes in the aspect ratio of the screen.
	 * @param nearPlane Takes in the near plane of the perspective frustum.
	 * @param farPlane Takes in the far plane of the perspective frustum.
	*/
	__forceinline Matrix4x4 perspective(float _fov, float aspectRatio, float nearPlane, float farPlane);


	/**
	 * Creates a orthographic view matrix.
	 * @param left Takes in the normalized left side of the orthographic view.
	 * @param right Takes in the normalized right side of the orthographic view.
	 * @param top Takes in the normalized top side of the orthographic view.
	 * @param bottom Takes in the normalized bottom side of the orthographic view.
	 * @param bottom Takes in the normalized near plane of the orthographic frustum.
	 * @param bottom Takes in the normalized far plane of the orthographic frustum.
	*/
	__forceinline Matrix4x4 orthographic(float left, float right, float top, float bottom, float nearPlane, float farPlane);

}

#else
#error View Matrix header had already been included.
#endif

#include "View_mat.inl"
