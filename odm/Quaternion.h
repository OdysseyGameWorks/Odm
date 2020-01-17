#pragma once

#ifndef QUATERNION_H
#define QUATERNION_H

#include "Vector4f.h"

namespace odm
{
	struct Quaternion
	{
		float x, y, z, w;

		Quaternion();
		Quaternion(float x, float y, float z, float w);
		Quaternion(const vec3& xyz, float w);
		Quaternion(const vec4& vec);
		Quaternion(float scalar);


		Quaternion& SetXYZ(const vec3& vec);
		vec3 GetXYZ() const;

		Quaternion& SetElement(int idx, float value);
		float GetElement(int idx) const;

		vec3 GetAxis() const;
		vec3 ToEulerAngles() const;
		
		Quaternion& operator=(const Quaternion& quaternion) = default;

		const Quaternion operator+(const Quaternion& Quaternion) const;
		const Quaternion operator-(const Quaternion& Quaternion) const;
		const Quaternion operator*(const Quaternion& Quaternion) const;
		const Quaternion operator*(float scalar) const;
		const Quaternion operator/(float scalar) const;
		float operator[](int idx) const;

		Quaternion& operator+=(const Quaternion& Quaternion) {
			*this = *this + Quaternion;
			return *this;
		}

		Quaternion& operator-=(const Quaternion& Quaternion) {
			*this = *this - Quaternion;
			return *this;
		}

		Quaternion& operator*=(const Quaternion& Quaternion) {
			*this = *this * Quaternion;
			return *this;
		}

		Quaternion& operator*=(float scalar) {
			*this = *this * scalar;
			return *this;
		}

		Quaternion& operator/=(float scalar) {
			*this = *this / scalar;
			return *this;
		}

		const Quaternion operator-() const;
		bool operator==(const Quaternion& quaternion) const;
		bool operator!=(const Quaternion& quaternion) const;

		static Quaternion Identity();
		static Quaternion FromEulerAngles(const vec3& angles);

		static vec3 Rotate(const Quaternion& quat, const vec3& vec);

		static const Quaternion Rotation(const vec3& unitVec0, const vec3& unitVec1);
		static const Quaternion Rotation(float radians, const vec3& unitVec);

		static const Quaternion RotationX(float radians)
		{
			float angle = radians * 0.5f;
			return Quaternion(sin(angle), 0.0f, 0.0f, cos(angle));
		}

		static const Quaternion RotationY(float radians)
		{
			float angle = radians * 0.5f;
			return Quaternion(0.0f, sin(angle), 0.0f, cos(angle));
		}

		static const Quaternion RotationZ(float radians)
		{
			float angle = radians * 0.5f;
			return Quaternion(0.0f, 0.0f, sin(angle), cos(angle));
		}

		float Dot(const Quaternion& other) const;
		Quaternion Conjugate() const;
	};


	constexpr auto VECTORMATH_SLERP_TOL = 0.999f;

	inline Quaternion::Quaternion()
		: x(0), y(0), z(0), w(1)
	{}

	inline Quaternion::Quaternion(float x, float y, float z, float w)
		: x(x), y(y), z(z), w(w)
	{}

	inline Quaternion::Quaternion(const vec4& vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
		w = vec.w;
	}

	inline Quaternion::Quaternion(float scalar) {
		x = scalar;
		y = scalar;
		z = scalar;
		w = scalar;
	}

	inline Quaternion::Quaternion(const vec3& xyz, float w) {
		this->SetXYZ(xyz);
		this->w = w;
	}

	inline Quaternion Quaternion::Identity() {
		return Quaternion(0.0f, 0.0f, 0.0f, 1.0f);
	}

	inline Quaternion Quaternion::FromEulerAngles(const vec3& angles) {
		Quaternion pitch(vec3(1.0, 0.0, 0.0), angles.x);
		Quaternion yaw(vec3(0.0, 1.0, 0.0), angles.y);
		Quaternion roll(vec3(0.0, 0.0, 1.0), angles.z);
		return pitch * yaw * roll;
	}

	inline Quaternion& Quaternion::SetXYZ(const vec3& vec) {
		x = vec.x;
		y = vec.y;
		z = vec.z;
		return *this;
	}

	inline vec3 Quaternion::GetXYZ() const
	{
		return vec3(x, y, z);
	}

	inline Quaternion& Quaternion::SetElement(int idx, float value) {
		*(&x + idx) = value;
		return *this;
	}

	inline float Quaternion::GetElement(int idx) const {
		return *(&x + idx);
	}

	inline float Quaternion::operator[](int idx) const {
		return *(&x + idx);
	}

	inline vec3 Quaternion::GetAxis() const {
		float x = 1.0f - w * w;
		if (x < 0.0000001f) // Divide by zero safety check
			return vec3::Up;

		const float x2 = x * x;
		return GetXYZ() / x2;
	}

	inline vec3 Quaternion::ToEulerAngles() const {
		return vec3(atan2(2 * x * w - 2 * y * z, 1 - 2 * x * x - 2 * z * z),
			atan2(2 * y * w - 2 * x * z, 1 - 2 * y * y - 2 * z * z),
			asin(2 * x * y + 2 * z * w));
	}

