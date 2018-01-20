/*
	Vector 4D
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once
#include "Matrix4.h"

namespace xCore
{
	// 4D vector with x, y, z, w coordinates
	class Vector4
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
				float w;
			};
			float v[4];
		};

		Vector4() noexcept {};
		Vector4(float f) noexcept : x(f), y(f), z(f), w(f) {};
		Vector4(const float *v) noexcept : x(v[0]), y(v[1]), z(v[2]), w(v[3]) {};
		Vector4(float x, float y, float z, float w) noexcept : x(x), y(y), z(z), w(w) {};

		Vector4 operator + () const noexcept;
		Vector4 operator - () const noexcept;

		Vector4 operator + (const Vector4 &v) const noexcept;
		Vector4 operator - (const Vector4 &v) const noexcept;
		Vector4 operator + (float f) const noexcept;
		Vector4 operator - (float f) const noexcept;
		Vector4 operator * (float f) const noexcept;
		Vector4 operator / (float f) const noexcept;
		Vector4 operator * (const Matrix4 &m) const noexcept;

		Vector4 & operator += (const Vector4 &v) noexcept;
		Vector4 & operator -= (const Vector4 &v) noexcept;
		Vector4 & operator += (float f) noexcept;
		Vector4 & operator -= (float f) noexcept;
		Vector4 & operator *= (float f) noexcept;
		Vector4 & operator /= (float f) noexcept;
		Vector4 & operator *= (const Matrix4 &m) noexcept;

		bool operator >(const Vector4 &v) const noexcept;
		bool operator <(const Vector4 &v) const noexcept;
		bool operator >=(const Vector4 &v) const noexcept;
		bool operator <=(const Vector4 &v) const noexcept;
		bool operator == (const Vector4 &v) const noexcept;
		bool operator != (const Vector4 &v) const noexcept;

		friend Vector4 operator * (float f, const Vector4 &v) noexcept;
		explicit operator float * () noexcept;

		// Returns the length of the vector
		float Length() const noexcept;

		// Returns the squared length of the vector
		float LengthSq() const noexcept;

		// Returns true if the vector is {0, 0, 0, 0}
		bool IsZero() const noexcept;

		// Returns true if the vector is {0, 0, 0, 0} with epsilon tolerance
		bool IsZero(float eps) const noexcept;

		// Returns true if the vector is {1, 1, 1, 1}
		bool IsOne() const noexcept;

		// Returns true if the vector is {1, 1, 1, 1} with epsilon tolerance
		bool IsOne(float eps) const noexcept;

		// Normalizes the vector, the null vector is left untouched
		Vector4 & Normalize() noexcept;

		// Inverts the vector direction
		Vector4 & Invert() noexcept;

		// Scales the vector by factor
		Vector4 & Scale(float f) noexcept;

		// Scales the vector by x, y, z, w factors
		Vector4 & Scale(float fx, float fy, float fz, float fw) noexcept;
	};
}