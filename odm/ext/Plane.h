#pragma once

#include "../Vector3f.h"

namespace odm
{
	struct Plane
	{
		Vector3f	normal;
		float		d;

		FINLINE Plane();
		FINLINE Plane(const Plane& p) = default;
		FINLINE Plane(float nX, float nY, float nZ, float distance);
		FINLINE Plane(const Vector3f& normal, float distance);
		FINLINE Plane(const Vector3f& point, const Vector3f& normal);
		FINLINE Plane(const Vector3f& p0, const Vector3f& p1, const Vector3f& p2);

		void SetNormal(const Vector3f& _normal) { normal = _normal; }
		NODISCARD FINLINE vec3f GetNormal() const { return normal; }

		void Normalize();
		NODISCARD FINLINE Plane Normalized() const;

		NODISCARD Vector3f Center() const { return normal * d; }
		NODISCARD FINLINE float Distance(const Vector3f& point) const;
		NODISCARD FINLINE bool Contains(const Vector3f& point, float tolerance = SMALL_NUMBER) const;

		bool Intersects3(const Plane& plane1, const Plane& plane2, Vector3f* result = nullptr) const;
		bool Intersects2(const Plane& plane1, Vector3f* intersection = nullptr, Vector3f* d = nullptr) const;
		bool IntersectsLine(const Vector3f& begin, const Vector3f& end, Vector3f* intersection) const;
		
		NODISCARD Vector3f Project(const Vector3f& point) const;

		Plane operator-() const { return Plane(-normal, -d); }
		NODISCARD bool IsEqual(const Plane& plane, float tolerance = SMALL_NUMBER) const;
		
		FINLINE bool operator==(const Plane& plane) const;
		FINLINE bool operator!=(const Plane& plane) const;
	};

	inline Plane::Plane()
		: d(0) {}

	inline Plane::Plane(float nX, float nY, float nZ, float distance)
		: normal({nX, nY, nZ}), d(distance) {}

	inline Plane::Plane(const Vector3f& normal, float distance)
		: normal(normal), d(distance) {}

	inline Plane::Plane(const Vector3f& point, const Vector3f& normal)
		: normal(normal), d(-point.Dot(normal)) {}

	inline Plane::Plane(const Vector3f& p0, const Vector3f& p1, const Vector3f& p2)
	{
		normal = (p1 - p0).Cross(p2 - p0).Normalize();
		d = -p0.Dot(normal);
	}

	inline void Plane::Normalize()
	{
		if (normal.Length() <= 0) return;
		const float denominator = 1 / normal.Length();
		normal *= denominator; d *= denominator;
	}

	inline Plane Plane::Normalized() const
	{
		Plane p = *this;
		p.Normalize();
		return p;
	}

	inline float Plane::Distance(const Vector3f& point) const
	{
		return (normal.Dot(point) - d);
	}

	inline bool Plane::Contains(const Vector3f& point, float tolerance) const
	{
		return (abs(normal.Dot(point) - d) <= tolerance);
	}

	inline bool Plane::Intersects3(const Plane& plane1, const Plane& plane2, Vector3f* result) const
	{
		const float denominator = Vector3f::Cross(normal, plane1.normal).Dot(plane2.normal);
		if (denominator == 0.0f) return false;
		if (result) {
			*result = ((Vector3f::Cross(plane1.normal, plane2.normal) * d) +
					(Vector3f::Cross(plane2.normal, normal) * plane1.d) +
					(Vector3f::Cross(normal, plane1.normal) * plane2.d)) / denominator;
		}
		return true;
	}

	inline bool Plane::Intersects2(const Plane& plane1, Vector3f* intersection, Vector3f* D) const
	{
		*D = Vector3f::Cross(normal, plane1.normal);
		const float DD = D->LengthSquared();
		if (DD < (0.001f * 0.001f)) { *D = *intersection = Vector3f::Zero; return false; }	
		*intersection = (d * (Vector3f::Cross(normal, *D)) + plane1.d * (Vector3f::Cross(*D, plane1.normal))) / DD; *D = D->Normalize(); return true;
	}

	inline bool Plane::IntersectsLine(const Vector3f& begin, const Vector3f& end, Vector3f* intersection) const
	{
		const Vector3f segment = begin - end;
		const float den = normal.Dot(segment);

		if (den == 0) return false;

		float dist = (normal.Dot(begin) - d) / den;
		if (dist < -SMALL_NUMBER || dist >(1.0 + SMALL_NUMBER))  return false;

		dist = -dist; *intersection = begin + segment * dist;
		return true;
	}

	inline Vector3f Plane::Project(const Vector3f& point) const
	{
		return point - normal * Distance(point);
	}

	inline bool Plane::IsEqual(const Plane& plane, float tolerance) const
	{
		return ((normal - plane.normal).Abs() <= tolerance) && (abs(d - plane.d) <= tolerance);
	}

	inline bool Plane::operator==(const Plane& plane) const
	{
		return normal == plane.normal && d == plane.d;
	}

	inline bool Plane::operator!=(const Plane& plane) const
	{
		return !(*this == plane);
	}

}