	inline const Quaternion Quaternion::operator+(const Quaternion& quaternion) const {
		return Quaternion(x + quaternion.x, y + quaternion.y, z + quaternion.z, w + quaternion.w);
	}

	inline const Quaternion Quaternion::operator-(const Quaternion& quaternion) const {
		return Quaternion(x - quaternion.x, y - quaternion.y, z - quaternion.z, w - quaternion.w);
	}

	inline const Quaternion Quaternion::operator*(float scalar) const {
		return Quaternion(x * scalar, y * scalar, z * scalar, w * scalar);
	}

	inline const Quaternion Quaternion::operator/(float scalar) const {
		return Quaternion(x / scalar, y / scalar, z / scalar, w / scalar);
	}

	inline const Quaternion Quaternion::operator-() const {
		return Quaternion(-x, -y, -z, -w);
	}

	inline bool Quaternion::operator ==(const Quaternion& Quaternion) const {
		return (x == Quaternion.x) && (y == Quaternion.y) && (z == Quaternion.z) && (w == Quaternion.w);
	}

	inline bool Quaternion::operator !=(const Quaternion& Quaternion) const {
		return !(*this == Quaternion);
	}

	inline float Norm(const Quaternion& quaternion) {
		float result = (quaternion.x * quaternion.x);
		result = (result + (quaternion.y * quaternion.y));
		result = (result + (quaternion.z * quaternion.z));
		result = (result + (quaternion.w * quaternion.w));
		return result;
	}

	inline float Length(const Quaternion& quaternion) {
		return sqrt(Norm(quaternion));
	}

	inline const Quaternion Normalize(const Quaternion& quaternion) {
		const float lenSqr = Norm(quaternion);
		const float lenInv = 1 / sqrt(lenSqr);
		return quaternion * lenInv;
	}

	inline const Quaternion NormalizeEst(const Quaternion& quaternion) {
		const float lenSqr = Norm(quaternion);
		const float lenInv = 1 / sqrt(lenSqr);
		return quaternion * lenInv;
	}

	inline const Quaternion Quaternion::Rotation(const vec3& unitVec0, const vec3& unitVec1) {
		const float cosHalfAngleX2 = sqrt((2.0f * (1.0f + unitVec0.Dot(unitVec1))));
		const float recipCosHalfAngleX2 = (1.0f / cosHalfAngleX2);
		return Quaternion((unitVec0.Cross(unitVec1) * recipCosHalfAngleX2), (cosHalfAngleX2 * 0.5f));
	}

	inline const Quaternion Quaternion::Rotation(float radians, const vec3& unitVec) {
		const float angle = radians * 0.5f;
		return Quaternion((unitVec * sin(angle)), cos(angle));
	}

	inline const Quaternion Quaternion::operator*(const Quaternion& quat) const {
		return Normalize(Quaternion(
			(((w * quat.x) + (x * quat.w)) + (y * quat.z)) - (z * quat.y),
			(((w * quat.y) + (y * quat.w)) + (z * quat.x)) - (x * quat.z),
			(((w * quat.z) + (z * quat.w)) + (x * quat.y)) - (y * quat.x),
			(((w * quat.w) - (x * quat.x)) - (y * quat.y)) - (z * quat.z)
		));
	}

	inline vec3 Quaternion::Rotate(const Quaternion& quat, const vec3& vec) {
		float tmpX = (((quat.w * vec.x) + (quat.y * vec.z)) - (quat.z * vec.y));
		float tmpY = (((quat.w * vec.y) + (quat.z * vec.x)) - (quat.x * vec.z));
		float tmpZ = (((quat.w * vec.z) + (quat.x * vec.y)) - (quat.y * vec.x));
		float tmpW = (((quat.x * vec.x) + (quat.y * vec.y)) + (quat.z * vec.z));
		return vec3(
			((((tmpW * quat.x) + (tmpX * quat.w)) - (tmpY * quat.z)) + (tmpZ * quat.y)),
			((((tmpW * quat.y) + (tmpY * quat.w)) - (tmpZ * quat.x)) + (tmpX * quat.z)),
			((((tmpW * quat.z) + (tmpZ * quat.w)) - (tmpX * quat.y)) + (tmpY * quat.x))
		);
	}

	inline Quaternion Quaternion::Conjugate() const {
		return Quaternion(-x, -y, -z, w);
	}

	inline const Quaternion Select(const Quaternion& quat0, const Quaternion& quat1, bool select1) {
		return Quaternion(select1 ? quat1.x : quat0.x, select1 ? quat1.y : quat0.y, select1 ? quat1.z : quat0.z, select1 ? quat1.w : quat0.w);
	}

	inline float Quaternion::Dot(const Quaternion& other) const {
		float result = (x * other.x);
		result = (result + (y * other.y));
		result = (result + (z * other.z));
		result = (result + (w * other.w));
		return result;
	}

}

#endif /* end of include guard: QUATERNION_H */
