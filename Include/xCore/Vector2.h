/*
	Vector 2D
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once

namespace xCore
{
	// 2D vector with x and y coordinates
	class Vector2
	{
	public:
		union
		{
			struct
			{
				float x;
				float y;
			};
			float v[2];
		};

		Vector2() noexcept {};
		Vector2(float f) noexcept : x(f), y(f) {};
		Vector2(const float *v) noexcept : x(v[0]), y(v[1]) {};
		Vector2(float x, float y) noexcept : x(x), y(y) {};

		Vector2 operator + () const noexcept;
		Vector2 operator - () const noexcept;

		Vector2 operator + (const Vector2 &v) const noexcept;
		Vector2 operator - (const Vector2 &v) const noexcept;
		Vector2 operator + (float f) const noexcept;
		Vector2 operator - (float f) const noexcept;
		Vector2 operator * (float f) const noexcept;
		Vector2 operator / (float f) const noexcept;

		Vector2 & operator += (const Vector2 &v) noexcept;
		Vector2 & operator -= (const Vector2 &v) noexcept;
		Vector2 & operator += (float f) noexcept;
		Vector2 & operator -= (float f) noexcept;
		Vector2 & operator *= (float f) noexcept;
		Vector2 & operator /= (float f) noexcept;

		bool operator >(const Vector2 &v) const noexcept;
		bool operator <(const Vector2 &v) const noexcept;
		bool operator >=(const Vector2 &v) const noexcept;
		bool operator <=(const Vector2 &v) const noexcept;
		bool operator == (const Vector2 &v) const noexcept;
		bool operator != (const Vector2 &v) const noexcept;

		friend Vector2 operator * (float f, const Vector2 &v) noexcept;
		explicit operator float * () noexcept;

		// Returns the length of the vector
		float Length() const noexcept;

		// Returns the squared length of the vector
		float LengthSq() const noexcept;

		// Returns true if the vector is {0, 0}
		bool IsZero() const noexcept;

		// Returns true if the vector is {0, 0} with epsilon tolerance
		bool IsZero(float eps) const noexcept;

		// Returns true if the vector is {1, 1}
		bool IsOne() const noexcept;

		// Returns true if the vector is {1, 1} with epsilon tolerance
		bool IsOne(float eps) const noexcept;

		// Normalizes the vector, the null vector is left untouched
		Vector2 & Normalize() noexcept;

		// Inverts the vector direction
		Vector2 & Invert() noexcept;

		// Scales the vector by factor
		Vector2 & Scale(float f) noexcept;

		// Scales the vector by x, y factors
		Vector2 & Scale(float fx, float fy) noexcept;
	};
}