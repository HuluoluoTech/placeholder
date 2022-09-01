#pragma once

#include "Config.h"
#include "events/EventApplication.h"
#include "core/Log.h"

namespace Placeholder
{
    class Application
    {
        public:
            Application(){}
            ~Application(){}

        public:
            void Run()
            {
                Placeholder::AppRenderEvent e;
                if(e.IsInCategory(EventCategory::EventCategoryInput))
                {
                    PL_CORE_TRACE(e.GetName());
                }

                std::cout << e.GetName() << std::endl;

                while(true);
            }
            void Update() 
            {
                PL_CORE_TRACE("Application::Update");
            }
    };
    
    // impl in client
    Placeholder::Application* CreateApplication();
}