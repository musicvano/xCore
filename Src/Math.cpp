/*
	Math
	xCore library
	2018 © Ivan Muzyka
	Licensed under the MIT license
*/

#include "xCore/Math.h"
#include <cmath>

namespace xCore
{
	int Abs(int x) noexcept
	{
		return abs(x);
	}

	float Abs(float x) noexcept
	{
		return fabsf(x);
	}

	double Abs(double x) noexcept
	{
		return fabs(x);
	}

	bool IsInf(float x) noexcept
	{
		return std::isinf(x);
	}

	bool IsInf(double x) noexcept
	{
		return std::isinf(x);
	}

	bool IsNaN(float x) noexcept
	{
		return isnan(x);
	}

	bool IsNaN(double x) noexcept
	{
		return isnan(x);
	}

	float Sqrt(float x) noexcept
	{
		return sqrtf(x);
	}

	double Sqrt(double x) noexcept
	{
		return sqrt(x);
	}

	float Sin(float x) noexcept
	{
		return sinf(x);
	}

	double Sin(double x) noexcept
	{
		return sin(x);
	}

	float Cos(float x) noexcept
	{
		return cosf(x);
	}

	double Cos(double x) noexcept
	{
		return cos(x);
	}

	float Tan(float x) noexcept
	{
		return tanf(x);
	}

	double Tan(double x) noexcept
	{
		return tan(x);
	}

	float Cotan(float x) noexcept
	{
		return cosf(x) / sinf(x);
	}

	double Cotan(double x) noexcept
	{
		return cos(x) / sin(x);
	}

	float Asin(float x) noexcept
	{
		return asinf(x);
	}

	double Asin(double x) noexcept
	{
		return asin(x);
	}

	float Acos(float x) noexcept
	{
		return acosf(x);
	}

	double Acos(double x) noexcept
	{
		return acos(x);
	}

	float Atan(float x) noexcept
	{
		return atanf(x);
	}

	double Atan(double x) noexcept
	{
		return atan(x);
	}

	float Sinh(float x) noexcept
	{
		return sinhf(x);
	}

	double Sinh(double x) noexcept
	{
		return sinh(x);
	}

	float Cosh(float x) noexcept
	{
		return coshf(x);
	}

	double Cosh(double x) noexcept
	{
		return cosh(x);
	}

	float Tanh(float x) noexcept
	{
		return tanhf(x);
	}

	double Tanh(double x) noexcept
	{
		return tanh(x);
	}

	float Cotanh(float x) noexcept
	{
		return coshf(x) / sinhf(x);
	}

	double Cotanh(double x) noexcept
	{
		return cosh(x) / sinh(x);
	}

	float Asinh(float x) noexcept
	{
		return asinhf(x);
	}

	double Asinh(double x) noexcept
	{
		return asinh(x);
	}

	float Acosh(float x) noexcept
	{
		return acoshf(x);
	}

	double Acosh(double x) noexcept
	{
		return acosh(x);
	}

	float Atanh(float x) noexcept
	{
		return atanhf(x);
	}

	double Atanh(double x) noexcept
	{
		return atanh(x);
	}

	float Exp(float x) noexcept
	{
		return expf(x);
	}

	double Exp(double x) noexcept
	{
		return exp(x);
	}

	float Exp2(float x) noexcept
	{
		return exp2f(x);
	}

	double Exp2(double x) noexcept
	{
		return exp2(x);
	}

	float Log(float x) noexcept
	{
		return logf(x);
	}

	double Log(double x) noexcept
	{
		return log(x);
	}

	float Log10(float x) noexcept
	{
		return log10f(x);
	}

	double Log10(double x) noexcept
	{
		return log10(x);
	}

	float Log1p(float x) noexcept
	{
		return log1pf(x);
	}

	double Log1p(double x) noexcept
	{
		return log1p(x);
	}

	float Log2(float x) noexcept
	{
		return log2f(x);
	}

	double Log2(double x) noexcept
	{
		return log2(x);
	}

	float Log(float x, float base) noexcept
	{
		return logf(x) / logf(base);
	}

	double Log(double x, double base) noexcept
	{
		return log(x) / log(base);
	}

	float Pow(float x, float y) noexcept
	{
		return powf(x, y);
	}

	double Pow(double x, double y) noexcept
	{
		return pow(x, y);
	}

	float Ceil(float x) noexcept
	{
		return ceilf(x);
	}

	double Ceil(double x) noexcept
	{
		return ceil(x);
	}

	float Floor(float x) noexcept
	{
		return floorf(x);
	}

	double Floor(double x) noexcept
	{
		return floor(x);
	}

	float Round(float x) noexcept
	{
		return roundf(x);
	}

	double Round(double x) noexcept
	{
		return round(x);
	}

	float Trunc(float x) noexcept
	{
		return truncf(x);
	}

	double Trunc(double x) noexcept
	{
		return trunc(x);
	}
}