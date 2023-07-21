
#include "pch.h"
#include "UUIDv4Generator.h"

namespace Aminophenol::Utils {

	UUID::UUID(const std::string& uuid)
	{
		std::stringstream ss{ uuid };
		ss >> std::hex >> m_data[0] >> m_data[1] >> m_data[2] >> m_data[3];
	}

	UUID::UUID(const uint32_t data[4])
	{
		m_data[0] = data[0];
		m_data[1] = data[1];
		m_data[2] = data[2];
		m_data[3] = data[3];
	}

	bool UUID::operator==(const UUID& uuid) const
	{
		return m_data[0] == uuid.m_data[0] && m_data[1] == uuid.m_data[1] && m_data[2] == uuid.m_data[2] && m_data[3] == uuid.m_data[3];
	}

	bool UUID::operator!=(const UUID& uuid) const
	{
		return !(*this == uuid);
	}

	std::string UUID::toString() const
	{
		std::stringstream ss;
		ss << std::hex << std::setfill('0')
			<< std::setw(8) << m_data[0] << "-"
			<< std::setw(4) << (m_data[1] >> 16) << "-"
			<< std::setw(4) << (m_data[1] & 0xFFFF) << "-"
			<< std::setw(4) << (m_data[2] >> 16) << "-"
			<< std::setw(4) << (m_data[2] & 0xFFFF)
			<< std::setw(8) << m_data[3];
		return ss.str();
	}

} // namespace Aminophenol
