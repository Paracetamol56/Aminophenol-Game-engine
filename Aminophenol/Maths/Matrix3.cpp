
#include "pch.h"
#include "Matrix3.h"

namespace Aminophenol::Maths
{

	const Matrix3f Matrix3<float>::zero{ 0.0f };
	const Matrix3f Matrix3<float>::identity{};
	const Matrix3f Matrix3<float>::infinity{ std::numeric_limits<float>::infinity() };

	const Matrix3d Matrix3<double>::zero{ 0.0 };
	const Matrix3d Matrix3<double>::identity{};
	const Matrix3d Matrix3<double>::infinity{ std::numeric_limits<double>::infinity() };

	const Matrix3i Matrix3<int>::zero{ 0 };
	const Matrix3i Matrix3<int>::identity{};
	const Matrix3i Matrix3<int>::infinity{ std::numeric_limits<int>::infinity() };

}
