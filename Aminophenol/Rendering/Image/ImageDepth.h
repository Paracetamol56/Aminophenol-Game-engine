
#ifndef IMAGE_DEPTH_H
#define IMAGE_DEPTH_H

#include "pch.h"
#include "Rendering/Image/Image.h"
#include "Rendering/Device/LogicalDevice.h"
#include "Rendering/Device/PhysicalDevice.h"

namespace Aminophenol
{

	class ImageDepth : public Image
	{
	public:

		ImageDepth(
			const LogicalDevice& logicalDevice,
			const PhysicalDevice& physicalDevice,
			const VkExtent3D& extent
		);

	};

} // namespace Aminophenol

#endif // !IMAGE_DEPTH_H
