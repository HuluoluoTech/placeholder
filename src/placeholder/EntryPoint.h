#pragma once

#include "Config.h"
#include "Log.h"

extern Placeholder::Application* Placeholder::CreateApplication();

int main(int argc, char** argv)
{
    Placeholder::Log::Init();
    PL_CORE_TRACE("core log");
    int x = 4;
    PL_CLIENT_TRACE("client trace : {0}", x);
    
    Placeholder::Application* app = Placeholder::CreateApplication();
    app->Run();
    app->Update();
    delete app;

    PL_CORE_TRACE("App Deleted...");
}

// #endif