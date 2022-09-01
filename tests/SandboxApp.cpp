#include "Sandbox2D.h"

class Sandbox : public Placeholder::Application
{
public:
	Sandbox(const Placeholder::ApplicationSpecification& specification)
	: Placeholder::Application(specification)
	{
		// PushLayer(new ExampleLayer());
		// PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

Placeholder::Application* Placeholder::CreateApplication(Placeholder::ApplicationCommandLineArgs args)
{
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../Placeholdernut";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}
