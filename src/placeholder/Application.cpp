#include <iostream>
#include "Application.h"
#include "Config.h"
#include "events/EventApplication.h"
#include "Log.h"

namespace Placeholder
{
	void Application::Run()
	{
		std::cout << "Run..." << std::endl;
		
		Placeholder::AppUpdateEvent e;
		PL_CORE_TRACE(e.GetName());

		while(true);
	}
}