
#ifndef UUID_V4_GENERATOR_H
#define UUID_V4_GENERATOR_H

#include "pch.h"

namespace Aminophenol::Utils {
	
	class AMINOPHENOL_API UUID
	{
	public:

		UUID() = default;
		UUID(const uint32_t data[4]);
		UUID(const std::string& uuid);
		UUID(const UUID& uuid) = default;
		UUID(UUID&& uuid) = default;
		~UUID() = default;

		UUID& operator=(const UUID& uuid) = default;
		UUID& operator=(UUID&& uuid) = default;

		bool operator==(const UUID& uuid) const;
		bool operator!=(const UUID& uuid) const;

		std::string toString() const;
		
	private:

		uint32_t m_data[4]{ 0, 0, 0, 0 };

	};
	
	template <typename Engine>
	class AMINOPHENOL_API UUIDv4Generator
	{
	public:

		UUIDv4Generator()
		{
			m_engine.seed(std::random_device{}());
		}

		static UUID getUUID()
		{
			uint32_t uuidData[4];
			uuidData[0] = m_distribution(m_engine);
			uuidData[1] = m_distribution(m_engine);
			uuidData[2] = m_distribution(m_engine);
			uuidData[3] = m_distribution(m_engine);
			return UUID{ uuidData };
		}
		
	private:
		
		static inline Engine m_engine;
		static inline std::uniform_int_distribution<uint32_t> m_distribution{ 0, 0xFFFFFFFF };

	};

	using UUIDv4Generator32 = UUIDv4Generator<std::mt19937>;
	// using UUIDv4Generator64 = UUIDv4Generator<std::mt19937_64>;

} // namespace Utils

#endif // UUID_V4_GENERATOR_H