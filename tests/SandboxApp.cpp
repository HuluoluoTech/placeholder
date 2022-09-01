#include <Placeholder.h>
#include <placeholder/core/EntryPoint.h>

#include "Sandbox2D.h"

class Sandbox : public Placeholder::Application
{
public:
	Sandbox(const Placeholder::ApplicationSpecification& specification)
	: Placeholder::Application(specification)
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Placeholder::Application* Placeholder::CreateApplication(Placeholder::ApplicationCommandLineArgs args)
{
	PL_CLIENT_TRACE("xxx");

	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "./Placeholdernut";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
