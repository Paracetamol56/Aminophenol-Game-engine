
#ifndef HASH_COMBINE_H
#define HASH_COMBINE_H

#include "pch.h"

namespace Aminophenol::Utils {

	/// <summary>
	/// Utility function to combine the hash of several values into a single hash.
	/// Origin: https://stackoverflow.com/a/57595105
	/// </summary>
	/// <typeparam name="T">Type of the structure</typeparam>
	/// <typeparam name="...Args">Types of the members of the structure</typeparam>
	/// <param name="seed">Seed of the hash</param>
	/// <param name="v">First member of the structure</param>
	/// <param name="...args">Other members of the structure</param>
	template <typename T, typename... Rest>
	void hashCombine(std::size_t& seed, const T& v, const Rest&... rest)
	{
		seed ^= std::hash<T>{}(v)+0x9e3779b9 + (seed << 6) + (seed >> 2);
		(hashCombine(seed, rest), ...);
	};

} // namespace Aminophenol

#endif // HASH_COMBINE_H
