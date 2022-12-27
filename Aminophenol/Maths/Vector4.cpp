
#include "pch.h"
#include "Vector4.h"

namespace Aminophenol::Maths
{

	const Vector4f Vector4<float>::zero(0.0f);
	const Vector4f Vector4<float>::unit(1.0f);
	const Vector4f Vector4<float>::infinity(std::numeric_limits<float>::infinity());

	const Vector4d Vector4<double>::zero(0.0);
	const Vector4d Vector4<double>::unit(1.0);
	const Vector4d Vector4<double>::infinity(std::numeric_limits<double>::infinity());

	const Vector4i Vector4<int>::zero(0);
	const Vector4i Vector4<int>::unit(1);
	const Vector4i Vector4<int>::infinity(std::numeric_limits<int>::infinity());

	const Vector4ui Vector4<unsigned int>::zero(0);
	const Vector4ui Vector4<unsigned int>::unit(1);

	const Vector4us Vector4<unsigned short>::zero(0);
	const Vector4us Vector4<unsigned short>::unit(1);

}