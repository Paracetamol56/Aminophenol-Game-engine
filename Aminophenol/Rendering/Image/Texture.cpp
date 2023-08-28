
#include "pch.h"
#include "Texture.h"
#include "Rendering/Buffers/Buffer.h"
#include <stb_image.h>

namespace Aminophenol
{

	Texture::Texture(
		const LogicalDevice& logicalDevice, const PhysicalDevice& physicalDevice, std::shared_ptr<CommandPool> commandPool,
		std::filesystem::path filename, VkFilter filter, VkSamplerAddressMode addressMode
	)
		: Image{
			logicalDevice, physicalDevice, commandPool,
			VkExtent3D{ 0, 0, 1 },
			VK_IMAGE_TILING_OPTIMAL,
			VK_IMAGE_USAGE_TRANSFER_SRC_BIT | VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
			VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT,
			VK_FORMAT_R8G8B8A8_UNORM,
			VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
		}
		, m_filemane { filename }
	{
		load();
	}

	Texture::~Texture()
	{}

	std::filesystem::path Texture::getFilename() const
	{
		return m_filemane;
	}

	void Texture::load()
	{
		if (!std::filesystem::exists(m_filemane))
			throw std::runtime_error("Texture file not found: " + m_filemane.string());

		int texWidth, texHeight, texChannels;
		stbi_uc* pixels = stbi_load(m_filemane.string().c_str(), &texWidth, &texHeight, &texChannels, STBI_rgb_alpha);
		m_extent = { static_cast<uint32_t>(texWidth), static_cast<uint32_t>(texHeight), 1 };
		VkDeviceSize imageSize = texWidth * texHeight * 4;

		if (!pixels)
			throw std::runtime_error("Failed to load texture image: " + m_filemane.string());

		Buffer stagingBuffer{
			m_logicalDevice,
			imageSize,
			VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
			VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
			pixels
		};

		stbi_image_free(pixels);

		Image::createImage(m_logicalDevice, m_image, m_imageMemory, m_extent, m_format, m_tiling, m_usage, m_properties);
		Image::createSampler(m_logicalDevice, m_sampler, VK_FILTER_LINEAR, VK_SAMPLER_ADDRESS_MODE_REPEAT, false, 1);
		Image::createImageView(m_logicalDevice, m_image, m_imageView, VK_IMAGE_VIEW_TYPE_2D, m_format, VK_IMAGE_ASPECT_COLOR_BIT, 1, 0, 1, 0);

	}

} // namespace Aminophenol
