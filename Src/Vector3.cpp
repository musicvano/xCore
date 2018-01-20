/*
	Vector 3D
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Vector3.h"
#include "xCore/Math.h"

namespace xCore
{
	Vector3 Vector3::operator + () const noexcept
	{
		return *this;
	}

	Vector3 Vector3::operator - () const noexcept
	{
		return Vector3(-x, -y, -z);
	}

	Vector3 Vector3::operator + (const Vector3 &v) const noexcept
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 Vector3::operator - (const Vector3 &v) const noexcept
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 Vector3::operator + (float f) const noexcept
	{
		return Vector3(x + f, y + f, z + f);
	}

	Vector3 Vector3::operator - (float f) const noexcept
	{
		return Vector3(x - f, y - f, z - f);
	}

	Vector3 Vector3::operator * (float f) const noexcept
	{
		return Vector3(x * f, y * f, z * f);
	}

	Vector3 Vector3::operator / (float f) const noexcept
	{
		return Vector3(x / f, y / f, z / f);
	}

	Vector3 Vector3::operator * (const Matrix4 &m) const noexcept
	{
		return Vector3(x * m.m00 + y * m.m10 + z * m.m20 + m.m30,
			x * m.m01 + y * m.m11 + z * m.m21 + m.m31,
			x * m.m02 + y * m.m12 + z * m.m22 + m.m32);
	}

	Vector3 & Vector3::operator += (const Vector3 &v) noexcept
	{
		x += v.x;
		y += v.y;
		z += v.z;
		return *this;
	}

	Vector3 & Vector3::operator -= (const Vector3 &v) noexcept
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vector3 & Vector3::operator += (float f) noexcept
	{
		x += f;
		y += f;
		z += f;
		return *this;
	}

	Vector3 & Vector3::operator -= (float f) noexcept
	{
		x -= f;
		y -= f;
		z -= f;
		return *this;
	}

	Vector3 & Vector3::operator *= (float f) noexcept
	{
		x *= f;
		y *= f;
		z *= f;
		return *this;
	}

	Vector3 & Vector3::operator /= (float f) noexcept
	{
		x /= f;
		y /= f;
		z /= f;
		return *this;
	}

	Vector3 & Vector3::operator *= (const Matrix4 &m) noexcept
	{
		*this = *this * m;
		return *this;
	}

	bool Vector3::operator > (const Vector3 &v) const noexcept
	{
		return (x > v.x) && (y > v.y) && (z > v.z);
	}

	bool Vector3::operator < (const Vector3 &v) const noexcept
	{
		return (x < v.x) && (y < v.y) && (z < v.z);
	}

	bool Vector3::operator >= (const Vector3 &v) const noexcept
	{
		return (x >= v.x) && (y >= v.y) && (z >= v.z);
	}

	bool Vector3::operator <= (const Vector3 &v) const noexcept
	{
		return (x <= v.x) && (y <= v.y) && (z < v.z);
	}

	bool Vector3::operator == (const Vector3 &v) const noexcept
	{
		return (x == v.x) && (y == v.y) && (z == v.z);
	}

	bool Vector3::operator != (const Vector3 &v) const noexcept
	{
		return (x != v.x) || (y != v.y) || (z != v.z);
	}

	Vector3 operator * (float f, const Vector3 &v) noexcept
	{
		return Vector3(f * v.x, f * v.y, f * v.z);
	}

	Vector3::operator float * () noexcept
	{
		return v;
	}

	float Vector3::Length() const noexcept
	{
		return Sqrt(x * x + y * y + z * z);
	}

	float Vector3::LengthSq() const noexcept
	{
		return x * x + y * y + z * z;
	}

	bool Vector3::IsZero() const noexcept
	{
		return (x == 0.0) && (y == 0.0) && (z == 0.0);
	}

	bool Vector3::IsZero(float eps) const noexcept
	{
		return (Abs(x) <= eps) && (Abs(y) <= eps) && (Abs(z) <= eps);
	}

	bool Vector3::IsOne() const noexcept
	{
		return (x == 1.0) && (y == 1.0) && (z == 1.0);
	}

	bool Vector3::IsOne(float eps) const noexcept
	{
		return (Abs(x - 1.0) <= eps) && (Abs(y - 1.0) < eps) && (Abs(z - 1.0) < eps);
	}

	Vector3 & Vector3::Normalize() noexcept
	{
		float length = Length();
		x /= length;
		y /= length;
		z /= length;
		return *this;
	}

	Vector3 & Vector3::Invert() noexcept
	{
		x = -x;
		y = -y;
		z = -z;
		return *this;
	}

	Vector3 & Vector3::Scale(float f) noexcept
	{
		x *= f;
		y *= f;
		z *= z;
		return *this;
	}

	Vector3 & Vector3::Scale(float fx, float fy, float fz) noexcept
	{
		x *= fx;
		y *= fy;
		z *= fz;
		return *this;
	}
}