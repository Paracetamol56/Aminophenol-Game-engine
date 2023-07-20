
#include "pch.h"
#include "CommandPool.h"

#include "Logging/Logger.h"

namespace Aminophenol {

	CommandPool::CommandPool(const LogicalDevice& logicalDevice)
		: m_logicalDevice(logicalDevice)
	{
		Logger::log(LogLevel::Trace, "Creating command pool");
		
		VkCommandPoolCreateInfo commandPoolCreateInfo{};
		commandPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
		commandPoolCreateInfo.flags = VK_COMMAND_POOL_CREATE_TRANSIENT_BIT | VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
		commandPoolCreateInfo.queueFamilyIndex = m_logicalDevice.getGraphicsQueueFamilyIndex();

		if (vkCreateCommandPool(m_logicalDevice, &commandPoolCreateInfo, nullptr, &m_commandPool) != VK_SUCCESS)
		{
			throw std::runtime_error("Failed to create command pool!");
		}

		Logger::log(LogLevel::Trace, "Successfully created command pool");
	}

	CommandPool::~CommandPool()
	{
		vkDestroyCommandPool(m_logicalDevice, m_commandPool, nullptr);
	}

	CommandPool::operator const VkCommandPool& () const
	{
		return m_commandPool;
	}

} // namespace Aminophenol
