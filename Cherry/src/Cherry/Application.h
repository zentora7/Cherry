#pragma once

#include "Core.h"

namespace Cherry 
{
	class CHERRY_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client
	Application* CreateApplication();

}
