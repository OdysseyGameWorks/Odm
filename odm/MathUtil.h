#pragma once

#include <cmath>

/** stores the value of 1/PI constant */
constexpr auto INV_PI = (0.31830988618f);
/** stores the value of 1/2 * PI constant */
constexpr auto HLF_PI = (1.57079632679f);

/** stores the value of PI constant */
constexpr auto PI = (3.14159265359f);
/** stores the value of 2 * PI constant */
constexpr auto PI2 = (6.28318530718f);

/** fraction for converting Degrees to Radians */
constexpr auto DEG_TO_RAD = (PI / 180.0f);
/** fraction for converting Radians to Degrees */
constexpr auto RAD_TO_DEG = (180.0f / PI);

namespace odm
{
	static float DegToRad(float angle) { return (angle * DEG_TO_RAD); }
	static float RadToDeg(float angle) { return (angle * RAD_TO_DEG); }
}

namespace MathF
{
	template <class T>
	constexpr T Max(T a, T b) { return a > b ? a : b; }

	template <class T>
	constexpr T Max3(T a, T b, T c) { return Max(a, Max(b, c)); }

	template <class T>
	constexpr T Min(T a, T b) { return a < b ? a : b; }

	template <class T>
	constexpr T Min3(T a, T b, T c) { return Min(a, Min(b, c)); }

	template <class T>
	constexpr T Sqrt(T x) { return sqrt(x); }

	template <class T>
	constexpr T Floor(T x) { return floor(x); }

	template <class T>
	constexpr T Ceil(T x) { return ceil(x); }

	template <class T>
	constexpr T Round(T x) { return round(x); }

	template <class T>
	constexpr T Tan(T x) { return tan(x); }

	template <typename T>
	constexpr int Sign(T x) { return (static_cast<T>(0) < x) - (x < static_cast<T>(0)); }

	template <class T>
	constexpr T Pow(T x, T y) { return pow(x, y); }

	template <class T>
	constexpr T Saturate(T x) { return Clamp(x, static_cast<T>(0), static_cast<T>(1)); }
}