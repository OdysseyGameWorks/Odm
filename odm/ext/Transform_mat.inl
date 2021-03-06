#pragma once
namespace odm
{
	Matrix4x4 translate(const Matrix4x4& m, const Vector3f& v)
	{
		auto Result(m);
 		Result[3] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3];
		return Result;
	}

	Matrix4x4 rotate(const Matrix4x4& m, float angle, const Vector3f& v)
	{
		auto const a = angle;
		auto const c = cos(a);
		auto const s = sin(a);

		const auto axis(vec3::Normalize(v));
		const auto temp((float(1) - c) * axis);

		Matrix4x4 Rotate;
		Rotate[0][0] = c + temp[0] * axis[0];
		Rotate[0][1] = temp[0] * axis[1] + s * axis[2];
		Rotate[0][2] = temp[0] * axis[2] - s * axis[1];

		Rotate[1][0] = temp[1] * axis[0] - s * axis[2];
		Rotate[1][1] = c + temp[1] * axis[1];
		Rotate[1][2] = temp[1] * axis[2] + s * axis[0];

		Rotate[2][0] = temp[2] * axis[0] + s * axis[1];
		Rotate[2][1] = temp[2] * axis[1] - s * axis[0];
		Rotate[2][2] = c + temp[2] * axis[2];

		Matrix4x4 Result;
		Result[0] = m[0] * Rotate[0][0] + m[1] * Rotate[0][1] + m[2] * Rotate[0][2];
		Result[1] = m[0] * Rotate[1][0] + m[1] * Rotate[1][1] + m[2] * Rotate[1][2];
		Result[2] = m[0] * Rotate[2][0] + m[1] * Rotate[2][1] + m[2] * Rotate[2][2];
		Result[3] = m[3];
		return Result;
	}

	Matrix4x4 scale(const Matrix4x4& m, const Vector3f& v)
	{
		auto Result(m);
		Result[0][0] = m[0][0] * v[0];
		Result[1][1] = m[1][1] * v[1];
		Result[2][2] = m[2][2] * v[2];
		Result[3][3] = m[3][3];
		return Result;
	}

	Matrix4x4 lookAt(const Vector3f& eye, const Vector3f& center, const Vector3f& up)
	{
		auto const f(vec3::Normalize(center - eye));
		auto const s(vec3::Normalize(vec3::Cross(f, up)));
		auto const u(vec3::Cross(s, f));

		Matrix4x4 Result(1.0f);
		Result[0][0] = s.x;
		Result[1][0] = s.y;
		Result[2][0] = s.z;
		Result[0][1] = u.x;
		Result[1][1] = u.y;
		Result[2][1] = u.z;
		Result[0][2] = -f.x;
		Result[1][2] = -f.y;
		Result[2][2] = -f.z;
		Result[3][0] = -vec3::Dot(s, eye);
		Result[3][1] = -vec3::Dot(u, eye);
		Result[3][2] = vec3::Dot(f, eye);
		return Result;
	}

	Matrix4x4 setPosition(const Matrix4x4& mat, const vec3f &position)
	{
		auto Result(mat);
		Result[3] = vec4(position, mat[3][3]);
		return Result;
	}

	Vector3f getPosition(const Matrix4x4& transform)
	{
		return Vector3f(transform[3][0], transform[3][1], transform[3][2]);
	}
}
