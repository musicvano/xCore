/*
	Matrix 4x4
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Matrix4.h"
#include "xCore/Math.h"

namespace xCore
{
	Matrix4::Matrix4(float f) noexcept :
		m00(f), m01(f), m02(f), m03(f),
		m10(f), m11(f), m12(f), m13(f),
		m20(f), m21(f), m22(f), m23(f),
		m30(f), m31(f), m32(f), m33(f)
	{ }

	Matrix4::Matrix4(const float *v) noexcept :
		m00(v[0]), m01(v[1]), m02(v[2]), m03(v[3]),
		m10(v[4]), m11(v[5]), m12(v[6]), m13(v[7]),
		m20(v[8]), m21(v[9]), m22(v[10]), m23(v[11]),
		m30(v[12]), m31(v[13]), m32(v[14]), m33(v[15])
	{ }

	Matrix4::Matrix4(float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33) noexcept :
		m00(m00), m01(m01), m02(m02), m03(m03),
		m10(m10), m11(m11), m12(m12), m13(m13),
		m20(m20), m21(m21), m22(m22), m23(m23),
		m30(m30), m31(m31), m32(m32), m33(m33)
	{ }

	Matrix4 Matrix4::operator + () const noexcept
	{
		return *this;
	}

	Matrix4 Matrix4::operator - () const noexcept
	{
		return Matrix4(-m00, -m01, -m02, -m03,
			-m10, -m11, -m12, -m13,
			-m20, -m21, -m22, -m23,
			-m30, -m31, -m32, -m33);
	}

	Matrix4 Matrix4::operator + (const Matrix4 &m) const noexcept
	{
		return Matrix4(m00 + m.m00, m01 + m.m01, m02 + m.m02, m03 + m.m03,
			m10 + m.m10, m11 + m.m11, m12 + m.m12, m13 + m.m13,
			m20 + m.m20, m21 + m.m21, m22 + m.m22, m23 + m.m23,
			m30 + m.m30, m31 + m.m31, m32 + m.m32, m33 + m.m33);
	}

	Matrix4 Matrix4::operator - (const Matrix4 &m) const noexcept
	{
		return Matrix4(m00 - m.m00, m01 - m.m01, m02 - m.m02, m03 - m.m03,
			m10 - m.m10, m11 - m.m11, m12 - m.m12, m13 - m.m13,
			m20 - m.m20, m21 - m.m21, m22 - m.m22, m23 - m.m23,
			m30 - m.m30, m31 - m.m31, m32 - m.m32, m33 - m.m33);
	}

	Matrix4 Matrix4::operator * (const Matrix4 &m) const noexcept
	{
		return Matrix4(m00*m.m00 + m01 * m.m10 + m02 * m.m20 + m03 * m.m30,
			m00*m.m01 + m01 * m.m11 + m02 * m.m21 + m03 * m.m31,
			m00*m.m02 + m01 * m.m12 + m02 * m.m22 + m03 * m.m32,
			m00*m.m03 + m01 * m.m13 + m02 * m.m23 + m03 * m.m33,
			m10*m.m00 + m11 * m.m10 + m12 * m.m20 + m13 * m.m30,
			m10*m.m01 + m11 * m.m11 + m12 * m.m21 + m13 * m.m31,
			m10*m.m02 + m11 * m.m12 + m12 * m.m22 + m13 * m.m32,
			m10*m.m03 + m11 * m.m13 + m12 * m.m23 + m13 * m.m33,
			m20*m.m00 + m21 * m.m10 + m22 * m.m20 + m23 * m.m30,
			m20*m.m01 + m21 * m.m11 + m22 * m.m21 + m23 * m.m31,
			m20*m.m02 + m21 * m.m12 + m22 * m.m22 + m23 * m.m32,
			m20*m.m03 + m21 * m.m13 + m22 * m.m23 + m23 * m.m33,
			m30*m.m00 + m31 * m.m10 + m32 * m.m20 + m33 * m.m30,
			m30*m.m01 + m31 * m.m11 + m32 * m.m21 + m33 * m.m31,
			m30*m.m02 + m31 * m.m12 + m32 * m.m22 + m33 * m.m32,
			m30*m.m03 + m31 * m.m13 + m32 * m.m23 + m33 * m.m33);
	}

	Matrix4 Matrix4::operator + (float f) const noexcept
	{
		return Matrix4(m00 + f, m01 + f, m02 + f, m03 + f,
			m10 + f, m11 + f, m12 + f, m13 + f,
			m20 + f, m21 + f, m22 + f, m23 + f,
			m30 + f, m31 + f, m32 + f, m33 + f);
	}

	Matrix4 Matrix4::operator - (float f) const noexcept
	{
		return Matrix4(m00 - f, m01 - f, m02 - f, m03 - f,
			m10 - f, m11 - f, m12 - f, m13 - f,
			m20 - f, m21 - f, m22 - f, m23 - f,
			m30 - f, m31 - f, m32 - f, m33 - f);
	}

	Matrix4 Matrix4::operator * (float f) const noexcept
	{
		return Matrix4(m00 * f, m01 * f, m02 * f, m03 * f,
			m10 * f, m11 * f, m12 * f, m13 * f,
			m20 * f, m21 * f, m22 * f, m23 * f,
			m30 * f, m31 * f, m32 * f, m33 * f);
	}

	Matrix4 Matrix4::operator / (float f) const noexcept
	{
		return Matrix4(m00 / f, m01 / f, m02 / f, m03 / f,
			m10 / f, m11 / f, m12 / f, m13 / f,
			m20 / f, m21 / f, m22 / f, m23 / f,
			m30 / f, m31 / f, m32 / f, m33 / f);
	}

	Matrix4 & Matrix4::operator += (const Matrix4 &m) noexcept
	{
		m00 += m.m00; m01 += m.m01; m02 += m.m02; m03 += m.m03;
		m10 += m.m10; m11 += m.m11; m12 += m.m12; m13 += m.m13;
		m20 += m.m20; m21 += m.m21; m22 += m.m22; m23 += m.m23;
		m30 += m.m30; m31 += m.m31; m32 += m.m32; m33 += m.m33;
		return *this;
	}

	Matrix4 & Matrix4::operator -= (const Matrix4 &m) noexcept
	{
		m00 -= m.m00; m01 -= m.m01; m02 -= m.m02; m03 -= m.m03;
		m10 -= m.m10; m11 -= m.m11; m12 -= m.m12; m13 -= m.m13;
		m20 -= m.m20; m21 -= m.m21; m22 -= m.m22; m23 -= m.m23;
		m30 -= m.m30; m31 -= m.m31; m32 -= m.m32; m33 -= m.m33;
		return *this;
	}

	Matrix4 & Matrix4::operator *= (const Matrix4 &m) noexcept
	{
		*this = *this * m;
		return *this;
	}

	Matrix4 & Matrix4::operator += (float f) noexcept
	{
		m00 += f; m01 += f; m02 += f; m03 += f;
		m10 += f; m11 += f; m12 += f; m13 += f;
		m20 += f; m21 += f; m22 += f; m23 += f;
		m30 += f; m31 += f; m32 += f; m33 += f;
		return *this;
	}

	Matrix4 & Matrix4::operator -= (float f) noexcept
	{
		m00 -= f; m01 -= f; m02 -= f; m03 -= f;
		m10 -= f; m11 -= f; m12 -= f; m13 -= f;
		m20 -= f; m21 -= f; m22 -= f; m23 -= f;
		m30 -= f; m31 -= f; m32 -= f; m33 -= f;
		return *this;
	}

	Matrix4 & Matrix4::operator *= (float f) noexcept
	{
		m00 *= f; m01 *= f; m02 *= f; m03 *= f;
		m10 *= f; m11 *= f; m12 *= f; m13 *= f;
		m20 *= f; m21 *= f; m22 *= f; m23 *= f;
		m30 *= f; m31 *= f; m32 *= f; m33 *= f;
		return *this;
	}

	Matrix4 & Matrix4::operator /= (float f) noexcept
	{
		m00 /= f; m01 /= f; m02 /= f; m03 /= f;
		m10 /= f; m11 /= f; m12 /= f; m13 /= f;
		m20 /= f; m21 /= f; m22 /= f; m23 /= f;
		m30 /= f; m31 /= f; m32 /= f; m33 /= f;
		return *this;
	}

	bool Matrix4::operator == (const Matrix4 &m) const noexcept
	{
		return IsEqual(m00, m.m00) && IsEqual(m01, m.m01) && IsEqual(m02, m.m02) && IsEqual(m03, m.m03)
			&& IsEqual(m10, m.m10) && IsEqual(m11, m.m11) && IsEqual(m12, m.m12) && IsEqual(m13, m.m13)
			&& IsEqual(m20, m.m20) && IsEqual(m21, m.m21) && IsEqual(m22, m.m22) && IsEqual(m23, m.m23)
			&& IsEqual(m30, m.m30) && IsEqual(m31, m.m31) && IsEqual(m32, m.m32) && IsEqual(m33, m.m33);
	}

	bool Matrix4::operator != (const Matrix4 &m) const noexcept
	{
		return !(*this == m);
	}

	Matrix4 operator * (float f, const Matrix4 &m) noexcept
	{
		return Matrix4(f * m.m00, f * m.m01, f * m.m02, f * m.m03,
			f * m.m10, f * m.m11, f * m.m12, f * m.m13,
			f * m.m20, f * m.m21, f * m.m22, f * m.m23,
			f * m.m30, f * m.m31, f * m.m32, f * m.m33);
	}

	Matrix4::operator float * () noexcept
	{
		return v;
	}

	float Matrix4::Determinant() const noexcept
	{
		return (m00 * m11 - m01 * m10) * (m22 * m33 - m32 * m23)
			+ (m02 * m10 - m00 * m12) * (m21 * m33 - m31 * m23)
			+ (m00 * m13 - m03 * m10) * (m21 * m32 - m31 * m22)
			+ (m01 * m12 - m02 * m11) * (m20 * m33 - m30 * m23)
			+ (m03 * m11 - m01 * m13) * (m20 * m32 - m30 * m22)
			+ (m02 * m13 - m03 * m12) * (m20 * m31 - m30 * m21);
	}

	Matrix4 & Matrix4::Transpose() noexcept
	{
		float tmp = m01; m01 = m10; m10 = tmp;
		tmp = m02; m02 = m20; m20 = tmp;
		tmp = m03; m03 = m30; m30 = tmp;
		tmp = m12; m12 = m21; m21 = tmp;
		tmp = m13; m13 = m31; m31 = tmp;
		tmp = m23; m23 = m32; m32 = tmp;
		return *this;
	}

	bool Matrix4::IsZero() const noexcept
	{
		return (m00 == 0.0f) && (m01 == 0.0f) && (m02 == 0.0f) && (m03 == 0.0f)
			&& (m10 == 0.0f) && (m11 == 0.0f) && (m12 == 0.0f) && (m13 == 0.0f)
			&& (m20 == 0.0f) && (m21 == 0.0f) && (m22 == 0.0f) && (m23 == 0.0f)
			&& (m30 == 0.0f) && (m31 == 0.0f) && (m32 == 0.0f) && (m33 == 0.0f);
	}

	bool Matrix4::IsOne() const noexcept
	{
		return (m00 == 1.0f) && (m01 == 1.0f) && (m02 == 1.0f) && (m03 == 1.0f)
			&& (m10 == 1.0f) && (m11 == 1.0f) && (m12 == 1.0f) && (m13 == 1.0f)
			&& (m20 == 1.0f) && (m21 == 1.0f) && (m22 == 1.0f) && (m23 == 1.0f)
			&& (m30 == 1.0f) && (m31 == 1.0f) && (m32 == 1.0f) && (m33 == 1.0f);
	}

	bool Matrix4::IsIdentity() const noexcept
	{
		return (m00 == 1.0f) && (m01 == 0.0f) && (m02 == 0.0f) && (m03 == 0.0f)
			&& (m10 == 0.0f) && (m11 == 1.0f) && (m12 == 0.0f) && (m13 == 0.0f)
			&& (m20 == 0.0f) && (m21 == 0.0f) && (m22 == 1.0f) && (m23 == 0.0f)
			&& (m30 == 0.0f) && (m31 == 0.0f) && (m32 == 0.0f) && (m33 == 1.0f);
	}

	const Matrix4 Matrix4::Zero = {
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0,
		0.0, 0.0, 0.0, 0.0
	};

	const Matrix4 Matrix4::Identity = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
}