/*
	Math 3D
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Math3D.h"
#include "xCore/Math.h"

namespace xCore
{
	float VectorDot(const Vector2 &v1, const Vector2 &v2) noexcept
	{
		return v1.x * v2.x + v1.y * v2.y;
	}

	float VectorDot(const Vector3 &v1, const Vector3 &v2) noexcept
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	float VectorDot(const Vector4 &v1, const Vector4 &v2) noexcept
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w;
	}

	Vector3 VectorCross(const Vector3 &v1, const Vector3 &v2) noexcept
	{
		return Vector3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	}

	Vector2 VectorNormalize(const Vector2 &v) noexcept
	{
		float length = v.Length();
		return Vector2(v.x / length, v.y / length);
	}

	Vector3 VectorNormalize(const Vector3 &v) noexcept
	{
		float length = v.Length();
		return Vector3(v.x / length, v.y / length, v.z / length);
	}

	Vector4 VectorNormalize(const Vector4 &v) noexcept
	{
		float length = v.Length();
		return Vector4(v.x / length, v.y / length, v.z / length, v.w / length);
	}

	Vector2 VectorLinerp(const Vector2 &v1, const Vector2 &v2, float s) noexcept
	{
		return Vector2(v1.x + s * (v2.x - v1.x), v1.y + s * (v2.y - v1.y));
	}

	Vector3 VectorLinerp(const Vector3 &v1, const Vector3 &v2, float s) noexcept
	{
		return Vector3(v1.x + s * (v2.x - v1.x), v1.y + s * (v2.y - v1.y), v1.z + s * (v2.z - v1.z));
	}

	Vector4 VectorLinerp(const Vector4 &v1, const Vector4 &v2, float s) noexcept
	{
		return Vector4(v1.x + s * (v2.x - v1.x), v1.y + s * (v2.y - v1.y), v1.z + s * (v2.z - v1.z), v1.w + s * (v2.w - v1.w));
	}

	float VectorAngle(const Vector2 &v1, const Vector2 &v2) noexcept
	{
		return Acos(VectorDot(v1, v2) / (v1.Length() * v2.Length()));
	}

	float VectorAngle(const Vector3 &v1, const Vector3 &v2) noexcept
	{
		return Acos(VectorDot(v1, v2) / (v1.Length() * v2.Length()));
	}

	float VectorAngle(const Vector4 &v1, const Vector4 &v2) noexcept
	{
		return Acos(VectorDot(v1, v2) / (v1.Length() * v2.Length()));
	}

	Vector3 VectorTransform(const Vector3 &v, const Matrix4 &m) noexcept
	{
		return Vector3(v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + m.m30,
			v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + m.m31,
			v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + m.m32);
	}

	Vector3 VectorTransformCoord(const Vector3 &v, const Matrix4 &m) noexcept
	{
		float invW = 1.0f / (v.x * m.m03 + v.y * m.m13 + v.z * m.m23 + m.m33);
		return Vector3(invW * (v.x * m.m00 + v.y * m.m10 + v.z * m.m20 + m.m30),
			invW * (v.x * m.m01 + v.y * m.m11 + v.z * m.m21 + m.m31),
			invW * (v.x * m.m02 + v.y * m.m12 + v.z * m.m22 + m.m32));
	}

	Vector3 VectorTransformNormal(const Vector3 &v, const Matrix4 &m) noexcept
	{
		return Vector3(v.x * m.m00 + v.y * m.m10 + v.z * m.m20,
			v.x * m.m01 + v.y * m.m11 + v.z * m.m21,
			v.x * m.m02 + v.y * m.m12 + v.z * m.m22);
	}

	Vector4 VectorTransform(const Vector4 &v, const Matrix4 &m) noexcept
	{
		return v * m;
	}

	Matrix4 MatrixIdentity() noexcept
	{
		return Matrix4::Identity;
	}

	Matrix4 MatrixTranspose(const Matrix4 &m) noexcept
	{
		return Matrix4(m.m00, m.m10, m.m20, m.m30,
			m.m01, m.m11, m.m21, m.m31,
			m.m02, m.m12, m.m22, m.m32,
			m.m03, m.m13, m.m23, m.m33);
	}

	Matrix4 MatrixMultiply(const Matrix4 &m1, const Matrix4 &m2) noexcept
	{
		return m1 * m2;
	}

	Matrix4 MatrixInverse(const Matrix4 &m) noexcept
	{
		float invDet = 1.0f / m.Determinant(),
			B1021 = m.m10*m.m21 - m.m20*m.m11,
			B1022 = m.m10*m.m22 - m.m20*m.m12,
			B1023 = m.m10*m.m23 - m.m20*m.m13,
			B1031 = m.m10*m.m31 - m.m30*m.m11,
			B1032 = m.m10*m.m32 - m.m30*m.m12,
			B1033 = m.m10*m.m33 - m.m30*m.m13,
			B1122 = m.m11*m.m22 - m.m21*m.m12,
			B1123 = m.m11*m.m23 - m.m21*m.m13,
			B1132 = m.m11*m.m32 - m.m31*m.m12,
			B1133 = m.m11*m.m33 - m.m31*m.m13,
			B1223 = m.m12*m.m23 - m.m22*m.m13,
			B1233 = m.m12*m.m33 - m.m32*m.m13,
			B2031 = m.m20*m.m31 - m.m30*m.m21,
			B2032 = m.m20*m.m32 - m.m30*m.m22,
			B2033 = m.m20*m.m33 - m.m30*m.m23,
			B2132 = m.m21*m.m32 - m.m31*m.m22,
			B2133 = m.m21*m.m33 - m.m31*m.m23,
			B2233 = m.m22*m.m33 - m.m32*m.m23,
			A00 = invDet * (m.m11*B2233 - m.m12*B2133 + m.m13*B2132),
			A01 = -invDet * (m.m10*B2233 - m.m12*B2033 + m.m13*B2032),
			A02 = invDet * (m.m10*B2133 - m.m11*B2033 + m.m13*B2031),
			A03 = -invDet * (m.m10*B2132 - m.m11*B2032 + m.m12*B2031),
			A10 = -invDet * (m.m01*B2233 - m.m02*B2133 + m.m03*B2132),
			A11 = invDet * (m.m00*B2233 - m.m02*B2033 + m.m03*B2032),
			A12 = -invDet * (m.m00*B2133 - m.m01*B2033 + m.m03*B2031),
			A13 = invDet * (m.m00*B2132 - m.m01*B2032 + m.m02*B2031),
			A20 = invDet * (m.m01*B1233 - m.m02*B1133 + m.m03*B1132),
			A21 = -invDet * (m.m00*B1233 - m.m02*B1033 + m.m03*B1032),
			A22 = invDet * (m.m00*B1133 - m.m01*B1033 + m.m03*B1031),
			A23 = -invDet * (m.m00*B1132 - m.m01*B1032 + m.m02*B1031),
			A30 = -invDet * (m.m01*B1223 - m.m02*B1123 + m.m03*B1122),
			A31 = invDet * (m.m00*B1223 - m.m02*B1023 + m.m03*B1022),
			A32 = -invDet * (m.m00*B1123 - m.m01*B1023 + m.m03*B1021),
			A33 = invDet * (m.m00*B1122 - m.m01*B1022 + m.m02*B1021);

		return Matrix4(A00, A10, A20, A30,
			A01, A11, A21, A31,
			A02, A12, A22, A32,
			A03, A13, A23, A33);
	}

	Matrix4 MatrixScaling(float sx, float sy, float sz) noexcept
	{
		return Matrix4(sx, 0.0, 0.0, 0.0,
			0.0, sy, 0.0, 0.0,
			0.0, 0.0, sz, 0.0,
			0.0, 0.0, 0.0, 1.0);
	}

	Matrix4 MatrixTranslation(float x, float y, float z) noexcept
	{
		return Matrix4(1.0, 0.0, 0.0, 0.0,
			0.0, 1.0, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			x, y, z, 1.0);
	}

	Matrix4 MatrixRotationX(float angle) noexcept
	{
		float sin = Sin(angle), cos = Cos(angle);
		return Matrix4(1.0, 0.0, 0.0, 0.0,
			0.0, cos, sin, 0.0,
			0.0, -sin, cos, 0.0,
			0.0, 0.0, 0.0, 1.0);
	}

	Matrix4 MatrixRotationY(float angle) noexcept
	{
		float sin = Sin(angle), cos = Cos(angle);
		return Matrix4(cos, 0.0, -sin, 0.0,
			0.0, 1.0, 0.0, 0.0,
			sin, 0.0, cos, 0.0,
			0.0, 0.0, 0.0, 1.0);
	}

	Matrix4 MatrixRotationZ(float angle) noexcept
	{
		float sin = Sin(angle), cos = Cos(angle);
		return Matrix4(cos, sin, 0.0, 0.0,
			-sin, cos, 0.0, 0.0,
			0.0, 0.0, 1.0, 0.0,
			0.0, 0.0, 0.0, 1.0);
	}

	Matrix4 MatrixRotationYawPitchRoll(float yaw, float pitch, float roll) noexcept
	{
		float sinY = Sin(yaw), cosY = Cos(yaw),
			sinP = Sin(pitch), cosP = Cos(pitch),
			sinR = Sin(roll), cosR = Cos(roll),
			srsp = sinR * sinP, crsp = cosR * sinP;
		return Matrix4(srsp*sinY + cosR * cosY, sinR*cosP, srsp*cosY - cosR * sinY, 0.0,
			crsp*sinY - sinR * cosY, cosR*cosP, crsp*cosY + sinR * sinY, 0.0,
			cosP*sinY, -sinP, cosP*cosY, 0.0,
			0.0, 0.0, 0.0, 1.0);
	}

	Matrix4 MatrixRotationAxis(const Vector3 &v, float angle) noexcept
	{
		Vector3 n = VectorNormalize(v);
		float sin = Sin(angle), cos = Cos(angle), oneCos = 1 - cos,
			cxx = oneCos * n.x * n.x, cyy = oneCos * n.y * n.y, czz = oneCos * n.z * n.z,
			cxy = oneCos * n.x * n.y, cxz = oneCos * n.x * n.z, cyz = oneCos * n.y * n.z,
			sinx = sin * n.x, siny = sin * n.y, sinz = sin * n.z;
		return Matrix4(cxx + cos, cxy + sinz, cxz - siny, 0.0,
			cxy - sinz, cyy + cos, cyz + sinx, 0.0,
			cxz + siny, cyz - sinx, czz + cos, 0.0,
			0.0, 0.0, 0.0, 1.0);
	}

	Matrix4 MatrixLookAt(const Vector3 &eye, const Vector3 &at, const Vector3 &up) noexcept
	{
		Vector3 xAxis, yAxis, zAxis;
		zAxis = VectorNormalize(at - eye);
		xAxis = VectorNormalize(VectorCross(up, zAxis));
		yAxis = VectorCross(zAxis, xAxis);

		float dotX, dotY, dotZ;
		dotX = VectorDot(xAxis, eye);
		dotY = VectorDot(yAxis, eye);
		dotZ = VectorDot(zAxis, eye);

		return Matrix4(xAxis.x, yAxis.x, zAxis.x, 0.0,
			xAxis.y, yAxis.y, zAxis.y, 0.0,
			xAxis.z, yAxis.z, zAxis.z, 0.0,
			-dotX, -dotY, -dotZ, 1.0);
	}

	Matrix4 MatrixPerspective(float width, float height, float zNear, float zFar) noexcept
	{
		return Matrix4(2.0f*zNear / width, 0.0, 0.0, 0.0,
			0.0, 2.0f*zNear / height, 0.0, 0.0,
			0.0, 0.0, zFar / (zFar - zNear), 1.0,
			0.0, 0.0, zNear*zFar / (zNear - zFar), 0.0);
	}

	Matrix4 MatrixPerspectiveFov(float FOV, float aspect, float zNear, float zFar) noexcept
	{
		float yScale = 1.0f / Tan(FOV / 2.0f),
			xScale = yScale / aspect,
			zfn = zFar / (zFar - zNear);
		return Matrix4(xScale, 0.0, 0.0, 0.0,
			0.0, yScale, 0.0, 0.0,
			0.0, 0.0, zfn, 1.0,
			0.0, 0.0, -zNear * zfn, 0.0);
	}

	Matrix4 MatrixOrtho(float width, float height, float zNear, float zFar) noexcept
	{
		float zfn = 1.0f / (zFar - zNear);
		return Matrix4(2.0f / width, 0.0, 0.0, 0.0,
			0.0, 2.0f / height, 0.0, 0.0,
			0.0, 0.0, zfn, 0.0,
			0.0, 0.0, -zNear * zfn, 1.0f);
	}
}