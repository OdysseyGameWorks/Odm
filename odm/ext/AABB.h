#pragma once

#ifndef AABB_H
#define AABB_H

#include "../Mat4x4.h"
#include "../Vector4f.h"
#include "Rectangle.h"

#include <cmath>
#include <cstdlib>


namespace odm
{
	struct Rectangle;

	// Axis-aligned bounding box
	struct AABB
	{
		static const size_t CORNER_COUNT = 8;

		vec3 min;
		vec3 max;

		AABB();
		AABB(const Rectangle& rectangle);
		AABB(const vec2& min, const vec2& max);
		AABB(const vec3& min, const vec3& max);
		AABB(float x, float y, float width, float height);
		AABB(float x, float y, float z, float width, float height, float depth);

		NODISCARD bool Intersects(const AABB& other) const;
		NODISCARD bool Contains(const vec2& point, float tolerance = 0.0f) const;
		NODISCARD bool Contains(const vec3& point, float tolerance = 0.0f) const;

		void Add(const AABB& bb);
		void ClipToBox(AABB const& bb);

		NODISCARD AABB TransformToAABB(const Matrix4x4& transform) const;

		NODISCARD vec3 GetSize() const;
		NODISCARD vec3 GetExtents() const;	// Distance from the center to each side.
		NODISCARD vec3 Center() const;		// Center of the box.

		NODISCARD vec3 GetMin() const;
		NODISCARD vec3 GetMax() const;

		NODISCARD int LargestAxis() const;
		
		bool operator==(const AABB& other) const;
		bool operator!=(const AABB& other) const;

		bool operator<(const AABB& other) const;
		bool operator>(const AABB& other) const;
	};

	inline AABB::AABB()
		: min(vec3()), max(vec3())
	{}

	inline AABB::AABB(const Rectangle& rectangle)
		: min(rectangle.GetMinimumBound()), max(rectangle.GetMaximumBound())
	{}

	inline AABB::AABB(const vec2& min, const vec2& max)
		: min(vec3(min)), max(vec3(max))
	{}

	inline AABB::AABB(const vec3& min, const vec3& max)
		: min(min), max(max)
	{}

	inline AABB::AABB(float x, float y, float width, float height)
		: min(vec3(x, y, 0.0f)), max(vec3(width, height, 0.0f))
	{}

	inline AABB::AABB(float x, float y, float z, float width, float height, float depth)
		: min(vec3(x, y, z)), max(vec3(width, height, depth))
	{}

	inline bool AABB::Intersects(const AABB& other) const {
		return (max > other.min && min < other.max) || (min > other.max && max < other.min);
	}

	inline bool AABB::Contains(const vec2& point, float tolerance) const {
		return point + tolerance > min && point - tolerance < max;
	}

	inline bool AABB::Contains(const vec3& point, float tolerance) const {
		return point + tolerance > min && point - tolerance < max;
	}

	inline void AABB::Add(const AABB& bb)
	{
		min = Vector3f::Min(min, bb.min);
		max = Vector3f::Max(max, bb.max);
	}

	inline void AABB::ClipToBox(AABB const& bb)
	{
		min = Vector3f::Max(min, bb.min);
		max = Vector3f::Min(max, bb.max);
	}

	inline AABB AABB::TransformToAABB(const Matrix4x4& transform) const
	{
		return AABB(
			(transform * Center()) - vec3 (
			(abs(transform.m[0][0]) * (GetSize() * 0.5f).x) + (abs(transform.m[0][1]) * (GetSize() * 0.5f).y) + (abs(transform.m[0][2]) * (GetSize() * 0.5f).z),
			(abs(transform.m[1][0]) * (GetSize() * 0.5f).x) + (abs(transform.m[1][1]) * (GetSize() * 0.5f).y) + (abs(transform.m[1][2]) * (GetSize() * 0.5f).z),
			(abs(transform.m[2][0]) * (GetSize() * 0.5f).x) + (abs(transform.m[2][1]) * (GetSize() * 0.5f).y) + (abs(transform.m[2][2]) * (GetSize() * 0.5f).z)
			),

			(transform * Center()) + 
			vec3(
			(abs(transform.m[0][0]) * (GetSize() * 0.5f).x) + (abs(transform.m[0][1]) * (GetSize() * 0.5f).y) + (abs(transform.m[0][2]) * (GetSize() * 0.5f).z),
			(abs(transform.m[1][0]) * (GetSize() * 0.5f).x) + (abs(transform.m[1][1]) * (GetSize() * 0.5f).y) + (abs(transform.m[1][2]) * (GetSize() * 0.5f).z),
			(abs(transform.m[2][0]) * (GetSize() * 0.5f).x) + (abs(transform.m[2][1]) * (GetSize() * 0.5f).y) + (abs(transform.m[2][2]) * (GetSize() * 0.5f).z)
		));
	}

	inline vec3 AABB::GetSize() const
	{
		return max - min;
	}

	inline vec3 AABB::GetExtents() const {
		return (max - min) * 0.5f;
	}

	inline vec3 AABB::Center() const {
		return (max + min) * 0.5f;
	}

	inline vec3 AABB::GetMin() const
	{
		return min;
	}

	inline vec3 AABB::GetMax() const
	{
		return max;
	}

	inline int AABB::LargestAxis() const
	{
		return MathF::Max3(GetExtents().x, GetExtents().y, GetExtents().z);
	}

	inline bool AABB::operator==(const AABB& other) const {
		return min == other.min && max == other.max;
	}

	inline bool AABB::operator!=(const AABB& other) const {
		return !(*this == other);
	}

	inline bool AABB::operator<(const AABB& other) const {
		return max < other.min;
	}

	inline bool AABB::operator>(const AABB& other) const {
		return min > other.max;
	}
}

#endif /* end of include guard: AABB_H */
