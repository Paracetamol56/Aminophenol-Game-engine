
#ifndef INSTANCE_H
#define INSTANCE_H

#include "pch.h"

namespace Aminophenol
{

	class AMINOPHENOL_API Instance
	{
	public:

		Instance(std::string appName = "Aminophenol");
		~Instance();

		VkInstance getInstance();

	private:

		VkInstance m_instance;
#ifdef _DEBUG
		VkDebugUtilsMessengerEXT m_debugMessenger;
#endif // _DEBUG
		
		bool checkExtentionSupport(const std::vector<const char*>& requiredExtensions);
		bool checkLayerSupport(const std::vector<const char*>& requiredLayers);

	};

} // namespace Aminophenol

#endif // INSTANCE_H
