#pragma once

#ifndef AABB_H
#define AABB_H

#include "../Vector2f.h"
#include "../Vector3f.h"

#include <cmath>

#include "Rectangle.h"
#include "../Mat4x4.h"

namespace odm
{
	struct Rectangle;
	struct AABB
	{
		vec3 min;
		vec3 max;

		AABB();
		AABB(const Rectangle& rectangle);
		AABB(const vec2& min, const vec2& max);
		AABB(const vec3& min, const vec3& max);
		AABB(float x, float y, float width, float height);
		AABB(float x, float y, float z, float width, float height, float depth);

		bool Intersects(const AABB& other) const;
		bool Contains(const vec2& point, float tolerance = 0.0f) const;
		bool Contains(const vec3& point, float tolerance = 0.0f) const;


		AABB TransformToAABB(const Matrix4x4& transform) const;

		vec3 GetSize() const;
		vec3 GetExtents() const;
		vec3 Center() const;

		vec3 GetMin() const;
		vec3 GetMax() const;

		int LargestAxis() const;
		
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
		return vec3(point) > min && vec3(point) < max;
	}

	inline bool AABB::Contains(const vec3& point, float tolerance) const {
		return point + tolerance > min && point - tolerance < max;
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
