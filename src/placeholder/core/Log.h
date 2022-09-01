#pragma once

#include <memory> // shared_ptr

#include <spdlog/spdlog.h>

namespace Placeholder
{
    class Log
    {
    public:
        Log();
        ~Log();

    public:
        static void Init();
        inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return _CoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return _ClientLogger; }

    private:
        static std::shared_ptr<spdlog::logger> _CoreLogger;
        static std::shared_ptr<spdlog::logger> _ClientLogger;
    };
}

// CORE 
#define PL_CORE_TRACE(...) ::Placeholder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PL_CORE_INFO(...)  ::Placeholder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PL_CORE_WARN(...)  ::Placeholder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PL_CORE_ERROR(...) ::Placeholder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PL_CORE_CRITICAL(...) ::Placeholder::Log::GetCoreLogger()->critical(__VA_ARGS__)

// CLIENT
#define PL_CLIENT_TRACE(...) ::Placeholder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PL_CLIENT_Info(...)  ::Placeholder::Log::GetClientLogger()->info(__VA_ARGS__)
#define PL_CLIENT_WARN(...)  ::Placeholder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PL_CLIENT_ERROR(...) ::Placeholder::Log::GetClientLogger()->error(__VA_ARGS__)
#define PL_CLIENT_CRITICAL(...) ::Placeholder::Log::GetClientLogger()->critical(__VA_ARGS__)
