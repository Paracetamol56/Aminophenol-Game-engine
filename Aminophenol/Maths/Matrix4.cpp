
#include "pch.h"
#include "Matrix4.h"

namespace Aminophenol::Maths
{

	const Matrix4f Matrix4<float>::zero{ 0.0f };
	const Matrix4f Matrix4<float>::identity{};
	const Matrix4f Matrix4<float>::infinity{ std::numeric_limits<float>::infinity() };

	const Matrix4d Matrix4<double>::zero{ 0.0 };
	const Matrix4d Matrix4<double>::identity{};
	const Matrix4d Matrix4<double>::infinity{ std::numeric_limits<double>::infinity() };

	const Matrix4i Matrix4<int>::zero{ 0 };
	const Matrix4i Matrix4<int>::identity{};
	const Matrix4i Matrix4<int>::infinity{ std::numeric_limits<int>::infinity() };

}
