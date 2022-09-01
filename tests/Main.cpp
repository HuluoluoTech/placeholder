#include <iostream>
#include <Placeholder.h>

class Sandbox : public Placeholder::Application
{
};

Placeholder::Application* Placeholder::CreateApplication()
{
    std::cout << "Sanbox created..." << std::endl;
    return new Sandbox();
}