
#ifndef LOGICAL_DEVICE_H
#define LOGICAL_DEVICE_H

#include "pch.h"

#include "Rendering/Device/PhysicalDevice.h"

namespace Aminophenol
{

	class AMINOPHENOL_API LogicalDevice
	{
	public:

		LogicalDevice(const Instance& instance, const PhysicalDevice& physicalDevice);
		~LogicalDevice();

		operator const VkDevice& () const;

		const VkDevice& getDevice() const;
		const Instance& getInstance() const;
		const PhysicalDevice& getPhysicalDevice() const;

		const uint32_t getGraphicsQueueFamilyIndex() const;
		const uint32_t getPresentQueueFamilyIndex() const;
		const uint32_t getComputeQueueFamilyIndex() const;
		const uint32_t getTransferQueueFamilyIndex() const;
		
		const VkQueue& getGraphicsQueue() const;
		const VkQueue& getPresentQueue() const;
		const VkQueue& getComputeQueue() const;
		const VkQueue& getTransferQueue() const;

		uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties) const;

	private:

		VkDevice m_device{ VK_NULL_HANDLE };

		const Instance& m_instance;
		const PhysicalDevice& m_physicalDevice;
		
		VkQueueFlags m_supportedQueues{};
		uint32_t m_graphicsFamilyIndex{ 0 };
		uint32_t m_presentFamilyIndex{ 0 };
		uint32_t m_computeFamilyIndex{ 0 };
		uint32_t m_transferFamilyIndex{ 0 };

		VkQueue m_graphicsQueue{ VK_NULL_HANDLE };
		VkQueue m_presentQueue{ VK_NULL_HANDLE };
		VkQueue m_computeQueue{ VK_NULL_HANDLE };
		VkQueue m_transferQueue{ VK_NULL_HANDLE };
		
		void findQueueFamilyIndices();

	};

} // namespace Aminophenol

#endif // LOGICAL_DEVICE_H
