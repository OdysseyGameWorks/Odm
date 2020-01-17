#include "Vector3f.h"

#include "Vector2f.h"

namespace odm
{
	Vector3f::Vector3f(const Vector2f& v, float z)
		: x(v.x), y(v.y), z(z)
	{}

	Vector3f::Vector3f(const Vector2f& v)
		: x(v.x), y(v.y), z(1.0f)
	{}

	const Vector3f Vector3f::Zero(0, 0, 0);
	const Vector3f Vector3f::One(1, 1, 1);
	const Vector3f Vector3f::Up(0, 1, 0);
	const Vector3f Vector3f::Down(0, -1, 0);
	const Vector3f Vector3f::Forward(0, 0, 1);
	const Vector3f Vector3f::Back(0, 0, -1);
	const Vector3f Vector3f::Left(1, 0, 0);
	const Vector3f Vector3f::Right(-1, 0, 0);
}