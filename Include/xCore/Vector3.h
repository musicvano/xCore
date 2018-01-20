/*
	Vector 3D
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once
#include "Matrix4.h"

namespace xCore
{
	// 3D vector with x, y, z coordinates
	class Vector3
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
				float z;
			};
			float v[3];
		};

		Vector3() noexcept {};
		Vector3(float f) noexcept : x(f), y(f), z(f) {};
		Vector3(const float *v) noexcept : x(v[0]), y(v[1]), z(v[2]) {};
		Vector3(float x, float y, float z) noexcept : x(x), y(y), z(z) {};

		Vector3 operator + () const noexcept;
		Vector3 operator - () const noexcept;

		Vector3 operator + (const Vector3 &v) const noexcept;
		Vector3 operator - (const Vector3 &v) const noexcept;
		Vector3 operator + (float f) const noexcept;
		Vector3 operator - (float f) const noexcept;
		Vector3 operator * (float f) const noexcept;
		Vector3 operator / (float f) const noexcept;
		Vector3 operator * (const Matrix4 &m) const noexcept;

		Vector3 & operator += (const Vector3 &v) noexcept;
		Vector3 & operator -= (const Vector3 &v) noexcept;
		Vector3 & operator += (float f) noexcept;
		Vector3 & operator -= (float f) noexcept;
		Vector3 & operator *= (float f) noexcept;
		Vector3 & operator /= (float f) noexcept;
		Vector3 & operator *= (const Matrix4 &m) noexcept;

		bool operator > (const Vector3 &v) const noexcept;
		bool operator < (const Vector3 &v) const noexcept;
		bool operator >= (const Vector3 &v) const noexcept;
		bool operator <= (const Vector3 &v) const noexcept;
		bool operator == (const Vector3 &v) const noexcept;
		bool operator != (const Vector3 &v) const noexcept;

		friend Vector3 operator * (float f, const Vector3 &v) noexcept;
		explicit operator float * () noexcept;

		// Returns the length of the vector
		float Length() const noexcept;

		// Returns the squared length of the vector
		float LengthSq() const noexcept;

		// Returns true if the vector is {0, 0, 0}
		bool IsZero() const noexcept;

		// Returns true if the vector is {0, 0, 0} with epsilon tolerance
		bool Vector3::IsZero(float eps) const noexcept;

		// Returns true if the vector is {1, 1, 1}
		bool IsOne() const noexcept;

		// Returns true if the vector is {1, 1, 1} with epsilon tolerance
		bool IsOne(float eps) const noexcept;

		// Normalizes the vector, the null vector is left untouched
		Vector3 & Normalize() noexcept;

		// Inverts the vector direction
		Vector3 & Invert() noexcept;

		// Scales the vector by factor
		Vector3 & Scale(float f) noexcept;

		// Scales the vector by x, y, z factors
		Vector3 & Scale(float fx, float fy, float fz) noexcept;
	};
}