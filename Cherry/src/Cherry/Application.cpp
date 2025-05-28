#include "crpch.h"
#include "Application.h"
#include "Cherry/Events/ApplicationEvent.h"
#include "Cherry/Log.h"

namespace Cherry
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(2560, 1440);
		CR_TRACE(e);

		while (true);
	}
}