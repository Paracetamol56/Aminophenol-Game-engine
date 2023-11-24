
#ifndef TEXTURE_H
#define TEXTURE_H

#include "Image.h"

namespace Aminophenol
{

	class Texture final
		: public Image
	{
	public:

		Texture(
			const LogicalDevice& logicalDevice, const PhysicalDevice& physicalDevice, std::shared_ptr<CommandPool> commandPool,
			std::filesystem::path filename, VkFilter filter = VK_FILTER_LINEAR, VkSamplerAddressMode addressMode = VK_SAMPLER_ADDRESS_MODE_REPEAT
		);
		~Texture();

		std::filesystem::path getFilename() const;

	private:

		void load();
		std::filesystem::path m_filemane;

	};

} // namespace Aminophenol

#endif // !TEXTURE_H
