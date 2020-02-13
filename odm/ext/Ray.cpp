#include "Ray.h"

namespace odm
{
	Ray::Ray(const vec3f& start, const vec3f& end)
		: m_Start(start), m_End(end), m_Direction(end - start), m_Length(0.0f)
	{
	}

	float Ray::HitDistance(const AABB& box) const
	{
		if (box.Contains(m_Start))
			return 0.0f;

		auto dist = INFINITY;

		if (m_Start.x < box.GetMin().x && m_Direction.x > 0.0f)
		{
			auto x = (box.GetMin().x - m_Start.x) / m_Direction.x;
			if (x < dist)
			{
				const auto point = m_Start + x * m_Direction;
				if (point.y >= box.GetMin().y && point.y <= box.GetMax().y && point.z >= box.GetMin().z && point.z <= box.GetMax().z)
				{
					dist = x;
				}
			}
		}
		if (m_Start.x > box.GetMax().x && m_Direction.x < 0.0f)
		{
			const auto x = (box.GetMax().x - m_Start.x) / m_Direction.x;
			if (x < dist)
			{
				const auto point = m_Start + x * m_Direction;
				if (point.y >= box.GetMin().y && point.y <= box.GetMax().y && point.z >= box.GetMin().z && point.z <= box.GetMax().z)
				{
					dist = x;
				}
			}
		}

		if (m_Start.y < box.GetMin().y && m_Direction.y > 0.0f)
		{
			const auto x = (box.GetMin().y - m_Start.y) / m_Direction.y;
			if (x < dist)
			{
				const auto point = m_Start + x * m_Direction;
				if (point.x >= box.GetMin().x && point.x <= box.GetMax().x && point.z >= box.GetMin().z && point.z <= box.GetMax().z)
				{
					dist = x;
				}
			}
		}
		if (m_Start.y > box.GetMax().y && m_Direction.y < 0.0f)
		{
			const auto x = (box.GetMax().y - m_Start.y) / m_Direction.y;
			if (x < dist)
			{
				const auto point = m_Start + x * m_Direction;
				if (point.x >= box.GetMin().x && point.x <= box.GetMax().x && point.z >= box.GetMin().z && point.z <= box.GetMax().z)
				{
					dist = x;
				}
			}
		}

		if (m_Start.z < box.GetMin().z && m_Direction.z > 0.0f)
		{
			const auto x = (box.GetMin().z - m_Start.z) / m_Direction.z;
			if (x < dist)
			{
				const auto point = m_Start + x * m_Direction;
				if (point.x >= box.GetMin().x && point.x <= box.GetMax().x && point.y >= box.GetMin().y && point.y <= box.GetMax().y)
				{
					dist = x;
				}
			}
		}
		if (m_Start.z > box.GetMax().z && m_Direction.z < 0.0f)
		{
			const auto x = (box.GetMax().z - m_Start.z) / m_Direction.z;
			if (x < dist)
			{
				const auto point = m_Start + x * m_Direction;
				if (point.x >= box.GetMin().x && point.x <= box.GetMax().x && point.y >= box.GetMin().y && point.y <= box.GetMax().y)
				{
					dist = x;
				}
			}
		}

		return dist;
	}
}