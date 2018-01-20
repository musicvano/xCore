/*
	Vector 4D
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Vector4.h"
#include "xCore/Math.h"

namespace xCore
{
	Vector4 Vector4::operator + () const noexcept
	{
		return *this;
	}

	Vector4 Vector4::operator - () const noexcept
	{
		return Vector4(-x, -y, -z, -w);
	}

	Vector4 Vector4::operator + (const Vector4 &v) const noexcept
	{
		return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	Vector4 Vector4::operator - (const Vector4 &v) const noexcept
	{
		return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	Vector4 Vector4::operator + (float f) const noexcept
	{
		return Vector4(x + f, y + f, z + f, w + f);
	}

	Vector4 Vector4::operator - (float f) const noexcept
	{
		return Vector4(x - f, y - f, z - f, w - f);
	}

	Vector4 Vector4::operator * (float f) const noexcept
	{
		return Vector4(x * f, y * f, z * f, w * f);
	}

	Vector4 Vector4::operator / (float f) const noexcept
	{
		return Vector4(x / f, y / f, z / f, w / f);
	}

	Vector4 Vector4::operator * (const Matrix4 &m) const noexcept
	{
		return Vector4(x * m.m00 + y * m.m10 + z * m.m20 + w * m.m30,
			x * m.m01 + y * m.m11 + z * m.m21 + w * m.m31,
			x * m.m02 + y * m.m12 + z * m.m22 + w * m.m32,
			x * m.m03 + y * m.m13 + z * m.m23 + w * m.m33);
	}

	Vector4 & Vector4::operator += (const Vector4 &v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;
		w += v.w;
		return *this;
	}

	Vector4 & Vector4::operator -= (const Vector4 &v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		w -= v.w;
		return *this;
	}

	Vector4 & Vector4::operator += (float f) noexcept
	{
		x += f;
		y += f;
		z += f;
		w += f;
		return *this;
	}

	Vector4 & Vector4::operator -= (float f) noexcept
	{
		x -= f;
		y -= f;
		z -= f;
		w -= f;
		return *this;
	}

	Vector4 & Vector4::operator *= (float f) noexcept
	{
		x *= f;
		y *= f;
		z *= f;
		w *= f;
		return *this;
	}

	Vector4 & Vector4::operator /= (float f) noexcept
	{
		x /= f;
		y /= f;
		z /= f;
		w /= f;
		return *this;
	}

	Vector4 & Vector4::operator *= (const Matrix4 &m) noexcept
	{
		*this = *this * m;
		return *this;
	}

	bool Vector4::operator > (const Vector4 &v) const noexcept
	{
		return (x > v.x) && (y > v.y) && (z > v.z) && (w > v.w);
	}

	bool Vector4::operator < (const Vector4 &v) const noexcept
	{
		return (x < v.x) && (y < v.y) && (z < v.z) && (w < v.w);
	}

	bool Vector4::operator >= (const Vector4 &v) const noexcept
	{
		return (x >= v.x) && (y >= v.y) && (z >= v.z) && (w >= v.w);
	}

	bool Vector4::operator <= (const Vector4 &v) const noexcept
	{
		return (x <= v.x) && (y <= v.y) && (z < v.z) && (w < v.w);
	}

	bool Vector4::operator == (const Vector4 &v) const noexcept
	{
		return (x == v.x) && (y == v.y) && (z == v.z) && (w == v.w);
	}

	bool Vector4::operator != (const Vector4 &v) const noexcept
	{
		return (x != v.x) || (y != v.y) || (z != v.z) || (w != v.w);
	}

	Vector4 operator * (float f, const Vector4 &v) noexcept
	{
		return Vector4(f * v.x, f * v.y, f * v.z, f * v.w);
	}

	Vector4::operator float * () noexcept
	{
		return v;
	}

	float Vector4::Length() const noexcept
	{
		return Sqrt(x * x + y * y + z * z + w * w);
	}

	float Vector4::LengthSq() const noexcept
	{
		return x * x + y * y + z * z + w * w;
	}

	bool Vector4::IsZero() const noexcept
	{
		return (x == 0.0) && (y == 0.0) && (z == 0.0) && (w == 0.0);
	}

	bool Vector4::IsZero(float eps) const noexcept
	{		
		return (Abs(x) <= eps) && (Abs(y) <= eps) && (Abs(z) <= eps) && (Abs(w) <= eps);
	}

	bool Vector4::IsOne() const noexcept
	{
		return (x == 1.0) && (y == 1.0) && (z == 1.0) && (w == 1.0);
	}

	bool Vector4::IsOne(float eps) const noexcept
	{
		return (Abs(x - 1.0) <= eps) && (Abs(y - 1.0) < eps) && (Abs(z - 1.0) < eps) && (Abs(w - 1.0) < eps);
	}

	Vector4 & Vector4::Normalize() noexcept
	{
		float length = Length();
		x /= length;
		y /= length;
		z /= length;
		w /= length;
		return *this;
	}

	Vector4 & Vector4::Invert() noexcept
	{
		x = -x;
		y = -y;
		z = -z;
		w = -w;
		return *this;
	}

	Vector4 & Vector4::Scale(float f) noexcept
	{
		x *= f;
		y *= f;
		z *= f;
		w *= f;
		return *this;
	}

	Vector4 & Vector4::Scale(float fx, float fy, float fz, float fw) noexcept
	{
		x *= fx;
		y *= fy;
		z *= fz;
		w *= fw;
		return *this;
	}
}