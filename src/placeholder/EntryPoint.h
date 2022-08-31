#pragma once

#include "Config.h"

extern Placeholder::Application* Placeholder::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Placeholder::CreateApplication();
    app->Run();
    delete app;
}

// #endif