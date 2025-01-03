#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Lupus/Log.h"
#include "Events/Event.h"

namespace Lupus {

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1920, 1080);
		LP_TRACE(e.ToString());
		while (true);
	}

}
