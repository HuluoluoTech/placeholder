#include <iostream>
#include <Placeholder.h>

class Sandbox : public Placeholder::Application
{
};

Placeholder::Application* Placeholder::CreateApplication()
{
    return new Sandbox();
}