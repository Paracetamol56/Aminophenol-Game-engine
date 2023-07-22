
#include "pch.h"
#include "Matrix2.h"

namespace Aminophenol::Maths
{

	const Matrix2f Matrix2<float>::zero{ 0.0f };
	const Matrix2f Matrix2<float>::identity{};
	const Matrix2f Matrix2<float>::infinity{ std::numeric_limits<float>::infinity() };

	const Matrix2d Matrix2<double>::zero{ 0.0 };
	const Matrix2d Matrix2<double>::identity{};
	const Matrix2d Matrix2<double>::infinity{ std::numeric_limits<double>::infinity() };

	const Matrix2i Matrix2<int>::zero{ 0 };
	const Matrix2i Matrix2<int>::identity{};
	const Matrix2i Matrix2<int>::infinity{ std::numeric_limits<int>::infinity() };

}
