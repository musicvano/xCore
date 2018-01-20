/*
	Matrix 4x4
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once

namespace xCore
{
	// A standard 4x4 transformation matrix
	class Matrix4
	{
	public:
		union
		{
			struct
			{
				float m00, m01, m02, m03;
				float m10, m11, m12, m13;
				float m20, m21, m22, m23;
				float m30, m31, m32, m33;
			};
			float m[4][4];
			float v[16];
		};

		Matrix4() noexcept {}
		Matrix4(float f) noexcept;
		Matrix4(const float *v) noexcept;
		Matrix4(float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33) noexcept;

		Matrix4 operator + () const noexcept;
		Matrix4 operator - () const noexcept;

		Matrix4 operator + (const Matrix4 &m) const noexcept;
		Matrix4 operator - (const Matrix4 &m) const noexcept;
		Matrix4 operator * (const Matrix4 &m) const noexcept;
		Matrix4 operator + (float f) const noexcept;
		Matrix4 operator - (float f) const noexcept;
		Matrix4 operator * (float f) const noexcept;
		Matrix4 operator / (float f) const noexcept;

		Matrix4 & operator += (const Matrix4 &m) noexcept;
		Matrix4 & operator -= (const Matrix4 &m) noexcept;
		Matrix4 & operator *= (const Matrix4 &m) noexcept;
		Matrix4 & operator += (float f) noexcept;
		Matrix4 & operator -= (float f) noexcept;
		Matrix4 & operator *= (float f) noexcept;
		Matrix4 & operator /= (float f) noexcept;

		bool operator == (const Matrix4 &m) const noexcept;
		bool operator != (const Matrix4 &m) const noexcept;

		friend Matrix4 operator * (float f, const Matrix4 &m) noexcept;
		explicit operator float*() noexcept;

		// Returns a determinant of the matrix
		float Determinant() const noexcept;

		// Transposes the matrix - columns exchanged with rows
		Matrix4 & Transpose() noexcept;

		// Returns true if all elements ot the matrix is 0.0
		bool IsZero() const noexcept;

		// Returns true if all elements ot the matrix is 1.0
		bool IsOne() const noexcept;

		// Returns true if the matrix is identity
		bool IsIdentity() const noexcept;

		// Constant zero matrix
		static const Matrix4 Zero;

		// Constant identity matrix
		static const Matrix4 Identity;
	};
}