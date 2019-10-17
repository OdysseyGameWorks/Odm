#include "Transform.hpp"
namespace odm
{
	Matrix4x4 static translate(const Vector3f& v)
	{
		return translate(Matrix4x4(1.0f), v);
	}

	Matrix4x4 static rotate(float angle, const Vector3f& v)
	{
		return rotate(Matrix4x4(1.0f), angle, v);
	}

	Matrix4x4 static scale(const Vector3f& v)
	{
		return scale(Matrix4x4(1.0f), v);
	}
}