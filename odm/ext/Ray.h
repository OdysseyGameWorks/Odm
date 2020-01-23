#pragma once

#include "../Vector3f.h"
#include "AABB.h"

namespace odm
{
	class Ray
	{
	public:
		Ray() = default;
		Ray(const vec3f &start, const vec3f &end);
		~Ray() = default;

		float HitDistance(const AABB& box) const;

		/** Gets the <b>starting position</b> of this ray. */
		const vec3f &GetStart() const { return m_Start; }

		/** Gets the <b>end position</b> of this ray. */
		const vec3f &GetEnd() const { return m_End; }

		/** Gets the <b>length</b> of this ray. */
		const float &GetLength() const { return m_Length; }

		/** Gets the <b>direction</b> of this ray. */
		const vec3f &GetDirection() const { return m_Direction; }

	private:
		vec3f m_Start;
		vec3f m_End;
		vec3f m_Direction;
		
		float m_Length;
	};
}