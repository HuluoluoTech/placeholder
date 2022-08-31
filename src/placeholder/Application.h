#pragma once

namespace Placeholder
{
    class Application
    {
        public:
            Application(){}
            ~Application(){}

        public:
            void Run();
    };
    
    // impl in client
    Placeholder::Application* CreateApplication();
}