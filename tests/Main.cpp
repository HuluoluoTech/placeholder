#include <iostream>
#include <Placeholder.h>

class Sandbox : public Placeholder::Application
{
};

Placeholder::Application* Placeholder::CreateApplication(Placeholder::ApplicationCommandLineArgs args)
{
    std::cout << "Sanbox created..." << std::endl;

	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.WorkingDirectory = "../Hazelnut";
	spec.CommandLineArgs = args;

	return new Sandbox(spec);
}