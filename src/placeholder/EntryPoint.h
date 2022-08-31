#pragma once

// #ifdef PL_PLATFORM_UNIX

extern Placeholder::Application* Placeholder::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Placeholder::CreateApplication();
    app->Run();
    delete app;
}

// #endif