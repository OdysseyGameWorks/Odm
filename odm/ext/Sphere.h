#pragma once
#include "../Vector3f.h"

#pragma omp decl

namespace odm
{
	/** Bounding sphere **/
	struct Sphere
	{
		Vector3f	Center;		// Center of the sphere.
		float		Radius;		// Radius of the sphere.

		Sphere() noexcept : Center(0, 0, 0), Radius(1.f) {}

		Sphere(const Sphere&) = default;
		Sphere& operator=(const Sphere&) = default;

		Sphere(Sphere&&) = default;
		Sphere& operator=(Sphere&&) = default;

		constexpr Sphere(_In_ const Vector3f& center, _In_ float radius)
			: Center(center), Radius(radius) {}

		bool Contains(const Sphere& other, float tolerance = KINDA_SMALL_NUMBER);
		bool Contains(const Vector3f& point, float tolerance = KINDA_SMALL_NUMBER);

	};
}
