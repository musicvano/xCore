/*
	Math 3D
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once
#include "xCore/Vector2.h"
#include "xCore/Vector3.h"
#include "xCore/Vector4.h"
#include "xCore/Matrix4.h"

namespace xCore
{
	// Returns the dot product of two 2D vectors
	float VectorDot(const Vector2 &v1, const Vector2 &v2) noexcept;

	// Returns the dot product of two 3D vectors
	float VectorDot(const Vector3 &v1, const Vector3 &v2) noexcept;

	// Returns the dot product of two 4D vectors
	float VectorDot(const Vector4 &v1, const Vector4 &v2) noexcept;

	// Returns a cross product of two 3D vectors
	Vector3 VectorCross(const Vector3 &v1, const Vector3 &v2) noexcept;

	// Returns the normalized 2D vector
	Vector2 VectorNormalize(const Vector2 &v) noexcept;

	// Returns the normalized 3D vector
	Vector3 VectorNormalize(const Vector3 &v) noexcept;

	// Returns the normalized 4D vector
	Vector4 VectorNormalize(const Vector4 &v) noexcept;

	// Returns 2D vector performing a linear interpolation v1+s*(v2-v1)
	Vector2 VectorLinerp(const Vector2 &v1, const Vector2 &v2, float s) noexcept;

	// Returns 3D vector performing a linear interpolation v1+s*(v2-v1)
	Vector3 VectorLinerp(const Vector3 &v1, const Vector3 &v2, float s) noexcept;

	// Returns 4D vector performing a linear interpolation v1+s*(v2-v1)
	Vector4 VectorLinerp(const Vector4 &v1, const Vector4 &v2, float s) noexcept;

	// Returns the radian angle between two 2D vectors
	float VectorAngle(const Vector2 &v1, const Vector2 &v2) noexcept;

	// Returns the radian angle between two 3D vectors
	float VectorAngle(const Vector3 &v1, const Vector3 &v2) noexcept;

	// Returns the radian angle between two 4D vectors
	float VectorAngle(const Vector4 &v1, const Vector4 &v2) noexcept;

	// Returns a transformed 3D vector by matrix. Uses {x, y, z, 1}
	Vector3 VectorTransform(const Vector3 &v, const Matrix4 &m) noexcept;

	// Returns a transformed 3D vector by matrix, projectes result back into w=1. Uses {x, y, z, 1}
	Vector3 VectorTransformCoord(const Vector3 &v, const Matrix4 &m) noexcept;

	// Returns a transformed 3D vector by matrix. Uses {x, y, z, 0}
	Vector3 VectorTransformNormal(const Vector3 &v, const Matrix4 &m) noexcept;

	// Returns a transformed 4D vector by matrix
	Vector4 VectorTransform(const Vector4 &v, const Matrix4 &m) noexcept;

	// Returns an identity matrix
	Matrix4 MatrixIdentity() noexcept;

	// Returns a transposed matrix
	Matrix4 MatrixTranspose(const Matrix4 &m) noexcept;

	// Returns a result of matrix multiplication
	Matrix4 MatrixMultiply(const Matrix4 &m1, const Matrix4 &m2) noexcept;

	// Returns an inversed matrix
	Matrix4 MatrixInverse(const Matrix4 &m) noexcept;

	// Returns a matrix which scales by {sx, sy, sz}
	Matrix4 MatrixScaling(float sx, float sy, float sz) noexcept;

	// Returns a matrix which translates by {x, y, z}
	Matrix4 MatrixTranslation(float x, float y, float z) noexcept;

	// Returns a matrix which rotates around the X axis
	Matrix4 MatrixRotationX(float angle) noexcept;

	// Returns a matrix which rotates around the Y axis
	Matrix4 MatrixRotationY(float angle) noexcept;

	// Returns a matrix which rotates around the Z axis
	Matrix4 MatrixRotationZ(float angle) noexcept;

	// Returns a rotation matrix. Yaw around the Y axis, a pitch around the X axis and a roll around the Z axis
	Matrix4 MatrixRotationYawPitchRoll(float yaw, float pitch, float roll) noexcept;

	// Returns a matrix which rotates around an arbitrary axis
	Matrix4 MatrixRotationAxis(const Vector3 &v, float angle) noexcept;

	// Returns a lookat left-handed matrix
	Matrix4 MatrixLookAt(const Vector3 &eye, const Vector3 &at, const Vector3 &up) noexcept;

	// Returns a perspective projection left-handed matrix
	Matrix4 MatrixPerspective(float width, float height, float zNear, float zFar) noexcept;

	// Returns a perspective projection left-handed matrix
	Matrix4 MatrixPerspectiveFov(float FOV, float aspect, float zNear, float zFar) noexcept;

	// Returns an ortho projection left-handed matrix
	Matrix4 MatrixOrtho(float width, float height, float zNear, float zFar) noexcept;
}