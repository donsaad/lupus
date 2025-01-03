#pragma once

#include "Core.h"

namespace Lupus
{
	class LUPUS_API Application
	{

	public:
		Application();
		virtual ~Application();
		void Run();
	};
	// will be defined by client
	Application* CreateApplication();
}