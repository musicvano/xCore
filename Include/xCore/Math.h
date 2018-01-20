/*
	Math
	xCore Library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#pragma once

namespace xCore
{
	// Constant π
	const double PI = 3.14159265358979323846;

	// Constant e represents the base of natural logarithm
	const double E = 2.71828182845904523536;

	// Returns the absolute value of x: |x|
	int Abs(int x) noexcept;

	// Returns the absolute value of x: |x|
	float Abs(float x) noexcept;

	// Returns the absolute value of x: |x|
	double Abs(double x) noexcept;

	// Returns whether x is an infinity value (either positive infinity or negative infinity)
	bool IsInf(float x) noexcept;

	// Returns whether x is an infinity value (either positive infinity or negative infinity)
	bool IsInf(double x) noexcept;

	// Returns whether x is a NaN (not a number) value
	bool IsNaN(float x) noexcept;

	// Returns whether x is a NaN (not a number) value
	bool IsNaN(double x) noexcept;

	// Returns the square root of x
	float Sqrt(float x) noexcept;

	// Returns the square root of x
	double Sqrt(double x) noexcept;

	// Returns the sine of an angle of x radians
	float Sin(float x) noexcept;

	// Returns the sine of an angle of x radians
	double Sin(double x) noexcept;

	// Returns the cosine of an angle of x radians
	float Cos(float x) noexcept;

	// Returns the cosine of an angle of x radians
	double Cos(double x) noexcept;

	// Returns the tangent of an angle of x radians
	float Tan(float x) noexcept;

	// Returns the tangent of an angle of x radians
	double Tan(double x) noexcept;

	// Returns the tangent of an angle of x radians
	float Cotan(float x) noexcept;

	// Returns the tangent of an angle of x radians
	double Cotan(double x) noexcept;

	// Returns the principal value of the arc sine of x, expressed in radians
	float Asin(float x) noexcept;

	// Returns the principal value of the arc sine of x, expressed in radians
	double Asin(double x) noexcept;

	// Returns the principal value of the arc cosine of x, expressed in radians
	float Acos(float x) noexcept;

	// Returns the principal value of the arc cosine of x, expressed in radians
	double Acos(double x) noexcept;

	// Returns the principal value of the arc tangent of x, expressed in radians
	float Atan(float x) noexcept;

	// Returns the principal value of the arc tangent of x, expressed in radians
	double Atan(double x) noexcept;

	// Returns the hyperbolic sine of x
	float Sinh(float x) noexcept;

	// Returns the hyperbolic sine of x
	double Sinh(double x) noexcept;

	// Returns the hyperbolic cosine of x
	float Cosh(float x) noexcept;

	// Returns the hyperbolic cosine of x
	double Cosh(double x) noexcept;

	// Returns the hyperbolic tangent of x
	float Tanh(float x) noexcept;

	// Returns the hyperbolic tangent of x
	double Tanh(double x) noexcept;

	// Returns the hyperbolic cotangent of x
	float Cotanh(float x) noexcept;

	// Returns the hyperbolic cotangent of x
	double Cotanh(double x) noexcept;

	// Returns the area hyperbolic sine of x
	float Asinh(float x) noexcept;

	// Returns the area hyperbolic sine of x
	double Asinh(double x) noexcept;

	// Returns the area hyperbolic cosine of x
	float Acosh(float x) noexcept;

	// Returns the area hyperbolic cosine of x
	double Acosh(double x) noexcept;

	// Returns the area hyperbolic tangent of x
	float Atanh(float x) noexcept;

	// Returns the area hyperbolic tangent of x
	double Atanh(double x) noexcept;

	// Returns e raised to the specified power: e^x
	float Exp(float x) noexcept;

	// Returns e raised to the specified power: e^x
	double Exp(double x) noexcept;

	// Returns 2 raised to the power x: 2^x
	float Exp2(float x) noexcept;

	// Returns 2 raised to the power x: 2^x
	double Exp2(double x) noexcept;

	// Returns the natural logarithm of x: ln(x)
	float Log(float x) noexcept;

	// Returns the natural logarithm of x: ln(x)
	double Log(double x) noexcept;

	// Returns the common (base 10) logarithm of x: lg(x)
	float Log10(float x) noexcept;

	// Returns the common (base 10) logarithm of x: lg(x)
	double Log10(double x) noexcept;

	// Returns the natural logarithm of one plus x: ln(1+x)
	float Log1p(float x) noexcept;

	// Returns the natural logarithm of one plus x: ln(1+x)
	double Log1p(double x) noexcept;

	// Returns the binary (base-2) logarithm of x
	float Log2(float x) noexcept;

	// Returns the binary (base-2) logarithm of x
	double Log2(double x) noexcept;

	// Returns the logarithm of x in a specified base
	float Log(float x, float base) noexcept;

	// Returns the logarithm of x in a specified base
	double Log(double x, double base) noexcept;

	// Returns the number x raised to the power y
	float Pow(float x, float y) noexcept;

	// Returns the number x raised to the power y
	double Pow(double x, double y) noexcept;

	// Rounds x upward, returning the smallest integral value that is not less than x
	float Ceil(float x) noexcept;

	// Rounds x upward, returning the smallest integral value that is not less than x
	double Ceil(double x) noexcept;

	// Rounds x downward, returning the largest integral value that is not greater than x
	float Floor(float x) noexcept;

	// Rounds x downward, returning the largest integral value that is not greater than x
	double Floor(double x) noexcept;

	// Returns the integral value that is nearest to x, with halfway cases rounded away from zero
	float Round(float x) noexcept;

	// Returns the integral value that is nearest to x, with halfway cases rounded away from zero
	double Round(double x) noexcept;

	// Rounds x toward zero, returning the nearest integral value that is not larger in magnitude than x
	float Trunc(float x) noexcept;

	// Rounds x toward zero, returning the nearest integral value that is not larger in magnitude than x
	double Trunc(double x) noexcept;

	// Returns an integer that indicates the sign of x
	template <typename T>
	int Sign(T x) noexcept
	{
		return x == 0 ? 0 : (x < 0 ? -1 : 1);
	};

	// Returns the larger of two numbers x and y
	template <typename T>
	T Max(T x, T y) noexcept
	{
		return x > y ? x : y;
	}

	// Returns the smaller of two numbers x and y
	template <typename T>
	T Min(T x, T y) noexcept
	{
		return x < y ? x : y;
	}

	// Returns true if x equals y
	template <typename T>
	bool IsEqual(T x, T y) noexcept
	{
		return x == y;
	}

	// Returns true if x equals y, taking a rounding tolerance into account
	template <typename T>
	bool IsEqual(T x, T y, T eps) noexcept
	{
		return Abs(x - y) <= eps;
	}

	// Returns if x equals zero
	template <typename T>
	bool IsZero(T x) noexcept
	{
		return x == T(0);
	}

	// Returns if x equals zero, taking rounding errors into account
	template <typename T>
	bool IsZero(T x, T eps) noexcept
	{
		return Abs(x) <= eps;
	}

	// Transforms radians to degrees
	template<typename T>
	auto RadToDeg(T angle) noexcept
	{
		return 180 * angle / T(PI);
	}

	// Transforms degrees to radians
	template<typename T>
	auto DegToRad(T angle) noexcept
	{
		return T(PI) * angle / 180;
	}
}