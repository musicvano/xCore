/*
	Vector 2D
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Vector2.h"
#include "xCore/Math.h"

namespace xCore
{
	Vector2 Vector2::operator + () const noexcept
	{
		return *this;
	}

	Vector2 Vector2::operator - () const noexcept
	{
		return Vector2(-x, -y);
	}

	Vector2 Vector2::operator + (const Vector2 &v) const noexcept
	{
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 Vector2::operator - (const Vector2 &v) const noexcept
	{
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 Vector2::operator + (float f) const noexcept
	{
		return Vector2(x + f, y + f);
	}

	Vector2 Vector2::operator - (float f) const noexcept
	{
		return Vector2(x - f, y - f);
	}

	Vector2 Vector2::operator * (float f) const noexcept
	{
		return Vector2(x * f, y * f);
	}

	Vector2 Vector2::operator / (float f) const noexcept
	{
		return Vector2(x / f, y / f);
	}

	Vector2 & Vector2::operator += (const Vector2 &v) noexcept
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector2 & Vector2::operator -= (const Vector2 &v) noexcept
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vector2 & Vector2::operator += (float f) noexcept
	{
		x += f;
		y += f;
		return *this;
	}

	Vector2 & Vector2::operator -= (float f) noexcept
	{
		x -= f;
		y -= f;
		return *this;
	}

	Vector2 & Vector2::operator *= (float f) noexcept
	{
		x *= f;
		y *= f;
		return *this;
	}

	Vector2 & Vector2::operator /= (float f) noexcept
	{
		x /= f;
		y /= f;
		return *this;
	}

	bool Vector2::operator >(const Vector2 &v) const noexcept
	{
		return (x > v.x) && (y > v.y);
	}

	bool Vector2::operator <(const Vector2 &v) const noexcept
	{
		return (x < v.x) && (y < v.y);
	}

	bool Vector2::operator >=(const Vector2 &v) const noexcept
	{
		return (x >= v.x) && (y >= v.y);
	}

	bool Vector2::operator <=(const Vector2 &v) const noexcept
	{
		return (x <= v.x) && (y <= v.y);
	}

	bool Vector2::operator == (const Vector2 &v) const noexcept
	{
		return (x == v.x) && (y == v.y);
	}

	bool Vector2::operator != (const Vector2 &v) const noexcept
	{
		return (x != v.x) || (y != v.y);
	}

	Vector2 operator * (float f, const Vector2 &v) noexcept
	{
		return Vector2(f * v.x, f * v.y);
	}

	Vector2::operator float * () noexcept
	{
		return v;
	}

	float Vector2::Length() const noexcept
	{
		return Sqrt(x * x + y * y);
	}

	float Vector2::LengthSq() const noexcept
	{
		return x * x + y * y;
	}

	bool Vector2::IsZero() const noexcept
	{
		return (x == 0.0) && (y == 0.0);
	}

	bool Vector2::IsZero(float eps) const noexcept
	{
		return (Abs(x) <= eps) && (Abs(y) <= eps);
	}

	bool Vector2::IsOne() const noexcept
	{
		return (x == 1.0) && (y == 1.0);
	}

	bool Vector2::IsOne(float eps) const noexcept
	{
		return (Abs(x - 1.0) <= eps) && (Abs(y - 1.0) < eps);
	}

	Vector2 & Vector2::Normalize() noexcept
	{
		float length = Length();
		x /= length;
		y /= length;
		return *this;
	}

	Vector2 & Vector2::Invert() noexcept
	{
		x = -x;
		y = -y;
		return *this;
	}

	Vector2 &Vector2::Scale(float f) noexcept
	{
		x *= f;
		y *= f;
		return *this;
	}

	Vector2 &Vector2::Scale(float fx, float fy) noexcept
	{
		x *= fx;
		y *= fy;
		return *this;
	}
}