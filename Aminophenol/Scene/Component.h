
#ifndef COMPONENT_H
#define COMPONENT_H

#include "pch.h"

#include "Utils/uuid_v4.h"

namespace Aminophenol {

	class AMINOPHENOL_API Component
	{
	public:

		Component();
		~Component();

		virtual void update() = 0;
		virtual void fixedUpdate() = 0;

	private:

	};

} // namespace Aminophenol

#endif // COMPONENT_H
