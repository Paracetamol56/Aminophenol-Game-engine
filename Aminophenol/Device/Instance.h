
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

	private:

		VkInstance m_instance;

		std::vector<const char*> getRequiredExtensions();

	};

} // namespace Aminophenol

#endif // INSTANCE_H
