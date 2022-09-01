#pragma once

#include "Base.h"
#include "Application.h"

// #ifdef PL_PLATFORM_LINUX

extern Placeholder::Application* Placeholder::CreateApplication(ApplicationCommandLineArgs args);

int main(int argc, char** argv)
{
	Placeholder::Log::Init();

	// HZ_PROFILE_BEGIN_SESSION("Startup", "HazelProfile-Startup.json");
	auto app = Placeholder::CreateApplication({ argc, argv });
	// HZ_PROFILE_END_SESSION();

	// HZ_PROFILE_BEGIN_SESSION("Runtime", "HazelProfile-Runtime.json");
	app->Run();
	// HZ_PROFILE_END_SESSION();

	// HZ_PROFILE_BEGIN_SESSION("Shutdown", "HazelProfile-Shutdown.json");
	delete app;
	// HZ_PROFILE_END_SESSION();
}

// #endif
