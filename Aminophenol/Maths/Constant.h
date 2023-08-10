
#ifndef CONSTANT_H
#define CONSTANT_H

namespace Aminophenol::Maths::Constant
{

	/// <summary>
	/// Zero
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T zero();

	/// <summary>
	/// One
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T one();

	/// <summary>
	/// Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T pi();

	/// <summary>
	/// Two Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T twoPi();

	/// <summary>
	/// Half Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T halfPi();

	/// <summary>
	/// Quarter Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T quarterPi();

	/// <summary>
	/// Three quarter Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T threeQuarterPi();

	/// <summary>
	/// Pi squared
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T piSquared();

	/// <summary>
	/// Root Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T rootPi();

	/// <summary>
	/// Root two Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T rootTwoPi();

	/// <summary>
	/// One over Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T oneOverPi();

	/// <summary>
	/// Pi over 180
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T piOverOneEighty();

	/// <summary>
	/// 180 over Pi
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T oneEightyOverPi();

	/// <summary>
	/// Root two
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T rootTwo();

	/// <summary>
	/// Ln two
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T lnTwo();

	/// <summary>
	/// Ln ten
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T lnTen();

	/// <summary>
	/// E
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T e();

	/// <summary>
	/// Euler's constant
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T euler();

	/// <summary>
	/// Golden ratio
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <returns></returns>
	template<typename T>
	const T phi();

} // namespace Aminophenol::Maths

#include "Constant.inl"

#endif // !CONSTANT_H
