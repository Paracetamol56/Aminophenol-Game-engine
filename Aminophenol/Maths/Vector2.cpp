
#include "pch.h"
#include "Vector2.h"

namespace Aminophenol::Maths
{
	
	const Vector2f Vector2<float>::zero(0.0f);
	const Vector2f Vector2<float>::unit(1.0f);
	const Vector2f Vector2<float>::infinity(std::numeric_limits<float>::infinity());
	const Vector2f Vector2<float>::left(-1.0f, 0.0f);
	const Vector2f Vector2<float>::right(1.0f, 0.0f);
	const Vector2f Vector2<float>::up(0.0f, 1.0f);
	const Vector2f Vector2<float>::down(0.0f, -1.0f);

	const Vector2d Vector2<double>::zero(0.0);
	const Vector2d Vector2<double>::unit(1.0);
	const Vector2d Vector2<double>::infinity(std::numeric_limits<double>::infinity());
	const Vector2d Vector2<double>::left(-1.0, 0.0);
	const Vector2d Vector2<double>::right(1.0, 0.0);
	const Vector2d Vector2<double>::up(0.0, 1.0);
	const Vector2d Vector2<double>::down(0.0, -1.0);
	
	const Vector2i Vector2<int>::zero(0);
	const Vector2i Vector2<int>::unit(1);
	const Vector2i Vector2<int>::infinity(std::numeric_limits<int>::infinity());
	const Vector2i Vector2<int>::left(-1, 0);
	const Vector2i Vector2<int>::right(1, 0);
	const Vector2i Vector2<int>::up(0, 1);
	const Vector2i Vector2<int>::down(0, -1);

	const Vector2ui Vector2<unsigned int>::zero(0);
	const Vector2ui Vector2<unsigned int>::unit(1);
	
	const Vector2us Vector2<unsigned short>::zero(0);
	const Vector2us Vector2<unsigned short>::unit(1);
	
}