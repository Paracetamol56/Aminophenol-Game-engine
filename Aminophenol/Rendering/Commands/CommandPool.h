
#ifndef COMMAND_POOL_H
#define COMMAND_POOL_H

#include "pch.h"
#include "Rendering/Device/LogicalDevice.h"

namespace Aminophenol {

	class CommandPool
	{
	public:

		CommandPool(const LogicalDevice& logicalDevice);
		~CommandPool();

		operator const VkCommandPool& () const;

	private:

		VkCommandPool m_commandPool{ VK_NULL_HANDLE };

		const LogicalDevice& m_logicalDevice;
	};

} // namespace Aminophenol

#endif // COMMAND_POOL_H
