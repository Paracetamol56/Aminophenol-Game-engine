
#include "pch.h"
#include "Vector3.h"

namespace Aminophenol::Maths
{

	const Vector3f Vector3<float>::zero(0.0f);
	const Vector3f Vector3<float>::unit(1.0f);
	const Vector3f Vector3<float>::infinity(std::numeric_limits<float>::infinity());
	const Vector3f Vector3<float>::left(-1.0f, 0.0f, 0.0f);
	const Vector3f Vector3<float>::right(1.0f, 0.0f, 0.0f);
	const Vector3f Vector3<float>::up(0.0f, 1.0f, 0.0f);
	const Vector3f Vector3<float>::down(0.0f, -1.0f, 0.0f);
	const Vector3f Vector3<float>::forward(0.0f, 0.0f, 1.0f);
	const Vector3f Vector3<float>::backward(0.0f, 0.0f, -1.0f);

	const Vector3d Vector3<double>::zero(0.0);
	const Vector3d Vector3<double>::unit(1.0);
	const Vector3d Vector3<double>::infinity(std::numeric_limits<double>::infinity());
	const Vector3d Vector3<double>::left(-1.0, 0.0, 0.0);
	const Vector3d Vector3<double>::right(1.0, 0.0, 0.0);
	const Vector3d Vector3<double>::up(0.0, 1.0, 0.0);
	const Vector3d Vector3<double>::down(0.0, -1.0, 0.0);
	const Vector3d Vector3<double>::forward(0.0, 0.0, 1.0);
	const Vector3d Vector3<double>::backward(0.0, 0.0, -1.0);

	const Vector3i Vector3<int>::zero(0);
	const Vector3i Vector3<int>::unit(1);
	const Vector3i Vector3<int>::infinity(std::numeric_limits<int>::infinity());
	const Vector3i Vector3<int>::left(-1, 0, 0);
	const Vector3i Vector3<int>::right(1, 0, 0);
	const Vector3i Vector3<int>::up(0, 1, 0);
	const Vector3i Vector3<int>::down(0, -1, 0);
	const Vector3i Vector3<int>::forward(0, 0, 1);
	const Vector3i Vector3<int>::backward(0, 0, -1);

}